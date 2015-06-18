/*********************************************************************
** Author: L. Herrick
** Date: 3/06/15
** Description:  Program evaluates postfix expressions entered by the
user until the user enters a single space, then exits.  Postfix 
expressions need to have spaces bewteen numbers and/or operators.
Only '+', '-', '*', and '/' operators are accepted.  Numbers entered
can only contain digits and cannot contain a decimal point.
Example of proper input: 25 12 7 - 2 * /
Example of output: 25 12 7 - 2 * / = 2.5
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>

using namespace std;

//prototypes
void evaluateExpression(string expression);
void compute(stack <double> &userStack, char sign);


int main()
{

	//variables for user input and flag
	string userExpression;
	bool onlySpaceDetected = false;

	//Rules
	cout << "**************************************************************************";
	cout << endl;
	cout << "Please enter your expression with spaces between numbers " 
	"and/or operators." << endl; 
	cout << "Numbers can only contain digits. Enter only a space to exit." << endl;
		

	//while not space flag
	while (onlySpaceDetected == false)
	{

		//get expression string
		cout << "Enter a postfix expression: ";
		getline(cin, userExpression);
		cout << endl;

		//Read expression, is it only a space?
		if(userExpression == " ")
		{
			//yes, it's a space = end
			cout << "Exiting..." << endl;
			onlySpaceDetected = true;
		}
		else
		{
			//no, it's not a space = evaluate and compute
			try
			{
				evaluateExpression(userExpression);
			}
			catch(string divideByZero)
			{
				cout << divideByZero << endl;
				cout << endl;
			}
		}
	}

	return 0;
}



/*********************************************************************
** Description: Takes a string and iterates through it parsing out 
the numbers and operators.  Adds the numbers to a stack.  Passes
the stack and operators to compute() to do arithmatic.  When the 
stack has only 1 element, that element is printed as the answer
to the postfix expression.
** Parameters: string expression that represent user input postfix
expression
*********************************************************************/
void evaluateExpression(string expression)
{
	//create new stack
	stack< double > userStack;

	//variable to mark position in user string
	int position = 0;

	//variable for single element of string to be compared
	string partOfString;

	//loop, read next element of string, while not end of string
	while(position < expression.size())
	{	

		//single element of string to be compared update
		partOfString = expression[position];

		//is it a number (typecast needed?)
		if(isdigit(expression[position]))
		{
			//variables to hold number
			string sNumber = "" + partOfString;
			double dNumber;

			//incriment position
			position++;
			partOfString = expression[position];

			//if still number, read until space, add to string
			while(partOfString != " ")
			{	
				//concatinate string
				sNumber = sNumber + partOfString;

				//incriment position
				position++;
				partOfString = expression[position];
			}
			

			//change string to double
			dNumber = static_cast<double>(atoi(sNumber.c_str()));

			//add double number to stack
			userStack.push(dNumber);
		}
		//is it an operator
		else if(partOfString == "+" || partOfString == "-" || partOfString == "*" || partOfString == "/")
		{	
			//compute
			compute(userStack, expression[position]);

			//incriment positon
			position++;
		}
		//is it a space
		else if(partOfString == " ")
		{	

			//incriment position
			position++;

		}
		//else it is not an acceptable char
		else
		{
			cout << "Error: Expression has an unacceptable operand or operator.";
			cout << endl << endl;

			//clear stack
			while(!userStack.empty())
			{
				userStack.pop();
			}

			//end loop, can't compute
			position = expression.size();
		}
	}

	//if there only one value in the stack
	if(userStack.size() == 1)
	{
		//print value (showpoint?)
		cout << expression << " = " << userStack.top() << endl;
		cout << endl;
	}
	//else if more than one value in stack still
	else if(userStack.size() > 1)
	{
		//print error message
		cout << "Error: There are too many numbers and not enough operators.";
		cout << endl << endl;
	}

	//clear stack
	while(!userStack.empty())
	{
		userStack.pop();
	}
}



/*********************************************************************
** Description: Takes a stack of doubles by reference and a single char
that represents an acceptable operator.  Identifies which operator the
char is, takes two numbers off of the stack, and performs the correct
arithmatic on those numbers.  For postfix, aritmatic should equate to: 
second to top number (operator) top number.  Once arithmatic is done,
total is added to the top of stack.
** Parameters: stack of doubles, char representing an operator
*********************************************************************/
void compute(stack <double> &userStack, char sign)
{
	//variables
	double total;
	double topNum;
	double secondToTopNum;

	//adjust variables and stack
	topNum = userStack.top();
	userStack.pop();
	secondToTopNum = userStack.top();
	userStack.pop();

	//if + sign
	if(sign == '+')
	{
		//add last number with second to last number
		total = secondToTopNum + topNum;

	}
	//if - sign
	else if(sign == '-')
	{
		//subtract second to last number and last number
		total = secondToTopNum - topNum;
	
	}
	//if * sign
	else if(sign == '*')
	{
		//multiple last number with second to last number
		total = secondToTopNum * topNum;

	}

	//else (it is / sign)
	else
	{
		//if last number entered is zero
		if (topNum == 0)
		{	
			//clear stack
			while(!userStack.empty())
			{
				userStack.pop();
			}

			//throw error
			throw string("Error: Cannot divide by zero.");
		}
		//else, it's ok to divide
		else
		{
			//divide second to last number by last number
			total = secondToTopNum / topNum;
		}
	}
	//put value on top of stack
	userStack.push(total);
}
