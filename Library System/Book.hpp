/*********************************************************************
** Author: L. Herrick
** Date: 3/10/15
** Description: Interface file for the Book class
*********************************************************************/
#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include "LibraryItem.hpp"

using namespace std;

class Book : public LibraryItem 
{
private:
    string idCode;
    string title;
	string author;

public:
	static const int CHECK_OUT_LENGTH = 21;

	Book();
	Book(string idc, string t, string o);
	int getCheckOutLength() const;
	string getOther() const;
	bool getIsBook() const;
	bool getIsAlbum() const;
	bool getIsMovie() const;
};
#endif