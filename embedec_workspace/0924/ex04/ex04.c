#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int is_number(const char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (!isdigit(str[i]))
			return 0;
	}

	return 1;
}

int main(){

	const char* vect = "DATA|32ALL|0|200|100|ABABC|200";
	char buffer[100];
	strcpy(buffer, vect);

	char* token;
	int size = sizeof(vect) / sizeof(vect[0]);
	int sum = 0;
	char other[100] = "";

	token = strtok(buffer, "|");
	while (token != NULL) {
		if (is_number(token)) {
			sum += atoi(token);
		}
		else {
			if (strlen(other) > 0) {
				strcat(other, "|");
			}
			strcat(other, token);
		}
		token = strtok(NULL, "|");
	}

	printf("sum : %d\n", sum);
	printf("other : %s", other);

	return 0;
}
