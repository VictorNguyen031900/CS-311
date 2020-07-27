// CS311 Yoshii - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: Victor Nguyen
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
void pqueue::insertjob(int j)
{
  cout << "Adding: " << j << endl;
  if (count == MAX)
    {
      cout << "..cannot add..Full!" << endl; //Display error message when array full
    }
  else
    {
      Q[count] = j; //Add j to the end of the array
      count++; //Increase counter
    }
  trickleup(); // moves the job to the right place
  //////////////////////////
  //       FINISHED       //
  //////////////////////////
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ 
  cout << "Jobs: " ;
  for(int i = 0; i < count; i++) //Loop to display elements in array
    {
      cout << Q[i] << " ";
    }
  cout << endl;
  //////////////////////////
  //       FINISHED       //
  //////////////////////////
} 


// Utility functions follow: ------------------
void pqueue::swap(int loc1, int loc2)
{
  int temp = Q[loc1]; //Temporary Variable to store loc1
  Q[loc1] = Q[loc2]; //Set loc1 to loc2
  Q[loc2] = temp; //Set loc2 to temporary variable
  //////////////////////////
  //       FINISHED       //
  //////////////////////////
}

// Purpose: to make the very last job trickle up to the right location 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job's location
  while(x > 0) //Loop until location is 0
    {
      int parent = getParent(x); //Variable to save the location of the job's parent
      if(Q[parent] > Q[x]) //if parent is greater than the job, swap postions
	{
	  swap(x, parent);
	  x = parent; //job's positions is now the parent's
	}
      else
	{
	  break;
	}
    }
  //////////////////////////
  //       FINISHED       //
  //////////////////////////
}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{
  bool temp = even(childloc); //Variable to determine if child's location is even
  if( temp == true) //If variable is true then return location of parent
    {
      return ((childloc - 2)/2);
    }
  else //Else is variable is false then return location of parent
    {
      return ((childloc - 1)/2);
    }
  //////////////////////////
  //       FINISHED       //
  //////////////////////////
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0)
    {
      return true;
    }
  else
    {
      return false;
    }
}




// Purpose: to reheapify the Pqueue after printing
//  This trickles down
void pqueue::reheapify()
{ 
  int x = 0;   // the current location
  Q[0] = Q[count-1];  // move the last job to the front
  count--;
  while(x < (count - 1)) //Loop until current is beyond count
    {
      int child = getSmallerchild(x); //Variable to get smallest child of parent
      if(child == -1) //If there is no left or right child
	{
	  return;
	}
      else if(Q[child] < Q[x]) //If child is less than Parent then swap positions
	{
	  swap(x, child); //Swap positions
	}
      x++; //Increase counter
    }
  //////////////////////////
  //       FINISHED       //
  //////////////////////////
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{
  int c1 = ((2 * i) + 1); //Left child
  int c2 = ((2 * i) + 2); //Right child
  if((c1 >= count) && (c2 >= count)) //If Left and Right child are beyond the array
    {
      return -1;
    }
  else if(c2 >= count) //There is no Right child
    {
      return c1;
    }
  else if(c1 >= count) //There is no Left child
    {
      return c2;
    }
  else if(Q[c1] < Q[c2]) //Left child is less than Right child
    {
      return c1;
    }
  else //Right child is less than Left child
    {
      return c2;
    }
  //////////////////////////
  //       FINISHED       //
  //////////////////////////
}

