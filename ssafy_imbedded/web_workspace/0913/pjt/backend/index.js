const express = require("express");

const app = express();
const PORT = 8080;
const axios = require("axios");
const dotenv = require("dotenv");
const fs = require("fs");
dotenv.config();

//cors 셋팅이 안되어있으면 frontend에서 cors 에러가 난다.


// 지금 환경이 프론트는 5137 백엔드는 8080 
// 서로 같은 ip지만 포트가 달라서 cors 에러가 난다. 
const cors = require("cors");

const morgan = require("morgan");
app.use(cors());
app.use(morgan("dev"));
app.use(express.json());

const url = 'https://openapi.naver.com/v1/datalab/search';

app.get("/", async (req, res) => {
  try {
    return res.json({
      test: true
    })
  } catch (error) {
    return res.json({
      test: false
    })
  }
})

app.post("/data", async (req, res) => {
  try {
    
    const request_body = {
      startDate: req.body.startDate,
      endDate: req.body.endDate,
      timeUnit: req.body.timeUnit,
      device: req.body.device === "all" ? "" : req.body.device,
      gender: req.body.gender === "all" ? "" : req.body.gender,
      keywordGroups: req.body.keywordGroups,
    };

   // console.log(process.env.CLIENT_ID, process.env.CLIENT_SECRET);
    const headers = {
      'X-Naver-Client-Id': process.env.CLIENT_ID,
      'X-Naver-Client-Secret': process.env.CLIENT_SECRET,
      'Content-Type': 'application/json'
    }

    //axios.post(주소,요청을넣을바디, {옵션})
    const response = await axios.post(url, request_body, {
      // headers:headers
      headers
    });
    //console.log(response);
    // console.log(response.data.results)
    console.log(JSON.stringify(response.data.results));

    fs.writeFile("./uploads/chart.json", JSON.stringify(response.data.results),
      error => {
        if (error) {
          console.log(error);
          throw error;
        }
      }
    )

    return res.json(response.data.results);
  } catch (error) {
    console.log(error);
    return res.json({
      test: false
    })
  }
});

app.get("/data", async (req, res) => {
  try {
    res.set("Content-Type", "application/json; charset=utf-8");
    const tempFile = fs.createReadStream("uploads/chart.json");
    return tempFile.pipe(res);
  } catch (error) {
    return res.json({
      test: false
    })
  }
})

app.delete("/data", async (req, res) => {
  try {
    return res.json({
      test: true
    })
  } catch (error) {
    return res.json({
      test: false
    })
  }
})


app.listen(PORT, () => console.log(`${PORT} 서버 기동중`));
