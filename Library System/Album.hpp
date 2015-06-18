/*********************************************************************
** Author: L. Herrick
** Date: 3/10/15
** Description: Interface file for the Album class
*********************************************************************/
#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>
#include "LibraryItem.hpp"

using namespace std;

class Album : public LibraryItem
{
private:
	string idCode;
    string title;
	string artist;

public:
	static const int CHECK_OUT_LENGTH = 14;

	Album();
	Album(string idc, string t, string a);
	void setArtist(string a);
	int getCheckOutLength() const;
	string getOther() const;
	bool getIsBook() const;
	bool getIsAlbum() const;
	bool getIsMovie() const;
};
#endif