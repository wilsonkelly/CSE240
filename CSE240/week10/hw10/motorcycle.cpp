#include "motorcycle.h"
#include <iostream>

// Q2-b: Define displayVehicle() for Motorcycle class (5 points)
// Define the function displayVehicle() that you declared within the Motorcycle class in the header file
// See expected output in question file.
void Motorcycle::displayVehicle()
{

	cout << "Registration Id: " << getId() << endl;

	cout << "Owner Name: " << getOwner() << endl;

	cout << "This vehicle is a car" << endl;

}

// (displayList() function in hw10.cpp should call this function.)
// Include necessary header files
