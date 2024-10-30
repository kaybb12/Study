const express = require("express");
const morgan = require("morgan");
const app = express();
const PORT = 8080;

app.use(express.json());
app.use(morgan("dev"));

const { pool } = require("./db");

app.get("/api/menus", async (req, res) => {
    try {
        const data = await pool.query("SELECT * FROM menus");
        console.log(data[0]);
        if (data[0]) {
            return res.json(data[0]);
        }
    }catch(error){
        return res.json(error);
    }
});

app.patch("/api/menus/:id", async (req, res) => {
    try {
        const data = await pool.query(
            "UPDATE menus SET name = ?, description = ? WHERE menu_id = ?",
            [req.body.name, req.body.description, req.params.id]
        );
        return res.json(data);
    }catch(error){
        return res.json(error);
    }
});
app.listen(PORT, () => `${PORT} 서버 기동중`)
