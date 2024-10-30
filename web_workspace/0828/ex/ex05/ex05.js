import { db } from "../app.js";
import { collection, getDocs, orderBy, query, getDoc, doc, Timestamp, addDoc } from "https://www.gstatic.com/firebasejs/10.13.0/firebase-firestore.js";

async function getArticles() {
    try {
        const collectionRef = await collection(db, "articles");
        const q = await query(collectionRef,
            orderBy("createdAt", "desc"));
        const querySnapShot = await getDocs(q);
        const articles = querySnapShot.docs.map((doc) => {
            return { id: doc.id, ...doc.data() }
        });
        return articles;
    } catch (error) {
        return error.code;
    }
}

async function getArticle(id) {
    try {
      const docRef = await doc(db, "articles", id);
      const docSnapshot = await getDoc(docRef);
      if(docSnapshot.exists() ){
        const article = {
          id: docSnapshot.id,
          ...docSnapshot.data()
        };
        return article
      } else{
        return 404;
      }
    } catch (error) {
      return error.code;
    }
}

async function createArticle(title, content) {
    const timestamp = Timestamp.fromDate(new Date());
    const newArticle = {
        title: title,
        content: content,
        createdAt: timestamp,
        updatedAt: timestamp,
    };
    try {
        const docRef = await addDoc(collection(db, "articles"), newArticle);
        return docRedf.id;
    } catch (error) {
        return error.code;
    }
}

export { getArticles, getArticle, createArticle };