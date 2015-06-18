/*********************************************************************
** Author: L. Herrick
** Date: 2/18/15
** Description:  Loops through menu asking the user if they would like
to create a new zombie, destroy a zombie, print the number of existing
zombies, tell all the zombies to speak, or quit.  Based off of user 
selection, the correct action is fulfilled.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Zombie.hpp"

using namespace std;

//definition of static member of Zombie class
int Zombie::zombieCounter = 0;


int main()
{
	//variables for user input
	string menuSelection;
	int leftoverCounter = 0;

	//declare a vector of type Zombie
	vector <Zombie*> zombies;

	//menu selection loop
	while(menuSelection != "5")
	{
		cout << "*********************************************************";
		cout << endl;
		cout << "1. Create a new zombie." << endl;
		cout << "2. Destroy a zombie." << endl;
		cout << "3. Print the number of exisiting zombies." << endl;
		cout << "4. Tell the existing zombies to speak." << endl;
		cout << "5. Quit." << endl;
		cout << endl;

		//user selection
		cout << "Enter the number corresponding to your menu selection: ";
		getline(cin, menuSelection);

		//menu actions
		if (menuSelection == "1")
		{
			//create and add new zombie to zombies vector
			zombies.push_back(new Zombie());
		}
		else if (menuSelection == "2")
		{
			//destroy a zombie
			if(zombies.size() > 0)
			{
				//delete zombie and remove pointer from vector
				delete zombies[zombies.size()-1];
				zombies.pop_back();
			}
			else
			{
				cout << "There are no zombies to kill." << endl;
			}
		}
		else if (menuSelection == "3")
		{
			//print the number of existing zombies
			if(zombies.size() > 0)
			{
				cout << "Number of existing zombies: ";
				cout << zombies[zombies.size()-1]->getZombieCounter() << endl;
			}
			else
			{
				cout << "Number of existing zombies: 0" << endl;
			}

		}
		else if (menuSelection == "4")
		{
			//tell the existing zombies to speak
			if(zombies.size() > 0)
			{
				for(int x = 0; x < zombies.size(); x++)
				{
					zombies[x]->speak();
				}
			}
			else
			{
				cout << "There are no zombies left to speak." << endl;
			}	
		}
		else if (menuSelection == "5")
		{
			//print exit message
			cout << "Exiting..." << endl;
		}
		else
		{
			cout << "Error. Please select a valid menu option." << endl;
		}
	}

	//delete any leftovers in vector
	leftoverCounter = zombies.size();

	//clear object elements
	if(leftoverCounter >= 0)
	{
		for(int x = 0; x < leftoverCounter; leftoverCounter--)
		{
			delete zombies[leftoverCounter-1];
			zombies.pop_back();
		}
	}
	//clear null element
	if(leftoverCounter == 0)
	{
		zombies.pop_back();
	}

	return 0;
}



/*********************************************************************
** Description: Constructor for Zombie object.  Increments the zombie
counter.
** Parameters: none
*********************************************************************/
Zombie::Zombie()
{
	zombieCounter += 1;
}



/*********************************************************************
** Description: Deconstructor for Zombie object.  Decrements the zombie
counter.
** Parameters: none
*********************************************************************/
Zombie::~Zombie()
{
	zombieCounter -= 1;
}



/*********************************************************************
** Description: Has individual zombie say, "Braaaainss!"
** Parameters: none
*********************************************************************/
void Zombie::speak()
{
	cout << "Braaaainss!" << endl;
}



/*********************************************************************
** Description: returns the int of zombieCounter
** Parameters: none
*********************************************************************/
int Zombie::getZombieCounter()
{
	return zombieCounter;
}
