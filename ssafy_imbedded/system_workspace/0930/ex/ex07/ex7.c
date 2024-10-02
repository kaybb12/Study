#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	
	int file = open("text.txt", O_RDONLY);
	if (file < 0)
			exit(1);
	char buf[100];
	ssize_t len = read(file, buf, sizeof(buf) - 1);

	buf[len] = '\0';
	
	close(file);

	char str[100][100];
	char *token = strtok(buf, "\n");
	int cnt = 1;
	while (token != NULL) {
			memcpy(str[cnt], token, sizeof(str[cnt]));
			//printf("%s\n", str[cnt]);
			cnt++;
			token = strtok(NULL, "\n");
	}
	//printf("%d", cnt);
	int num;
	printf("지울 라인번호\n");
	scanf("%d", &num);
	
	file = open("text.txt", O_WRONLY | O_TRUNC);
	if (file < 0)
			exit(1);

	for (int i = 1; i < cnt; ++i) {
		if (i == num)
			 continue;
		//printf("%s\n", str[i]);
		write(file, str[i], strlen(str[i]));
		write(file, "\n", 1);	
	}

	close(file);
	
	return 0;

}
