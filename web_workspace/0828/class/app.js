 // Import the functions you need from the SDKs you need
 import { initializeApp } from "https://www.gstatic.com/firebasejs/10.13.0/firebase-app.js";
 import { getFirestore } from "https://www.gstatic.com/firebasejs/10.13.0/firebase-firestore.js";
 import { getAuth } from "https://www.gstatic.com/firebasejs/10.13.0/firebase-auth.js"
 // TODO: Add SDKs for Firebase products that you want to use
 // https://firebase.google.com/docs/web/setup#available-libraries

 // Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
 const firebaseConfig = {
    apiKey: "AIzaSyAVqNH9KRKgCsBkjfnRgDHT__5NimkLw0c",
    authDomain: "my-project-7ceed.firebaseapp.com",
    projectId: "my-project-7ceed",
    storageBucket: "my-project-7ceed.appspot.com",
    messagingSenderId: "949385673702",
    appId: "1:949385673702:web:926b115cfccab7f4db3427",
    measurementId: "G-7XF086WX94"
  };

 // Initialize Firebase
 const app = initializeApp(firebaseConfig);
 const db = getFirestore(app);
 const auth = getAuth(app);
 export { db, auth };