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
const imageURL = ref("");
const quantity = ref();
const request_detail = ref("없음");
const menu_id = ref("");

async function getMenu() {
  const result = await api.menus.findOne(route.params.id);
  foundMenu.value = result;
  name.value = result.name;
  description.value = result.description;
  imageURL.value = result.image_src;
  menu_id.value = result.id;  
  //console.log(menu_id);
}

getMenu();

async function orderCreate() {
  //console.log("메뉴 추가");
  if (!quantity.value || !request_detail.value) {
    alert("빈 값이 있습니다. 내용을 전부 작성해주세요.");
  }
  else {
    await api.orders.create(quantity.value, request_detail.value, menu_id.value);
    alert("주문 추가 성공");
    router.push({ name: "order-register" });
  }
}

common.changeTitle("주문 추가하기");
</script>
  
<template>
    <div class="form-wrapper">
      <div class="order-image"
                :style="`background-image: url(${imageURL})`"
      ></div>
      <div>
        <span>{{ name }}</span>
      </div>
      <div>
        <span>메뉴 설명: {{ description }}</span>
      </div>
      <div>
        <span>주문수량: </span>
        <input type="text" v-model="quantity">
      </div>
      <div>
        <span>요청사항: </span>
        <input type="text" v-model="request_detail">
      </div>
        <button @click="orderCreate">메뉴 추가하기</button>
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

.order-image {
  background-size: cover;
  background-position: center;
  width: 180px;
  height: 180px;
}
</style>
