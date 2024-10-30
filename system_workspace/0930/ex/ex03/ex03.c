#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char buf[10] = {0};
	int fd = open("./num.txt", O_RDONLY, 0);
	if (fd < 0) {
		exit(1);
	}

	read(fd, buf, 10);

	int res = atoi(buf);

	printf("%d\n", res + 10);

	return 0;
}
