//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 

//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Victor Nguyen
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: To display all the permutations "A", "B", and "C" using a queue.
//Algorithm: Everytime an element is removed and placed in a temporary string variable from the front of the queue 
//           and displayed, if there is still space in the queue, take the temporary string variable and concatenate
//           it with strings "A", "B", and "C" and add to the end of the queue. Goes on infinitely till overflow.
int main()
{ 
  int tempcount = 0;
  queue permutations;// ** "A", "B", "C" in the queue
  permutations.add("A");
  permutations.add("B");
  permutations.add("C");
  while(1==1)
    {
      try
	{
	  el_t temp;
	  if(!permutations.isEmpty())
	    {
	      permutations.remove(temp);
	      cout << temp << endl;
	    }
	  if(!permutations.isFull())
	    {
	      permutations.add(temp + "A");
	      permutations.add(temp + "B");
	      permutations.add(temp + "C");
	    }
	}
      catch(queue::Underflow)
	{
	  cerr << "ERROR: The queue is empty!";
	  return 0;
	}
      catch(queue::Overflow)
	{
	  cerr << "ERROR: Queue is full!" << endl;
	  return 0;
	}
    }// end of loop
}

