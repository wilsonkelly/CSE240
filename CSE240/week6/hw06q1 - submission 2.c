// CSE240 Fall 2022 HW6
// Wilson Kelly
// gcc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) 			// for Visual Studio Only

#define MAX_INSTRUCTORS 20
#define MAX_NAME_LENGTH 50

typedef enum { cs = 0, physics, mathematics, english } departmentEnum; // enum type

struct instructorRecord {					// struct for instructor details
	char name[MAX_NAME_LENGTH];
	departmentEnum department;
	unsigned int instructorId;
	unsigned int age;
	struct instructorRecord* next;			// pointer to next node
}*list = NULL;							// declare linked list 'list'

int count = 0;							// the number of instructors currently stored in the list (initialized to 0)

// functions already implmented
void flushStdIn();
void executeAction(char);
void save(char* fileName);

// functions that need implementation:
int add(char* name_input, unsigned int instructorId_input, unsigned int age_input, char* department_input); // 10 points
void sort();				  				// 10 points
int delete(unsigned int instructorId_input);  // 10 points
void load(char* fileName);		  			// 10 points
void display();				  // 10 points


int main()
{
	char* fileName = "Instructor_List77.txt";
	load(fileName);			// load list of instructors from file (if it exists). Initially there will be no file.
	char choice = 'i';		// initialized to a dummy value
	do
	{
		printf("\nEnter your selection:\n");
		printf("\t a: add a new instructor\n");
		printf("\t d: display instructor list\n");
		printf("\t r: remove an instructor from list\n");
		printf("\t s: sort instructor list by ID\n");
		printf("\t q: quit\n");
		choice = getchar();
		flushStdIn();
		executeAction(choice);
	} while (choice != 'q');

	save(fileName); 		// save list of instructors to file (overwrites file, if it exists)
	return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}

// ask for details from user for the given selection and perform that action
void executeAction(char c)
{
	char name_input[MAX_NAME_LENGTH];
	unsigned int instructorId_input, age_input, add_result = 0;
	char department_input[20];
	switch (c)
	{
	case 'a':
		// input instructor record from user
		printf("\nEnter instructor name: ");
		fgets(name_input, sizeof(name_input), stdin);
		name_input[strlen(name_input) - 1] = '\0';	// discard the trailing '\n' char
		
		printf("Enter instructor department (cs/physics/mathematics/english): ");
		fgets(department_input, sizeof(department_input), stdin);
		department_input[strlen(department_input) - 1] = '\0';	// discard the trailing '\n' char
		
		printf("Please enter instructor ID number: ");
		scanf("%d", &instructorId_input);
		
		printf("Please enter instructor age: ");
		scanf("%d", &age_input);
		flushStdIn();


		// add the instructor to the list
		add_result = add(name_input, instructorId_input, age_input, department_input);
		if (add_result == 0)
			printf("\nInstructor is already on the list! \n\n");
		else if (add_result == 1)
			printf("\nInstructor successfully added to the list! \n\n");
		else
			printf("\nUnable to add. Instructor list is full! \n\n");

		break;

	case 'r':
		printf("Please enter instructor ID to be deleted: ");
		scanf("%d", &instructorId_input);
		flushStdIn();
		int delete_result = delete(instructorId_input);
		if (delete_result == 0)
			printf("\nInstructor not found in the list! \n\n");
		else
			printf("\nInstructor deleted successfully! \n\n");
		break;
	case 'd': display();	break;
	case 's': sort();		break;

	case 'q': break;
	default: printf("%c is invalid input!\n", c);
	}
}

// Q1 : add (10 points)
// This function is used to add an instructor into the list. You can simply add the new instructor to the end of list (linked list of structs).
// Do not allow the instructor to be added to the list if it already exists in the list. You can do that by checking instructor names OR IDs already in the list. If either condition matches, return 0 without adding it to the list.
// If the instructor already exists then return 0 without adding it to the list. If the instructor does not exist in the list then add the instructor at the end of the list and return 1.
// If instructor list is full, then do not add new instructor to the list and return 2.
// NOTE: Notice how return type of add() is checked in case 'a' of executeAction()
// NOTE: You must convert the string 'department_input' to an enum type and store it in the list because the department has enum type (not string type). Any incorrect or mistyped values will be defaulted to "english".
// The list should be case sensitive. For instance, 'Roger' and 'roger' should be considered two different names.
// Hint: 'count' holds the number of instructors currently in the list
int add(char* name_input, unsigned int instructorId_input, unsigned int age_input, char* department_input)
{
	struct instructorRecord* tempList = list;	// work on a copy of 'list'.

	
	// Check to see if list is full
	if (count >= MAX_INSTRUCTORS) {
		return 2; // List is full, return 2
	}
	else {
		// Go through each instructor in list
		
		while(tempList) {
			// Check if id already on list
			if ( strcmp(tempList->name, name_input) == 0) {
				return 0; // ID already on list
			}
			if (tempList->next != NULL) {
				tempList = tempList->next;
			}
			else {
				break;
			}
		}
		
	// If ID not on list and the list isn't full, add to end of list
		struct instructorRecord* newInstructor1 = (struct instructorRecord*)malloc(sizeof(struct instructorRecord));
		
		strcpy(newInstructor1->name, name_input);
		newInstructor1->instructorId = instructorId_input;
		newInstructor1->age = age_input;
		
		newInstructor1->next = NULL;

		//compare strings department_input with the string version if its possible enum 
			// cs = 0, physics = 1, mathematics = 2, english = 3
		if (strcmp(department_input, "cs") == 0) {
			newInstructor1->department = cs;
		}
		else if (strcmp(department_input, "physics") == 0) {
			newInstructor1->department = physics;
		}
		else if (strcmp(department_input, "mathematics") == 0) {
			newInstructor1->department = mathematics;
		}
		else {
			newInstructor1->department = english;
		}
		
		if (tempList) {
			tempList->next = newInstructor1;
		}
		else {
			tempList = newInstructor1;
			list = tempList;
		}
		count++;
		return 1; // ID not on list, added to list
	}
}



// This function displays the instructor list with the details (struct elements) of each instructor. 
// Q2. display (10 points)
// Display all instructors.
void display()
{
	struct instructorRecord* tempList = list;							// work on a copy of 'list'
	// Write the code below
	char* departmentString = "Physics";

	//check if list is empty
	if (tempList != NULL) {
		while (tempList) {
			// display student's name
			printf("\nInstuctor Name: %s", tempList->name);

			if (tempList->department == cs)							// find what to display for department
				departmentString = "CS";
			else if (tempList->department == physics)
				departmentString = "Physics";
			else if (tempList->department == mathematics)
				departmentString = "Mathematics";
			else
				departmentString = "English";

			printf("\nDepartment: %s", departmentString);				// display department

			printf("\nInstructor ID: %d", tempList->instructorId);	// display instructor's ID
			printf("\nInstructor Age: %d", tempList->age);			// display age
			printf("\n");

			if (tempList->next != NULL) {
				tempList = tempList->next;
			}
			else {
				break;
			}
		}
	}
	else {
		printf("No instructors\n");
	}
}

// Q3 : sort (10 points)
// This function is used to sort the list(linked list of structs) numerically in ascending order by instructor ID.
// Parse the list and compare the instructor IDs to check which one should appear before the other in the list.
// Sorting should happen within the list. That is, you should not create a new node of structs having sorted books.
void sort()
{
	struct instructorRecord* tempList = list;		// work on a copy of 'list'
	struct instructorRecord* tempList2 = list;
	struct instructorRecord* tempList3 = list;
	//go through the list of instructors
	if (tempList != NULL) {
		while (tempList) {
			// Check if ids of 2 lists are the same
			tempList2 = tempList->next;
			tempList3 = tempList2->next;
			if (strcmp(tempList->name,tempList2->name) == 0) {
				//ID already on list
			}
			else if(strcmp(tempList->name, tempList2->name) > 0) {				
				
				//swap nexts
				tempList2->next = tempList;
				tempList->next = tempList3;
				//swap values
				tempList3 = tempList;
				tempList = tempList2;
				tempList2 = tempList3;
				
				//bug I couldn't fix: values are swapped, but then are not saved/displayed correctly
			}
			if (tempList->next != NULL && tempList2->next!=NULL) {
				tempList = tempList2;
				tempList2 = tempList2->next;
			}
			else {
				break;
			}
		}
	}
	else {
		printf("No instructors\n");
	}
	
	// display message for user to check the result of sorting.
	printf("\nInstructor list sorted! Use display option 'd' to view sorted list.\n");
}

// save() is called at the end of main()
// This function saves the linked list of structures to file.
// save() is called at end of main() to save the instructor list to a file.
// The file is saved at the same place as your C file. For VS, the default directory looks like this:
// C:\Users\<username>\Documents\Visual Studio 2017\Projects\Project1\Project1
// You can simply delete the file to 'reset the list' or to avoid loading from it.
void save(char* fileName)
{
	struct instructorRecord* tempList = list;	// work on a copy of 'list'

	FILE* file;
	int departmentValue = 0;
	file = fopen(fileName, "wb");		// open file for writing

	fwrite(&count, sizeof(count), 1, file);		// First, store the number of books in the list

	// Parse the list and write instructor record to file
	while (tempList != NULL) {
		fwrite(tempList->name, sizeof(tempList->name), 1, file);
		// convert enum to a number for storing
		// cs = 0, physics = 1, mathematics = 2, english = 3
		if (tempList->department == cs)
			departmentValue = 0;
		else if (tempList->department == physics)
			departmentValue = 1;
		else if (tempList->department == mathematics)
			departmentValue = 2;
		else
			departmentValue = 3;

		fwrite(&departmentValue, sizeof(departmentValue), 1, file);
		fwrite(&tempList->instructorId, sizeof(tempList->instructorId), 1, file);
		fwrite(&tempList->age, sizeof(tempList->age), 1, file);

		tempList = tempList->next;
	}

	fclose(file);			// close the file after writing
}

// Q4 : delete (10 points)
// This function is used to delete an instructor by ID.
// Parse the list and compare the instructor IDs to check which one should be deleted.
// Return 0 if the specified ID was not found. Return 1 upon successful removal of a record.
int delete(unsigned int instructorId_input)
{
	struct instructorRecord* tempListCur = list;	// work on a copy of 'list'
	struct instructorRecord* tempListPrev = list;	// work on a copy of 'list'
	
	// If instructor ID is found
	if (tempListCur->instructorId == instructorId_input) {
		// Delete instructor
		list = tempListCur->next;
		free(tempListCur);
		count--;
		return 1;
	}
	// ID not found, check all
	while (tempListCur) {
		// Compare ID again
		if (tempListCur->instructorId == instructorId_input) {
			break;
		}
		tempListPrev = tempListCur;
		tempListCur = tempListCur->next;
	}
	
	// Last one
	if (tempListCur) {
		// Delete instructor
		tempListPrev->next = tempListCur->next;
		free(tempListCur);
		count--;
		return 1;
	}
	// ID not found
	return 0;
}
// Q5:  load (10 points)
// This function is called in the beginning of main().
// This function reads the instructor list from the saved file and builds the linked list of structures 'list'. 
// In the first run of the program, there will be no saved file because save() is called at the end of program.
// So at the begining of this function, write code to open the file and check if it exists. If file does not exist, then return from the function.
// (See expected output of add() in homework question file. It displays "Instructor_List.txt not found" because the file did not exist initially.)
// If the file exists, then parse the instructor list to read the instructor details from the file.
// Use the save function given above as an example of how to write this function. Notice the order in which the struct elements are saved in save()
// You need to use the same order to read the list back.
// NOTE: The saved file is not exactly readable because all elements of the struct are not string or char type.
//       So you need to implement load() similar to how save() is implemented. Only then the 'list' will be loaded correctly.
//		You can simply delete the file to 'reset the list' or to avoid loading from it.
void load(char* fileName)
{
	struct instructorRecord* tempList = list;	// work on a copy of 'list'

	FILE* file;
	int departmentValue = 0;
	file = fopen(fileName, "rb");		// open file for writing
	struct instructorRecord* newInstructorRecord = NULL;
	fwrite(&count, sizeof(count), 1, file);		// First, store the number of books in the list
	
	// Check if file is valid
	if (file) {
		printf("Insturctor record loaded from %s.\n", fileName);
		// Read file to get count
		fread(&count, sizeof(count), 1, file);
		// Go through each each student in the list
		for (int i = 0; i < count; i++)
		{
			struct instructorRecord* newINode = (struct instructorRecord*)malloc(sizeof(struct instructorRecord));
			newINode->next = NULL;
			
			// Read name, idnumber, department, and age
			fread(newINode->name, sizeof(newINode->name), 1, file);
			fread(&departmentValue, sizeof(departmentValue), 1, file);
			fread(&newINode->instructorId, sizeof(newINode->instructorId), 1, file);
			fread(&newINode->age, sizeof(newINode->age), 1, file);

			// Check depertment val
				// cs = 0, physics = 1, mathematics = 2, english = 3
			if (departmentValue == 0) {
				newINode->department = 0;
			}
			else if (departmentValue == 1) {
				newINode->department = 1;
			}
			else if (departmentValue == 2) {
				newINode->department = 2;
			}
			else {
				newINode->department = 3;
			}
			
			// Check if first
			if (i == 0) {
				newInstructorRecord = list = newINode;
			}
			else {
				newInstructorRecord->next = newINode;
				newInstructorRecord = newInstructorRecord->next;
			}
		}
		fclose(file); // Close the file after writing
	}
	else {
		//file doesn't exist
		printf("Instructor_List.txt not found");
	}
}