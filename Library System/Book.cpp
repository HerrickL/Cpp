/*********************************************************************
** Author: L. Herrick
** Date: 3/10/15
** Description: Implementation file for the Book class
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Book.hpp"

using namespace std;



/*********************************************************************
** Description: Default constructor for Book class.  Sets idCode, 
title, and author to empty strings, checkedOutBy and requestedBy to 
NULL, and location to ON_SHELF.
** Parameters: none
*********************************************************************/
Book::Book()
{
	this->idCode = "";
	this->title = "";
	this->author = "";

	//checkedOutBy = NULL;
	setCheckedOutBy(NULL);
	//requestedBy = NULL;
	setRequestedBy(NULL);
	setLocation(ON_SHELF);
}


/*********************************************************************
** Description: Takes three strings and sets the first to be the item's
id code, the second to be the title of the item, and the third to 
author.  Sets checkedOutBy and requestedBy to NULL and the location 
to ON_SHELF.
** Parameters: string id code, string title, string author
*********************************************************************/
Book::Book(string idc, string t, string a)
{
	this->setIdCode(idc);
	this->setTitle(t);
	author = a;

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
int Book::getCheckOutLength() const
{
	return CHECK_OUT_LENGTH;
}



/*********************************************************************
** Description: Returns author
** Parameters: none
*********************************************************************/
string Book::getOther() const
{
	return author;
}



/*********************************************************************
** Description: Returns isAlbum
** Parameters: none
*********************************************************************/
bool Book::getIsAlbum() const
{
	return false;
}



/*********************************************************************
** Description: Returns isBook
** Parameters: none
*********************************************************************/
bool Book::getIsBook() const
{
	return true;
}



/*********************************************************************
** Description: Returns isMovie
** Parameters: none
*********************************************************************/
bool Book::getIsMovie() const
{
	return false;
}
