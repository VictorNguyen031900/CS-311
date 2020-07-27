//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

//====================================================
//HW#: HW3P1 llist
//Your name: Victor Nguyen
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ 
  cout << "... in llist constructor..." << endl; 
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

llist::~llist()
{ 
  cout << ".... in llist destructor..." << endl; 
  el_t oldNum;
  while(!isEmpty())
    {
      deleteFront(oldNum);
    }
}

//PURPOSE: Checks if the list is empty by checking if Front and Rear are NULL and that count is 0
bool llist::isEmpty()
{ 
  if((Front == NULL) && (Rear == NULL) && (Count == 0))
    return true;
  else
    return false;
} // be sure to check all 3 data members

//PURPOSE: Displays all element in the list
void llist::displayAll() 
{ 
  if(isEmpty())
    {
      cout << "[ empty ]" << endl;
    }
  else
    {
      Node *P = Front;
      while(P != NULL)
	{
	  cout << "[" << P->Elem << "] ";
	  P = P->Next;
	}
      cout << endl;
    }
}  // be sure to display horizontally in [  ] with
// blanks between elements
  
//PURPOSE: Adds a new node and its element to the rear of the list
//PARAMETER: New element that is going to be added to the rear of the list
//ALGORITHM: If there is no elements in the list, then add a node to the front and rear.  Else we can
//           just add to the rear.
void llist::addRear(el_t NewNum) 
{ 
  if(Front == NULL)
    {
      Front = new Node;
      Rear = Front;
    }
  else
    {
      Rear->Next = new Node;
      Rear = Rear->Next;
    }
  Rear->Elem = NewNum;
  Rear->Next = NULL;
  Count++;
} // comment the 2 cases

//PURPOSE: Adds a new node and its element to the front of the list
//PARAMETER: New element that is going to be added to the front of the list
//ALGORITHM: If the list is empty, then make a node at the front.  Else make a temporary node x and
//           make x->next point to front.  Change front to x and add the element to that node
void llist::addFront(el_t NewNum) 
{ 
  if(Front == NULL) //case 1 if there is no elements in list already
    {
      Front = new Node;
      Front->Elem = NewNum;
      Front->Next = NULL;
      Rear = Front;
    }
  else //case 2 if these is already atleast one element in the list already
    {
      Node *x;
      x = new Node;
      x->Next = Front;
      Front = x;
      Front->Elem = NewNum;
    }
  Count++;
} // comment the 2 cases

//PURPOSE: Deletes the node in front of the list
//PARAMETER: Variable that will be passed the old element that will be deleted
//ALGORITHM: If list is empty, than throw error.  Else, if count is equal to 1, then set OldNum.
//           delete front and set it to NULL also read.  Else, if we have count is more than 1, then
//           do the same as before but set a temporary value to front->next and make that node the new front
void llist::deleteFront(el_t& OldNum) 
{ 
  if(isEmpty()) //case 1 if list is empty, throws underflow error
    {
      throw Underflow();
    }
  else if(Count == 1) //case 2 if there is only one element in the list
    {
      OldNum = Front->Elem;
      delete Front;
      Front = NULL;
      Rear = NULL;
      Count--;
    }
  else //case 3 if there is more than one element in the list
    {
      OldNum = Front->Elem;
      Node *Second;
      Second = Front->Next;
      delete Front;
      Front = Second;
      Count--;
    }
} // comment the 3 cases

//PURPOSE: Deletes the node in the rear of the list
//PARAMETER: Variable that will receive the old element
//ALGORITHM: If list is empty, than throw error. Else if count is equal to 1, then set OldNum, delete the
//           node and set the front and rear to NULL. Else if count is move than 1, then tranverse the
//           list until reached rear, delete rear node, set p->next = NULL;
void llist::deleteRear(el_t& OldNum)
{
  if(isEmpty()) //case 1 if list is empty, throws underflow error
    {
      throw Underflow();
    }
  else if(Count == 1) //case 2 if there is only one element in the list
    {
      OldNum = Rear->Elem;
      delete Rear;
      Front = NULL;
      Rear = NULL;
      Count--;
    }
  else //case 3 if there is more than one element in the list
    {
      OldNum = Rear->Elem;
      Node *P = Front;
      while(P->Next != Rear)
	P = P->Next;
      delete Rear;
      Rear = P;
      Rear->Next = NULL;
      Count--;
    }
} // comment the 3 cases


/* harder ones follow */

// Utility Function to move a local pointer to the Ith node
void llist::moveTo(int I, Node*& temp)
{ // moves temp I-1 times
  for ( int j = 1; j <= I-1; j++) 
    {
      temp = temp->Next;
    }
}

//PURPOSE: Delete the desired node
//PARAMETER: The node position that is going to be deleted and a variable to receive the element
//ALGORITHM: If the desired node postion exist, if not then throw an error. Else, if the desired node is the first
//           node then call the deleteFront function, but if it is the last node then call the deleteRear
//           function.  Else if the desired node is inbetween front and rear, make two pointers to traverse
//           through the list.
void llist::deleteIth(int I, el_t& OldNum) 
{ 
  if((I > Count) || (I < 1)) //case 1 if desired postion is out of range of 1 through count
    {
      throw OutOfRange();
    }
  else if(I == 1) //case 2 if desired position is the front of the list
    {
      deleteFront(OldNum);
    }
  else if(I == Count) //case 3 if deisred position is the rear fo the list
    {
      deleteRear(OldNum);
    }
  else //case 4 if desired position is inbetween front and rear
    {
      Node *P = Front; //make a pointer set to the front
      moveTo(I-1, P); //function call returns the pointer before the desired node position
      Node *PToDelete = P->Next; //set a temporary node pointer to next node to delete
      P->Next = PToDelete->Next; //set P->Next to the next node after the one being deleted
      OldNum = PToDelete->Elem; //saves the element from the node being deleted to return by reference
      delete PToDelete; //deletes node
      Count--;
    }
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.  

//PURPOSE: Inserts a new node at the desired positon in the list
//PARAMETER: The node position and the variable to add the element in the node
//ALGORITHM: If the desired node postion exist, if not then throw an error. Else, if the desired node position is
//           the first node, then call addToFront function, if it is the last node, then call addToRear function.
//           Else, if it is somewhere between front and rear then traverse the list until desired postion.
void llist::insertIth(int I, el_t newNum) 
{ 
  if((I > Count+1) || (I < 1)) //case 1 if desired postion is out of range of 1 - (count+1)
    {
      throw OutOfRange();
    }
  else if(I == 1) //case 2 if desired position is the front of the list
    {
      addFront(newNum);
    }
  else if(I == Count+1) //case 3 if desired postion is the rear of the list
    {
      addRear(newNum);
    }
  else //case 4 if desired postion if inbetween front and rear
    {
      Node *P = Front; //make a pointer set to the front
      moveTo(I-1, P); //function call returns the pointer before the desired node postion
      Node *temp = P->Next; //set a temporary node pointer for a new node
      P->Next = new Node; //make a new node at P->Next
      P->Next->Next = temp; //set the new node's next to the temporary node
      P->Next->Elem = newNum; //set the new node's element to newNum variable
      Count++;
    }
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: Copies the list value by value
//PARAMETER: The original list
//ALGORITHM: Every value that is traversed, is copied in to the new list.
llist::llist(const llist& Original) 
{ 
  el_t x;
  Front = 0;
  Rear = 0;
  Count = 0;
  if(&Original != this)
    {
      while(!this->isEmpty())
        {
          this->deleteRear(x);
        }
      Node *P;
      P = Original.Front;
      while(P != NULL)
        {
          this->addRear(P->Elem);
          P = P->Next;
        }
    }
} // use my code

//PURPOSE: Overload = function
//PARAMETER: The original list
//ALGORITHM: If calling list is not the same as OtherOne, if so then empty calling list.  Then build up the list
//           by traversing through the list one element at a time.
llist& llist::operator=(const llist& OtherOne) 
{ 
  el_t x;
  if(&OtherOne != this)
    {
      while(!this->isEmpty())
	{
	  this->deleteRear(x);
	}
      Node *P;
      P = OtherOne.Front;
      while(P != NULL)
	{
	  this->addRear(P->Elem);
	  P = P->Next;
	}
    }
  return *this;
} // use my code

