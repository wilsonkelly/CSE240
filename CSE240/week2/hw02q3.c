#include <stdio.h>

// CSE 240 Fall 2022 Homework 2 Question 3 (25 points)
// Note: You may notice some warnings when you compile in GCC or VS, that is okay.

#define square(x) (x * x)

#define mulMacro(a, b)	(a + b + a * a + b * b + a * a * a + b * b * b)

int mulFunc(int a, int b) {
	return 
						(a + b + a * a + b * b + a * a * a + b * b * b);
					  // 
}

// Part 1:
// We want to pass the value of 6 to square and expect the result of square to be 36, why is the result 25? Correct the error (5 points)
void part1(int x) {
	
	int result;
	x--; //7-1 = 6
	result = square(x);

	printf("square(6) = %d \n\n", result);

	// Why did this error occur? Please provide the answer in your own words below.
	printf	("Explanation: --x means decrement x, then give the value. Additionally, the function will be square(--x) (--x * --x) so it will be square(6) and then (5 * 5).  \n\n\n"); // (2.5 points)
}


// Part 2:
// We want to pass decremented values of x and y to the macro and function to compare their outputs in VS and GCC.
// Run this program in Visual Studio(VS) and then again in GCC. Fill the blanks below with the output values for mulFunc and mulMacro.
// Then correct/edit this function so that mulFunc and mulMacro produce same correct output of 261.			// (5 points)
// 
void part2(int x, int y) {
	int x_copy = x, y_copy = y;
	x_copy--;
	y_copy--;
	printf("mulFunc(x, y) = %d\nmulMacro(x, y) = %d\n\n", mulFunc(--x, --y), mulMacro(x_copy, y_copy));


	// Replace the 4 blank spaces below with the actual output observed when running the code in VS and GCC.
	// The blanks should have the answers of unedited program. Keep the answers in blanks as they were, after editing the program.
	printf("In VS : the result of mulFun = 261 and mulMacro = -49 \n"); 			// (5 points)
	printf("In GCC: the result of mulFun = 261 and mulMacro = 261 \n\n"); 		// (5 points)
		//NOTE: GCC did not run due to errors in the unedited program, such as --y_copy being undefined. As such, the only time it ran was after I edited the program, so I entered those values.

	// Explain in a short sentence why VS and GCC could possibly produce a different value for the same program and for the same input.
	printf("Explanation: VS and GCC are translated differently, as they have different compilers.  \n\n"); //  (2.5 points)
}

// Do not edit main()  
int main()
{
	int x = 7, y = 2;

	printf("Part 1:\n\n");
	part1(x);
	printf("Part 2:\n\n");
	part2(x, y);

	while (1);	// needed to keep console open in VS
	return 0;
}
