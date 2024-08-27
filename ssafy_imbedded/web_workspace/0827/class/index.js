const express = require("express");
//로그 남기는 세팅
const morgan = require("morgan");

const app = express();
const PORT = 8080;
//express.json() body의 데이터 사용시 넣는 옵션
//app.use 모든 요청마다 전역 적용
app.use(express.json());
app.use(morgan("dev"));
app.get("/", (req, res) => {
    return res.json({
        hello: "world"
    })
});

app.get("/api/info", (req, res) => {
    return res.json({
        name: "david",
        job: "tutor"
    })
});

const infos = [
    {name: "나나", age: 12},
    {name: "유진", age: 8},
    {name: "재범", age: 40}
];

app.get("/api/info/names", (req, res) => {
    const nameList = infos.map(el => el.name);
    return res.json(nameList);
});

app.post("/api/info/names", (req, res) => {
    const nameList = infos.map(el => el.name);
    console.log(req.query);
    console.log(req.params);
    console.log(req.body);
    return res.json(nameList);
});

app.get("/api/info/names/:id", (req, res) => {
    console.log(req.params);
    return res.json({
        test: "OK"
    })
});

app.listen(PORT, () => console.log('${PORT} 서버 기동중'));