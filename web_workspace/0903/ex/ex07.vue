<script setup>

import { ref } from 'vue';

const todos = ref([])

const todo = ref("");

function addTodo() {
    const temp = { id: 0, name: ""};
    temp.id = todos.value.length + 1;
    temp.name = todo.value;
    todos.value.push(temp);
    todo.value = "";
}

function deleteTodo(id) {
    //console.log(todos.value);
    //console.log(id);
    const temp = todos.value.filter(item => item.id !== id);
    //console.log(temp);
    todos.value = temp;
}

</script>

<template>
    <input type="text" v-model="todo">
    <button @click="addTodo">할 일 추가</button>
    <br/>
    <div v-if="todos.length === 0">할 일이 없습니다</div>
    <div v-else>
        <li v-for="t in todos" :key="t.id">{{ t.name }}
            <button @click="deleteTodo(t.id)">X</button>
        </li>
    </div>
</template>

<style scoped>

</style>