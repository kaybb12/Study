import axios from "axios";

const api = axios.create({
  baseURL: "http://localhost:8080"
});

const dataLab = {
  get:() => {
    return api.get("/data")
    // return axios.get("http://localhost:8080/data")
  },
  post:(data) => {
    return api.post("/data", data)
  }
}

export default dataLab;
