<script setup>
import { ref } from 'vue';
import { useCommonStore } from '@/stores/common';
import { api } from '@/utils/firebase_api';
import { useRouter, useRoute } from "vue-router";

const router = useRouter();
const route = useRoute();
const common = useCommonStore();
common.changeTitle("주문 목록");


const menus = ref([]);
const orders = ref([]);
const quantity = ref();
const name = ref("");
const request_detail = ref("");
const foundOrder = ref({});
const imgURL = ref("");
const orderid = ref("");

async function getOrders() {
  common.changeTitle("주문 목록");
  const result = await api.orders.findAll();
  //console.log(result)
  orders.value = result;
  //console.log(result);
}

function moveDetail(id) {
    router.push({
        name: "order-getdetail",
        params: { id: id },
    });
}

function orderFinish() {
  router.push({
    name: "order-pay"
  });
}

function orderMore() {
  router.push({
    name: "order-register"
  }); 
}

getOrders();

</script>

<template>
    <ul>
      <li 
            v-for="order in orders" 
            :key="order.id"
            @click="moveDetail(order.id)"
            >
        <div class="order-container">
            <div class="order-image"
                :style="`background-image: url(${order.image_src})`"
            ></div>
            <div class="order-info-wrapper">
                <h2 class="order-name">{{ order.menu_id.name }}</h2>
                <p class="order-quantity">주문 수량: {{ order.quantity }}</p>
                <p class="order-request_detail">요청 사항: {{ order.request_detail }}</p>
            </div>
        </div>
      </li>
    </ul>
    <button @click="orderMore" class="more-button btn btn-outline-dark w-100">주문 추가하기</button>
    <button @click="orderFinish" class="finish-button btn btn-outline-dark w-100">주문 완료하기</button>
</template>

<style scoped>
.order-container {
  display: flex;
  align-items: center;
  border-bottom: 3px solid black;
}

.order-info-wrapper {
  margin: 0 auto;
  text-align: center;
}

.order-name {
  font-size: 25px;
  font-weight: bold;
}

.order-quantity {
  padding-top: 10px;
}
.order-request_detail {
  padding-top: 10px;
}

.order-image {
  background-size: cover;
  background-position: center;
  width: 180px;
  height: 180px;
}
</style>