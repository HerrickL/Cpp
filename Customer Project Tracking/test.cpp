/*********************************************************************
** Author: L. Herrick
** Date: 2/25/15
** Description:  Uses the inheritance heirarchy, starting with 
CustomerProject and continuing with the derived classes RegularProject
and PreferredProject.  Asks the user how many hours, materials cost,
and transportation cost were put into the project.  Asks user if the
project was regular or preferred.  Based off of user input, creats an
object and prints to the console the bill amount total from that 
project.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "CustomerProject.hpp"
#include "RegularProject.hpp"
#include "PreferredProject.hpp"

using namespace std;

int main()
{
	//user input variables
	double userHours;
	double userMaterials;
	double userTransportation;
	string userProjectSelection;
	CustomerProject *pCustProj;

	cout << "How many hours were put into the project: ";
	cin >> userHours;

	cout << "How much were materials: $";
	cin >> userMaterials;

	cout << "How much was transportation: $";
	cin >> userTransportation;

	cout << "Which type of project was it?" << endl;
	cout << "Enter 'regular' or 'preferred': ";
	cin.ignore(1, '\n');
	getline(cin, userProjectSelection);

	//validate user selection
	while(userProjectSelection != "regular" && userProjectSelection != "preferred")
	{
		string temp = userProjectSelection;

		//check if it's a case sensitive issue
		for(int x = 0; x < userProjectSelection.size(); x++)
		{
			temp[x] = tolower(userProjectSelection[x]);
		}

		//if it matches, exit loop.  else get new input and try again.
		if(temp == "regular" || temp == "preferred")
		{
			userProjectSelection = temp;
		}
		else
		{
			cout << "Error: Please enter 'regular' or 'preferred': ";
			getline(cin, userProjectSelection);
		}
	}

	//regular project
	if(userProjectSelection == "regular")
	{
		//dynamically allocate memory
		pCustProj = new RegularProject(userHours,userMaterials,userTransportation);
		
		//print bill amount
		cout << "Total for regular project: $" << fixed << setprecision(2) 
		<< showpoint << pCustProj->billAmount() << endl;
		
		//free up memory
		delete pCustProj;
		pCustProj = NULL;
	}
	//preferred project
	else
	{
		//dynamically allocate memory
		pCustProj = new PreferredProject(userHours,userMaterials,userTransportation);
		
		//print bill amount
		cout << "Total for preferred project: $" << fixed << setprecision(2) 
		<< showpoint << pCustProj->billAmount() << endl;
		
		//free up memory
		delete pCustProj;
		pCustProj = NULL;
	}

	return 0;
}

