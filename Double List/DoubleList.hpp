/*********************************************************************
** Author: L. Herrick
** Date: 3/04/15
** Description:  Header file for DoubleList class. Build of ListNode
and ideas for class taken from example on pages 1027-1028 of C++ Early
 Objects by Gaddis et al.
*********************************************************************/
#ifndef DOUBLELIST_HPP
#define DOUBLELIST_HPP
#include <iostream>
using namespace std;

class DoubleList
{
protected:
	struct ListNode
	{
		double value;
		ListNode *next;
		ListNode(double value1, ListNode *next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	ListNode *head;

public:
	DoubleList() {head = NULL;}
	~DoubleList();
	DoubleList(const DoubleList&);
	void add(double);
	bool isMember(double);
	void remove(double number);
	void recPrint()const;
	void recPrint(ListNode* )const;
	void nodeSwap(int, int);

};
#endif