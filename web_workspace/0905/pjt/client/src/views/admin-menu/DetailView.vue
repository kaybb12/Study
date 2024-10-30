<script setup>
import { ref } from "vue";
import { useRouter, useRoute } from "vue-router";
import { api } from "@/utils/firebase_api";

const router = useRouter();
const route = useRoute();

const data = ref({});

async function getMenu() {
  const result = await api.menus.findOne(route.params.id);
  //console.log(result);
  data.value = result;
}

function moveRegister() {
  router.push({
    name: "menus-update",
    params: { id: route.params.id },
  });
}

async function deleteMenu() {
  //console.log("삭제 구현");
  const confirmResult = confirm("삭제하시겠습니까?");
  if (confirmResult) {
    await api.menus.delete(data.value);
    router.push({ name: "menus" });
  }
}

function moveList() {
  router.push({ name: "menus" });
}

getMenu();
</script>

<template>
    <div class="card mb-2" v-if="data">
      <img :src="data.image_src" class="card-img-top" alt="menu" />
      <div class="card-body">
        <h5 class="card-title">{{ data.name }}</h5>
        <p class="card-text">{{ data.description }}</p>
        <button type="button" class="btn btn-primary" @click="moveRegister">
          수정하기
        </button>
        <button type="button" class="btn btn-danger" @click="deleteMenu">
          삭제
        </button>
        <button type="button" class="btn btn-outline-primary" @click="moveList">
          목록
        </button>
      </div>
    </div>
</template>
  
