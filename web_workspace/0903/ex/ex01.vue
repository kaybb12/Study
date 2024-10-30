<script setup>

import { ref } from 'vue';

const id = ref("id");
const pw = ref("pw");
const toggle = ref("false");
const picked = ref("red");
const selected = ref("");

</script>

<template>
    <div>
        <input type="text" v-model="id">{{ id }}
    </div>
    <div>
        <input type="password" v-model="pw">{{ pw }}
    </div>
    <div>
        <input type="checkbox" v-model="toggle">{{ toggle }}
    </div>
    <br/>
    <div>
        <input type="radio" id="red" value="red" v-model="picked">
        <label for="red">빨강</label>
        <input type="radio" id="blue" value="blue" v-model="picked">
        <label for="blue">파랑</label>
        <div>{{ picked }}</div>
    </div>
    <br/>
    <div>
        직업<select v-model="selected">
            <option disabled value="">직업선택</option>
            <option value="student">student</option>
            <option value="home-protector">home-protector</option>
        </select>
        <div>
            {{selected}}
        </div>
    </div>
</template>

<style scoped>

</style>