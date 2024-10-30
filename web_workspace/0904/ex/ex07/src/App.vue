<script setup>
import { ref, computed } from 'vue'

const todos = ref([])
const newTodo = ref('')
const hideCompleted = ref(false)

const addTodo = () => {
  if (newTodo.value.trim()) {
    todos.value.push({
      id: Date.now(),
      text: newTodo.value.trim(),
      completed: false
    })
    newTodo.value = ''
  }
}

const deleteTodo = (id) => {
  todos.value = todos.value.filter(todo => todo.id !== id)
}

const filteredTodos = computed(() => {
  return hideCompleted.value
    ? todos.value.filter(todo => !todo.completed)
    : todos.value
})
</script>

<template>
  <div class="container mt-5">
    <h1 class="mb-4">Todo List</h1>
    <div class="input-group mb-3">
      <input v-model="newTodo" @keyup.enter="addTodo" type="text" class="form-control" placeholder="할 일을 입력하세요" aria-label="할 일 입력">
      <button @click="addTodo" class="btn btn-primary" type="button">추가</button>
    </div>
    <ul class="list-group mb-3">
      <li v-for="todo in filteredTodos" :key="todo.id" class="list-group-item d-flex justify-content-between align-items-center">
        <div>
          <input class="form-check-input me-2" type="checkbox" v-model="todo.completed" :id="'todo-' + todo.id">
          <label class="form-check-label" :for="'todo-' + todo.id" :class="{ 'text-decoration-line-through': todo.completed }">
            {{ todo.text }}
          </label>
        </div>
        <button @click="deleteTodo(todo.id)" class="btn btn-danger btn-sm">삭제</button>
      </li>
    </ul>
    <div class="form-check mb-3">
      <input class="form-check-input" type="checkbox" v-model="hideCompleted" id="hideCompleted">
      <label class="form-check-label" for="hideCompleted">
        완료된 항목 숨기기
      </label>
    </div>
    <div v-if="todos.length === 0" class="alert alert-info">
      모든 일을 완료했습니다.
    </div>
  </div>
</template>

