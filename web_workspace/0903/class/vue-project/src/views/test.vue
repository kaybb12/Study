<script setup>
import { ref } from 'vue';

const message = ref("delete text");

</script>

<template>
    {{ message }}
    <input type="text" v-model="message">
    <input type="text" :value="message">
</template>

<style scoped>

</style>