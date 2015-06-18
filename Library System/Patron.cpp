/*********************************************************************
** Author: L. Herrick
** Date: 3/10/15
** Description: Implementation file for the Patron class
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Patron.hpp"
#include "LibraryItem.hpp"

using namespace std;


/*********************************************************************
** Description: Default constructor for the Patron class.  Sets idNum
and name to empty strings.
** Parameters: none
*********************************************************************/
Patron::Patron()
{
	idNum = "";
	name = "";
}



/*********************************************************************
** Description: Constructor for the Patron class. Sets idNum to first
string parameter and name to the second string parameter.
** Parameters: string id number, string name
*********************************************************************/
Patron::Patron(string idn, string n)
{
	idNum = idn;
	name = n;
}



/*********************************************************************
** Description: Returns idNum
** Parameters: none
*********************************************************************/
string Patron::getIdNum()
{
	return idNum;
}



/*********************************************************************
** Description: Returns name
** Parameters: none
*********************************************************************/
string Patron::getName()
{
	return name;
}



/*********************************************************************
** Description: Returns vector of checkedOutItems
** Parameters: none
*********************************************************************/
vector<LibraryItem*> Patron::getCheckedOutItems()
{
	return checkedOutItems;
}



/*********************************************************************
** Description: Adds item to vector checkedOutItems
** Parameters: LibraryItem pointer to b item
*********************************************************************/
void Patron::addLibraryItem(LibraryItem* b)
{
	checkedOutItems.push_back(b);
}



/*********************************************************************
** Description: Checks checkedOutItems vector for LibraryItem b. If b 
is in vector, b is removed from vector. 
** Parameters: pointer to LibraryItem b
*********************************************************************/
void Patron::removeLibraryItem(LibraryItem* b)
{
	//find position
	int position = 0;
	while(checkedOutItems[position] != b && position <= checkedOutItems.size())
	{
		position++;
	}

	//validate b is in list and remove
	if(checkedOutItems[position] == b)
	{
		checkedOutItems.erase(checkedOutItems.begin() + position);
	}
}



/*********************************************************************
** Description: Returns fineAmount
** Parameters: none
*********************************************************************/
double Patron::getFineAmount()
{
	return fineAmount;
}



/*********************************************************************
** Description: Updates fine amount by adding amount parameter to 
fineAmount.  A positive amount adds to fine while a negative amount
reduces fine.
** Parameters: double amount
*********************************************************************/
void Patron::amendFine(double amount)
{
	fineAmount += amount;
}