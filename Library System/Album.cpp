/*********************************************************************
** artist: L. Herrick
** Date: 3/10/15
** Description: Implementation file for the Album class
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Album.hpp"
#include "LibraryItem.hpp"

using namespace std;

/*********************************************************************
** Description: Default constructor for Album class.  Sets idCode, 
title, and artist to empty strings, checkedOutBy and requestedBy to 
NULL, and location to ON_SHELF.
** Parameters: none
*********************************************************************/
Album::Album()
{
	idCode = "";
	title = "";
	artist = "";

	//checkedOutBy = NULL;
	setCheckedOutBy(NULL);
	//requestedBy = NULL;
	setRequestedBy(NULL);
	setLocation(ON_SHELF);
}


/*********************************************************************
** Description: Takes three strings and sets the first to be the item's
id code, the second to be the title of the item, and the third to 
artist.  Sets checkedOutBy and requestedBy to NULL and the location 
to ON_SHELF.
** Parameters: string id code, string title, string artist
*********************************************************************/
Album::Album(string idc, string t, string a)
{
	this->setIdCode(idc);
	this->setTitle(t);
	artist = a;

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
int Album::getCheckOutLength() const
{
	return CHECK_OUT_LENGTH;
}



/*********************************************************************
** Description: Returns artist
** Parameters: none
*********************************************************************/
string Album::getOther() const
{
	return artist;
}



/*********************************************************************
** Description: Returns isAlbum
** Parameters: none
*********************************************************************/
bool Album::getIsAlbum() const
{
	return true;
}



/*********************************************************************
** Description: Returns isBook
** Parameters: none
*********************************************************************/
bool Album::getIsBook()const 
{
	return false;
}



/*********************************************************************
** Description: Returns isMovie
** Parameters: none
*********************************************************************/
bool Album::getIsMovie() const
{
	return false;
}



/*********************************************************************
** Description: Returns isMovie
** Parameters: none
*********************************************************************/
void Album::setArtist(string a)
{
	artist = a;
}


