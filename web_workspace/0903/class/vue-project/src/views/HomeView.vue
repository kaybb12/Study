
<script setup>

import { ref } from 'vue';

const test = ref("");
const flag = ref(test === "A" || test === "B" || test === "C");
console.log(test);
</script>

<template>
    <input type="text" v-model="test">
    <div>{{ test }}</div>
    <div v-if="flag">{{ test }}</div>
    <div v-else>A B C 가 아닙니다</div>
</template>

<style scoped>

</style>s