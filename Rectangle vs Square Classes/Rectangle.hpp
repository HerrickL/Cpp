/*********************************************************************
** Author: L. Herrick
** Date: 2/18/15
** Description:  This is the header file for the Rectancgle class.
*********************************************************************/
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include <cstdlib>

class Rectangle
{
public:
	Rectangle(double, double);
	Rectangle();
	void setLength(double);
	void setWidth(double);
	double area();
	double perimeter();

private:
	double length;
	double width;

};
#endif