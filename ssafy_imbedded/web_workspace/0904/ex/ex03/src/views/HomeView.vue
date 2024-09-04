<script setup>

import { ref } from 'vue';
import Detail from '@/components/Detail.vue';

const posts = ref([
    { id: 1, title: '즐거운 싸피' },
    { id: 2, title: 'vue 할만함?' },
    { id: 3, title: '임베 화이팅' },
]);
</script>

<template>
    <h1>게시판</h1>
    <ul>
      <li v-for="post in posts" :key="post.id">
        <router-link :to="{ name: 'Detail', params: { id: post.id }}">{{ post.title }}</router-link>
      </li>
    </ul>
</template>

<style scoped>

</style>