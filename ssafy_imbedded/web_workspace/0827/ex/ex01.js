let a = 2;
let b = 4;

const calc = {
    add: (a, b) => {
        const res = a + b;
        console.log(`덧셈 결과 : ${res}`);
        return res;
    },
    sub: (a, b) => {
        const res = a - b;
        console.log(`뺄셈 결과 : ${res}`);
        return res;
    },
    mul: (a, b) => {
        const res = a * b;
        console.log(`곱셈 결과 : ${res}`);
        return res;
    },
    div: (a, b) => {
        if (b !== 0) {
            const res = a / b;
            console.log(`나눗셈 결과 : ${res}`);
            return res;
        } else {
            console.log("0으로 나눌 수 없습니다.");
            return null;
        }
    }
};

console.log(`주어진 수 : ${a}, ${b}`);
calc.add(a, b);
calc.sub(a, b);
calc.mul(a, b);
calc.div(a, b);