<script setup>
import { RouterLink, RouterView } from 'vue-router'

</script>

<template>
  <header>
      <nav>
        <RouterLink :to="{name : 'home' }">Home</RouterLink>
        <span> | </span>
        <RouterLink :to="{name : 'about' }">About</RouterLink>

      </nav>
  </header>
  <RouterView />
</template>
