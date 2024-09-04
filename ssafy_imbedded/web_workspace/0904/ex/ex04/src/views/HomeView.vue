<script setup>

import { usePersonStore } from '@/stores/person';
import Homechild from '@/components/Homechild.vue';

const personStore = usePersonStore();
</script>

<template>
    <h1>게시판</h1>
    <p>이름: {{ personStore.name }}</p>
    <p>나이: {{ personStore.age }}</p>
    <button @click="personStore.decreaseAge">나이를 줄이자</button>
    <Homechild></Homechild>
</template>

<style scoped>
</style>
