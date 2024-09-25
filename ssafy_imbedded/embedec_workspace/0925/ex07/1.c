#include <stdio.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1);

union DATA {
	uint16_t buf[7];

	struct {
		uint16_t weight : 16;
		uint16_t pass : 16;
		uint16_t salary : 16;
		uint8_t food[4];
		uint8_t drink[4];
	};
};

int main(){

	FILE *fp = fopen("binary", "rb");
	union DATA data; //16 + 96 = 112 bit / 8 = 14 Byte

	fread(data.buf, 1, sizeof(data.buf), fp);
	fclose(fp);

	printf("weight : %dKG\n", data.weight);
	printf("PASS : %d\n", data.pass);
	printf("SALARY : %d$\n", data.salary);
    printf("FOOD : %c%c%c%c\n", data.food[3], data.food[2], data.food[1], data.food[0]);

    printf("DRINK : %c%c%c%c\n", data.drink[3], data.drink[2], data.drink[1], data.drink[0]);

	return 0;
}
