// CSE240 Fall 2022 HW9
// Write your name here
// Write the compiler used: Visual studio or g++

// READ BEFORE YOU START:
// You are given a partially completed program which consist of a class 'Book' defined in book.h
// The definitions of class member functions are to be filled in book.cpp
// hw09q1.cpp (this file) creates an array of objects 'b[]' and uses a menu driven program to add a book, display book info, 
// sort the book list and to find the oldest book(by publication year).
// You should start completing the program from from Q1. Question numbers are given around line 33.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// If you modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().

// ***** WRITE COMMENTS FOR IMPORTANT STEPS OF YOUR CODE. *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****

#include "book.h"
#include <iostream>
#include <string>

#define MAX_BOOKS 10

using namespace std;

// forward declaration of functions (already implemented)
void executeAction(char);

// functions that need implementation:
// in book.cpp :
// Q1 Book constructor			// 2 points
// Q2 Book member functions		// 18 points

// in this file (hw09q1.cpp) : Q3 to Q6
int addBook(string name_input, string author_input, int yearOfPublication_input, int ID_input);	// 10 points
void displayBooks(int n);																// 5 points
void sort();																		// 10 points
void newestBook();																// 5 points

Book b[MAX_BOOKS];			// array of objects
int currentCount = 0;				// number of books in the list

int main()
{
	char choice = 'i';		// initialized to a dummy value
	do
	{
		cout << "\nCSE240 HW9\n";
		cout << "Please select an action:\n";
		cout << "\t a: add a new book\n";
		cout << "\t d: display book list\n";
		cout << "\t s: sort the books in descending order based on publication year (within a range)\n";
		cout << "\t n: display the newest book whose name starts with a specific letter\n";
		cout << "\t q: quit\n";
		cin >> choice;
		cin.ignore();			// ignores the trailing \n
		executeAction(choice);
	} while (choice != 'q');

	return 0;
}


// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string name_input, author_input;
	int yearOfPublication_input, ID_input, result = 0;

	switch (c)
	{
	case 'a':	// add book
				// input book details from user
		cout << "Please enter book name: ";
		getline(cin, name_input);
		cout << "Please enter author name: ";
		getline(cin, author_input);
		cout << "Please enter the book publication year: ";
		cin >> yearOfPublication_input;
		cin.ignore();
		cout << "Please enter book ID: ";
		cin >> ID_input;
		cin.ignore();

		// add the book to the list
		result = addBook(name_input, author_input, yearOfPublication_input, ID_input);
		if (result == 0)
			cout << "\nThat book is already in the list or list is full! \n\n";
		else
			cout << "\nBook successfully added to the list! \n\n";
		break;

	case 'd':		// display the list
		displayBooks(0);
		break;

	case 's':		// sort the list
		sort();
		break;

	case 'n':		// find and display oldestt book
		newestBook();
		break;

	case 'q':		// quit
		break;

	default: cout << c << " is invalid input!\n";
	}

}

// Q3 addBook (10 points)
// This function adds a new book with the details given in function arguments.
// Add the book in 'b' (array of objects) only if there is remaining capacity in the array and if the book does not already exist in the list
// Check the id of the book to check if the book already exist in the list
// This function returns 1 if the book is added successfully, else it returns 0 for the cases mentioned above.
int addBook(string name_input, string author_input, int yearOfPublication_input, int ID_input)
{
	// Write the code below
	
	return 1;	// edit this line if needed
}

// Q4 displayBooks (5 points)
// This function displays the list of books.
// You must use recursion to display the book details. No for loop is allowed.
// Display the books from array 'b' from index '0' to 'currentCount-1'. See expected output given in question file.
// You can call the class function 'displayBooks()' here. Note that these are two different functions.
// Book::displayBook() displays details of one Book object, while displayBooks() should display all books
void displayBooks(int n)
{
    // Write the code below

}

// Q5 sort (10 points)
// This function sorts the books in descending order respect to publication year, and then display the books within a given range of publication year.
// You may use the 'tempBook' object for sorting logic, if needed.
void sort()
{
	Book tempBook;
	int lowerBoundYear;
	int upperBoundYear;
	// Write the code below
	
}

// Q6 newestBook (5 points)
// This functions displays books that is newest and name starts with a specific letter
// Parse the array to check if the book is the newest book based of the character input
// If the book is the newest book, then copy that book's details (object's data members) 
// to 'newBook' object created using 'new' and display those book details using 'newBook' object.
// Finally delete the 'newBook' object.
// NOTE: You necessarily have to use the 'newBook' object to store the book details in it and delete it after displaying.
//       You should not display book details using 'b[]' object.
void newestBook()
{
	char startingCharacter;				// Ask the user for a character
	Book* newBook = new Book;
	// Write the code below

}
