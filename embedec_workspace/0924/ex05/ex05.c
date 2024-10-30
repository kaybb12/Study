#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

	char vect[100] = "DBABCEQABC";
	char tar[4] = "ABC";
	char res[100] = "";


	char* pos;
	int len = strlen(tar);
	char* cur = vect;

	while((pos = strstr(cur, tar)) != NULL) {
		strncat(res, cur, pos - cur);

		cur = pos + len;
	}

	strcat(res, cur);

	printf("%s", res);

	return 0;
}
