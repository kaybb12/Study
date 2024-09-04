<script setup>
import { useRouter } from 'vue-router';
const router = useRouter();

function goBack() {
    router.push({name : "home"});
}

</script>

<template>
    <div>
        <h1>{{ $route.params.id }}번 글 상세페이지</h1>
        <button @click="goBack">뒤로가기</button>
  </div>
</template>

<style scoped>

</style>