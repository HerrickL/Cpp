/*********************************************************************
** Author: L. Herrick
** Date: 2/25/15
** Description:  Header file for RegularProject class
*********************************************************************/
#ifndef REGULARPROJECT_HPP
#define REGULARPROJECT_HPP
#include "CustomerProject.hpp"

class RegularProject : public CustomerProject
{
public:
	RegularProject(double, double, double);
	double billAmount()const;

};
#endif
