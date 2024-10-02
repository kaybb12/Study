#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	int fd = open("text.txt", O_RDONLY, 0);
	if (fd < 0)
			exit(1);

	char buf[6];
	ssize_t i = read(fd, buf, 5);
	printf("%s\n", buf);

	memset(buf, 0, strlen(buf));

	lseek(fd, -6, SEEK_END);
	read(fd, buf, 5);
	printf("%s\n", buf);
	memset(buf, 0, strlen(buf));
	lseek(fd, 0, SEEK_SET);
	i = read(fd, buf, 3);
	while(i > 0) {	
		if (strcmp(buf, "GHI") == 0) {
			lseek(fd, 5, SEEK_CUR);
			//printf("1");
			memset(buf, 0, strlen(buf));
			read(fd, buf, 3);
			printf("%s\n", buf);
		}
		memset(buf, 0, strlen(buf));
		i = read(fd, buf, 3);
		//printf("%s\n", buf);
	}

	return 0;
}
