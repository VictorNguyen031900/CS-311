// CS311 : This is the BST implementation file template by Rika Yoshii

// Each node has an Up link to make it easy to go up the tree.  It must be set as nodes are inserted.  Some deletion
// cases require Up link to be updated.  Couts are there to test to make sure
// you set the Up links correctly!!!! (Fall 19)
//
// INSTRUCTIONS:
// Look for ** comments to complete this file for HW4
// Try not to delete the ** comments, but add the code next to them
// Make sure all { } match. Doing Tab on each line helps.
// Draw pictures as you complete each **

// =========================================================
//HW#: HW4 BST
//Your name: Victor Nguyen
//Complier:  g++
//File type: implementation file binstree.cpp
//================================================================

using namespace std;
#include <iostream>
#include "binstree.h"

// constructor  initializes Root
BST::BST()
{
  Root = NULL;   // This is an empty tree
}

// destructor must completely destroy the tree
BST::~BST()
{
  dtraverse(Root); // traverse to delete all vertices in post order
  Root = NULL;    
}
// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:   V is a pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // recursive post order traversal
{   
  if (V != NULL) 
    {
      dtraverse(V->Left);         // destroy left sub tree of V
      dtraverse(V->Right);       //  destroy right sub tree of V
      delete V;                  //  delete V
    }
}

// PURPOSE: Show vertices in IN order traversal from the Root
void BST::Display()
{
  cout << "Elements in the IN order: " << endl;
  INorderTraversal(Root);  // start in-order traversal from the root
}
// PURPOSE: Does IN order traversal from V recursively
// PARAM: V is te pointer to the vertex to visit right now
// For non EC, the height and balance will always be 0 
void BST::INorderTraversal(Vertex *V)
{
  if (V != NULL)
    {
      INorderTraversal(V->Left);
      cout << V->Elem << " Height:" << V->Height << " Balance:" << V->Balance << endl;
      INorderTraversal(V->Right);
    }
}

// PURPOSE: Searches for an element in PRE-order traversal
// This is the same as Depth First Traversal
bool BST::Search(elem_t K)
{
  PREorderSearch(Root, K);  // start pre-order traversal from the root
}
// PURPOSE: Does PRE order search from V recursively
// PARAM: V is the pointer to the vertex to be visited now
//        K is what we are looking for
bool BST::PREorderSearch(Vertex *V, elem_t K)
{
    if (V != NULL)
      {
        if (K == V->Elem) return true; // found the element in V
        else if ( K < V->Elem ) 
	  PREorderSearch(V->Left, K);
	else 
	  PREorderSearch(V->Right, K);
      }
    else return false;
}

// ------ The following are for adding and deleting vertices -----


// PURPOSE: Adds a vertex to the binary search tree for a new element 
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively)
// to demonstrate the algorithm that is in the notes
//    - smaller than the current -> go to the left
//    - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::InsertVertex(elem_t E)
{
  // Set up a new vertex first
   Vertex *N;         // N will point to the new vertex to be inserted
   N = new Vertex;    // a new vertex is created
   N->Left  = NULL;   // make sure it does not
   N->Right = NULL;   // point to anything
   N->Elem  = E;      // put element E in it
   N->Height = 0;
   N->Balance = 0;
   N->Up = NULL;      // no parent for now
   cout << "Trying to insert " << E << endl;

   if (Root == NULL)  // Special case: we have a brand new empty tree
     {
       Root = N;      // the new vertex is added as the root
       cout << "...adding " << E << " as the root" << endl; 
     }// end of the special case
   else  // the tree is not empty
     {
        Vertex *V;       // V will point to the current vertex
        Vertex *Parent;  // Parent will always point to V's parent

        V = Root;        // start with the root as V
        Parent = NULL;   // above V so it does not point to anything  

	// go down the tree until you cannot go any further        
	while (V != NULL)
	  {
	    if (N->Elem == V->Elem) // the element already exists
              {	 cout << "...error: the element already exists" << endl;
		return;  }
	    else
	      if (N->Elem < V->Elem)  // what I have is smaller than V
		{  cout << "...going to the left" << endl;  
		  Parent = V;
		  V = V->Left;
		}
	      else // what I have is bigger than V
		{  cout << "...going to the right" << endl;
		  Parent = V;
		  V = V->Right;
		}
      }//end of while
        
   // reached NULL -- Must add N as the Parent's child
        
        if (N->Elem < Parent->Elem)  
          {  
	    Parent->Left = N;
	    cout << "...adding " << E << " as the left child of " 
		 << Parent->Elem << endl;
	    N->Up = Parent;
            cout << N->Elem  << " now points UP to " << N->Up->Elem << endl;   
            // *** EC call here to adjust height and BF //***
	  }
        else 
           { 
             Parent->Right = N;
	     cout << "...adding " << E << " as the right child of " 
                  << Parent->Elem << endl; 
	     N->Up = Parent;
             cout << N->Elem << " now points UP to " << N->Up->Elem << endl;   
	     // *** EC call here to adjust height and BF //***
  	}

      }// end of normal case

}// end of InsertVertex


// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove 
void BST::DeleteVertex(elem_t E)
{
  cout << "Trying to delete " << E << endl;
  
  Vertex *V;       // the current vertex
  Vertex *Parent;  // Parent will always point to V's parent

  // case 1: Lonely Root  --------------------
  if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
    { cout << "...deleting the lonely root" << endl;
      delete Root; 
      Root = NULL;
      return; 
    }  // only the Root was there and deleted it

  // case 2:  One Substree Root ----------------
  if ((E == Root->Elem) && (((Root->Left != NULL) && (Root->Right == NULL)) || ((Root->Right != NULL) && (Root->Left == NULL))))
  { cout << "... deleting the root with just one child" << endl; 
    if((Root->Left != NULL) && (Root->Right == NULL))
    {
      Root = Root->Left; 
      Root->Up = NULL;
    }
    else
    {
      Root = Root->Right;
      Root->Up = NULL;
    }
    return;
  }// end of deleting the root with one subtree
  
  // ---- Otherwise deleting something else  --------------
  
  V = Root;  // start with the root to look for E
  Parent = NULL;  // above the V so does not point to anything yet

  // going down the tree looking for E
  while (V != NULL)
    { 
      if (E == V->Elem)   // found it
	{  cout << "...removing " << V->Elem << endl;
	  remove(V, Parent);
	  return;
	}
      else
	if (E < V->Elem)
	  {  cout << "...going to the left" << endl; 
	    Parent = V;
	    V = V->Left;
	  }
	else
	  {  cout << "...going to the right" << endl;
	    Parent = V;
	    V = V->Right;
	  }
      
    }// end of while
  
  // reached NULL  -- did not find it
  cout << "Did not find the key in the tree." << endl;
  
}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf, delete it
// Case 2: it has just one child, bypass it
// Case 3: it has two children, replace it with the max of the left subtree
void BST::remove(Vertex *V, Vertex *P)
{
  if ((V->Left == NULL) && (V->Right == NULL))
     {
	cout << "removing a leaf" << endl;
	if (P->Left == V)
	{
          // *** EC call here from P to adjust height and BF
	  delete V;
	  P->Left = NULL;
	}
	else // V is a right child of the Parent
	 {  
          // *** EC call from P to adjust height and BF
	   delete V;
	   P->Right = NULL;
	 }
	return;
      }//end of leaf case
    
  else if ((V->Left != NULL) && (V->Right == NULL))
     { Vertex* C = V->Left; // the left child //(Replace Node* with Vertex*)
	  cout << "removing a vertex with just the left child" << endl;
	  if (P->Elem > C->Elem)
	    {
	      P->Left = C;
	      C->Up = P;
	      delete V;
	    }
	  else
	    {
	      P->Right = C;
	      C->Up = P;
	      delete V;
	  }
          cout << C->Elem << " points up to " << C->Up->Elem << endl;
          // *** EC call from P to adjust height and BF
	}// end of V with left child       
 
  else if ((V->Left == NULL) && (V->Right != NULL))
     { Vertex* C = V->Right;  // the right child //(Replace Node* with Vertex*)
	  cout << "removing a vertex with just the right child" << endl;   
	  if (P->Elem > C->Elem)
	    {
	      P->Left = C;
	      C->Up = P;
	      delete V;
	    }
	  else
	    {
	      P->Right = C; 
	      C->Up = P;
	      delete V;
	    }
          cout << C->Elem << " points up to " << C->Up->Elem << endl;
          // *** EC call from P to adjust height and BF 
        }//end of V with right child
      
   else // V has two children (case 3)
	{ cout << "removing an internal vertex with children" << endl;
	  cout << "..find the MAX of its left sub-tree" << endl;
	  elem_t Melem;
	  // find MAX element in the left sub-tree of V
          Melem = findMax(V); 
          cout << "..replacing " << V->Elem << " with " << Melem << endl;
          V->Elem = Melem;
        }//end of V with two children
      
}// end of remove

// PURPOSE: Finds the Maximum element in the left sub-tree of V
// and also deletes that vertex
elem_t BST::findMax(Vertex *V)
{
  Vertex *Parent = V;
  V = V->Left;          // start with the left child of V
  while (V->Right != NULL)
  {
    Parent = V;
    V = V->Right;
  }
  
  // reached NULL Right  -- V now has the MAX element
  elem_t X = V->Elem;
  cout << "...Max is " << X << endl;
  remove(V, Parent);    // remove the MAX vertex 
  return X;             // return the MAX element
  
}// end of FindMax

