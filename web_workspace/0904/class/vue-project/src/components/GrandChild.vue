<script setup>

const props = defineProps({
    nameProp: String,
    ageProp: Number,
})

</script>

<template>
    <h1>GrandChild</h1>
    <div>{{ nameProp }}</div>
    <div>{{ ageProp }}</div>
</template>

<style scoped>

</style>