<script setup>
import { ref } from 'vue';
import FriedChicken from '@/components/FriedChicken.vue';

const title = ref("치킨은 맛있다");
const salt = ref(30);

const updateSalt = (newSalt) => {
  salt.value = newSalt;
};
</script>

<template>
    <div>
      <h1>HomeView</h1>
      <FriedChicken :title="title" :salt="salt" @update-salt="updateSalt" />
    </div>
  </template>

  