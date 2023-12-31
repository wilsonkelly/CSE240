// CSE240 Fall 2022 HW10
// Write your name here
// Programming environment used: VS or g++

// READ BEFORE YOU START:
// You are given a partially completed program that creates a list of vehicles.
// Each vehicle has id, owner and vehicle type (car or motorcycle).
// This information is stored as an object of Vehicle class. Class defined in vehicle.h
// The classes Car and Motorcycle are child classes of the Vehicle class.
// When adding a new vehicle, these child classes are used to make the vehicle node of the list.
// So each node in the list is actually an object of either Car or Motorcycle class.

// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// Do not modify given code.

// You can assume that all input is valid:

#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"
#include "vehicle.h"
#include "motorcycle.h"
#include "car.h"

using namespace std;

// functions already implemented:
void executeAction(char c);
Vehicle* searchVehicle(string id_input);

// functions that need implementation:
void addVehicle(string id_input, string owner_input, vehicleType type);	// 7 points
void displayList();														// 4 points
void save(string fileName);												// 7 points
void load(string fileName);												// 7 points

Container* list = NULL;				// global list

int main()
{
	char c = 'i';				// initialized to a dummy value

  // During first execution, there will be no list.txt in source directory. list.txt is generated by save() while exiting the program.
	load("list.txt");
	do {
		cout << "\nCSE240 HW10\n";
		cout << "Please enter your selection:\n";
		cout << "\t a: add a new vehicle\n";
		cout << "\t d: display vehicle list\n";
		cout << "\t c: change owner of a vehicle\n";
		cout << "\t q: quit\n";
		cin >> c;
		cin.ignore();
		executeAction(c);
	} while (c != 'q');

	save("list.txt");

	list = NULL;

	return 0;
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string id_input;
	string owner_input;
	int type_input = 2;
	vehicleType type;
	Vehicle* returnedVehicle = NULL;

	switch (c)
	{
	case 'a':	// add vehicle
				// input vehicle details from user
        cout << endl << "Enter vehicle registration id: ";
		getline(cin, id_input);
		cout << "Enter owner name: ";
		getline(cin, owner_input);

		while (!(type_input == 0 || type_input == 1))
		{
			cout << "Enter vehicle type: " << endl;
			cout << "0. Car " << endl;
			cout << "1. Motorcycle" << endl;
			cin >> type_input;
			cin.ignore();
		}
		type = (vehicleType)type_input;

		// searchVehicle() will return the vehicle object if found, else returns NULL
		returnedVehicle = searchVehicle(id_input);
		if (returnedVehicle == NULL)
		{
			addVehicle(id_input, owner_input, type);
			cout << endl << "Vehicle added to list!" << endl << endl;
		}
		else
			cout << endl << "Vehicle already exists in the list!" << endl << endl;

		break;

	case 'd':		// display the list
		displayList();
		break;

	case 'c':		// change owner
		cout << endl << "Enter vehicle id: ";
		getline(cin, id_input);
		// searchVehicle() will return the vehicle node if found, else returns NULL
		returnedVehicle = searchVehicle(id_input);
		if (returnedVehicle == NULL)
		{
			cout << endl << "Vehicle not in list!" << endl << endl;
		}
		else
		{
			// if vehicle exists in the list, then ask user for new owner
			cout << endl << "Enter new owner name: ";
			getline(cin, owner_input);

			// Q3-c: Call changeOwner() here   (1 point)
			// 'returnedVehicle' contains the vehicle whose 'owner' is to be changed.
			// 'owner_input' contains the new owner name of the vehicle.
			// Call the function with appropriate arguments.

			cout << endl << "Owner changed!" << endl << endl;
		}
		break;

	case 'q':		// quit
		break;

	default: cout << c << " is invalid input!\n";
	}

}

// No implementation needed here, however it may be helpful to review this function
Vehicle* searchVehicle(string id_input)
{

	Container* tempList = list;			// work on a copy of 'list'

	while (tempList != NULL)			// parse till end of list
	{
		if (tempList->vehicle->getId() == id_input)
		{
			return tempList->vehicle;	// return the vehicle if found
		}

		tempList = tempList->next;		// parse the list
	}

	return NULL;						// return NULL if vehicle not found in list
}

// Q3-b: Define Friend Function changeOwner()  (3 points)
// Define the function changeOwner() that is declared in vehicle.h file.
// This function sets the new 'owner' of the vehicle. The vehicle object and new owner is to be passed as function arguments.
// Use 'd' display option after using 'c' option to verify.
// You will need to implement add() and displayList() before you test this function.



// Q4: addVehicle  (7 points)
// This function is used to add a new vehicle to the global linked list 'list'. You may add the new vehicle to head or tail of the list. (Sample solution adds to tail)
// vehicleType 'type' can be car or motorcycle. You will need to use the function argument �type� to determine which constructor to use to create new vehicle node.
// For example, if the user enters type as 'motorcycle', then you need to use Motorcycle class and constructor to create new vehicle node and add it to the list.
// NOTE: In executeAction(), searchVehicle() is called before this function. Therefore no need to check here if the vehicle exists in the list.
//       See how this function is called in case 'a' of executeAction()
void addVehicle(string id_input, string owner_input, vehicleType type)
{

	Container* tempList = list;				// work on a copy of 'list'
    // Write the code below.
}

// Q5: displayList	(4 points)
// This function displays the list of vehicle and their details (id, owner, vehicle type)
// Parse the list and use the class member function to display the vehicle info.
// See expected output in the question file.
void displayList()
{
	Container* tempList = list;			// work on a copy of 'list'

	// Write the code below.
}

// Q6: save  (7 points)
// Save the linked list of vehicles to a file list.txt using ofstream.
// You will need to save the number of vehicles in linked list. That will help in load() when reading the file.
// One format to store is:
// <no. of vehicles>
// <Vehicle1 id>
// <Vehicle1 owner>
// <Vehicle1 type>
// <Vehicle2 id>
// <Vehicle2 owner>
// <Vehicle2 type>
// and so on..
// You may store the list in another format if you wish. You need to read the file in load () the same way that it is saved in save().
// This function is called when exiting the program (end of main() ).
// Hint: You may want to cast the enum �vehicleType� to an int before writing it to the file.
void save(string fileName)
{
    // Write the code below.
}

// Q7: load (7 points)
// Load the linked list of vehicles from the file using ifstream.
// You will need to create the linked list in the same order that is was saved to the file in save().
// First, read the number of vehicles saved in the file.
// Then, for every vehicle you will need to create a new Vehicle node depending on vehicle type. You may add the vehicle to head or tail of the list.
// Hint: If you casted the enum 'vehicleType' to an int, you will need to cast it back to 'vehicleType' when making the vehicle node.
// This function is called at the beginning of main().
void load(string fileName)
{
	// Write the code below.
}