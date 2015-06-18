

#ifndef LIBRARY_ITEM_HPP
#define LIBRARY_ITEM_HPP

#include <string>


class Patron;


// These three locations are mutually exclusive, but note that
// a LibraryItem can be on request for a Patron while being checked
// out to another Patron.  In that case the LibraryItem's location is
// CHECKED_OUT, and when it is returned, it's location will
// become ON_HOLD_SHELF.
enum Locale {ON_SHELF, ON_HOLD_SHELF, CHECKED_OUT};

using namespace std;

class LibraryItem
{
private:
    string idCode;
    string title;
    Locale location;
    Patron* checkedOutBy;
    Patron* requestedBy;
    int dateCheckedOut;
public:
    LibraryItem();
    LibraryItem(string idc, string t);
    virtual int getCheckOutLength() const = 0;
    void setIdCode(string idc);
    void setTitle(string t);
    string getIdCode();
    string getTitle();
    Locale getLocation();
    void setLocation(Locale lo);
    Patron* getCheckedOutBy();
    void setCheckedOutBy(Patron* p);
    Patron* getRequestedBy();
    void setRequestedBy(Patron* p);
    int getDateCheckedOut();
    void setDateCheckedOut(int d);
    virtual bool getIsBook() const = 0;
    virtual bool getIsAlbum() const = 0;
    virtual bool getIsMovie() const = 0;
    virtual string getOther() const = 0;
};


#endif