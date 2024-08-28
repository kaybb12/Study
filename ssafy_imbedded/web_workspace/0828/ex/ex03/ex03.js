import { db } from "../app.js";
import { collection, getDocs, orderBy, query, getDoc, doc } from "https://www.gstatic.com/firebasejs/10.13.0/firebase-firestore.js";

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

export { getArticles }
