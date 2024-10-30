  // Import the functions you need from the SDKs you need
  import { initializeApp } from "https://www.gstatic.com/firebasejs/10.13.1/firebase-app.js";
  import { getFirestore } from "https://www.gstatic.com/firebasejs/10.13.1/firebase-firestore.js";
  import { getStorage } from "https://www.gstatic.com/firebasejs/10.13.1/firebase-storage.js";

  // TODO: Add SDKs for Firebase products that you want to use
  // https://firebase.google.com/docs/web/setup#available-libraries

  // Your web app's Firebase configuration
  const firebaseConfig = {
    apiKey: "AIzaSyBq8A0uv2tP5W1T8BX86Ws4wQXty7cJyNA",
    authDomain: "office-project-64c1c.firebaseapp.com",
    projectId: "office-project-64c1c",
    storageBucket: "office-project-64c1c.appspot.com",
    messagingSenderId: "471409948066",
    appId: "1:471409948066:web:1c4f5060153e02bf19eefb"
  };

  // Initialize Firebase
  const app = initializeApp(firebaseConfig);
  const db = getFirestore(app);
  const storage = getStorage();

  export { db, storage };