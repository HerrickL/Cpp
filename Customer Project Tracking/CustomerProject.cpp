/*********************************************************************
** Author: L. Herrick
** Date: 2/25/15
** Description:  Functions for CustomerProject class
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "CustomerProject.hpp"


/*********************************************************************
** Description: Cunstructor for CustomerProject object.
** Parameters: double hours, double material cost, double
transportation costs.
*********************************************************************/
CustomerProject::CustomerProject(double hours, double materials, double transportation)
{
	setHours(hours);
	setMaterials(materials);
	setTransportation(transportation);
}



/*********************************************************************
** Description: Sets number to class variable hours
** Parameters: double num
*********************************************************************/
void CustomerProject::setHours(double num)
{
	hours = num;
}



/*********************************************************************
** Description: Sets number to class variable materials
** Parameters: double num
*********************************************************************/
void CustomerProject::setMaterials(double num)
{
	materials = num;
}



/*********************************************************************
** Description: Sets num to class variable transportation
** Parameters: double num
*********************************************************************/
void CustomerProject::setTransportation(double num)
{
	transportation = num;
}



/*********************************************************************
** Description: Returns hours
** Parameters: none
*********************************************************************/
double CustomerProject::getHours() const
{
	return hours;
}



/*********************************************************************
** Description: Returns materials
** Parameters: none
*********************************************************************/
double CustomerProject::getMaterials() const
{
	return materials;
}



/*********************************************************************
** Description: Returns transportation
** Parameters: none
*********************************************************************/
double CustomerProject::getTransportation() const
{
	return transportation;
}