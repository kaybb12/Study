<script setup>
import { defineProps, defineEmits } from 'vue';
import ChickenChild from './ChickenChild.vue';

const props = defineProps({
  title: String,
  salt: Number,
});

const emit = defineEmits(['update-salt']);

const updateSalt = (newSalt) => {
  emit('update-salt', newSalt);
};
</script>

<template>
    <div>
      <h2>FriedChicken</h2>
      <p>Title: {{ title }}</p>
      <p>Salt: {{ salt }}</p>
      <ChickenChild :title="title" :salt="salt" @update-salt="updateSalt" />
    </div>
</template>
  
  