/*********************************************************************
** Author: L. Herrick
** Date: 3/11/15
** Description:
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Library.hpp"
#include "Patron.hpp"
#include "LibraryItem.hpp"
#include "Movie.hpp"
#include "Album.hpp"
#include "Book.hpp"

using namespace std;

//prototype
void printMenu();

int main()
{
	//user input variables and library
	string menuInput = "";
	int itemCounter = 0;
	int memberCounter = 0;
	Library* userLibrary = new Library();

	//print menu options
	printMenu();

	//menu loop: when user enters space, loop quits
	while(menuInput != " ")
	{
		//get user's menu input
		cout << "Make a menu selection (enter only a number or space): ";
		getline(cin, menuInput);

		//add item to the library
		if(menuInput == "1")
		{
			string userInput, idc, title, other;

			//verify which type of item to add
			cout << "Enter 'book', 'album', or 'movie': ";
			getline(cin, userInput);

			//validate selection
			while(userInput != "book" && userInput != "album" && userInput != "movie")
			{
				cout << "Error: Your input does not match any selection option." << endl;
				cout << "Please enter only the lowercase word 'book', 'album', or 'movie': ";
				getline(cin, userInput);
			}

			//get info for new item
			if(userInput == "book")
			{
				bool notUnique = true;

				//get and validate idc is unique
				while(notUnique)
				{
					cout << "Enter A Unique Id: ";
					getline(cin, idc);
					
					if(itemCounter > 0)
					{
						//check system for matching id
						notUnique = userLibrary->itemIdCheck(idc);

						if(notUnique)
						{
							cout << "Error: This Id is not unique." << endl;
						}
						
					}
					else
					{
						notUnique = false;
					}
				}

				//title
				cout << "Enter The Item's Title: ";
				getline(cin, title);

				//author
				cout << "Enter The Item's Author: ";
				getline(cin, other);

				//create new item and add to library, increment items counter
				LibraryItem* newItem = new Book(idc, title, other);

				userLibrary->addLibraryItem(newItem);

				itemCounter += 1;

			}
			else if(userInput == "album")
			{
				bool notUnique = true;

				//get and validate idc is unique
				while(notUnique)
				{
					cout << "Enter A Unique Id: ";
					getline(cin, idc);

					if(itemCounter > 0)
					{
						//check system for matching id
						notUnique = userLibrary->itemIdCheck(idc);

						cout << "Error: This Id is not unique." << endl;
					}
					else
					{
						notUnique = false;
					}
				}

				//title
				cout << "Enter The Item's Title: ";
				getline(cin, title);

				//author
				cout << "Enter The Item's Artist: ";
				getline(cin, other);

				//create new item and add to library, increment items counter
				LibraryItem* newItem = new Album(idc, title, other);

				userLibrary->addLibraryItem(newItem);

				itemCounter += 1;
			}
			else if(userInput == "movie")
			{
				bool notUnique = true;

				//get and validate idc is unique
				while(notUnique)
				{
					cout << "Enter A Unique Id: ";
					getline(cin, idc);

					if(itemCounter > 0)
					{
						//check system for matching id
						notUnique = userLibrary->itemIdCheck(idc);

						cout << "Error: This Id is not unique." << endl;
					}
					else
					{
						notUnique = false;
					}
				}

				//title
				cout << "Enter The Item's Title: ";
				getline(cin, title);

				//author
				cout << "Enter The Item's Director: ";
				getline(cin, other);

				//create new item and add to library, increment items counter
				LibraryItem* newItem = new Movie(idc, title, other);

				userLibrary->addLibraryItem(newItem);

				itemCounter += 1;
			}

			//space for readibility
			cout << endl;
		}
		//add member to library
		else if(menuInput == "2")
		{
			string idn, name;
			bool notUnique = true;

			//get and validate idc is unique
			while(notUnique)
			{
				cout << "Enter A Unique Id: ";
				getline(cin, idn);

				if(memberCounter > 0)
				{
					//check system for matching id
					notUnique = userLibrary->patronIdCheck(idn);

					if(notUnique)
					{
						cout << "Error: Id is not unique." << endl;
					}
				}
				else
				{
					notUnique = false;
				}
			}

			//title
			cout << "Enter Patron's Name: ";
			getline(cin, name);

			//create a new Patron
			Patron* newPatron = new Patron(idn, name);

			userLibrary->addMember(newPatron);

			memberCounter += 1;

			//space for readibility
			cout << endl;
		}
		//check out item
		else if(menuInput == "3")
		{
			if(itemCounter > 0 && memberCounter > 0)
			{
				string patronID, ItemID;

				cout << "Enter the Patron's Id: ";
				getline(cin, patronID);

				cout << "Enter the Item's Id: ";
				getline(cin, ItemID);

				userLibrary->checkOutLibraryItem(patronID, ItemID);
			}	
			else
			{
				cout <<"Error: There are either no items or no members." << endl;
			}

			//space for readibility
			cout << endl;
		}
		//return item
		else if(menuInput == "4")
		{

			if(itemCounter > 0 && memberCounter > 0)
			{
				string ItemID;

				cout << "Enter the Returning Item's Id: ";
				getline(cin, ItemID);

				userLibrary->returnLibraryItem(ItemID);
			}
			else
			{
				cout <<"Error: There are either no items or no members." << endl;
			}

			//space for readibility
			cout << endl;
		}
		//request item
		else if(menuInput == "5")
		{
			if(itemCounter > 0 && memberCounter > 0)
			{
				string patronID, ItemID;

				cout << "Enter the Patron's Id: ";
				getline(cin, patronID);

				cout << "Enter the Requested Item's Id: ";
				getline(cin, ItemID);

				userLibrary->requestLibraryItem(patronID, ItemID);
			}
			else
			{
				cout <<"Error: There are either no items or no members." << endl;
			}

			//space for readibility
			cout << endl;
		}
		//increment current date
		else if(menuInput == "6")
		{
			userLibrary->incrementCurrentDate();
			cout << "The date has been incremented." << endl;

			cout << endl;	
		}
		//pay fine
		else if(menuInput == "7")
		{
			if(memberCounter > 0)
			{
				string patronID;
				double payment;

				cout << "Enter the Patron's Id: ";
				getline(cin, patronID);

				cout << "Enter the Amount of the Payment: $";
				cin >> payment;

				userLibrary->payFine(patronID, payment);

				//clear stream
				cin.ignore(1, '\n');
			}
			else
			{
				cout <<"Error: There are no members in the system." << endl;
			}
			
			//space for readibility
			cout << endl;
		}
		//view patron info
		else if(menuInput == "8")
		{
			if(memberCounter > 0)
			{
				string patronID;

				cout <<  "Enter the Patron's Id: ";
				getline(cin, patronID);

				userLibrary->viewPatronInfo(patronID);
			}
			else
			{
				cout << "Error: There are no members in the system." << endl;
			}

			//space for readiblity
			cout << endl;
		}
		//view item info
		else if(menuInput == "9")
		{
			if(itemCounter > 0)
			{
				string ItemID;

				cout << "Enter the Item's Id: ";
				getline(cin, ItemID);

				userLibrary->viewItemInfo(ItemID);
			}
			else
			{
				cout << "Error: There are no items in the system." << endl;
			}

			//space for readibility
			cout << endl;
		}
		//print menu
		else if(menuInput == "0")
		{
			printMenu();
		}
		//quit
		else if(menuInput == " ")
		{
			cout << "Quiting..." << endl;
		}
		//not a proper menu selection
		else
		{
			cout << "Error: That does not correspond to a menu option." << endl;
		}
	}

	//delete memory allocated for library object
	delete userLibrary;

	return 0;
}



/*********************************************************************
** Description: Prints menu for library system input options
** Parameters: none
*********************************************************************/
void printMenu()
{
	cout << "MENU OPTIONS" << endl;
	cout << "1. Add Item to Library" << endl;
	cout << "2. Add Member to Library" << endl;
	cout << "3. Check Out Library Item" << endl;
	cout << "4. Return Library Item" << endl;
	cout << "5. Request Library Item" << endl;
	cout << "6. Increment Current Date" << endl;
	cout << "7. Pay Fine" << endl;
	cout << "8. View Patron Info" << endl;
	cout << "9. View Item Info" << endl;
	cout << "0. Print Menu" << endl;
	cout << "Ener a space to quit" << endl;
	cout << endl;
}