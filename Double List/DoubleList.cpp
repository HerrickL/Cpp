/*********************************************************************
** Author: L. Herrick
** Date: 3/04/15
** Description:  Implementation file of DoubleList class functions.
Functions include a copy constructor that makes a seperate copy of
a linked list, a destructor that deletes memory used by linked list, 
add which adds a new value to the front of a linked list, isMember 
which iterates through a linked list to see if a given value is found
in the list, recPrint which recursively traverses a linked list and
prints all the values, and nodeSwap which takes two given positions, 
locates the nodes in those positions, and swaps the nodes by 
rearranging the points to and from them.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "DoubleList.hpp"

using namespace std;



/*********************************************************************
** Description: Copy constructor for DoubleList class.  Copies list by
 iterating through list and adding each element from list one to the 
 end of new list 2.  Ideas for implimentation of how to make a seperate
 copy of a linked list from example code on pp1056-1057 of C++ Early
 Objects by Gaddis et al.
** Parameters: reference to list to be copied
*********************************************************************/
DoubleList::DoubleList(const DoubleList &list)
{

	ListNode *nodePtr; 
	ListNode *endOfList;

	if(list.head == NULL)
	{
		head = NULL;
	}
	else
	{
		head = new ListNode(list.head->value);
		endOfList = head;

		nodePtr = list.head->next;

		while(nodePtr != NULL)
		{
			endOfList->next = new ListNode(nodePtr->value);
			endOfList = endOfList->next;
			nodePtr = nodePtr->next;
		}

		//end copied list
		endOfList->next = NULL;
	}
}




/*********************************************************************
** Description: Destructor for DoubleList class, deallocates memory
used when adding nodes.
** Parameters: none
*********************************************************************/
DoubleList::~DoubleList()
{
	//start at heade of list
	ListNode *nodePtr = head;
	while (nodePtr != NULL)
	{
		//keep track of what needs to be deleted
		ListNode *discardable = nodePtr;

		//if applicable, move to next node in the list
		nodePtr = nodePtr->next;

		//delete node
		delete discardable;	
	}
}




/*********************************************************************
** Description: Add a new node containing val to the front of the
list.
** Parameters: double value to be added to list
*********************************************************************/
void DoubleList::add(double val)
{
	//list is empty
	if(head == NULL)
	{
		head = new ListNode(val);
	}
	//list is not empty
	else
	{
		//create pointer to new value
		ListNode *nodePtr = new ListNode(val);
		//connect new pointer to head of list
		nodePtr->next = head;
		//reappropriate title "head" of list
		head = nodePtr;
	}
}




/*********************************************************************
** Description: Determines if the value passed into the function
is a value anywhere in the linked list
** Parameters: double value to be searched for in linked list
*********************************************************************/
bool DoubleList::isMember(double val)
{
	//start at the beginning
	ListNode *nodePtr = head;

	//traverse the list
	while(nodePtr != NULL)
	{
		//check if equal
		if((nodePtr->value) - val < .0001)
		{
			return true;
		}
		//move to the next value
		nodePtr = nodePtr->next;
	}

	return false;
}




/*********************************************************************
** Description: Recursively iterates through linked list, printing
each node value of the list.
** Parameters: none
*********************************************************************/
void DoubleList::recPrint()const 
{
	ListNode *nodePtr = head;
	return recPrint(nodePtr);
}




/*********************************************************************
** Description: Helper function for recurive recPrint() function.
Takes a pointer to a node, prints value, and iterates to next node 
based off of parameter node, etc until end of list.
** Parameters: pointer to node
*********************************************************************/
void DoubleList::recPrint(ListNode *nodePtr)const
{
	if(nodePtr)
	{
		cout << nodePtr->value << "   ";
		nodePtr = nodePtr->next;
		recPrint(nodePtr);
	}
}




/*********************************************************************
** Description: Takes two int positions that represent nodes, based 
off of zero-based positions in a linked list. Finds the node values
at those positions and "swaps" them by adjusting pointers in the 
linked list. 
** Parameters: int position 1 and int position 2
*********************************************************************/
void DoubleList::nodeSwap(int pos1, int pos2)
{
	ListNode *tempHolder;
	ListNode *prevPos1 = NULL;
	ListNode *prevPos2 = NULL;

	//start at the beginning
	ListNode *nodePtr1 = head;

	//iterate through list until pos1
	for(int counter = 1; counter < pos1; counter++)
	{
		//remember previous node for connect
		prevPos1 = nodePtr1;

		//iterate
		nodePtr1 = nodePtr1->next;
	}

	//start at the beginning
	ListNode *nodePtr2 = head;

	//iterate through list until pos2
	for(int counter = 1; counter < pos2; counter++)
	{
		//remember previous node for connect
		prevPos2 = nodePtr2;

		//iterate
		nodePtr2 = nodePtr2->next;
	}

	//swap actions
	//attach head if applicable
	if(pos1 == 0)
	{
		head = nodePtr2;
	}
	if(pos2 == 0)
	{
		head = nodePtr1;
	}

	//if there is a prev to pos1, link it to pos2
	if(prevPos1 != NULL)
	{
		prevPos1->next = nodePtr2;
	}

	//if there is a prev to pos2, link it to pos1
	if(prevPos2 != NULL)
	{
		prevPos2->next = nodePtr1;
	}

	//connect swapped nodes to right part of link
	//use temp to not lose nodes during swap
	tempHolder = nodePtr1->next;
	nodePtr1->next = nodePtr2->next;
	nodePtr2->next = tempHolder;
}



