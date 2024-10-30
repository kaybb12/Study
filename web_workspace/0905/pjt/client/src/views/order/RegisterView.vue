<script setup>
import { ref } from 'vue';
import { useCommonStore } from '@/stores/common';
import { api } from '@/utils/firebase_api';
import { useRouter, useRoute } from "vue-router";

const common = useCommonStore();
const router = useRouter();
const route = useRoute();

common.changeTitle("메뉴 목록");
const data = ref({});

const menus = ref([]);
const quantity = ref();
const name = ref("");
const request_detail = ref("");
const foundOrder = ref({});
const imgURL = ref("");


async function getMenus() {
    if (route.params.id) {
        common.changeTitle("메뉴 수정하기");
        const result = await api.orders.findOne(route.params.id);
        foundOrder.value = result;
        name.value = result.menu_id.name;
        quantity.value = result.quantity;
        request_detail.value = result.request_detail;
        imgURL.value = result.image_src;
        data.value = result;
        console.log(result);
    } else {
        common.changeTitle("메뉴 목록");
        const result = await api.menus.findAll();
        menus.value = result;
        console.log(result);
    }
}

function moveDetail(id) {
    router.push({
        name: "order-detail",
        params: { id: id },
    });
}

getMenus();


async function orderUpdate() {
  if (!quantity.value || !request_detail.value) {
    alert("수정사항을 작성해주세요.");
  }
  else {
    await api.orders.update(route.params.id, quantity.value, request_detail.value);
    alert("주문 수정 성공");
    router.push({
      name: "orders",
    });
  }
}

async function orderDelete() {
    const confirmResult = confirm("삭제하시겠습니까?");
    if (confirmResult) {
        await api.orders.delete(data.value);
        router.push({ name: "orders" });
    }
}

</script>

<template>
    <div v-if="route.params.id">
        <div class="form-wrapper">
            <div class="order-image"
                :style="`background-image: url(${imgURL})`"
            ></div>
            <h2 class="order-name">{{ name }}</h2>
            <div>
                <span>주문 수량: </span>
                <input type="text" v-model="quantity">
            </div>
        <div>
            <span>요청 사항: </span>
            <input type="text" v-model="request_detail">
        </div>
        <button @click="orderUpdate">주문 수정하기</button>
        <button @click="orderDelete">주문 삭제하기</button>

    </div>
    </div>
    <div v-else>
        <ul>
        <li 
            v-for="menu in menus" 
            :key="menu.id"
            @click="moveDetail(menu.id)"
            >
            <div class="menu-container">
                <div class="menu-image"
                    :style="`background-image: url(${menu.image_src})`"
                ></div>
                <div class="menu-info-wrapper">
                    <h2 class="menu-name">{{ menu.name }}</h2>
                    <p class="menu-description">{{ menu.description }}</p>
                </div>
            </div>
        </li>
        </ul>
        <RouterLink :to="{ name : 'orders' }">
            <button
                type="button" 
                class="order-button btn btn-outline-dark w-100"
            >
                주문내역 확인
            </button>
        </RouterLink>
    </div>

</template>

<style scoped>
.menu-container {
  display: flex;
  align-items: center;
  border-bottom: 3px solid black;
}

.menu-info-wrapper {
  margin: 0 auto;
  text-align: center;
}

.menu-name {
  font-size: 25px;
  font-weight: bold;
}

.menu-description {
  padding-top: 10px;
}

.menu-image {
  background-size: cover;
  background-position: center;
  width: 180px;
  height: 180px;
}
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

.order-name {
  font-size: 25px;
  font-weight: bold;
}

.order-image {
  background-size: cover;
  background-position: center;
  width: 180px;
  height: 180px;
}
</style>