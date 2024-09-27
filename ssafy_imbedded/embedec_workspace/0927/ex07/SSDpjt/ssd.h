#pragma once
//참조
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//상수
#define SSD_SIZE 400 // SSD 크기 (4MB)
#define LBA_SIZE 4    // LBA 크기 (4Byte)

//함수
void readData(const int dataNum, const int isFullRead);
void writeData(char* data, const int dataNum);
void initFile();
