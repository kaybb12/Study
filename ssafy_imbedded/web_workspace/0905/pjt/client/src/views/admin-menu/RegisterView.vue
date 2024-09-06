<script setup>
import { ref } from "vue";
import { useCommonStore } from "@/stores/common";
import { api } from "@/utils/firebase_api";
import { useRouter, useRoute } from "vue-router";

const common = useCommonStore();
const router = useRouter();
const route = useRoute();

const name = ref("");
const description = ref("");
const file = ref(null);
const foundMenu = ref({});

async function getMenu() {
  const result = await api.menus.findOne(route.params.id);
  foundMenu.value = result;
  name.value = result.name;
  description.value = result.description;

  if (route.params.id) {
    common.changeTitle("메뉴 수정하기");
  } else {
    common.changeTitle("메뉴 추가하기");
  }
}

getMenu();

async function menuUpdate() {
  if (!name.value || !description.value) {
    alert("수정사항을 작성해주세요.");
  }
  else {
    await api.menus.update(route.params.id, name.value, description.value);
    alert("메뉴 수정 성공");
    router.push({
      name: "menus-detail",
      params: { id: route.params.id },
    });
  }
}

async function updateImage() {
  if (!file.value) {
    alert("이미지를 업데이트해주세요.");
  }
  else {
    await api.menus.updateImage(foundMenu.value, file.value);
    alert("이미지 수정 성공");
    router.push({
    name: "menus-detail",
    params: { id: route.params.id },
    });
  }
}

function fileChange(e) {
  //console.log(e.target.files);
  file.value = e.target.files[0];
}

async function menuCreate() {
  //console.log("메뉴 추가");
  if (!name.value || !description.value || !file.value) {
    alert("빈 값이 있습니다. 내용을 전부 작성해주세요.");
  }
  else {
    await api.menus.create(name.value, description.value, file.value);
    alert("메뉴 추가 성공");
    router.push({ name: "menus" });
  }
}

function setURL(file) {
    const imageURL = URL.createObjectURL(file);
    return imageURL;
}

common.changeTitle("메뉴 추가하기");
</script>

<template>
    <div class="form-wrapper">
      <div>
        <span>메뉴 이름: </span>
        <input type="text" v-model="name">
      </div>
      <div>
        <span>메뉴 설명: </span>
        <input type="text" v-model="description">
      </div>
      <input type="file" @change="fileChange">
      <div v-if="route.params.id">
        <button @click="menuUpdate">메뉴 수정하기</button>
        <button @click="updateImage">이미지 수정하기</button>
      </div>
      <div v-else>
        <button @click="menuCreate">메뉴 추가하기</button>
      </div>
    </div>
    <div class="image-wrapper" v-if="file">
        <img class="selected-image" :src="setURL(file)">
    </div>
</template>
  

<style scoped>
.form-wrapper {
  display: flex;
  flex-direction: column;
  margin-top: 50px;
  border: 1px solid black;
  padding: 20px;
}

.form-wrapper > * {
  margin: 10px;
}

.image-wrapper {
  margin-top: 30px;
  border: 1px solid black;
}

.selected-image {
  width: 100%;
}
</style>
