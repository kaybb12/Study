<script setup>

import GrandChild from './GrandChild.vue';
import { useCounterStore } from '@/stores/counter';
const counter = useCounterStore();
console.log(counter.count);
counter.increment();
counter.increment();

const props = defineProps({
    nameProp: String,
    ageProp: Number,
})

const emit = defineEmits(["emitTest"]);

function changeName() {
    emit("emitTest", "자잔");
}

</script>

<template>
    <h1>HomeChild</h1>
    <div>count : {{ counter.count }}</div>
    <div>{{ nameProp }}</div>
    <div>{{ ageProp }}</div>
    <button @click="changeName(a)">부모에게 요청하기</button>
    <GrandChild :nameProp="nameProp" :ageProp="ageProp"></GrandChild>
</template>

<style scoped>

</style>