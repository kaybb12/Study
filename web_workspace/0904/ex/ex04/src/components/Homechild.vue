<script setup>
import { usePersonStore } from '@/stores/person';
import GrandChild from './GrandChild.vue';

const personStore = usePersonStore();
</script>

<template>
  <div>
    <h2>Child</h2>
    <p>이름: {{ personStore.name }}</p>
    <p>나이: {{ personStore.age }}</p>
    <button @click="personStore.changeName('데이비드')">이름 변경</button>
  </div>
  <GrandChild></GrandChild>
</template>

<style scoped>
</style>
