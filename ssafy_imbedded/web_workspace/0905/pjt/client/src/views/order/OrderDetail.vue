<script setup>
import { ref } from 'vue';
import { useCommonStore } from '@/stores/common';
import { api } from '@/utils/firebase_api';
import { useRouter, useRoute } from "vue-router";

const router = useRouter();
const route = useRoute();
const common = useCommonStore();
common.changeTitle("주문 목록");

const quantity = ref();
const name = ref("");
const request_detail = ref("");
const foundOrder = ref({});
const imgURL = ref("");
const orderid = ref("");
console.log(route)

async function getOrders() {
    common.changeTitle("주문 상세");
    const result = await api.orders.findOne(route.params.id);
    foundOrder.value = result;
    name.value = result.menu_id.name;
    quantity.value = result.quantity;
    request_detail.value = result.request_detail;
    imgURL.value = result.image_src;
    orderid.value = result.id;
    console.log(result.image_src);
}

function orderDetail(id) {
  router.push({
        name: "order-update",
        params: { id: id },
  });
}

function moveBack() {
  router.push({
    name: "orders",
  })
}

getOrders();

</script>

<template>
    <div class="form-wrapper">
        <div class="order-image"
            :style="`background-image: url(${imgURL})`"
        ></div>
            <h2 class="order-name">{{ name }}</h2>
            <div>
                <span>주문 수량: {{  quantity }}</span>
            </div>
        <div>
        <span>요청 사항: {{ request_detail }}</span>
        </div>
        <button @click="orderDetail(orderid)">주문 수정하기</button>
        <button @click="moveBack">뒤로</button>

    </div>
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