
<script setup>

import { ref } from 'vue';

const num = ref();
const ans = Math.floor(Math.random() * 100) + 1
console.log(ans);
</script>

<template>
    <h1>1 to 100</h1>
    <input type="number" v-model="num">
    <div v-if="num === undefined">1 부터 100 사이 숫자를 입력하세요</div>
    <div v-else-if="num > 100 || num < 1">1 부터 100 까지의 수가 아닙니다</div>
    <div v-else-if="num === ans">정답</div>
    <div v-else-if="num <= ans">UP</div>
    <div v-else-if="num >= ans">DOWN</div>
    
</template>

<style scoped>

</style>s