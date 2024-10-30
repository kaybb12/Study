<script setup>
import { ref } from "vue";
import dataLab from '@/utils/api';
import { useChartStore } from "@/stores/chart.js";

const chartStore = useChartStore();
const startDate = ref("");
const endDate = ref("");
const timeUnit = ref("month");
const keywordGroups = ref([]);
const userInputGroupName = ref("");
const userInputKeyword = ref("");
const tempGroupName = ref("");
const tempKeywords = ref([]);
const toApiData = ref({});
const ages = ref([]);

function tempGroupAdd() {
    tempGroupName.value = userInputGroupName.value;
}

function tempKeywordAdd() {
    if (userInputKeyword.value) {
        tempKeywords.value.push(userInputKeyword.value);
        userInputKeyword.value = "";
    }
}

function makeGroup() {
    if (tempGroupName.value && tempKeywords.value.length) {
        keywordGroups.value.push({
            groupName: tempGroupName.value,
            keywords: tempKeywords.value,
            ages: ages.value,
        });

        tempGroupName.value = "";
        tempKeywords.value = [];
        userInputGroupName.value = "";
    }
}

async function sendResultToApi() {
    toApiData.value = {
        startDate: startDate.value,
        endDate: endDate.value,
        timeUnit: timeUnit.value,
        keywordGroups: keywordGroups.value,
        ages: keywordGroups.value.ages,
    };
    console.log(toApiData.value);
    try {
        await dataLab.post(toApiData.value);
        chartStore.makeChart();
        alert("데이터가 성공적으로 전송되었습니다.");
    } catch (error) {
        console.error(error);
        alert("데이터 전송 중 오류가 발생했습니다.");
    }
}
</script>

<template>
    <div>시작일 <input type="date" v-model="startDate" /></div>
    <div>종료일 <input type="date" v-model="endDate" /></div>
    <select v-model="timeUnit">
        <option value="date">일간</option>
        <option value="week">주간</option>
        <option value="month">월간</option>
    </select>
    <div>
        그룹명: <input type="text" v-model="userInputGroupName" />
        <button v-on::click="tempGroupAdd">추가</button>
        {{ tempGroupName }}
    </div>
    <div>
        키워드: <input type="text" v-model="userInputKeyword" />
        <button v-on::click="tempKeywordAdd">추가</button>
        {{ tempKeywords }}
    </div>
    <div>
        <label>연령대 선택: </label>
        <select v-model="ages">
            <option value="1">0~12세</option>
            <option value="2">13~18세</option>
            <option value="3">19~24세</option>
            <option value="4">25~29세</option>
            <option value="5">30~34세</option>
            <option value="6">35~39세</option>
            <option value="7">40~44세</option>
            <option value="8">45~49세</option>
            <option value="9">50~54세</option>
            <option value="10">55~59세</option>
            <option value="11">60세 이상</option>
        </select>
    </div>
    <div>
        <button v-on::click="makeGroup">그룹 확정</button>
    </div>
    <p>사용자 입력 그룹별 키워드</p>
    <ul v-if="keywordGroups.length">
        <li v-for="(keywordGroup, index) in keywordGroups" :key="index">
            <p>그룹 이름: {{ keywordGroup.groupName }}</p>
            <p>그룹 키워드: {{ keywordGroup.keywords.join(', ') }}</p>
            <p>그룹 나이: {{ keywordGroup.ages }}</p>
        </li>
    </ul>
    <input type="submit" v-on::click="sendResultToApi" />
</template>
