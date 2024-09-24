#include<stdio.h>
#include<string.h>

unsigned char binaryStringToByte(const char *binStr) {
    unsigned char result = 0;
    while (*binStr) {
        result = (result << 1) | (*binStr++ - '0');
    }
    return result;
}

int main(){


	char A_str[5] = "0x00";
	char B_str[9] = "00000000";
	unsigned int temp = 0;
	unsigned char A, B;

	scanf("%s", A_str);
	scanf("%s", B_str);

	sscanf(A_str, "%x", &temp);
	A = (unsigned char)temp;
	B = binaryStringToByte(B_str);

    unsigned char res1 = ~(A & B) << 4;
    printf("%d\n", res1);

    unsigned char res2 = (A ^ 0xCD) & (B >> 3);
    printf("%d\n", res2);

	return 0;
}
