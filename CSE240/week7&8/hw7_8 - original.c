// CSE240 Fall 2022 HW 7 & 8
// Write your name here
// Write the compiler used: Visual studio or gcc

// READ BEFORE YOU START:
// You are given a partially completed program that creates a linked list of student information.
// The global linked list 'list' is a list of students with each node being struct 'studentList'.
// 'studentList' consists of struct 'student' which has: student name, id, and a linked list of 'courses'.
// The linked list of courses has each node containing simply the name of the course.
// HW7 ignores the 'courses' linked list since there is no operation/manipulation to be done on 'courses' list in HW7.
// HW8 has operations/manipulations to be done with 'courses' list like add a course, display last added course.

// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// If you modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().
// You can use string library functions.

// ***** WRITE COMMENTS FOR IMPORTANT STEPS OF YOUR CODE. *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****
// ***** Before implementing any function, see how it is called in executeAction() *****


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996) // for Visual Studio

#define MAX_NAME 30

// global linked list 'list' contains the list of students
struct studentList {
	struct student* student;
	struct studentList* next;
} *list = NULL;				// currently empty list

// structure "student" contains the student's name, id and linked list of courses
struct student {
	char name[MAX_NAME];
	unsigned int id;
	struct course* courses;		// linked list 'courses' contains names of courses
};

//  structure 'course' contains course's name
struct course {
	char name[MAX_NAME];
	struct course* next;
};

// forward declaration of functions (already implemented)
void flushStdIn();
void executeAction(char);

// functions that need implementation:
// HW 7
void addStudent(char* studentNameInput, unsigned int idInput); // 20 points
void displayStudentList(struct studentList* tempList);	      // 15 points
struct student* searchStudent(char* studentNameInput);	      // 15 points
//HW 8
void addCourse(char* studentNameInput, char* courseNameInput);	// 15 points
void displayStudentCourseList(struct studentList* tempList);	// 15 points
void removeStudent(char* studentNameInput);			        // 20 points

int main()
{
	char selection = 'a';		// initialized to a dummy value
	do
	{
		printf("\nCSE240 HW 7,8\n");
		printf("Please enter your selection:\n");
		printf("HW7:\n");
		printf("\t a: add a new student to the list\n");
		printf("\t d: display student list (no courses)\n");
		printf("\t b: search for an student on the list\n");
		printf("\t q: quit\n");
		printf("HW8:\n");
		printf("\t c: add a course of a student\n");
		printf("\t l: display students who has a specific course\n");
		printf("\t r: remove an student\n");
		printf("\t q: quit\n");

		selection = getchar();
		flushStdIn();
		executeAction(selection);
	} while (selection != 'q');

	return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	char studentNameInput[MAX_NAME], courseNameInput[MAX_NAME];
	unsigned int idInput;
	struct student* searchResult = NULL;

	switch (c)
	{
	case 'a':	// add student
				// input student details from user
		printf("\nPlease enter student's name: ");
		fgets(studentNameInput, sizeof(studentNameInput), stdin);
		studentNameInput[strlen(studentNameInput) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter id: ");
		scanf("%d", &idInput);
		flushStdIn();

		if (searchStudent(studentNameInput) == NULL)
		{
			addStudent(studentNameInput, idInput);
			printf("\nStudent successfully added to the list!\n");
		}
		else
			printf("\nThat student is already on the list!\n");
		break;

	case 'd':		// display the list
		displayStudentList(list);
		break;

	case 'b':		// search for an student on the list
		printf("\nPlease enter student's name: ");
		fgets(studentNameInput, sizeof(studentNameInput), stdin);
		studentNameInput[strlen(studentNameInput) - 1] = '\0';	// discard the trailing '\n' char

		if (searchStudent(studentNameInput) == NULL)
			printf("\nStudent name does not exist or the list is empty! \n\n");
		else
		{
			printf("\nStudent name exists on the list! \n\n");
		}
		break;

	case 'r':		// remove student
		printf("\nPlease enter student's name: ");
		fgets(studentNameInput, sizeof(studentNameInput), stdin);
		studentNameInput[strlen(studentNameInput) - 1] = '\0';	// discard the trailing '\n' char

		if (searchStudent(studentNameInput) == NULL)
			printf("\nStudent name does not exist or the list is empty! \n\n");
		else
		{
			removeStudent(studentNameInput);
			printf("\nStudent successfully removed from the list! \n\n");
		}
		break;

	case 'c':		// add course
		printf("\nPlease enter student's name: ");
		fgets(studentNameInput, sizeof(studentNameInput), stdin);
		studentNameInput[strlen(studentNameInput) - 1] = '\0';	// discard the trailing '\n' char

		if (searchStudent(studentNameInput) == NULL)
			printf("\nStudent name does not exist or the list is empty! \n\n");
		else
		{
			printf("\nPlease enter course's name: ");
			fgets(courseNameInput, sizeof(courseNameInput), stdin);
			courseNameInput[strlen(courseNameInput) - 1] = '\0';	// discard the trailing '\n' char

			addCourse(studentNameInput, courseNameInput);
			printf("\nCourse added! \n\n");
		}
		break;

	case 'l':		// list course's students
		displayStudentCourseList(list);
		break;

	case 'q':		// quit
		break;

	default: printf("%c is invalid input!\n", c);
	}
}

// HW7 Q1: addStudent (20 points)
// This function is used to insert a new student in the linked list.
// You must insert the new student to the head of linked list 'list'.
// You need NOT check if the student already exists in the list because that is taken care by searchStudent() called in executeAction(). Look at how this function is used in executeAction().
// Don't bother to check how to implement searchStudent() while implementing this function. Simply assume that student does not exist in the list while implementing this function.
// NOTE: The function needs to add the student to the head of the list.
// NOTE: This function does not add courses to the student info. There is another function addCourse() in HW8 for that.
// Hint: In this question, no courses means NULL courses.

void addStudent(char* studentNameInput, unsigned int idInput)
{
	// write the code below.

}

// HW7 Q2: displayStudentList (15 points)
// This function displays the student details (struct elements) of each student.
// Parse through the linked list 'list' and print the student details (name and id) one after the other. See expected output screenshots in homework question file.
// You should not display course names (because they are not added in HW7).
// You MUST use recursion in the function to get full points. Notice that 'list' is passed to the function argument. Use recursion to keep calling this function till end of list.

void displayStudentList(struct studentList* tempList)
{
	// write the code below.

}

// HW7 Q3: searchStudent (15 points)
// This function searches the 'list' to check if the given student exists in the list. Search by student name.
// If it exists then return that 'student' node of the list. Notice the return type of this function.
// If the student does not exist in the list, then return NULL.
// NOTE: After implementing this fucntion, go to executeAction() to comment and un-comment the lines mentioned there which use searchStudent()
//       in case 'a', case 'r', case 'l' (total 3 places)

struct student* searchStudent(char* studentNameInput)
{
	struct studentList* tempList = list;			// work on a copy of 'list'
	// write the code below.

	return NULL;
}



// HW8 Q1: addCourse (15 points)
// This function adds course's name to a student node.
// Parse the list to locate the student and add the course to that student's 'courses' linked list. No need to check if the student name exists on the list. That is done in executeAction().
// If the 'courses' list is empty, then add the course. If the student has existing courses, then you may add the new course to the head or the tail of the 'courses' list.
// You can assume that the same course name does not exist. So no need to check for existing course names, like we do when we add new student.
// NOTE: Make note of whether you add the course to the head or tail of 'courses' list.
//       (Sample solution has course added to the tail of 'courses' list. You are free to add new course to head or tail of 'courses' list.)

void addCourse(char* studentNameInput, char* courseNameInput)
{
	struct studentList* tempList = list;		// work on a copy of 'list'
	// write the code below.
	// create new 'course' node

}

// HW8 Q2: displayStudentCourseList (15 points)
// This function prompts the user to enter a course name. This function then searches for students with this course.
// Parse through the linked list passed as parameter and print the matching student details ( name and id) one after the other. See expected output screenshots in homework question file.
// HINT: Use inputs gathered in executeAction() as a model for getting the course name input.
// NOTE: You may re-use some HW7 Q2 displayStudentList(list) code here.

void displayStudentCourseList(struct studentList* tempList)
{
	// write the code below.
	
}

// HW8 Q3: removeStudent (20 points)
// This function removes an student from the list.
// Parse the list to locate the student and delete that 'student' node.
// You need not check if the student exists because that is done in executeAction()
// removeStudent() is supposed to remove student details like name and id.
// The function will remove courses of the student too.
// When the student is located in the 'list', after removing the student name and id, parse the 'courses' list of that student
// and remove the courses.

void removeStudent(char* studentNameInput)
{

	struct studentList* tempList = list;	// work on a copy of 'list'
	struct course* tempCourse;
	// write the code below.
	
}