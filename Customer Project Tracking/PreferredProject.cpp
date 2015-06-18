/*********************************************************************
** Author: L. Herrick
** Date: 2/25/15
** Description:  Implenation file for the PreferredProject class
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "CustomerProject.hpp"
#include "PreferredProject.hpp"

/*********************************************************************
** Description: PreferredProject constructor, empty.  Uses base class
constructor.
** Parameters: double hours, double material cost, double transportation
cost
*********************************************************************/
PreferredProject::PreferredProject(double hours, double materials, double transportation): CustomerProject(hours, materials, transportation)
{
}



/*********************************************************************
** Description: Override function for billAmount.  Returns the sum of
hours (up to the max of 100) times 80, 85% materials, and 90% 
transportation.
** Parameters: none
*********************************************************************/
double PreferredProject::billAmount()const
{
	if(this->getHours() < 100)
	{
		return ((this->getHours()*80)+(this->getMaterials()*.85)+(this->getTransportation()*.90));
	}
	else
	{
		return ((100*80)+(this->getMaterials()*.85)+(this->getTransportation()*.90));
	}
}