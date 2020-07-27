// CS311 Yoshii
// HW6 Client file 
//INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: Victor Nguyen
// File type:  Client file  (tester)
// ================================================
#include <iostream>
#include "dgraph.h"
using namespace std;
int main()
{
    //0.Declare table object
    //1.fillTable()
  //2.displayGraph()
  //while (the user does not want to stop)
  //a.the user will specify which vertex     
  //b.findOutDegree of the vertex and display the result
  //b.findAdjacency of the vertex and display the result (see Hint)
  //c.catch exception to display error mesg but do not exit

  int option = 0;
  char key; //vertex looking for
  int degree;
  slist adjacents;
  dgraph tableObj; //0.Declare table object
  int exception = 0;
  tableObj.fillTable(); //1.fillTable()
  tableObj.displayGraph(); //2.displayGraph()
  
  while(option == 0) //Loop to find the degress of a vertex
    {
      cout << "Please enter the vertex: ";
      cin >> key;
      try
	{
	  degree = tableObj.findOutDegree(key); //Variable to hold number of degress
	  adjacents = tableObj.findAdjacency(key); //Variable to hold linked list of adjacent vertices
	}
      catch(dgraph::BadVertex) //Error if vertex is not found
	{
	  cout << "ERROR: vertex does not exist! " << endl;
	  exception = 1; //Changes variable so it won't display a number on accident
	}
      if(exception == 0) //Display number of degrees when vertex is found
	{
	  cout << degree << " edges comes out to:" << endl;
          adjacents.displayAll();
	}
      //Menu of options
      cout <<"Please, enter one of the following: " << endl ;
      cout <<"0. to look at another vertex." << endl ;
      cout <<"1. to quit." << endl ;
      cout <<"Your option: " ;
      cin >> option;
      cout << endl;
      exception = 0; //Change variable back so next turn can have an opportunity to display
    }
}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
