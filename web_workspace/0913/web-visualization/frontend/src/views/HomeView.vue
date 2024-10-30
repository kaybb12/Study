<script setup>
import LineChart from "@/components/LineChart.vue"
import dataLab from "../utils/api.js"


async function getData() {
  try {
    const response = await dataLab.get();
    console.log(response);
  } catch (error) {
    console.log(error);
  }
}

getData();


</script>

<template>
  <LineChart></LineChart>
</template>
