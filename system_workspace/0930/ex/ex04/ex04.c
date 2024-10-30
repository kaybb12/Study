#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
		
		int fd = open("./cal.txt", O_RDONLY, 0);
		if (fd < 0)
				exit(1);
		char buf[10];
		read(fd, buf, 10);
		
		close(fd);

		int rd_res = atoi(buf);
		printf("%d\n", rd_res);	
		
		int wr_res = rd_res * 2;
		sprintf(buf, "%d", wr_res);

		fd = open("./cal.txt", O_WRONLY, 0);
		if (fd < 0)
				exit(1);

		write(fd, buf , strlen(buf));

		close(fd);	

		return 0;
}

