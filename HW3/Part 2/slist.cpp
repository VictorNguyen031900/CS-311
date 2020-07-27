// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Victor Nguyen
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{ cout << "slist constructor:" << endl;}


// positions always start at 1
//PURPOSE: To find the postion of a node given the key(element inside said node)
//ALGORITHM: Create a temporary node and set to the front of the linked list, go through list until
//           temporary node is NULL.  While in loop check is node's element is equal to the given key.
//           Everytime the loop cycles, increase a counter to indicate position. If node's element is
//           not equal to give key continue looping until end of list else return counter/position.
int slist::search(el_t key)
{
  Node *p = Front; //temporary pointer to front of list
  int elemNum = 1; //variable indicate postion
  while(p != NULL) //keep looping until p pointer is NULL
    {
      if(p->Elem == key) //check is node's element is equal to given key.
	{
	  return elemNum; //If node's element is equal to key, return elemNum(position)
	}
      p = p->Next; //set p pointer to p->Next pointer
      elemNum++; //increase counter to indicate list position increase
    }
  return 0; //return 0 if key given is not found in the list
}

// don't forget to throw OutOfRange for bad pos
//PURPOSE: To replace the element the in the position in the list
//ALGORITHM: Check is position given is in range of the list, if not throw an error.  Create a 
//           temporary pointer and set to the front of the linked list, use for loop to go
//           through list until pointer is at the right position in the list, then replace
//           the element in the node with the new element.
void slist::replace(el_t element, int pos)
{
  if((pos < 1) || (pos > Count)) //check is pos is out of range
    {
      throw OutOfRange(); //if out of range throw error
    }
  Node *p = Front; //temporary pointer set to front of list
  for(int i = 1; i < pos; i++) //loop unti p pointer is at desired position
    {
      p = p->Next; //p pointer is set to p->Next pointer
    }
  p->Elem = element; //p pointer is at desired position, replace node's element with new element
}


//PURPOSE: To check if both linked list are the same in terms of same elements and length
//ALGORITHM: Checks is calling object's count is equal to passed object's count, if not equal
//           return false, if both counts are equal to zero return true.  Else both counts are
//           greater than 0(special case), create temporary pointers for both objects. Loop
//           through list checking each node if both object element's are equal to each other.
//           If both object elements are equal advance to next node.  But if not equal immediately
//           return false since that means the objects are similar to each other.
bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false
  // if the same lengths,
  //check each node to see if the elements are the same
  if(Count != OtherOne.Count) //check if calling object's Count is not equal to passing object's Count
    {
      return false; //return false when both object's Count aren't equal
    }
  else if((Count == 0) && (OtherOne.Count == 0)) //check if both object's Counts are 0
    {
      return true; //return true when both object's Count are equal to 0
    }
  else //if both object's Count are equal and greater than 0
    {
      Node *p1 = Front; //temporary pointer for calling object's front of list
      Node *p2 = OtherOne.Front; //temporary for passing object's front of list
      bool compare; //bool variable to return if objects are equal or not
      while(p1 != NULL) //loop calling object's list to until its pointer is NULL
	{
	  if(p1->Elem == p2->Elem) //if both object's elements are equal then go to next nodes
	    {
	      p1 = p1->Next;
	      p2 = p2->Next;
	      //compare = true;
	    }
	  else //both object's elements are not equal to each other
	    {
	      //compare = false;
	      //return compare;
	      return false; //return false due to both elements not being equal to each other
	    }
	}
      //return compare;
      return true; //return true since reached end of list and all elements are equal to each other
    }
}
