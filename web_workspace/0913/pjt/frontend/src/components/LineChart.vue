<script setup>
import {
  Chart as ChartJS,
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
  Title,
  Tooltip,
  Legend
} from 'chart.js'
import { Line } from 'vue-chartjs'
import { ref } from "vue"
// import * as chartConfig from './chartConfig.js'

ChartJS.register(
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
  Title,
  Tooltip,
  Legend
)


import { useChartStore } from "@/stores/chart.js"

const chartStore = useChartStore();

console.log(chartStore.chartData);

// const chartData = ref ( {
//   labels: ["January", "February", "March"],
//   datasets: [
//     {
//       label: "A",
//       backgroundColor: "blue",
//       borderColor: "blue",
//       data: [7.179, 8.210, 15.568],
//       tension: 0.3
//     },
//     {
//       label: "B",
//       backgroundColor: "green",
//       borderColor: "green",
//       data: [10.179, 2.210, 50.568],
//       tension: 0.3
//     }
//   ]
// } )

const chartOptions = ref({
  responsive: true,
})

</script>

<template>
  <Line id="my-chart-id" :options="chartOptions" :data="chartStore.chartData"></Line>
</template>
