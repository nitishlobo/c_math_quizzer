#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int qLeftTotal; //Total questions left
	int qLeftInRow[11][1]; //Number of questions left in row
	int qHeaderNum[11][1]; //Contains the first part of the question to ask user
	int nums[11][11]; //Contains the second part of the question to ask user
} TableStructure;
