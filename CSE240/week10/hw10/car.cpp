#include "car.h"
#include <iostream>

// Q2a: Define displayVehicle() for Car class (5 points)
// Define the function displayVehicle() that you declared within the Car class in the header file
// See expected output in question file.
void Car::displayVehicle()
{	
	cout << "Registration Id: " << getId() << endl;

	cout << "Owner Name: "<< getOwner() << endl;

	cout << "This vehicle is a car" << endl;

}

// (displayList() function in hw10.cpp should call this function.)
// Include necessary header files
