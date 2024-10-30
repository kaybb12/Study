<script setup>
import { usePersonStore } from '@/stores/person';

const personStore = usePersonStore();
</script>

<template>
  <div>
    <h3>GrandChild</h3>
    <p>이름: {{ personStore.name }}</p>
    <button @click="personStore.resetAge">한살로 돌아가자</button>
  </div>
</template>

<style scoped>
</style>
