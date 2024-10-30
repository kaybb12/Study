import {ref} from "vue";
import { defineStore} from "pinia"

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

  return {chartData, setChartData}
  
})
