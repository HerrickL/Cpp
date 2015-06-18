/*********************************************************************
** director: L. Herrick
** Date: 3/10/15
** Description: Implementation file for the Movie class
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Movie.hpp"

using namespace std;



/*********************************************************************
** Description: Default constructor for Movie class.  Sets idCode, 
title, and director to empty strings, checkedOutBy and requestedBy to 
NULL, and location to ON_SHELF.
** Parameters: none
*********************************************************************/
Movie::Movie()
{
	idCode = "";
	title = "";
	director = "";

	//checkedOutBy = NULL;
	setCheckedOutBy(NULL);
	//requestedBy = NULL;
	setRequestedBy(NULL);
	setLocation(ON_SHELF);

}


/*********************************************************************
** Description: Takes three strings and sets the first to be the item's
id code, the second to be the title of the item, and the third to 
director.  Sets checkedOutBy and requestedBy to NULL and the location 
to ON_SHELF.
** Parameters: string id code, string title, string director
*********************************************************************/
Movie::Movie(string idc, string t, string d)
{
	this->setIdCode(idc);
	this->setTitle(t);
	director = d;

	//checkedOutBy = NULL;
	this->setCheckedOutBy(NULL);
	//requestedBy = NULL;
	this->setRequestedBy(NULL);
	this->setLocation(ON_SHELF);
}



/*********************************************************************
** Description: Returns CHECK_OUT_LENGTH	
** Parameters: none
*********************************************************************/
int Movie::getCheckOutLength() const
{
	return CHECK_OUT_LENGTH;
}



/*********************************************************************
** Description: Returns director
** Parameters: none
*********************************************************************/
string Movie::getOther() const
{
	return director;
}



/*********************************************************************
** Description: Returns isAlbum
** Parameters: none
*********************************************************************/
bool Movie::getIsAlbum() const
{
	return false;
}



/*********************************************************************
** Description: Returns isBook
** Parameters: none
*********************************************************************/
bool Movie::getIsBook() const
{
	return false;
}



/*********************************************************************
** Description: Returns isMovie
** Parameters: none
*********************************************************************/
bool Movie::getIsMovie() const
{
	return true;
}
