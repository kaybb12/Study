<script setup>

import { ref } from 'vue';
const lottoNums = ref([ 0, 0, 0, 0, 0, 0 ]);
function createNum() {
    for (let i = 0; i < 6; ++i) {
        let num = Math.floor(Math.random() * 45) + 1;
        if (lottoNums.value.includes(num)) {
            while(lottoNums.value.includes(num)) {
                num = Math.floor(Math.random() * 45) + 1;
            }               
        }
        lottoNums.value[i] = num; 
    }
    lottoNums.value.sort((a, b) => a - b);
}

</script>

<template>
    <h1>로또 번호 생성기</h1>
    <button @click="createNum">번호 생성</button>
    <div>{{ lottoNums }}</div>
</template>

<style scoped>

</style>