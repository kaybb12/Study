#include "testshell.h"
#define _CRT_SECURE_NO_WARNINGS

void help() {
	printf("Available commands:\n");
	printf("- write [num] [data] : Write the specified data to the SSD at the given index.\n");
	printf("- read [num]         : Read data from the SSD at the specified index.\n");
	printf("- fullwrite          : Write data to the entire SSD.\n");
	printf("- fullread           : Read all data from the SSD.\n");
	printf("- help               : Display this help message.\n");
	printf("- exit               : Exit the program.\n");
}

void fullwrite(char* data) {
	FILE* file = fopen("C:/Users/SSAFY/source/repos/ProjectSSD/nand.txt", "w");
	//파일 초기화
	for (int i = 0; i < SSD_SIZE / LBA_SIZE; i++) {
		fprintf(file, "%s\n", data);
	}

	fclose(file);
}

void fullread() {
	for (int i = 0; i < SSD_SIZE / LBA_SIZE; ++i) {
		readData(i, 1);
	}
}

void playCommand(char *command) {
	char* token;
	token = strtok(command, " ");
	char com[3][100];
	//parsing command
	int commandNum = 0;
	
	while (token != NULL) {
		memcpy(com[commandNum], token, sizeof(com[commandNum]));
		token = strtok(NULL, " ");
		commandNum++;
	}

	if (strcmp(com[0], "write") == 0) {
		int dataNum = atoi(com[1]);
		char* data;
		data = com[2];
		if (dataNum < 0 || dataNum > SSD_SIZE) {
			printf("invalid command\n");
			return;
		}

		if (strncmp(data, "0x", 2) != 0) {
			printf("invalid command\n");
			return;
		}

		int isUnvalid = 0;

		if (strlen(data) != 10) {
			printf("invalid command\n");
			return;
		}

		for (int i = 2; i < strlen(data); i++) {
			if (data[i] < '0' || data[i]>'F') {
				isUnvalid = 1;
				break;
			}
		}

		if (isUnvalid) {
			printf("invalid command\n");
			return;
		}

		writeData(data, dataNum);
	}

	else if (strcmp(com[0], "read") == 0) {
		int dataNum = atoi(com[1]);

		if (dataNum < 0 || dataNum > SSD_SIZE) {
			printf("invalid command\n");
			return;
		}

		if (commandNum!=2) {
			printf("invalid command\n");
			return;
		}

		readData(dataNum, 0);
	}

	else if (strcmp(com[0], "help") == 0) {
		if (commandNum != 1) {
			printf("invalid command\n");
			return;
		}

		help();
	}

	else if (strcmp(com[0], "fullwrite") == 0) {
		if (commandNum != 2) {
			printf("invalid command\n");
			return;
		}

		char* data;
		data = com[1];

		if (strlen(data) != 10) {
			printf("invalid command\n");
			return;
		}

		int isUnvalid = 0;
		for (int i = 2; i < strlen(data); i++) {
			if (data[i] < '0' || data[i]>'F') {
				isUnvalid = 1;
				break;
			}
		}

		if (isUnvalid) {
			printf("invalid command\n");
			return;
		}

		fullwrite(com[1]);
	}

	else if (strcmp(com[0], "fullread") == 0) {
		if (commandNum != 1) {
			printf("invalid command\n");
			return;
		}

		fullread();
	}

	else {
		printf("invalid command\n");
	}
}

int main() {
	printf("init shell\n");

	while (1) {
		char command[100] = "";

		printf(">> ");

		fgets(command, sizeof(command), stdin);
		command[strlen(command) - 1] = '\0';

		if (strcmp(command, "exit") == 0) {
			break;
		}

		playCommand(command);
	}

	printf("exit shell\n");

	return 0;
}