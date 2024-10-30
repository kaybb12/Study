<script setup>

import { ref } from 'vue';

const word = ref("Hello World!")

function reverseMessage() {
    const temp = word.value.split('');
    //console.log(temp);
    temp.reverse();
    //console.log(temp);
    word.value = temp.join('');    
}

function append() {
    word.value += "!";
}

</script>

<template>
    <h1>{{ word }}</h1>
    <button @click="reverseMessage">Reverse Message</button>
    <button @click="append">Append “!”</button>

</template>

<style scoped>

</style>