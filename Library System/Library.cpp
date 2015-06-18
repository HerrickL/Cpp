/*********************************************************************
** Author: L. Herrick
** Date: 3/10/15
** Description: Implementation file for the Library class
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>
#include "Library.hpp"
#include "LibraryItem.hpp"
#include "Patron.hpp"

using namespace std;


/*********************************************************************
** Description: Constructor for the Library class. Sets currentDate to
0.
** Parameters: none
*********************************************************************/
Library::Library()
{
	currentDate = 0;
}



/*********************************************************************
** Description: Destrictor for the Library class.
** Parameters: none
*********************************************************************/
Library::~Library()
{
	//delete LibraryItems objects
	for(int pos = 0; pos < holdings.size(); pos++)
	{
		delete holdings[pos];
	}

	//delete Patron objects
	for(int pos = 0; pos < members.size(); pos++)
	{
		delete members[pos];
	}

}



/*********************************************************************
** Description: Takes a pointer to an item and adds it to the holdings
vector in the Library class.
** Parameters: pointer to an LibraryItem item
*********************************************************************/
void Library::addLibraryItem(LibraryItem *item)
{
	//add item to library holdings vector
	holdings.push_back(item);
}



/*********************************************************************
** Description: Takes a pointer to a Patron and adds it to the members
vector in the Libary class.
** Parameters: pointer to a Patron member
*********************************************************************/
void Library::addMember(Patron *person)
{
	//add member to library members vector
	members.push_back(person);
}



/*********************************************************************
** Description: Checks if both item and user ids are in the system.
Prints errors if they are not.  Checks if item is currently in and not
on hold by another member.  Prints error messages if it is not. Assigns
checked out information of the item to the requesting member.
** Parameters: string Patron member id and string LibraryItem item id
*********************************************************************/
void Library::checkOutLibraryItem(string patronID, string ItemID)
{
	//flag to trigger errors
	bool noError = true;

	//Is LibraryItem id in the system?
	LibraryItem* thisIsTheItem;

	for(int pos = 0; pos < holdings.size(); pos++)
	{
		noError = false;
		thisIsTheItem = holdings[pos];

		//found it, noError, remember item location, exit loop
		if(thisIsTheItem->getIdCode() == ItemID)
		{
			noError = true;
			pos = holdings.size() + 1;
		}
	}
	//yes, the item is in the system
	if(noError)
	{	
		//Is Patron id in the system?
		Patron* thisIsThePatron;

		for(int pos = 0; pos < this->members.size(); pos++)
		{
			noError = false;
			thisIsThePatron = members[pos];

			//found it, noError, remember member location, exit loop
			if(thisIsThePatron->getIdNum() == patronID)
			{
				noError = true;
				pos = members.size() + 1;
			}
		}
		//yes, they are registered to the system
		if(noError)
		{	
			//Is the LibraryItem not checked out?
			if(thisIsTheItem->getLocation() != CHECKED_OUT)
			{
				//Is the LibraryItem not on hold or on hold by this patron?
				if(thisIsTheItem->getLocation() != ON_HOLD_SHELF || 
					thisIsTheItem->getRequestedBy() == thisIsThePatron)
				{	
					//update checked out info
					thisIsTheItem->setCheckedOutBy(thisIsThePatron);
					thisIsTheItem->setDateCheckedOut(currentDate);
					thisIsTheItem->setLocation(CHECKED_OUT);

					thisIsThePatron->addLibraryItem(thisIsTheItem);
	
						//if on hold by patron
						if(thisIsTheItem->getRequestedBy() == thisIsThePatron)		
						{
							//LibraryItem setRequestedBy()
							thisIsTheItem->setRequestedBy(NULL);	
						}

						//print out that LibraryItem title has been checked out to Patron name
						cout << "A copy of \"" << thisIsTheItem->getTitle() << "\" has been checked out to ";
						cout << thisIsThePatron->getName() << "." << endl;
				}
				//no, not available (on hold)
				else
				{
					//print on hold error message and end
					cout << "Error: This item is currently on hold for someone else." << endl;
				}
			}
			//no, not available (checked out)
			else
			{
				//print checked out error message and end
				cout << "Error: This item is currently checked out to someone else." << endl;
			}
		}
		//no, person not registered to us
		else
		{
			//print not Patron error message and end
			cout << "Error: Your id is not in the system." << endl;
		}
	}
	//no, item not registered to us
	else
	{
		//print not LibraryItem error message and end	
		cout << "Error: This item is not registered to our system." << endl;
	}
}



/*********************************************************************
** Description: Checks if item is checked out.  If it isn't, prints 
error message.  If it is, checks item back in and updates system.
** Parameters: string ItemID
*********************************************************************/
void Library::returnLibraryItem(string ItemID)
{
	//flag to trigger errors
	bool noError = true;

	//Is LibraryItem id in the system?
	LibraryItem* thisIsTheItem;

	for(int pos = 0; pos < holdings.size(); pos++)
	{
		noError = false;
		thisIsTheItem = holdings[pos];

		//found it, noError, remember item location, exit loop
		if(thisIsTheItem->getIdCode() == ItemID)
		{
			noError = true;
			pos = holdings.size() + 1;
		}
	}
	//yes, the item is in the system
	if(noError)
	{
		//Is the library item checked out?
		if(thisIsTheItem->getLocation() == CHECKED_OUT)
		{			
			//update Patron's info
			Patron* thisIsThePatron = thisIsTheItem->getCheckedOutBy();
			thisIsThePatron->removeLibraryItem(thisIsTheItem);

			//update item's info
			if(thisIsTheItem->getRequestedBy() == NULL)
			{
				thisIsTheItem->setLocation(ON_SHELF);
			}
			else
			{
				thisIsTheItem->setLocation(ON_HOLD_SHELF);
			}

			thisIsTheItem->setCheckedOutBy(NULL);
			thisIsTheItem->setDateCheckedOut(NULL);

			//print out that LibraryItem title has been returned
			cout << "\"" << thisIsTheItem->getTitle() << "\" was returned by ";
			cout << thisIsThePatron->getName() << "." << endl;
		}
		//no, not checked out
		else	
		{
			//print not checked out error message
			cout << "Error: This item is not currently checked out." << endl;
		}
	}	
	//no, not in system
	else
	{
		//print not in system error message
		cout << "Error: This item is not registered to our system." << endl;
	}
}



/*********************************************************************
** Description: Checks if patron and item are in the library system.
If not, prints out proper error message.  Checks if the item is 
available to be put on hold.  If not prints out a proper error 
message. Updates system as needed to mark that item as on hold by
that patron. 
** Parameters: string patron's id and string item's id
*********************************************************************/
void Library::requestLibraryItem(string patronID, string ItemID)
{
	//flag to trigger errors
	bool noError = true;

	//Is patron's id in the system?
	Patron* thisIsThePatron;

	for(int pos = 0; pos < this->members.size(); pos++)
	{
		noError = false;
		thisIsThePatron = members[pos];

		//found it, noError, remember member location, exit loop
		if(thisIsThePatron->getIdNum() == patronID)
		{
			noError = true;
			pos = members.size() + 1;
		}
	}
	//yes, they are in the system
	if(noError)
	{
		//Is the requested item in the system?
		LibraryItem* thisIsTheItem;

		for(int pos = 0; pos < holdings.size(); pos++)
		{
			noError = false;
			thisIsTheItem = holdings[pos];

			//found it, noError, remember item location, exit loop
			if(thisIsTheItem->getIdCode() == ItemID)
			{
				noError = true;
				pos = holdings.size() + 1;
			}
		}
		//yes, the item is in the system
		if(noError)
		{
			//Is the item not already requested by someone else?
			if(thisIsTheItem->getRequestedBy() == NULL)
			{
				//Is item not currently checked out by this patron?
				if(thisIsTheItem->getCheckedOutBy() != thisIsThePatron)
				{	
					//update LibraryItem's requestedBy
					thisIsTheItem->setRequestedBy(thisIsThePatron);

					//if the item is on the shelf, change location to on hold
					if(thisIsTheItem->getLocation() == ON_SHELF)
					{
						thisIsTheItem->setLocation(ON_HOLD_SHELF);
					}

					//print LibraryItem title is on request for Patron name
					cout << "A copy of \"" << thisIsTheItem->getTitle() << "\" is now on ";
					cout << "hold for " << thisIsThePatron->getName() << "." << endl;
				}
				//no, this patron has the item checked out that they are requesting
				else
				{
					//print you have this item 
					cout << "Error: This item is already checked out by you." << endl;
				}
			}
			//no, it's already on hold by someone else
			else
			{
				//print already on hold error message
				cout << "Error: That item is already requested by someone else." << endl;
			}
		}
		//no, item is not in the system
		else
		{
			//print not in system error message
			cout << "Error: This item is not registered to our system." << endl;
		}
	}
	//no, person not in system
	else
	{
		//print patron not in system error message
		cout << "Error: Your id is not in the system." << endl;
	}
}



/*********************************************************************
** Description: Increments current date. Increases patron fines by 10 
cents for each overdue item that is checked out.
** Parameters: none
*********************************************************************/
void Library::incrementCurrentDate()
{
	//increment current date
	currentDate += 1;

	//increase each Patron's fines by 10cents for each overdue item
	Patron* thisIsThePatron;
	LibraryItem* thisIsTheItem;

	//iterate through each patron, 
	for(int memberX = 0; memberX < this->members.size(); memberX++)
	{
		thisIsThePatron = members[memberX];

		//iterate through each item the patron has checked out
		for(int itemX = 0; itemX < (thisIsThePatron->getCheckedOutItems()).size(); itemX++)
		{
			thisIsTheItem = thisIsThePatron->getCheckedOutItems()[itemX];

			//is anything overdue? (Check out day + check out length)
			if(currentDate - thisIsTheItem->getDateCheckedOut() >= thisIsTheItem->getCheckOutLength() + 1)
			{
				thisIsThePatron->amendFine(0.10);
			}
		}
	}
}



/*********************************************************************
** Description: Checks if patron is in the system.  If not, prints 
out error message. If they are, applies money to fine and prints out
updated fine amount for that patron.
** Parameters: string patron's id and double payment amount
*********************************************************************/
void Library::payFine(string patronID, double payment)
{
	//flag to trigger errors
	bool noError = true;

	//Is patron's id in the system?
	Patron* thisIsThePatron;

	for(int pos = 0; pos < this->members.size(); pos++)
	{
		noError = false;
		thisIsThePatron = members[pos];

		//found it, noError, remember member location, exit loop
		if(thisIsThePatron->getIdNum() == patronID)
		{
			noError = true;
			pos = members.size() + 1;
		}
	}
	//yes, they are in the system
	if(noError)
	{
		//update the Patron's fine
		double paid = 0 - payment;
		thisIsThePatron->amendFine(paid);

		//print out that the fines for Patron name are now Patron fineAmount
		cout << "The fines for " << thisIsThePatron->getName() << " are now: $";
		cout << fixed << setprecision(2) << showpoint << thisIsThePatron->getFineAmount();
		cout << endl;
	}
	//no, patron is not in system
	else
	{
		//print out patron not in system error message
		cout << "Error: Your id is not in the system." << endl;
	}
}



/*********************************************************************
** Description: Checks if patron is in the system. If not, prints out
error message. If they are, prints ID, name, titles checked out, 
and current fines.
** Parameters: string patron id
*********************************************************************/
void Library::viewPatronInfo(string patronID)
{
	//flag to trigger errors
	bool noError = true;

	//Is patron's id in the system?
	Patron* thisIsThePatron;

	//space for readibility
	cout << endl;

	for(int pos = 0; pos < this->members.size(); pos++)
	{
		noError = false;
		thisIsThePatron = members[pos];

		//found it, noError, remember member location, exit loop
		if(thisIsThePatron->getIdNum()== patronID)
		{
			noError = true;
			pos = members.size();
		}
	}
	//yes, they are in the system
	if(noError)
	{
		//print the Patron's ID, name, the titles of any checked out LibraryItems, 
		//and their current fines
		cout << "ID: " << thisIsThePatron->getIdNum() << endl;

		cout << "Name: " << thisIsThePatron->getName() << endl;
		
		cout << "Items Currently Checked Out: ";

		for(int itemX = 0; itemX < (thisIsThePatron->getCheckedOutItems()).size(); itemX++)
		{
			if(itemX != (thisIsThePatron->getCheckedOutItems()).size())
			{
				cout << thisIsThePatron->getCheckedOutItems()[itemX]->getTitle() << ", ";
			}
			else
			{
				cout << thisIsThePatron->getCheckedOutItems()[itemX]->getTitle() << "."; 
			}

		}
		cout << endl;

		cout << "Current Fines: $" << fixed << setprecision(2) << showpoint << thisIsThePatron->getFineAmount();
		cout << endl;

	}
	//no, patron is not in system
	else
	{
		//print out patron not in system error message
		cout << "Error: Your id is not in the system." << endl;
	}
}



/*********************************************************************
** Description: Checks if item is in the system. If it isn't, prints 
an error message. If it is, prints: id, title, author/artist/director,
who requested it (if applicable), who checked it out and how much 
longer until it is overdue (if applicable).
** Parameters: string item id
*********************************************************************/
void Library::viewItemInfo(string ItemID)
{
	//flag to trigger errors
	bool noError = true;

	//space for readibility
	cout << endl;

	//Is LibraryItem id in the system?
	LibraryItem* thisIsTheItem;

	for(int pos = 0; pos < holdings.size(); pos++)
	{
		noError = false;
		thisIsTheItem = holdings[pos];

		//found it, noError, remember item location, exit loop
		if(thisIsTheItem->getIdCode() == ItemID)
		{
			noError = true;
			pos = holdings.size();
		}
	}
	//yes, the item is in the system
	if(noError)
	{
		//print item id
		cout << "ID: " << thisIsTheItem->getIdCode() << endl;

		//print item title
		cout << "Title: " << thisIsTheItem->getTitle() << endl;

		//print author, artist, or director
		if(thisIsTheItem->getIsBook() == true)
		{
			cout << "Author: " << thisIsTheItem->getOther() << endl;
		} 
		else if(thisIsTheItem->getIsAlbum() == true)
		{
			cout << "Artist: " << thisIsTheItem->getOther() << endl;
		}
		else if(thisIsTheItem->getIsMovie() == true)
		{
			cout << "Director: " << thisIsTheItem->getOther() << endl;
		}

		//print item location
		cout << "Location: "; 
		if(thisIsTheItem->getLocation() == ON_SHELF)
		{
			cout << "On Shelf";
		}
		if(thisIsTheItem->getLocation() == ON_HOLD_SHELF)
		{
			cout << "On Hold Shelf";
		}
		else if (thisIsTheItem->getLocation() == CHECKED_OUT)
		{
			cout << "Checked Out";
		}
		cout << endl;

		//if applicable, print who has requested this item
		cout << "Requested By: ";
		if(thisIsTheItem->getRequestedBy())
		{
			Patron* thisIsThePatron = thisIsTheItem->getRequestedBy();

			cout << thisIsThePatron->getName();
		}
		cout << endl;

		//if applicable, print checked out info
		cout << "Checked Out By: ";
		if(thisIsTheItem->getCheckedOutBy())
		{
			//print the patron who check this item out
			Patron* thisIsThePatron = thisIsTheItem->getCheckedOutBy();
			cout << thisIsThePatron->getName() << endl;

			//print the days until item is overdue or "overdue"
			cout << "Days Until Overdue: ";

			//due date (days allowed from today - check out day is day 0)
			int dueDay = thisIsTheItem->getCheckOutLength() + thisIsTheItem->getDateCheckedOut() + 1;
			
			//overdue message (due date + 1)
			if(dueDay + 1 > this->getCurDate())
			{

				cout << dueDay - getCurDate() << endl;

			}
			else
			{
				cout << "Overdue";
			}
		}
		cout << endl;
	}
	//no, item is not in system
	else
	{
		//print out item not in system error message
		cout << "Error: This item is not registered to our system." << endl;
	}
}



/*********************************************************************
** Description: Returns true if string id perfectly matches another id
in the holdings vector.
** Parameters: string id to compare
*********************************************************************/
bool Library::itemIdCheck(string ItemID)
{
	for(int itemX = 0; itemX < this->holdings.size(); itemX++)
	{
		if(holdings[itemX]->getIdCode() == ItemID)
		{
			return true;
		}
	}

	return false;
}



/*********************************************************************
** Description: Returns true if string id perfectly matches another id
in the members vector.
** Parameters: string id to compare
*********************************************************************/
bool Library::patronIdCheck(string PatronID)
{
	for(int memberX = 0; memberX < this->members.size(); memberX++)
	{
		if(members[memberX]->getIdNum() == PatronID)
		{
			return true;
		}
	}

	return false;
}



/*********************************************************************
** Description: Returns current date
** Parameters: none
*********************************************************************/
int Library::getCurDate()
{
	return currentDate;
}