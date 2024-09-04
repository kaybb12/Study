import { defineStore } from 'pinia'

export const useChickenStore = defineStore('chicken', {
  state: () => ({
    title: "치킨은 맛있다",
    salt: 30
  }),
  actions: {
    updateSalt(newSalt) {
      this.salt = newSalt
    }
  }
})