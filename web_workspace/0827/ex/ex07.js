const express = require("express");
const morgan = require("morgan");
const app = express();
const PORT = 8080;

app.use(express.json());
app.use(morgan("dev"));

const { pool } = require("./db");

app.get("/api/todos", async (req, res) => {
    try {
        const data = await pool.query("SELECT * FROM todos");
        console.log(data[0]);
        if (data[0]) {
            return res.json(data[0]);
        }
    }catch(error){
        return res.json(error);
    }
});

app.get("/api/todos/:id", async (req, res) => {
    try {
        const data = await pool.query(
            "SELECT * FROM todos WHERE todo_id = ?",
            [req.params.id]
        );
        return res.json(data[0][0]);
    } catch(error){
        return res.json(error);
    }
});

app.post("/api/todos", async (req, res) => {
    try {
        const data = await pool.query(
            "insert todos (todo_id, title, is_completed, author) value (?, ?, ?, ?)",
            [req.body.todo_id, req.body.title, req.body.is_completed, req.body.author]
        );
        return res.json(data);
    } catch(error){
        return res.json(error);
    }
});

app.patch("/api/todos/:id", async (req, res) => {
    try {
        const data = await pool.query(
            "UPDATE todos SET title = ?, is_completed = ?, author = ? WHERE todo_id = ?",
            [req.body.title, req.body.is_completed, req.body.author, req.params.id]  
        );
        return res.json(data);
    } catch(error){
        return res.json(error);
    }
});

app.delete("/api/todos/:id", async (req, res) => {
    try {
        const data = await pool.query(
            "delete from todos WHERE todo_id = ?",
            [req.params.id]  
        );
        return res.json(data);
    } catch(error){
        return res.json(error);
    }
});

app.get("/api/author/:name", async (req, res) => {
    try {
        const data = await pool.query(
            "SELECT * FROM todos WHERE author = ?",
            [req.params.name]
        );
        return res.json(data[0][0]);
    } catch(error){
        return res.json(error);
    }
});

app.get("/api/completed", async (req, res) => {
    try {
        const data = await pool.query(
            "SELECT * FROM todos WHERE is_completed = 1"
        );
        return res.json(data[0]);
    } catch(error){
        return res.json(error);
    }
});

app.listen(PORT, () => `${PORT} 서버 기동중`)
