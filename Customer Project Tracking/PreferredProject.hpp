/*********************************************************************
** Author: L. Herrick
** Date: 2/25/15
** Description: Header file for PreferredProject class
*********************************************************************/
#ifndef PREFERREDPROJECT_HPP
#define PREFERREDPROJECT_HPP
#include "CustomerProject.hpp"

class PreferredProject : public CustomerProject
{
public:
	PreferredProject(double, double, double);
	double billAmount()const;
};
#endif
