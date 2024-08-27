const express = require("express");
const morgan = require("morgan");
const app = express();
const PORT = 8080;

app.use(express.json());
app.use(morgan("dev"));

const infos = [
    {
        name: "나나",
        age: 12,
    },
    {
        name: "유진",
        age: 8,
    },
    {
        name: "재범",
        age: 40,
    }
]

app.get("/api/info/names", (req, res) => {
    const nameList = infos.map(el => el.name);
    return res.json(nameList);
});

app.get("/api/info/ages", (req, res) => {
    const ageList = infos.map(el => el.age);
    return res.json(ageList);
});

app.get("/api/info/:id", (req, res) => {
    const data = infos;
    const idx = req.params.id;
    return res.json(data[idx]);
});

app.listen(PORT, () => `${PORT} 서버 기동중`);