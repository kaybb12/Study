<script setup>

import { ref } from 'vue';

const url = ref("https://naver.com/");

function setURLNaver() {
  url.value = "https://naver.com/";
}

function setURLGoogle() {
  url.value = "https://google.com/"
}

const selectedColor = ref("red");

</script>

<template>
    <div>
      <a :href="url">이동</a>
    </div>

    <button @click="setURLNaver">naver</button>
    <button @click="setURLGoogle">Google</button>
    <input type="text" v-model="selectedColor">

    <hr/>
    <h1 :style="{color : selectedColor }"> color </h1>

</template>

<style scoped>

</style>