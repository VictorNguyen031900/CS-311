//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW7-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW7 dgraph
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
  el_t x; //changed el_t to char
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
  cout << "The number of edges is: " << totalEdges << endl;
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
  c = c - 65; //minus 65 because 65 is the ascii value of 'A' to get array slots
  if(c > 25 || c < 0) //Checks if c is out of bounds of 00-25
    {
      throw BadVertex(); //throw error if out of bounds
    }
  else
    {
      if(Gtable[c].vertexName == V) //if array's slot vertex is same as key
	{
	  return Gtable[c].outDegree; //if same then return outDegree
	}
      else
	{
	  throw BadVertex(); //throw error if array's slot vertex is not the same as the key
	}
    }
}

//PURPOSE: Returns a linked list of adjacent vertices
slist dgraph::findAdjacency(char V)// throws exception
{// does not use a loop
  int c = V; //converts char to int
  c = c - 65; //minus 65 because 65 is the ascii value of 'A' to get array slots
  if(c > 25 || c < 0) //Checks if c is out of bounds of 00-25
    {
      throw BadVertex();  //throw error if out of bounds
    }
  else
    {
      if(Gtable[c].vertexName == V)  //if array's slot vertex is same as key
	{
	  return Gtable[c].adjacentOnes;  //if same then return linked list of adjacent vertices
	}
      else 
	{
	  throw BadVertex(); //throw error if array's slot vertex is not the same as the key
	}
    }
}

// ADDED to HW7
// PURPOSE: to assign a visit number to each of the no visited vertices
void dgraph::visit(int visitNum, char visitName)
{
  int givenLocation = visitName; //convert vertex name (char) to ascii
  Gtable[givenLocation - 65].visit = visitNum; //obtain visit variable from the array's slot and set to vistiNum
}

// ADDED to HW7
// PURPOSE: checks if a vertex has a been marked
bool dgraph::isMarked(char visitCheck)
{
  int checkLocation = visitCheck; //convert vertex name (char) to ascii

  if(Gtable[checkLocation - 65].visit == 0) //if visit variable is 0 (meaning not visited yet)
    {
      return 0; //return false
    }
  else //visit variable is greater than 0 (meaning visited already)
    {
      return 1; //return true
    }
}
