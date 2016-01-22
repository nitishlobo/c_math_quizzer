#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int qLeftTotal;
	int qLeftInRow[11][1]; //qLeft indicates the number of questions left.
	int qHeaderNum[11][1];
	int nums[11][11];
} TableStructure;