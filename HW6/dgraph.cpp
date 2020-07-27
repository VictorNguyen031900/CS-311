//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Victor Nguyen
// File Type: Implementation File
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0
{
  for(int i = 0; i < SIZE; i++) //Loop to make vertexName blank and visit variable 0 in each slot of the array
    {
      Gtable[i].vertexName = ' ';
      Gtable[i].visit = 0;
    }
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
  //llist destructor will be called automatically when the program ends
}

//PURPOSE: Reads from an input file and puts each entry in a Gvertex object in an array slot
void dgraph::fillTable()  // be sure to read from a specified file
{
  el_t x;
  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname

  // the rest is in HW6-help
  while(fin >> Gtable[countUsed].vertexName) //if can read the name
    {
      fin >> Gtable[countUsed].outDegree; //reads next entry and sets to outDegree
      for(int i=0; i<Gtable[countUsed].outDegree; i++) //loop for number of outDegree
	{
	  fin >> x; //reads next entry and sets to x
	  (Gtable[countUsed].adjacentOnes).addRear(x); //linked list of adjacent vertices
	}
      countUsed++; //Increase slot in array
    }
  fin.close(); //closing file
}

//PURPOSE: Displays each slot of the array which is an object with variables inside it. Displays it orderly.
void dgraph::displayGraph() // be sure to display
{// in a really nice table format -- all columns but no unused rows 
  int totalEdges = 0;
  for(int i = 0; i < countUsed; i++)
    {
      totalEdges += Gtable[i].outDegree;
    }
  cout << "The numeber of edges is: " << totalEdges << endl;
  cout << "Vertices   Out   Visit   Adj" << endl;
  cout << "---------------------------------" << endl;
    for(int i = 0; i < countUsed; i++)
      {
	cout << "    " << Gtable[i].vertexName << "       " << Gtable[i].outDegree << "      " << Gtable[i].visit << "     ";
	(Gtable[i].adjacentOnes).displayAll(); //Displayed as a row but is Gvertex obejct in an array
      }
}

//PURPOSE: Returns the number of degrees a vertex has
int dgraph::findOutDegree(char V)// throws exception
{// does not use a loop
  int c = V; //converts char to int
  if(Gtable[(c % 65)].vertexName == V) //mod 65 because 65 is the ascii value of 'A', so = 0,1,2,3,...
    {
      return Gtable[(c % 65)].outDegree; //returns array slot's outDegree variable
    }
  else //if V is not found in array then throw error
    {
      throw BadVertex();
    }
}

//PURPOSE: Returns a linked list of adjacent vertices
slist dgraph::findAdjacency(char V)// throws exception
{// does not use a loop
  int c = V; //converts char to int
  if(Gtable[(c % 65)].vertexName == V) //mod 65 because 65 is the ascii value of 'A', so = 0,1,2,3,...
    {
      return Gtable[(c % 65)].adjacentOnes; //returns linked list of adjacent vertices
    }
  else //if V is not found in array then throw error
    {
      throw BadVertex();
    }
}
