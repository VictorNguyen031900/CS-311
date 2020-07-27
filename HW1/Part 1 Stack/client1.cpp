//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Victor Nguyen
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: To calculate the expression using a postfix expression and the usage of a stack
//Algorithm: User enters a string but the algorithm will treat the string as an array and will go through each element of the array. If the element is a one digit number, it will push it onto the stack. But if the element is an operator, pop the top element from the stack into a variable and pop again into another variable and use the operation and two variables, then push the result back into the stack.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char
	 if (isdigit(item))  // check char is a number
	       { postfixstack.push(item - '0'); }
	 else if ((item == '*') || (item == '-') || (item == '+')) // if char is not number then continue operation
	   {
	     postfixstack.pop(box2);
	     postfixstack.pop(box1);
	     if (item == '*')
	       { postfixstack.push(box1 * box2); }
	     else if (item == '-')
	       { postfixstack.push(box1 - box2); }
	     else if (item == '+')
	       { postfixstack.push(box1 + box2); }
	   }
	 // ** do all the steps in the algorithm given in Notes-1
	 else {throw "Invalid item";}	 
	 
       } // this closes try
      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{cerr << "ERROR: Too many numbers in your expression." << endl; return 0; }
      catch (stack::Underflow)
	{cerr << "ERROR: Not enough numbers in your expression to complete the expression." << endl; return 0; }
      catch (char const* errormsg ) // for invalid item case
	{cerr << "ERROR:  Invalid character.  Please only use numbers and operators!" << endl; return 0; }

      // go back to the loop after incrementing i
     i++;
     if (expression[i] == '\0')
       {}
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.
  int result;
  postfixstack.pop(result);
  if (postfixstack.isEmpty())
    { 
      cout << "Result: " << result << endl;
    }
  else
    { cerr << "ERROR: Incomplete expression.  Please make sure you entered it in correctly." << endl; }

}// end of the program
