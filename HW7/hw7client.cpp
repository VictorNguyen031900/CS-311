//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Victor Nguyen
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include dgraph, slist and stack
#include <iostream>
#include "dgraph.h"
#include "slist.h"
#include "stack.h"

using namespace std;
// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that has the comments. 
  //variables and initializations

  dgraph TableObj;
  stack stackList;
  char V = 'A';
  char vTmp;
  int vCount = 0;

  //before DFS begins, fill table and display graph
  TableObj.fillTable();
  TableObj.displayGraph();

  //push A onto stack to start visiting
  stackList.push(V);

  //loop while stack is not empty
  while(!stackList.isEmpty())
    {
      stackList.pop(V); //begin visiting by popping top of stack
      cout << "Removed " << V << " from stack" << endl;
      if(!TableObj.isMarked(V)) //if v is not marked yet
	{
	  TableObj.visit(++vCount, V); //proceed to mark it
	  cout << "Visit " << V << " as " << vCount << endl;
	  slist adjacentList = TableObj.findAdjacency(V); //get V's adjacency list
	  if(adjacentList.isEmpty()) //if adjacency list is empty, backup
	    {
	      cout << "Deadend reached - backup" << endl;
	    }
	  else //otherwise push adjacency list to stack
	    {
	      cout << "...pushing ";
	      adjacentList.displayAll();
	      while(!adjacentList.isEmpty()) //loop until list is empty
		{
		  adjacentList.deleteRear(vTmp); //delete rear node from adjacentList
		  stackList.push(vTmp); //push vertices onto stack
		}
	    }
	}
      else //if V has been marked already, backup
	{
	  cout << V << " had been visited already - backup" << endl;
	}
      stackList.displayAll(); //display stack
    }

  TableObj.displayGraph(); //display graph after DFS

  return 0;
}
