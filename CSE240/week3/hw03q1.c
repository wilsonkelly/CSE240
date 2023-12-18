// CSE240 Fall 2022 HW3

// Wilson Kelly
// State the IDE that you use: Visual Studio

#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)  // compiler directive for Visual Studio only

// Read before you start:
// You are given a partially complete program. Your job is to complete the functions in order for this program to work successfully.
// All instructions are given above the required functions, please read them and follow them carefully. 
// You shoud not modify the function return types or parameters.
// You can assume that all inputs are valid. Ex: If prompted for an integer, the user will input an integer.

// Global Macro Values. They are used to define the size of 2D array of integers
#define NUM_ROWS 5
#define NUM_COLUMNS 5
#define NUM_STRINGS 5 
#define STRING_LENGTH 50

// Forward Declarations
void printMatrix(int[NUM_ROWS][NUM_COLUMNS]);
void printMatrixDiagonal(int[NUM_ROWS][NUM_COLUMNS]);
void sumMatrixCols(int[NUM_ROWS][NUM_COLUMNS]);
void rotateMatrixRows(int[NUM_ROWS][NUM_COLUMNS], int);
void transposeMatrix(int[NUM_ROWS][NUM_COLUMNS]);
void horizontalFlipMatrix(int[NUM_ROWS][NUM_COLUMNS]);
void reverseStrings(char strings[NUM_STRINGS * STRING_LENGTH]);
int noOfOccurencesOfChar(char s[NUM_STRINGS * STRING_LENGTH], char);


// Problem 1: printMatrix (5 points)
// Traverse the 2D array of integers variable 'matrix' (input from main)
// and print the contents in the following format (actual contents may vary)
// e.g.
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25
void printMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	//simple print code, goes through each number in a column,
	//then on to the next row
	for (int i = 0;i <NUM_ROWS ;i++) {
		for (int j = 0; j< NUM_COLUMNS; j++) {
			printf("%d, ", matrix[i][j]);
		}
		printf("\n");
	}
}

// Problem 2: printMatrixDiagonal (5 points)
// Traverse the 2D array of integers 'matrix' and print each value on the diagonal from the 
// top left to bottom right position.
// e.g.
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15	=> 1 7 13 19 25
// 16 17 18 19 20
// 21 22 23 24 25
void printMatrixDiagonal(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	//diagonal positions are [1,1], [2,2], etc
	for (int i = 0;i < NUM_ROWS;i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
		if (i == j)
			printf("%d, ", matrix[i][j]);
		}
		//printf("\n");
	}
}

// Problem 3: sumMatrixCols (5 points)
// Traverse the 2D array of integers 'matrix' and print the sum of each column on its own line.
// e.g.
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15	=> 55 60 65 70 75
// 16 17 18 19 20
// 21 22 23 24 25
void sumMatrixCols(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	//By doing [column][row], you get the values through each column, then row.
	//This, along with adding each num in each column, and checking 
	//that that all nums in the length of the column are added, and going on to
	//the next, allows us to get sum of columns.
	int sum=0, count =0;
	for (int i = 0;i < NUM_COLUMNS;i++) {
		//sum += matrix[i][0];
		for (int j = 0; j < NUM_ROWS; j++) {
			//printf("%d, ", matrix[j][i]);
			sum += matrix[j][i];
			count++;
		}
		if(count%NUM_ROWS ==0) {
			printf("%d, ", sum);
			sum = 0;
		}
	}
	
}

// Problem 4: rotateMatrixRows (5 points)
// Take the 2D array of integers 'matrix' and print the result of rotating each row to the right
// by the amount specified by the integer 'offset'. In other words, shift each entry position right by 'offset'.
// If shifting would move an integer off the end of the row, it moves to the beginning of the row.
// **Hint: Use printMatrix to print the result**
// e.g.
// 1 2 3 4 5			5 1 2 3 4
// 6 7 8 9 10			10 6 7 8 9
// 11 12 13 14 15	=>	15 11 12 13 14
// 16 17 18 19 20		20 16 17 18 19
// 21 22 23 24 25		25 21 22 23 24
void rotateMatrixRows(int matrix[NUM_ROWS][NUM_COLUMNS], int offset)
{
	// Use this matrix to store each element
	int matrix2[NUM_ROWS][NUM_COLUMNS];

	// Create an index to keep track of matrix2 position index from matrix index
	int index = offset;
	// Store index 1-4 nums of matrix into matrix2 with offset
		//matrix[0][1] = matrix[0][0] to
		//matrix[0][4] = matrix[0][3]
		// so 12345 becomes (blank)1234, etc
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS-offset; j++) {
			matrix2[i][index] = matrix[i][j];
			//printf("%d, ", matrix2[i][index]);
			index++;
		}
		//printf("\n");
		index = 1;
	}
	
	// Store first displacement nums of matrix into matrix2
	// matrix2[0][0]=matrix[0][4] to
	// matrix2[4][0]=matrix[4][4],
	// so (blank)1234 becomes 51234, etc
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < offset; j++) {
			matrix2[i][j] = matrix[i][NUM_COLUMNS - offset];
		}
	}
	//print out final matrix2
	printMatrix(matrix2);
}

// Problem 5: transposeMatrix (10 points)
// Take the 2D array of integers 'matrix' and print the tranpose matrix.
// You may assume that row and column counts are equal.
// **Hint: Use printMatrix to print the result**
// e.g.
// 1 2 3 4 5			1 6 11 16 21
// 6 7 8 9 10			2 7 12 17 22
// 11 12 13 14 15	=>	3 8 13 18 23
// 16 17 18 19 20		4 9 14 19 24
// 21 22 23 24 25		5 10 15 20 25
void transposeMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	// Use this matrix to store each element
	int matrix2[NUM_ROWS][NUM_COLUMNS];

	// matrix2  matrix
	// [0][0] = [0][0]
	// [1][0] = [0][1]
	// [2][0] = [0][2]
	// 
	// so 1,2,3 = 1,
	//			  2,
	//			  3, etc...
	// 
	// puts values from matrix into matrix2, going down each column, then goes to next row
	for (int i = 0;i < NUM_COLUMNS;i++) {
		for (int j = 0; j < NUM_ROWS; j++) {
			matrix2[j][i] = matrix[i][j];
		}
	}
	printMatrix(matrix2);
}

// Problem 6: horizontalFlipMatrix (10 points)
// Take the 2D array of integers 'matrix' and print the matrix flipped horizontally.
// **Hint: Use printMatrix to print the result**
// e.g.
// 1 2 3 4 5			21 22 23 24 25
// 6 7 8 9 10			16 17 18 19 20
// 11 12 13 14 15	=>	11 12 13 14 15
// 16 17 18 19 20		6 7 8 9 10
// 21 22 23 24 25		1 2 3 4 5
void horizontalFlipMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	// Use this matrix to store each element
	int matrix2[NUM_ROWS][NUM_COLUMNS];
	
	// matrix2 Counts down rows from bottom to top, while getting row values top to bottom from matrix
	// 
	// matrix2	matrix
	// [4][0] = [0][0] ...
	// [4][4] = [0][4] 
	// ...
	// [0][4] = [4][0] ...
	// [0][4] = [4][4]

	int index = 0;
	for (int i = NUM_ROWS-1; i >= 0; i--) {
		for (int j = 0; j < NUM_ROWS; j++) {
			matrix2[i][j] = matrix[index][j];
		}
		index++;
	}
	printMatrix(matrix2);
}

// Problem 7: reverseString (5 points)
// Reverse each string of strings[]. 
// Consider one string at a time and reverse the characters. For instance, "hi hello" should reverse to "olleh ih".
// begin with swapping first and last letter.
// We have 2 indices: i begins from start and increments, len begins from end and decrements
// run the swapping logic length/2 times
void reverseStrings(char strings[NUM_STRINGS * STRING_LENGTH])
{
	// hi hello = olleh ih
	// Start by taking length of strings array
	int length = strlen(strings);
	int temp;
	// Make a temporary int to be able to swap first and last as iterates
	// Iterate from 0 to half the length
	for (int i = 0; i < length/2; i++) {
			// Swap first and last
			temp = strings[i];
			strings[i] = strings[length-i-1];
			strings[length - i - 1] = temp;
	}
}

// Problem 8: noOfOccurencesOfChar (5 points)
// Count all occurrences of the specified character 'filter' from s[]. 
int noOfOccurencesOfChar(char s[NUM_STRINGS * STRING_LENGTH], char filter)
{
	// Go through entirety of s, check if s[index] is the same as 'filter',
	// if its the same then add to sum
	int length = strlen(s);
	int sum=0;
	for (int i = 0; i < length; i++) {
		// Check for filter char
		if (s[i] == filter) {
			sum++;
		}
	}
	// Return the amount of times the filter character was detected
	return sum;
}

// You should study and understand how this main() works.
// *** DO NOT modify it in any way ***
int main()
{
	printf("CSE240 HW3: 2D Integer Arrays\n\n");

	int matrix[NUM_ROWS][NUM_COLUMNS] =
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};

	printMatrix(matrix);
	printf("\n\n");
	printMatrixDiagonal(matrix);
	printf("\n\n");
	sumMatrixCols(matrix);
	printf("\n\n");
	rotateMatrixRows(matrix, 1);
	printf("\n\n");
	transposeMatrix(matrix);
	printf("\n\n");
	horizontalFlipMatrix(matrix);

	printf("\nCSE240 HW3: 2D Character Arrays\n\n");

	char words[NUM_STRINGS * STRING_LENGTH];
	printf("\nEnter sentence with max 5 words: ");
	fgets(words, sizeof(words), stdin);
	reverseStrings(words);
	printf("\nReveresed string: %s\n", words);
	printf("\nNo of occurences of \'a\': %d", noOfOccurencesOfChar(words, 'a'));

	int i = getchar();
	i = getchar(); // Keep console open
	return 0;
}
