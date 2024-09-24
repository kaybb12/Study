#include<stdio.h>
#include<string.h>

unsigned char binaryStringToByte(const char *binStr) {
    unsigned char result = 0;
    while (*binStr) {
        result = (result << 1) | (*binStr++ - '0');
    }

    return result;
}

void insertStr(char* result, char* vect, char* str, int index) {
    strncpy(result, vect, index);
    result[index] = '\0'; // strncpy는 널 문자를 추가하지 않으므로 직접 넣어줌

    strcat(result, str);

    strcat(result, vect + index);
}

int main(){

	char vect[10] = "ZXXVQ";
	char result[10];

	insertStr(result, vect, "ABC", 2);

	printf("%s", result);

	return 0;
}
