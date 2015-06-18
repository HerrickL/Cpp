/*********************************************************************
** Author: L. Herrick
** Date: 2/25/15
** Description:  Implementation file for RegularProject class
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "CustomerProject.hpp"
#include "RegularProject.hpp"

/*********************************************************************
** Description: RegularProject constructor, empty.  Uses base class
constructor.
** Parameters: double hours, double material cost, double transportation
cost
*********************************************************************/
RegularProject::RegularProject(double hours, double materials, double transportation) : CustomerProject(hours, materials, transportation)
{	
}


/*********************************************************************
** Description: Override function for base class BillAmount.  Returns
the sum of hours time 80, materials, and transportation.
** Parameters: none.
*********************************************************************/
double RegularProject::billAmount()const
{
	return ((this->getHours()*80)+(this->getMaterials())+(this->getTransportation()));
}