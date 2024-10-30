#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd = open("./ex5.txt", O_RDONLY, 0);
	if (fd < 0)
			exit(1);

	char buf[10];
	ssize_t i = read(fd, buf, 10);
	
	while(i > 0) {
		printf("==================\n");
		printf("%s\n", buf);
		printf("==================\n");
		printf("%ld\n", i);
		memset(buf, '\0', strlen(buf));
		i = read(fd, buf, 10);
	}
	
	close(fd);

	return 0;
}

