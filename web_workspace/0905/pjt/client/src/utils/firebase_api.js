  // Import the functions you need from the SDKs you need
  import { initializeApp } from "firebase/app";
  import { 
      getFirestore,
      collection,
      getDocs,
      getDoc,
      doc,
      addDoc,
      updateDoc,
      deleteDoc,
   } from "firebase/firestore";
  import { 
      getStorage,
      getDownloadURL,
      ref,
      uploadBytes,
      deleteObject, 
  } from "firebase/storage";
  // TODO: Add SDKs for Firebase products that you want to use
  // https://firebase.google.com/docs/web/setup#available-libraries
  
    // Your web app's Firebase configuration
    const firebaseConfig = {
      apiKey: "AIzaSyBaQF5ZRnykHTJZEdnJ1MlmEx79-W3YD88",
      authDomain: "oreder-system.firebaseapp.com",
      projectId: "oreder-system",
      storageBucket: "oreder-system.appspot.com",
      messagingSenderId: "964396017061",
      appId: "1:964396017061:web:6db0a99f01dbbc9741b44c"
    };
  
    // Initialize Firebase
    const app = initializeApp(firebaseConfig);
    const db = getFirestore(app);
    const storage = getStorage();
  
    const api ={
      menus: {
          findAll: async () => {
              try {
                  const querySnapshot = await getDocs(collection(db, "menus"));
                  const menus = querySnapshot.docs.map((doc) => {
                      return { id: doc.id, ...doc.data() };
                  });
                  //console.log(menus);
                  const newMenusPending = menus.map(async (menu) => {
                      const urlRef = ref(storage, `images/${menu.image_file_name}`);
                      const url = await getDownloadURL(urlRef)
                      return {
                          ...menu,
                          image_src: url,
                      };
                  });
                  const newMenus = await Promise.all(newMenusPending);
                  return newMenus;
              } catch (error) {
                  return error.code;
              }                
          },
          findOne: async (id) => {
              try {
                  const docSnapshot = await getDoc(doc(db, "menus", id));
                  if (docSnapshot.exists()) {
                      const menu = {
                          id: docSnapshot.id,
                          ...docSnapshot.data(),
                      };
                      const urlRef = ref(storage, `images/${menu.image_file_name}`);
                      const url = await getDownloadURL(urlRef);
                      return {
                          ...menu,
                          image_src: url,
                      };
                  } else {
                      return 404;
                  }
              } catch (error) {
                  return error.code;
              }                
          },
          create: async (name, description, file) => {
              const timestamp = Date.now();
              const newFileName = `${timestamp}_${file.name}`;
              const newMenu = {
                  name: name,
                  description: description,
                  image_file_name: newFileName,
              };
              try {
                  await addDoc(collection(db, "menus"), newMenu);
                  const uploadRef = ref(storage, `images/${newFileName}`);
                  await uploadBytes(uploadRef, file);
              } catch (error) {
                  return error.code;
              }
          },
          update: async (id, newName, newDescription) => {
              const newMenu = {
                  name: newName,
                  description: newDescription,
              };
              try {
                  await updateDoc(doc(db, "menus", id), newMenu);
              } catch (error) {
                  return error.code;
              }                
          },
          updateImage: async (originalMenu, newFile) => {
              const timestamp = Date.now();
              const newFileName = `${timestamp}_${newFile.name}`;
              const newMenu = {
                  name: originalMenu.name,
                  description: originalMenu.description,
                  image_file_name: newFileName,
              };
              try {
                  await updateDoc(doc(db, "menus", originalMenu.id), newMenu);
                  const deleteRef = ref(storage, `images/${originalMenu.image_file_name}`);
                  await deleteObject(deleteRef);
                  const uploadRef = ref(storage, `images/${newFileName}`);
                  await uploadBytes(uploadRef, newFile);
              } catch (error) {
              return error.code;
              }
          },
          delete: async (originalMenu) => {
              try {
                  const deleteRef = ref(storage, `images/${originalMenu.image_file_name}`)
                  await deleteObject(deleteRef);
                  await deleteDoc(doc(db, "menus", originalMenu.id));
              } catch (error) {
                  return error.code;
              }                
          },
      },
      orders: {
          findAll: async () => {
              try {
                  const querySnapshot = await getDocs(collection(db, "orders"));
                //console.log(querySnapshot);
                  const ordersPending = querySnapshot.docs.map(async (doc) => {
                      const mdRef = doc.data().menu_id;
                      const mdDoc = await getDoc(mdRef);
                      const mdObj = mdDoc.data();
                      const urlRef = ref(storage, `images/${mdObj.image_file_name}`);
                      const url = await getDownloadURL(urlRef)

                      return {
                          id: doc.id,
                          ...doc.data(),
                          menu_id: mdObj,
                          image_src: url,
                      };
                  });
                  //console.log("aa")
                  const orders = await Promise.all(ordersPending);
                  //console.log(orders);
                  return orders;
              } catch (error) {
                console.log(error);
                  return error.code;
              }                
          },
          findOne: async (id) => {
              try {
                  const docSnapshot = await getDoc(doc(db, "orders", id));
                  //console.log(docSnapshot);
                  if (docSnapshot.exists()) {
                      const mdRef = docSnapshot.data().menu_id;
                      //console.log(mdRef);
                      const mdDoc = await getDoc(mdRef);
                      //console.log(mdDoc);
                      const mdObj = mdDoc.data();
                      //console.log(mdObj);
                      const urlRef = ref(storage, `images/${mdObj.image_file_name}`);
                      const url = await getDownloadURL(urlRef)      
                      const order = {
                          id: docSnapshot.id,
                          ...docSnapshot.data(),
                          menu_id: mdObj,
                          image_src: url,
                      };
                      //console.log(order);
                      return order;
                  } else {
                      return 404;
                  } 
              } catch (error) {
                  return error.code;
              }
          },
          create: async (quantity, request_detail, mdID) => {
              const newOrder = {
                  quantity: quantity,
                  request_detail: request_detail,
                  menu_id: doc(db, "menus", mdID),
              };
              try {
                  await addDoc(collection(db, "orders"), newOrder);
              } catch(error) {
                  return error.code;
              }
          },
          update: async (id, newQuantity, newRequest_detail) => {
              const newOrder = {
                  quantity: newQuantity,
                  request_detail: newRequest_detail,
              }
              try {
                  await updateDoc(doc(db, "orders", id), newOrder);
              } catch (error) {
                  return error.code;
              }
          },
          delete: async (exOrder) => {
              try {
                  const delDoc = doc(db, "orders", exOrder.id);
                  await deleteDoc(delDoc);
              } catch (error) {
                  return error.code;
              }
          },
      },
  };
  
  export { app, db, storage, api };
      