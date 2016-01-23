#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <time.h>

void InitialiseTable(TableStructure *table)
{
		int i, j;

		//Intialising the total no. of questions left in table.
		table->qLeftTotal = 121;
		for (j=0; j<11; j++) {
			table->qLeftInRow[j][0] = 11; 		//Initialising the number of questions left in each row.
			table->qHeaderNum[j][0] = j+2;		//Initialising the the first part of the question that will be asked to the user.
			for (i=0; i<11; i++) {
				table->nums[i][j] = j+2;				//Intialising the second part of the question to the user.
			}
		}
}

void Shuffle(TableStructure *table)
{
	int column, colsLeftToShuffle, i, temp;
	TableStructure tableCopy;
	tableCopy = *table; //Duplicating the table and it's contents to make a fair Shuffle possible.

	for (i=0; i<11; i++) {
		colsLeftToShuffle = 10 + 1; //Initialising as 10 columns left to Shuffle, but add 1 because column uses remainder algorithm.
		while (colsLeftToShuffle > 0) {
			column = rand() % colsLeftToShuffle; //Generating numbers between 0 and number of elements left to Shuffle.

			//Shuffle Step 1: Moving a randomly picked element into the first position of table.
			table->nums[i][11-colsLeftToShuffle] = tableCopy.nums[i][column];

			//Shuffle Step 2: Swapping the randomly picked number in the element with the number in the last element.
			temp = tableCopy.nums[i][column];
			tableCopy.nums[i][column] = tableCopy.nums[i][colsLeftToShuffle-1];
			tableCopy.nums[i][colsLeftToShuffle-1] = temp;
			colsLeftToShuffle--; //Decreasing number of elements not Shuffled by 1.
		}
	}
}

int RowPicker(TableStructure *table)
{
	int row = 0; //Initialising variables.
	int validRow = 0;

	while (validRow == 0) {
		row = rand() % 11; //Randomly picking a row between 0 and 10.
		if (table->qLeftInRow[row][0] > 0) {
			validRow = 1;
		}
	}
	return row;
}

int CalculatePoints(TableStructure *table, int row, int column, int correctAns, int enteredAns)
{
	int temp;
	//Swapping the query element with the last element in the big array.
	temp = table->nums[row][column];
	table->nums[row][column] = table->nums[row][(table->qLeftInRow[row][0])-1];
	table->nums[row][(table->qLeftInRow[row][0])-1] = temp;

	//Number of questions in that row and the total number of questions is decreased by 1.
	table->qLeftInRow[row][0] = table->qLeftInRow[row][0] - 1;
	table->qLeftTotal = table->qLeftTotal - 1;

	if (correctAns != enteredAns) {
		printf("\n\n!!!   Incorrect answer entered.   !!!\n!!!   The correct answer is %d.   !!!\n", correctAns);
		return 0;
	}
	return 1; //If entered answer is correct, then returning 1 point.
}

int main(void) {
	FILE *pFile;
	TableStructure divTable, mulTable, addTable, subTable; //Decalaring variables.
	int i, j, row, column, questionsLeft, points, totalPoints, correctAns, enteredAns;
	clock_t startingTime, finishTime;
	double timeSpent;

	//Setting the seed to be able to generate random numbers.
	srand((unsigned int) time(NULL));

	InitialiseTable(&divTable); //Initialising a table for each operation
	InitialiseTable(&mulTable);
	InitialiseTable(&addTable);
	InitialiseTable(&subTable);

	Shuffle(&divTable); //Sending each query array to be Shuffled.
	Shuffle(&mulTable);
	Shuffle(&addTable);
	Shuffle(&subTable);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\t\t   << Hello user. The Arithmetic Tester has been activated. >>\n");
	printf("\n\t<< A special thanks to Jesus Christ, my friend, for inspiring me in this project. >>\n");
	printf("\t   << Also, thank you to Dipesh Trikam, Manmeet Singh and Nirojan Jayananthan. >>\n");
	printf("\n\nStarting to record the time.\n");
	startingTime = clock();

	questionsLeft = 121*4; //Setting the total number of questions in the entire program.
	totalPoints = 0; //Setting the total number of points to 0.
	enteredAns = 0;
	while (questionsLeft > 0) { //Ask the user a arithmetic question.
		points = 0; //Setting the number of points to 0 by default in each iteration.
		i = rand() % 4; //i decides which type of question will be asked out of division, multiplication, addition & subtraction.
		if (i == 0) {
			if (divTable.qLeftTotal > 0) {
				row = RowPicker(&divTable); //Selecting a random row and column in the nums array to ask the user a question.
				column = rand() % divTable.qLeftInRow[row][0];

				correctAns = divTable.nums[row][column]; //Computing the correct answer to the division problem.

				//Displaying the division problem to the user and prompting the user to enter an answer.
				printf("\n%d / %d = ", (divTable.nums[row][column])*(divTable.qHeaderNum[row][0]), (divTable.qHeaderNum[row][0]));
				scanf("%d", &enteredAns);
				points = CalculatePoints(&divTable, row, column, correctAns, enteredAns); //Calculating points.
			}
		} else if (i == 1) {
			if (mulTable.qLeftTotal > 0) {
				row = RowPicker(&mulTable);
				column = rand() % mulTable.qLeftInRow[row][0];
				correctAns = (mulTable.qHeaderNum[row][0]) * (mulTable.nums[row][column]);
				printf("\n%d * %d = ", mulTable.qHeaderNum[row][0], mulTable.nums[row][column]);
				scanf("%d", &enteredAns);
				points = CalculatePoints(&mulTable, row, column, correctAns, enteredAns);
			}
		} else if (i == 2) {
			if (addTable.qLeftTotal > 0) {
				row = RowPicker(&addTable);
				column = rand() % addTable.qLeftInRow[row][0];

				//Computing the correct answer to the addition problem.
				correctAns = (addTable.qHeaderNum[row][0]) + (addTable.nums[row][column]);
				printf("\n%d + %d = ", addTable.qHeaderNum[row][0], addTable.nums[row][column]);
				scanf("%d", &enteredAns);
				points = CalculatePoints(&addTable, row, column, correctAns, enteredAns);
			}
		} else if (i == 3) {
			if (subTable.qLeftTotal > 0) {
				row = RowPicker(&subTable);
				column = rand() % subTable.qLeftInRow[row][0];

				//Computing the correct answer to the subtraction problem.
				correctAns = (subTable.qHeaderNum[row][0]) - (subTable.nums[row][column]);
				printf("\n%d - %d = ", subTable.qHeaderNum[row][0], subTable.nums[row][column]);
				scanf("%d", &enteredAns);
				points = CalculatePoints(&subTable, row, column, correctAns, enteredAns);
			}
		}
		totalPoints = totalPoints + points; //Calculating total # of points and decrementing no. of questions by 1.
		questionsLeft--;

		printf("\n     < Total number of Points: %d >", totalPoints); //Displaying message for user to keep track of how many questions are done.
		printf("\n     < %d questions done. >\n", 484 - questionsLeft);
		printf("     < %d questions remaining. >\n", questionsLeft);
	}
	//Capturing finish time and calculating time elapsed
	finishTime = clock();
	timeSpent = (((double)(finishTime - startingTime))/CLOCKS_PER_SEC)/60; //CLOCKS_PER_SEC constant is used from the <time.h> file
	printf("\n     < Time you took in minutes is: %.2f >", timeSpent);

	//Exporting time to previousTimes.txt file
	pFile = fopen("previousTimes.txt","a");
	if (pFile==NULL) {
		printf("Error opening file.");
	} else {
		fprintf(pFile, "%d, %.2f\n", totalPoints, timeSpent);
	}
	fclose(pFile);

	printf("\n\n<<===== End of program. Recorded the total points earned and time. =====>>\n");
	printf("<<===== Type any letter and hit enter to exit. =====>>\n");
	scanf("%d", &enteredAns);
}
