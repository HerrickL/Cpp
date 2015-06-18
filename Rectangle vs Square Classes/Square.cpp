/*********************************************************************
** Author: L. Herrick
** Date: 2/18/15
** Description:  Asks the user if they would like to calculate the
area and perimeter of a square or a rectangle.  Collects the proper
input depending on square or rectangle selection and outputs the 
area and the perimeter.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "Rectangle.hpp"
#include "Square.hpp"

//prototype
double selection();

using namespace std;

int main()
{
	//variables for user input
	string userSelection;
	double userInputSide1;
	double userInputSide2;

	//Menu for selection
	cout << "1. Get the calculations for a square." << endl;
	cout << "2. Get the calculations for a rectangle." << endl;
	cout << endl;
	cout << "Enter the number for your selection: ";
	getline(cin, userSelection);

	//validate user selection
	while(userSelection != "1" && userSelection != "2")
	{
		cout << "Error. Please make a vaid selection or '1' or '2': ";
		cin >> userSelection;
	}

	//make a square
	if(userSelection == "1")
	{
		cout << "Enter the length of one side of the square: ";
		cin >> userInputSide1;

		Square obj1(userInputSide1);
		cout << "Area of the Square: " << obj1.area() << endl;
		cout << "Perimeter of the Square: " << obj1.perimeter() << endl;
	}
	//make a rectangle
	else
	{
		cout << "Enter the length of the rectangle: ";
		cin >> userInputSide1;
		cout << "Enter the width of the rectangle: ";
		cin >> userInputSide2;

		Rectangle obj1(userInputSide1, userInputSide2);
		cout << "Area of the Rectangle: " << obj1.area() << endl;
		cout << "Perimeter of the Rectangle: " << obj1.perimeter() << endl;
	}


	return 0;
}

