import { 
    collection,
    getDocs,
    getDoc,
    doc,
    addDoc,
} from "https://www.gstatic.com/firebasejs/10.13.1/firebase-firestore.js";
import { 
    getDownloadURL,
    ref,
    uploadBytes,
} from "https://www.gstatic.com/firebasejs/10.13.1/firebase-storage.js";

import { db, storage } from "./app.js";

async function getMembers() {
    try {
        const querySnapshot = await getDocs(collection(db, "member"));
        const membersPending = querySnapshot.docs.map(async (doc) => {
            const depRef = doc.data().department;
            const depDoc = await getDoc(depRef);
            const depObj = depDoc.data();
            console.log(storage);
            //getDownloadURL
            const image_file_name = doc.data().image_file_name;
            console.log(image_file_name);
            const fileRef = ref(storage, `images/${image_file_name}`)
            const imageSrc = await getDownloadURL(fileRef);
            console.log(fileRef);            

            return { 
                id: doc.id, 
                ...doc.data(),
                department: depObj,
                imageSrc: imageSrc, 
            };
        });
        const members = await Promise.all(membersPending);
        return members;
    } catch (error) {
        return error.code;
    }
}

async function getMember(id) {
    try {
        const docSnapshot = await getDoc(doc(db, "member", id));
        if (docSnapshot.exists()) {
            const depRef = docSnapshot.data().department;
            const depDoc = await getDoc(depRef);
            const depObj = depDoc.data();

            const member = {
                id: docSnapshot.id, 
                ...docSnapshot.data(),
                department: depObj,
            };
            return member;
        } else {
            return 404;
        }
    } catch (error) {
        return error.code;
    }
}

async function createMember(name, depId) {
    const newMember = {
        name: name,
        department: doc(db, "department", depId),
    };
    try {
        await addDoc(collection(db, "member"), newMember);
    } catch (error) {
        return error.code;
    }
}

async function uploadImage(newFile) {
    const timestamp = Date.now();
    try {
        const newFileName = `${timestamp}_${newFile.name}`;
        const fileRef = ref(storage, `images/${newFileName}`);
        await uploadBytes(fileRef, newFile);
    } catch (error) {
        return error.code;
    }
}

    
export { getMembers, getMember, createMember, uploadImage };