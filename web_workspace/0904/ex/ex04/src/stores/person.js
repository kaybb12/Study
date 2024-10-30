// /stores/person.js
import { defineStore } from 'pinia';

export const usePersonStore = defineStore('person', {
  state: () => ({
    name: 'david',
    age: 10
  }),
  actions: {
    decreaseAge() {
      this.age -= 1;
    },
    changeName(newName) {
      this.name = newName;
    },
    resetAge() {
      this.age = 1;
    }
  }
});
