/*********************************************************************
** Author: L. Herrick
** Date: 2/25/15
** Description: Header file for Fraction class
*********************************************************************/
#ifndef FRACTION_HPP
#define	FRACTION_HPP

using namespace std;

class Fraction
{
public:
	Fraction(int, int);
	void setNumerator(int);
	void setDenominator(int);
	int getNumerator()const;
	int getDenominator()const;

	//overloaded arithmatic operators
	const Fraction operator*(const Fraction &);
	const Fraction operator/(const Fraction &);

	//overloaded stream output operator
	friend ostream &operator<<(ostream &out, Fraction obj);

private:
	int numerator;
	int denominator;
};
#endif