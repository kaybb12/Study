#pragma once
//����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//���
#define SSD_SIZE 400 // SSD ũ�� (4MB)
#define LBA_SIZE 4    // LBA ũ�� (4Byte)

//�Լ�
void readData(const int dataNum, const int isFullRead);
void writeData(char* data, const int dataNum);
void initFile();
