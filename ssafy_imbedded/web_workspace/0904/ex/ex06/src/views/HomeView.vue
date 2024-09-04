<script setup>

import HomeChild from '@/components/HomeChild.vue';
import { ref } from 'vue';
import { useCounterStore } from '@/stores/counter';
const counter = useCounterStore();
console.log(counter.count);
counter.increment();
counter.increment();


const name = ref("david");
const age = ref(10);

function changeName(n){
    console.log(n);
    name.value = n;
    console.log("comein")
}

</script>

<template>
    <h1>Home</h1>
    <div>count : {{ counter.count }}</div>
    <div>{{ name }}</div>
    <div>{{ age }}</div>
    
    <HomeChild
    @emitTest="changeName"
    :nameProp="name" 
    :ageProp="age"
    ></HomeChild>

</template>

<style scoped>

</style>