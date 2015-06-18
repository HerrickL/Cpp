/*********************************************************************
** Author: L. Herrick
** Date: 2/25/15
** Description:  
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Fraction.hpp"

using namespace std;

int main()
{
	//user variables
	string userNumber;
	int numerator1;
	int numerator2;
	int denominator1;
	int denominator2;
	string userSelection;


	//ask user for value for the numerator
	cout << "Enter the numerator for the first fraction: ";
	getline(cin, userNumber);

	//validate user input
	bool checking = true;
	while(checking)
	{
		int problem = 0;

		for(int x = 0; x< userNumber.size(); x++)
		{
			if (isdigit(userNumber[x]) != true)
			{
				problem += 1;
			}
		}

		if(problem > 0)
		{
			cout << "Error. Please enter an integer for the numerator: ";
			getline(cin, userNumber);
		}
		else
		{
			numerator1 = atoi(userNumber.c_str());
			checking = false;
		}
	}

	//ask user for value for the denominator
	cout << "Enter the denominator for the first fraction: ";
	getline(cin, userNumber);

	//validate user input
	checking = true;
	while(checking)
	{
		int problem = 0;

		for(int x = 0; x< userNumber.size(); x++)
		{
			if (isdigit(userNumber[x]) != true)
			{
				problem += 1;
			}
		}

		if(problem > 0)
		{
			cout << "Error. Please enter an integer for the denominator: ";
			getline(cin, userNumber);
		}
		else
		{
			denominator1 = atoi(userNumber.c_str());
			checking = false;
		}
	}

	//create fraction obj1
	try
	{
		Fraction obj1(numerator1, denominator1);
	}
	catch(string exceptionString)
	{
		cout << exceptionString;
		return 0;
	}

	Fraction obj1(numerator1, denominator1);

	//ask user for the value for the numerator
	cout << "Enter the numerator for the second fraction: ";
	getline(cin, userNumber);

	//validate user input
	checking = true;
	while(checking)
	{
		int problem = 0;

		for(int x = 0; x< userNumber.size(); x++)
		{
			if (isdigit(userNumber[x]) != true)
			{
				problem += 1;
			}
		}

		if(problem > 0)
		{
			cout << "Error. Please enter an integer for the numerator: ";
			getline(cin, userNumber);
		}
		else
		{
			numerator2 = atoi(userNumber.c_str());
			checking = false;
		}
	}

	//ask user for the value of the denominator
	cout << "Enter the denominator for the second fraction: ";
	getline(cin, userNumber);

	//validate user input
	checking = true;
	while(checking)
	{
		int problem = 0;

		for(int x = 0; x< userNumber.size(); x++)
		{
			if (isdigit(userNumber[x]) != true)
			{
				problem += 1;
			}
		}

		if(problem > 0)
		{
			cout << "Error. Please enter an integer for the denominator: ";
			getline(cin, userNumber);
		}
		else
		{
			denominator2 = atoi(userNumber.c_str());
			checking = false;
		}
	}

	//create fraction obj2
	try
	{
		Fraction obj2(numerator2, denominator2);
	}
	catch(string exceptionString)
	{
		cout << exceptionString;
		return 0;
	}

	Fraction obj2(numerator2, denominator2);

	//ask the user if they want to multiply or divide
	cout << "Would you like to multiply or divide the first fraction by the second?" << endl;
	cout << "Enter 'multiply' or 'divide': ";
	getline(cin, userSelection);

	//validate user selection
	while(userSelection != "multiply" && userSelection != "divide")
	{
		string temp = userSelection;

		//check if it's a case sensitive issue
		for (int x = 0; x < userSelection.size(); x++)
		{
			temp[x] = tolower(userSelection[x]);
		}

		userSelection = temp;

		if(userSelection != "multiply" && userSelection != "divide")
		{
			cout << "Error: please enter 'multiply' or 'divide': ";
			getline(cin, userSelection);
		}
	}

	//multiply
	if(userSelection == "multiply")
	{
		try
		{
			Fraction obj3 = obj1 * obj2;

			//print result
			cout << obj1 << " * " << obj2 << " = ";
			cout << obj3 << endl;
		}
		catch(string exceptionString)
		{
			cout << exceptionString;
			return 0;
		}
	}
	//divide
	else
	{
		try
		{
			Fraction obj3 = obj1 / obj2;

			//print result
			cout << obj1 << " / " << obj2 << " = ";
			cout << obj3 << endl;
		}
		catch(string exceptionString)
		{
			cout << exceptionString;
			return 0;
		}
	}

	return 0;
}




/*********************************************************************
** Description: Constructor function for Fraction objects
** Parameters: int numerator, int denominator
*********************************************************************/
Fraction::Fraction(int numerator, int denominator)
{
	setNumerator(numerator);
	setDenominator(denominator);
}



/*********************************************************************
** Description: Sets number to class variable numerator
** Parameters: int number
*********************************************************************/
void Fraction::setNumerator(int num)
{
	numerator = num;
}



/*********************************************************************
** Description: Sets number to class variable denominator.  Throws
an exception if denominator is 0.
** Parameters: int number
*********************************************************************/
void Fraction::setDenominator(int num)
{
	denominator = num;

	//throw an exception if 0
	if(denominator == 0)
	{
		throw string("Error: Cannot have a denominator of zero.\n");
	}
}



/*********************************************************************
** Description: Returns numerator
** Parameters: none
*********************************************************************/
int Fraction::getNumerator() const
{
	return numerator;
}



/*********************************************************************
** Description: Returns denominator
** Parameters: none
*********************************************************************/
int Fraction::getDenominator() const
{
	return denominator;
}
 



/*********************************************************************
** Description: Overloads * operator to multiply objects representing
fractions.  Returns as a fraction object.  
** Parameters: refernce to object right of * operator
*********************************************************************/
const Fraction Fraction::operator* (const Fraction &obj2)
{
		
	return Fraction(this->getNumerator() * obj2.getNumerator(), 
		this->getDenominator() * obj2.getDenominator());
}




/*********************************************************************
** Description: Overloads the / operator to divide objects representing
fractions.  Returns as a fraction object.  By way of creating an 
object, uses the setDenominator method to throw an exception if the
denominator is 0.
** Parameters: reference to the object right of / operator
*********************************************************************/
const Fraction Fraction::operator/ (const Fraction &obj2)
{

	return Fraction(this->getNumerator() * obj2.getDenominator(), 
		this->getDenominator() * obj2.getNumerator());
}



/*********************************************************************
** Description: Overloads the << stream operator to print objects that
represent fractions in "numerator / denominator" notation
** Parameters: ref to out, object being printed
*********************************************************************/
ostream &operator<<(ostream& out, Fraction obj)
{
	out << obj.getNumerator() << "/" << obj.getDenominator();
	return out;
}