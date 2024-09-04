<script setup>
import { defineProps, defineEmits } from 'vue';

const props = defineProps({
  title: String,
  salt: Number,
});

const emit = defineEmits(['update-salt']);

const changeSalt = () => {
  emit('update-salt', 20);
};
</script>

<template>
    <div>
      <h3>ChickenChild</h3>
      <p>Title: {{ title }}</p>
      <p>Salt: {{ salt }}</p>
      <button @click="changeSalt">소금을 20으로 변경</button>
    </div>
</template>
  