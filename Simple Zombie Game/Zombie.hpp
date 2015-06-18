/*********************************************************************
** Author: L. Herrick
** Date: 2/18/15
** Description:  Header file for the Zombie class.
*********************************************************************/
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

class Zombie
{
public:
	Zombie();
	~Zombie();
	void speak();
	int getZombieCounter();

private:
	static int zombieCounter;

};
#endif