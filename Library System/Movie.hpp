/*********************************************************************
** Author: L. Herrick
** Date: 3/10/15
** Description: Interface file for the Movie class
*********************************************************************/
#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
#include "LibraryItem.hpp"

using namespace std;

class Movie : public LibraryItem
{
private:
	string idCode;
    string title;
	string director;

public:
	static const int CHECK_OUT_LENGTH = 7;

	Movie();
	Movie(string idc, string t, string d);
	int getCheckOutLength() const; 
	string getOther() const;
	bool getIsBook() const;
	bool getIsAlbum() const;
	bool getIsMovie() const;
};
#endif