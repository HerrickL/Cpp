/*********************************************************************
** Author: L. Herrick
** Date: 2/25/15
** Description:  Header file for CustomerProject class
*********************************************************************/
#ifndef CUSTOMERPROJECT_HPP
#define CUSTOMERPROJECT_HPP

class CustomerProject
{
public:
	CustomerProject(double, double, double);
	void setHours(double);
	void setMaterials(double);
	void setTransportation(double);
	double getHours()const;
	double getMaterials()const;
	double getTransportation()const;
	virtual double billAmount() const = 0;

private:
	double hours;
	double materials;
	double transportation;	
};
#endif