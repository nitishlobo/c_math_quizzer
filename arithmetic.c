#define _CRT_SECURE_NO_WARNINGS
//Ctrl K + Ctrl F for correct indentation.
#include "NLFile.h"   

//Prototype declarations.
void Shuffle(TableStructure *theTable);
int askDivQuestion(TableStructure *divTable, int askRow, int askCol);
int askMulQuestion(TableStructure *mulTable, int askRow, int askCol);
int askAddQuestion(TableStructure *addTable, int askRow, int askCol);
int askSubQuestion(TableStructure *subTable, int askRow, int askCol);
int markTheAnswer(int correctAns, int enteredAns);
int RowPicker(TableStructure *theTable);
int ColPicker(TableStructure *theTable, int askRow);

int main(void) {
	//Decalaring variables.
	TableStructure divTable, mulTable, addTable, subTable;
	int i, j, askRow, askCol, invalidTable, totalNumOfQuestionsLeft, points, totalPoints;

	//Displaying message to user.
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\t\t   <<--- Hello user. The Arithmetic Tester has been activated. --->>\n");
	printf("\n\t<<--- A special thanks to Jesus Christ, my friend for inspiring me in this project. --->>\n");
	printf("\t   <<--- Also, thank you to Dipesh Trikam, Manmeet Singh and Nirojan Jayananthan. --->>\n");

	//Setting the seed to be able to generate random numbers.
	srand((unsigned int) time(NULL));

	//Intialising the total no. of questions left in each table.
	divTable.qLeftTotal = 121;
	mulTable.qLeftTotal = 121;
	addTable.qLeftTotal = 121;
	subTable.qLeftTotal = 121;

	//Setting the total number of questions in the entire program.
	totalNumOfQuestionsLeft = 121*4;

	//Initialising the number of questions left in each row of each array structure.
	for (i=0; i<11; i++) {
		divTable.qLeftInRow[i][0] = 11; //qLeftInRow is the number of questions left.
		mulTable.qLeftInRow[i][0] = 11;
		addTable.qLeftInRow[i][0] = 11;
		subTable.qLeftInRow[i][0] = 11;
	}

	//Initialising the header number for each question.
	for (i=0; i<11; i++) {
		divTable.qHeaderNum[i][0] = i+2;
		mulTable.qHeaderNum[i][0] = i+2;
		addTable.qHeaderNum[i][0] = i+2;
		subTable.qHeaderNum[i][0] = i+2;
	}

	//Intialising the query number for each table.
	for (j=0; j<11; j++) {
		for (i=0; i<11; i++) {
			divTable.nums[i][j] = j+2;
			mulTable.nums[i][j] = j+2;
			addTable.nums[i][j] = j+2;
			subTable.nums[i][j] = j+2;
		}
	}

/*	//Printing array as a check.
	printf("qLeftTotal:  %d\n\n", divTable.qLeftTotal);

	printf("qLeftInRow:\n");
	for (i=0; i<11; i++) {
	printf("%d\n", divTable.qLeftInRow[i][0]);
	}

	printf("\n\nHeader's:\n");
	for (i=0; i<11; i++) {
	printf("%d\n", divTable.qHeaderNum[i][0]);
	}

	printf("\nOriginal Nums:\n");
	for (j=0; j<11; j++) {
	for (i=0; i<11; i++) {
	printf("%d ", divTable.nums[j][i]);
	}
	printf("\n");
	}

	printf("\n\n-----THE END----");
*/
	//Sending each query array to be Shuffled.
	Shuffle(&divTable);
	Shuffle(&mulTable);
	Shuffle(&addTable);
	Shuffle(&subTable);

	printf("\nShuffled Nums:\n");
	for (j=0; j<11; j++) {
	for (i=0; i<11; i++) {
	printf("%d ", divTable.nums[j][i]);
	}
	printf("\n");
	}

	//Setting the total number of points to 0.
	totalPoints = 0;

	//All the initialising has been finished. The rest of the code that follows after this line is to ask the user a arithmetic question.

	while (totalNumOfQuestionsLeft > 0) {
		//Setting the table as invalid selection for each iteration.
		//Setting the number of points to 0 by default in each iteration.
		invalidTable = 1;
		points = 0;
		while (invalidTable == 1) {
			//i variable indicates which type of arithmetic question will be asked (i.e.: division, multiplication, addition, subtraction).
			i = rand() % 4;
			if (i == 0) {
				if (divTable.qLeftTotal > 0) {
					//Setting the table selection to be valid.
					invalidTable = 0;

					//Selecting a random row and column in the nums array to ask the user a question.
					askRow = RowPicker(&divTable);
					askCol = ColPicker(&divTable, askRow);

					//Asking division question.
					points = askDivQuestion(&divTable, askRow, askCol);
				}
			} else if (i == 1) {
				if (mulTable.qLeftTotal > 0) {
					//Setting the table selection to be valid.
					invalidTable = 0;

					//Selecting a random row and column in the nums array to ask the user a question.
					askRow = RowPicker(&mulTable);
					askCol = ColPicker(&mulTable, askRow);

					//Asking division question.
					askMulQuestion(&mulTable, askRow, askCol);
				}
			} else if (i == 2) {
				if (addTable.qLeftTotal > 0) {
					//Setting the table selection to be valid.
					invalidTable = 0;

					//Selecting a random row and column in the nums array to ask the user a question.
					askRow = RowPicker(&addTable);
					askCol = ColPicker(&addTable, askRow);

					//Asking division question.
					askAddQuestion(&addTable, askRow, askCol);
				}
			} else if (i == 3) {
				if (subTable.qLeftTotal > 0) {
					//Setting the table selection to be valid.
					invalidTable = 0;

					//Selecting a random row and column in the nums array to ask the user a question.
					askRow = RowPicker(&subTable);
					askCol = ColPicker(&subTable, askRow);

					//Asking division question.
					askSubQuestion(&subTable, askRow, askCol);
				}
			}

		//Decrementing no. of questions by 1.
		totalNumOfQuestionsLeft--;

		//Displaying message for user to keep track of how many questions are done.
		printf("\n     <<--- %d questions done. --->>\n", 484 - totalNumOfQuestionsLeft);
		
		//Printing array as a check.
		printf("TESTLER__qLeftTotal:  %d\n\n", divTable.qLeftTotal);

		printf("TESTLER__qLeftInRow:\n");
		for (i=0; i<11; i++) {
		printf("%d\n", divTable.qLeftInRow[i][0]);
		}

		printf("\n\nTESTLER__Header's:\n");
		for (i=0; i<11; i++) {
		printf("%d\n", divTable.qHeaderNum[i][0]);
		}

		printf("\nTESTLER__Nums:\n");
		for (j=0; j<11; j++) {
		for (i=0; i<11; i++) {
		printf("%d ", divTable.nums[j][i]);
		}
		printf("\n");
		}
	}
}

void Shuffle(TableStructure *theTable) 
{
	int pickColNum, numLeftToShuffle, i, temp;
	TableStructure copyOfTheTable;


	//Duplicating the table and it's contents to make a fair Shuffle possible.
	copyOfTheTable = *theTable;

	for (i=0; i<11; i++) {
		//Initialising the variable as 10 columns left to Shuffle, but we add 1 because pickColNum uses remainder algorithm.
		numLeftToShuffle = 10 + 1;

		while (numLeftToShuffle > 0) {
			//Generating numbers between 0 and number of elements left to Shuffle.
			pickColNum = rand() % numLeftToShuffle;

			//Using Fisher Yates Method to Shuffle. All Shuffle step descriptions to follow are regarding first iteration only.

			//Shuffle Step 1: 
			//Moving a randomly picked element into the first position of theTable.
			theTable->nums[i][11-numLeftToShuffle] = copyOfTheTable.nums[i][pickColNum];

			//Shuffle Step 2:
			//Swapping the randomly picked number in the element with the number in the last element.
			temp = copyOfTheTable.nums[i][pickColNum];
			copyOfTheTable.nums[i][pickColNum] = copyOfTheTable.nums[i][numLeftToShuffle-1];
			copyOfTheTable.nums[i][numLeftToShuffle-1] = temp;

			//Decreasing number of elements not Shuffled by 1.	
			numLeftToShuffle--;
		}
	}
}

int askDivQuestion (TableStructure *divTable, int askRow, int askCol) 
{
	//Declaring variables.
	int temp, correctAns, enteredAns;

	//Computing the correct answer to the division problem.
	correctAns = divTable->nums[askRow][askCol];

	//Displaying the division problem to the user and prompting the user to enter an answer.
	printf("\n%d / %d =", (divTable->nums[askRow][askCol])*(divTable->qHeaderNum[askRow][0]), (divTable->qHeaderNum[askRow][0]));
	scanf("%d", &enteredAns);

	//Swapping the query element with the last element in the big array.
	temp = divTable->nums[askRow][askCol];
	divTable->nums[askRow][askCol] = divTable->nums[askRow][(divTable->qLeftInRow[askRow][0])-1];
	divTable->nums[askRow][(divTable->qLeftInRow[askRow][0])-1] = temp;

	//Number of questions in that row and the total number of questions is decreased by 1.
	divTable->qLeftInRow[askRow][0] = divTable->qLeftInRow[askRow][0] - 1;
	divTable->qLeftTotal = divTable->qLeftTotal - 1;

	//Marking the answer and returning the number of points.
	points = markTheAnswer(correctAns, enteredAns);
	return points;
}

int askMulQuestion(TableStructure *mulTable, int askRow, int askCol) 
{
	//Declaring variables.
	int temp, correctAns, enteredAns;

	//Computing the correct answer to the multiplication problem.
	correctAns = (mulTable->qHeaderNum[askRow][0]) * (mulTable->nums[askRow][askCol]);

	//Displaying the multiplication problem to the user and prompting the user to enter an answer.
	printf("\n%d * %d =", mulTable->qHeaderNum[askRow][0], mulTable->nums[askRow][askCol]);
	scanf("%d", &enteredAns);

	//Swapping the query element with the last element in the big array.
	temp = mulTable->nums[askRow][askCol];
	mulTable->nums[askRow][askCol] = mulTable->nums[askRow][(mulTable->qLeftInRow[askRow][0])-1];
	mulTable->nums[askRow][(mulTable->qLeftInRow[askRow][0])-1] = temp;

	//Number of questions in that row and the total number of questions is decreased by 1.
	mulTable->qLeftInRow[askRow][0] = mulTable->qLeftInRow[askRow][0] - 1;
	mulTable->qLeftTotal = mulTable->qLeftTotal - 1;

	//Marking the answer and returning the number of points.
	points = markTheAnswer(correctAns, enteredAns);
	return points;
}

int askAddQuestion(TableStructure *addTable, int askRow, int askCol) 
{
	//Declaring variables.
	int temp, correctAns, enteredAns;

	//Computing the correct answer to the multiplication problem.
	correctAns = (addTable->qHeaderNum[askRow][0]) + (addTable->nums[askRow][askCol]);

	//Displaying the multiplication problem to the user and prompting the user to enter an answer.
	printf("\n%d + %d =", addTable->qHeaderNum[askRow][0], addTable->nums[askRow][askCol]);
	scanf("%d", &enteredAns);

	//Swapping the query element with the last element in the big array.
	temp = addTable->nums[askRow][askCol];
	addTable->nums[askRow][askCol] = addTable->nums[askRow][(addTable->qLeftInRow[askRow][0])-1];
	addTable->nums[askRow][(addTable->qLeftInRow[askRow][0])-1] = temp;

	//Number of questions in that row and the total number of questions is decreased by 1.
	addTable->qLeftInRow[askRow][0] = addTable->qLeftInRow[askRow][0] - 1;
	addTable->qLeftTotal = addTable->qLeftTotal - 1;

	//Marking the answer and returning the number of points.
	points = markTheAnswer(correctAns, enteredAns);
	return points;
}

int askSubQuestion(TableStructure *subTable, int askRow, int askCol) 
{
	//Declaring variables.
	int temp, correctAns, enteredAns;

	//Computing the correct answer to the multiplication problem.
	correctAns = (subTable->qHeaderNum[askRow][0]) + (subTable->nums[askRow][askCol]);

	//Displaying the multiplication problem to the user and prompting the user to enter an answer.
	printf("\n%d - %d =", subTable->qHeaderNum[askRow][0], subTable->nums[askRow][askCol]);
	scanf("%d", &enteredAns);

	//Swapping the query element with the last element in the big array.
	temp = subTable->nums[askRow][askCol];
	subTable->nums[askRow][askCol] = subTable->nums[askRow][(subTable->qLeftInRow[askRow][0])-1];
	subTable->nums[askRow][(subTable->qLeftInRow[askRow][0])-1] = temp;

	//Number of questions in that row and the total number of questions is decreased by 1.
	subTable->qLeftInRow[askRow][0] = subTable->qLeftInRow[askRow][0] - 1;
	subTable->qLeftTotal = subTable->qLeftTotal - 1;

	//Marking the answer and returning the number of points.
	points = markTheAnswer(correctAns, enteredAns);
	return points;
}

int markTheAnswer(int correctAns, int enteredAns)
{
	//If the entered answer does not match the correct answer then returning 0 points and displaying message.
	if (correctAns != enteredAns) {
		printf("\nIncorrect answer entered.\n The correct answer is %d", correctAns);
		return 0;
	}

	//If entered answer is correct, then returning 1 point.
	return 1;
}

int RowPicker(TableStructure *theTable)
{
	//Declaring variables.
	int pickRow = 0; //Initialising variables so that no error messages will be generated.
	int wrongRow =1;

		while (wrongRow == 1) {
		//Randomly picking a row between 0 and 10.
		pickRow = rand() % 11;
		if (theTable->qLeftInRow[pickRow][0] > 0) {
			wrongRow = 0;
		}
	}

	return pickRow;
}

int ColPicker(TableStructure *theTable, int askRow)
{
	//Declaring variable.
	int pickCol;

	//Picking a random column in the row picked based on the number of questions left.
	pickCol = rand() % theTable->qLeftInRow[askRow][0];

	return pickCol;
}