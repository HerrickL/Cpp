/*********************************************************************
** Author: L. Herrick
** Date: 2/18/15
** Description:  This is the header file for the Square class.
*********************************************************************/
#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>
#include <cstdlib>
#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
	Square(double side) : Rectangle(side,side){}

private:

};
#endif