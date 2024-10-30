<script setup>

import { ref } from "vue"
//import aa from "vue" 
// aa.ref

//반응형 변수를 생성할때 사용한다. 
//반응형 변수가 변하면 화면도 변하다. 
const message = ref("Hello wolrd");

// react는 데이터가 바뀌면 HTML이 바뀐다
// react에서는 이벤트함수로 데이터를 변경시킨다. 
// vue에서는 HTML이 바뀌어도 데이터가 바뀌는 v-model이 존재한다. 

const text = ref("?")
function changeText(){
  console.log("aa");
  // 값을 바꾸는법
  // ref로가져온value를 바꾸기 
  text.value = "짜잔";
}

</script>

<template>
  <h1>
  <!-- {{ }} 변수를 나타내는 방식중 하나 -->
    message : {{message}}    
    <!-- vue의 특징 양방향바인딩 -->
    <input type="text" v-model="message">
  </h1>
  <div>
    {{ text }}
  </div>
  <!-- vue에서 이벤트 할당 v-on 혹은 @ v-on:click="함수" @click="changeText" -->
  <button v-on:click="changeText">클릭</button>
</template>

<style scoped>

</style>
