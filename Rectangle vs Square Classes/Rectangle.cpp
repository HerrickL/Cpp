/*********************************************************************
** Author: L. Herrick
** Date: 2/18/15
** Description: This file contains the methods for the Rectangle 
class.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "Rectangle.hpp"


/*********************************************************************
** Description: Constructor for Rectangle object.  Takes two doubles
and sets them as the length and width of a rectangle.
** Parameters:  two double nums
*********************************************************************/
Rectangle::Rectangle(double numLength, double numWidth)
{
	setLength(numLength);
	setWidth(numWidth);
}



/*********************************************************************
** Description: Default constructor for Rectangle object.  Sets the 
length and width to 0s. 
** Parameters:  none
*********************************************************************/
Rectangle::Rectangle()
{
	setLength(0);
	setWidth(0);
}



/*********************************************************************
** Description: Sets the length of a rectangle
** Parameters: double num
*********************************************************************/
void Rectangle::setLength(double numLength)
{
	length = numLength;
}



/*********************************************************************
** Description: Sets the width of a rectangle
** Parameters:  double num
*********************************************************************/
void Rectangle::setWidth(double numWidth)
{
	width = numWidth;
}



/*********************************************************************
** Description:  Returns the area of a rectangle
** Parameters:  none
*********************************************************************/
double Rectangle::area()
{
	return length*width;
}



/*********************************************************************
** Description:  Returns the perimeter of a rectangle
** Parameters:  none
*********************************************************************/
double Rectangle::perimeter()
{
	return (length + width + length + width);
}