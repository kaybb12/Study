#include "ssd.h"

void initFile() {
	FILE* file = fopen("C:/Users/SSAFY/source/repos/ProjectSSD/nand.txt", "w");
	//파일 초기화
	for (int i = 0; i < SSD_SIZE / LBA_SIZE; i++) {
		unsigned int value = 0;
		//memcpy(&value, &ssd.data[i * LBA_SIZE], sizeof(value));
		fprintf(file, "0x%08X\n", value);
	}

	fclose(file);
}

//nand 저장하기
void writeData(char* data, const int dataNum) {
	FILE* file = fopen("C:/Users/SSAFY/source/repos/ProjectSSD/nand.txt", "r+");

	fseek(file, dataNum * 12, SEEK_SET);

	//printf("%s", data);

	fprintf(file, "%-10s\n", data);
	
	fclose(file);
}

void readData(const int dataNum, const int isFullRead) {
	FILE* fileNand = fopen("C:/Users/SSAFY/source/repos/ProjectSSD/nand.txt", "r");
	FILE* fileResult = fopen("C:/Users/SSAFY/source/repos/ProjectSSD/result.txt", "w");


	char buffer[100];
	fseek(fileNand, dataNum * 12, SEEK_SET);
	fgets(buffer, 100, fileNand);
	if (isFullRead) {
		printf("%s\n", buffer);
	}

	fprintf(fileResult, "%-10s\n", buffer);

	fclose(fileNand);
	fclose(fileResult);

}

//int main() {
//	initFile();
//
//	//writeToNand("0x12345678", 3);
//	//sendToResult(3);
//
//	return 0;
//}