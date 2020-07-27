//==========================================================
//FINAL PROJECT
//Your name: Victor Nguyen
//Complier:  g++
//File type: Implementation file for binstree.cpp
//==========================================================
#include "elem.h"

// definition of what a Vertex is - also hidden from the client
struct Vertex
{
  Vertex *Up;  // points to the parent node 
  Vertex *Left;
  elem_t  Elem;
  Vertex *Right;
  int Height;  // for EC 
  int Balance;  // for EC 
};   

// this is set up to be inherited by another class
class BST
{
  
 public:
  
  BST();  // intializes Root
  ~BST();  // destructor calls dtraverse to destroy the dynamic tree
  
  // PURPOSE: these will show the vertices in IN order 
  // TO CALL: No parameter  but provide a pointer to 
  //          the root vertex in calling INorderTraversal
  void Display();      
  void INorderTraversal(Vertex*); // recursive
  
  // PURPOSE: these will search in PRE order - same as Depth First
  // TO CALL: provide the element to search for; provide a pointer to 
  //          the root vertex in calling PREorderSearch
  bool Search(elem_t);
  bool PREorderSearch(Vertex*, elem_t); // recursive
  
  // PURPOSE: This adds a new vertex into the BST 
  // TO CALL: provide the element to be added to the tree
  void InsertVertex(elem_t);
  
  // PURPOSE: This deletes a vertex with the given element 
  //     - calls remove and  findMax (see below)
  // TO CALL: provide the element to be removed from the tree
  void DeleteVertex(elem_t);
  
  //==========Functions added for final project====================

  // PURPOSE: Used to search for an elem_t that matches or is closest
  //          to elem_t that was passed, retuns elem_t to Search2
  // TO CALL: provide the element to be searched for and provide a vertex
  //          pointer that is the root of the tree
  elem_t MorrisSearchTraversal(Vertex*, elem_t);

  // PURPOSE: Make an elem_t object with float value as price and calls 
  //          MorrisSearchTraversal
  // TO CALL: provide the float value to search for
  void Search2(float);

  // PURPOSE: This deletes a vertex with the given element
  // TO CALL: provide the Node struct to be added to the tree
  void InsertVertex2(Node);

  // PURPOSE: these will show the vertices in IN order
  // TO CALL: No parameter  but provide a pointer to 
  //          the root vertex in calling DisplayTraversal
  void Display2();
  void DisplayTraversal(Vertex*);

  //=================================================================

 // the following can be inherited but not available to the client
 protected:   

  Vertex *Root; //  Root which is a pointer to the root vertex

  // utility functions follow - these are not for the clients to use
  // These were created to implement the public methods
  
  void dtraverse(Vertex*);
  // traverse and delete all vertices in post order
  
  void remove(Vertex*, Vertex*); 
  // removes the vertex knowing its parent
  
  elem_t findMax(Vertex*);  // finds the MAX element in the
  // left sub-tree of the vertex and also deletes it
  
};


