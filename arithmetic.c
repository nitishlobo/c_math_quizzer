//Ctrl K + Ctrl F for correct indentation.

#define _CRT_SECURE_NO_WARNINGS

#include "functions.h" 
void Shuffle(TableStructure *theTable)
{
	int pickColNum, numLeftToShuffle, i, temp;
	TableStructure copyOfTheTable;
	copyOfTheTable = *theTable; //Duplicating the table and it's contents to make a fair Shuffle possible.

	for (i=0; i<11; i++) {
		numLeftToShuffle = 10 + 1; //Initialising as 10 columns left to Shuffle, but add 1 because pickColNum uses remainder algorithm.
		while (numLeftToShuffle > 0) {
			pickColNum = rand() % numLeftToShuffle; //Generating numbers between 0 and number of elements left to Shuffle.

			//Shuffle Step 1: Moving a randomly picked element into the first position of theTable.
			theTable->nums[i][11-numLeftToShuffle] = copyOfTheTable.nums[i][pickColNum];

			//Shuffle Step 2: Swapping the randomly picked number in the element with the number in the last element.
			temp = copyOfTheTable.nums[i][pickColNum];
			copyOfTheTable.nums[i][pickColNum] = copyOfTheTable.nums[i][numLeftToShuffle-1];
			copyOfTheTable.nums[i][numLeftToShuffle-1] = temp;
			numLeftToShuffle--; //Decreasing number of elements not Shuffled by 1.
		}
	}
}

int RowPicker(TableStructure *theTable)
{
	int pickRow = 0; //Initialising variables so that no error messages will be generated.
	int wrongRow =1;

	while (wrongRow == 1) {
		pickRow = rand() % 11; //Randomly picking a row between 0 and 10.
		if (theTable->qLeftInRow[pickRow][0] > 0) {
			wrongRow = 0;
		}
	}
	return pickRow;
}

int CalculatePoints(TableStructure *theTable, int askRow, int askCol, int correctAns, int enteredAns)
{
	int temp;
	//Swapping the query element with the last element in the big array.
	temp = theTable->nums[askRow][askCol];
	theTable->nums[askRow][askCol] = theTable->nums[askRow][(theTable->qLeftInRow[askRow][0])-1];
	theTable->nums[askRow][(theTable->qLeftInRow[askRow][0])-1] = temp;

	//Number of questions in that row and the total number of questions is decreased by 1.
	theTable->qLeftInRow[askRow][0] = theTable->qLeftInRow[askRow][0] - 1;
	theTable->qLeftTotal = theTable->qLeftTotal - 1;

	if (correctAns != enteredAns) {
		printf("\n\n!!!   Incorrect answer entered.   !!!\n!!!   The correct answer is %d.   !!!\n", correctAns);
		return 0;
	}
	return 1; //If entered answer is correct, then returning 1 point.
}

int main(void) {
	TableStructure divTable, mulTable, addTable, subTable; //Decalaring variables.
	int i, j, askRow, askCol, invalidTable, totalNumOfQuestionsLeft, points, totalPoints;
	int correctAns, enteredAns;

	enteredAns = 0;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\t\t   << Hello user. The Arithmetic Tester has been activated. >>\n"); //Displaying message to user.
	printf("\n\t<< A special thanks to Jesus Christ, my friend for inspiring me in this project. >>\n");
	printf("\t   << Also, thank you to Dipesh Trikam, Manmeet Singh and Nirojan Jayananthan. >>\n");
	printf("\n\nStarted recording the time.\n");

	srand((unsigned int) time(NULL)); //Setting the seed to be able to generate random numbers.

	divTable.qLeftTotal = 121; //Intialising the total no. of questions left in each table.
	mulTable.qLeftTotal = 121;
	addTable.qLeftTotal = 121;
	subTable.qLeftTotal = 121;

	for (i=0; i<11; i++) { //Initialising the number of questions left in each row of each array structure.
		divTable.qLeftInRow[i][0] = 11; //qLeftInRow is the number of questions left.
		mulTable.qLeftInRow[i][0] = 11;
		addTable.qLeftInRow[i][0] = 11;
		subTable.qLeftInRow[i][0] = 11;
	}

	for (i=0; i<11; i++) { //Initialising the header number for each question.
		divTable.qHeaderNum[i][0] = i+2;
		mulTable.qHeaderNum[i][0] = i+2;
		addTable.qHeaderNum[i][0] = i+2;
		subTable.qHeaderNum[i][0] = i+2;
	}

	for (j=0; j<11; j++) { //Intialising the query number for each table.
		for (i=0; i<11; i++) {
			divTable.nums[i][j] = j+2;
			mulTable.nums[i][j] = j+2;
			addTable.nums[i][j] = j+2;
			subTable.nums[i][j] = j+2;
		}
	}
	Shuffle(&divTable); //Sending each query array to be Shuffled.
	Shuffle(&mulTable);
	Shuffle(&addTable);
	Shuffle(&subTable);

	totalNumOfQuestionsLeft = 121*4; //Setting the total number of questions in the entire program.
	totalPoints = 0; //Setting the total number of points to 0.
	while (totalNumOfQuestionsLeft > 0) { //All the initialising has been finished. The rest of the code that follows after this line is to ask the user a arithmetic question.
		invalidTable = 1; //Setting the table as invalid selection for each iteration.
		points = 0; //Setting the number of points to 0 by default in each iteration.
		while (invalidTable == 1) {
			i = rand() % 4; //i decides which type of question will be asked out of division, multiplication, addition & subtraction.
			if (i == 0) {
				if (divTable.qLeftTotal > 0) {
					invalidTable = 0; //Setting the table selection to be valid.
					askRow = RowPicker(&divTable); //Selecting a random row and column in the nums array to ask the user a question.
					askCol = rand() % divTable.qLeftInRow[askRow][0];

					correctAns = divTable.nums[askRow][askCol]; //Computing the correct answer to the division problem.

					//Displaying the division problem to the user and prompting the user to enter an answer.
					printf("\n%d / %d = ", (divTable.nums[askRow][askCol])*(divTable.qHeaderNum[askRow][0]), (divTable.qHeaderNum[askRow][0]));
					scanf("%d", &enteredAns);
					points = CalculatePoints(&divTable, askRow, askCol, correctAns, enteredAns); //Calculating points.
				}
			} else if (i == 1) {
				if (mulTable.qLeftTotal > 0) {
					invalidTable = 0;
					askRow = RowPicker(&mulTable);
					askCol = rand() % mulTable.qLeftInRow[askRow][0];
					correctAns = (mulTable.qHeaderNum[askRow][0]) * (mulTable.nums[askRow][askCol]);
					printf("\n%d * %d = ", mulTable.qHeaderNum[askRow][0], mulTable.nums[askRow][askCol]);
					scanf("%d", &enteredAns);
					points = CalculatePoints(&mulTable, askRow, askCol, correctAns, enteredAns);
				}
			} else if (i == 2) {
				if (addTable.qLeftTotal > 0) {
					invalidTable = 0;
					askRow = RowPicker(&addTable);
					askCol = rand() % addTable.qLeftInRow[askRow][0];

					//Computing the correct answer to the addition problem.
					correctAns = (addTable.qHeaderNum[askRow][0]) + (addTable.nums[askRow][askCol]);
					printf("\n%d + %d = ", addTable.qHeaderNum[askRow][0], addTable.nums[askRow][askCol]);
					scanf("%d", &enteredAns);
					points = CalculatePoints(&addTable, askRow, askCol, correctAns, enteredAns);
				}
			} else if (i == 3) {
				if (subTable.qLeftTotal > 0) {
					invalidTable = 0;
					askRow = RowPicker(&subTable);
					askCol = rand() % subTable.qLeftInRow[askRow][0];

					//Computing the correct answer to the subtraction problem.
					correctAns = (subTable.qHeaderNum[askRow][0]) - (subTable.nums[askRow][askCol]);
					printf("\n%d - %d = ", subTable.qHeaderNum[askRow][0], subTable.nums[askRow][askCol]);
					scanf("%d", &enteredAns);
					points = CalculatePoints(&subTable, askRow, askCol, correctAns, enteredAns);
				}
			}
		}
		totalPoints = totalPoints + points; //Calculating total # of points and decrementing no. of questions by 1.
		totalNumOfQuestionsLeft--;

		printf("\n     < Total number of Points: %d >", totalPoints); //Displaying message for user to keep track of how many questions are done.
		printf("\n     < %d questions done. >\n", 484 - totalNumOfQuestionsLeft);
		printf("     < %d questions remaining. >\n", totalNumOfQuestionsLeft);
	}

	printf("\n\n<<===== End of program. Please record the score and time. =====>>\n");
	scanf("%d", enteredAns);
}
