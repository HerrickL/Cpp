/*********************************************************************
** Author: L. Herrick
** Date: 3/11/15
** Description: Implementation file for the LibraryItem class
*********************************************************************/
#include <string>
#include <iostream>
#include <cstdlib>
#include "LibraryItem.hpp"
#include "Patron.hpp"

using namespace std;



/*********************************************************************
** Description: Default constructor that sets idCode and title to 
empty strings, checkedOutBy and requestedBy to NULL, and location to
ON_SHELF
** Parameters: none
*********************************************************************/
LibraryItem::LibraryItem()
{
	idCode = "";
	title = "";
	//checkedOutBy = NULL;
	setCheckedOutBy(NULL);
	//requestedBy = NULL;
	setRequestedBy(NULL);
	setLocation(ON_SHELF);
}



/*********************************************************************
** Description: Takes two strings and sets the first to be the item's
id code and the second to be the title of the item.  Sets 
checkedOutBy and requestedBy to NULL and the location to ON_SHELF.
** Parameters: string for id code and string for title
*********************************************************************/
LibraryItem::LibraryItem(string idc, string t)
{
	setIdCode(idc);
	setTitle(t);
	//checkedOutBy = NULL;
	setCheckedOutBy(NULL);
	//requestedBy = NULL;
	setRequestedBy(NULL);
	setLocation(ON_SHELF);
}



/*********************************************************************
** Description: Returns Id code
** Parameters: none
*********************************************************************/
void LibraryItem::setIdCode(string idc)
{
	idCode = idc;
}



/*********************************************************************
** Description: Returns Id code
** Parameters: none
*********************************************************************/
void LibraryItem::setTitle(string t)
{
	title = t;
}


/*********************************************************************
** Description: Returns Id code
** Parameters: none
*********************************************************************/
string LibraryItem::getIdCode()
{
	return idCode;
}



/*********************************************************************
** Description: Returns title
** Parameters: none
*********************************************************************/
string LibraryItem::getTitle()
{
	return title;
}



/*********************************************************************
** Description: Returns location
** Parameters: none
*********************************************************************/
Locale LibraryItem::getLocation()
{
	return location;
}



/*********************************************************************
** Description: Sets location to parameter
** Parameters: Locale of location
*********************************************************************/
void LibraryItem::setLocation(Locale lo)
{
	location = lo;
}



/*********************************************************************
** Description: Returns pointer of Patron that is assigned to 
checkedOutBy
** Parameters: none
*********************************************************************/
Patron* LibraryItem::getCheckedOutBy()
{
	return checkedOutBy;
}



/*********************************************************************
** Description: Assigns a pointer to a Patron to checkedOutBy
** Parameters: pointer to Patron
*********************************************************************/
void LibraryItem::setCheckedOutBy(Patron *p)
{
	checkedOutBy = p;
}



/*********************************************************************
** Description: Returns pointer to Patron that is assigned to 
requestedBy
** Parameters: none
*********************************************************************/
Patron* LibraryItem::getRequestedBy()
{
	return requestedBy;
}



/*********************************************************************
** Description: Assigns a pointer to a Patron to requestedBy
** Parameters: pointer to a Patron
*********************************************************************/
void LibraryItem::setRequestedBy(Patron *p)
{
	requestedBy = p;
}



/*********************************************************************
** Description: Returns dateCheckedOut
** Parameters: none
*********************************************************************/
int LibraryItem::getDateCheckedOut()
{
	return dateCheckedOut;
}



/*********************************************************************
** Description: Sets dateCheckedOut to paramater int d
** Parameters: int d
*********************************************************************/
void LibraryItem::setDateCheckedOut(int d)
{
	dateCheckedOut = d;
}