import {ref} from "vue";
import { defineStore} from "pinia"
import dataLab from "@/utils/api";

export const useChartStore = defineStore("chart", () => {

  const chartData = ref ( {
    labels: ["January", "February", "March"],
    datasets: [
      {
        label: "A",
        backgroundColor: "blue",
        borderColor: "blue",
        data: [7.179, 8.210, 15.568],
        tension: 0.3
      },
      {
        label: "B",
        backgroundColor: "green",
        borderColor: "green",
        data: [10.179, 2.210, 50.568],
        tension: 0.3
      }
    ]
  } )

  function setChartData(data){
    chartData.value = data;
  }

  function makeColor() {
    return "#" + Math.round(Math.random() * 0xffffff).toString
  }

  async function makeChart() {
    try {
      const response = await dataLab.get();
      console.log(response);
      const chartData = {
        labels: response.data[0].data.map((li) => li.period),
        datasets: response.data.reduce((acc, cur) => {
          const label = cur.title;
          const data = cur.data.map((li) => li.ratio);
          acc.push({
            label: label,
            data: data,
            fill: false,
            backgroundColor: makeColor(),
            borderColor: makeColor(),
          });
        return acc;
    }, []),
  };
  
  setChartData(chartData);
  } catch (error) {
  console.log(error);
  }
  }
  
  return { chartData, setChartData, makeChart };
});   
