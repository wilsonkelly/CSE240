// CSE240 Fall 2022 HW9
// Write your name here
// Write the compiler used: Visual studio or g++

#include "book.h"
#include <iostream>
#include <string>

using namespace std;

// Q1 Book (2 points)
// Book() constructor assigns the following default values to class data members
// name: abc
// author: bcd
// yearOfPublication: 2000
// ID: 0
Book::Book()
{
	// Write the code below

}

// Q2 (18 points)
// 2 points for each function

// Define all the class member functions.
// While defining member functions, note that these functions will be called using 
// a 'Book' object which will represent one book.
// Eg-  Book b[10]; creates 10 Book objects
//		b[2].setID(19); will set 3rd book's ID to 19

// setName assigns 'name_input' to class data member 'name'
void Book::setName(string name_input)
{
	// Write the code below

}

// setAuthor assigns author_input to class data member 'author'
void Book::setAuthor(string author_input)
{
	// Write the code below

}

// setYearOfPublication assigns 'yearOfPublication_input' to class data member 'yearOfPublication'
void Book::setYearOfPublication(int yearOfPublication_input)
{
	// Write the code below

}

// setID assigns 'ID_input' to class data member 'ID'
void Book::setID(int ID_input)
{
	// Write the code below

}

// displayBook displays the name, author, Publication Year and ID of the book
// See expected output in question file.
void Book::displayBook()
{
	// Write the code below
	cout << "Name: " << name << endl;
	cout << "Name of Book Author: " << author << endl;
	cout << "Publication Year: " << yearOfPublication << endl;
	cout << "ID: " << ID << endl;

}

// getName returns the class data member 'name'.
string Book::getName()
{
	// Write the code below

}

// getAuthor returns the class data member 'author'.
string Book::getAuthor()
{
	// Write the code below

}

// getYearOfPublication returns the class data member 'yearOfPublication'.
int Book::getYearOfPublication()
{
	// Write the code below

}

// getID returns the class data member 'ID'.
int Book::getID()
{	
	// Write the code below

}
