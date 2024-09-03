<script setup>

import { ref } from 'vue';

const addname = ref("");
const addprice = ref(0);

const menus = ref([
    {
        id: 1, name: "짜장면", price: 6000, isPossible: true
    },
    {
        id: 2, name: "짬뽕", price: 7000, isPossible: true
    },
    {
        id: 3, name: "탕수육", price: 18000, isPossible: false
    },
    {
        id: 4, name: "군만두", price: 5000, isPossible: true
    }
]);

function addMenus() {
    let addMenu =
    {
        id: 0, name: "", price: 0, isPossible: true
    }
    addMenu.id = menus.value.length + 1;
    addMenu.name = addname.value;
    addMenu.price = addprice.value;
    menus.value.push(addMenu);
    console.log(menus.value);

    addname.value = "";
    addprice.value = 0;
}



</script>

<template>
    <h1>북경반점</h1>
    <div v-for="menu in menus" :key="menu.id">
        <li v-if="menu.isPossible">
            {{ menu.name }} - {{ menu.price }}
        </li>
    </div>
    <br/>
    <div>
        <input type="text" v-model="addname">메뉴이름
        <input type="number" v-model="addprice">가격
        <br/>
        <button @click="addMenus">추가</button>
    </div>
</template>

<style scoped>

</style>