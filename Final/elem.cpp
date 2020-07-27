// =========================================================
//FINAL PROJECT
//Your name: Victor Nguyen
//Complier:  g++
//File type: implementation file for elem.cpp
//===========================================================
#include "elem.h"
#include <iostream>
#include <string>
using namespace std;

elem_t::elem_t()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

elem_t::~elem_t()
{
  Node oldNum;
  while(!isEmpty())
    {
      deleteFront(oldNum);
    }
}

//PURPOSE: Checks if the list is empty by checking if Front and Rear are NULL and that count is 0
bool elem_t::isEmpty()
{
  if((Front == NULL) && (Rear == NULL) && (Count == 0))
    return true;
  else
    return false;
}

//PURPOSE: Displays all element in the list
void elem_t::displayAll()
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
	  //print out every variable in node
	  cout << "Price: $" << P->price<< endl;
	  cout << "CPU: " << P->cpu[0] << " " << P->cpu[1] << " " << P->cpu[2] << endl;
	  cout << "GPU: " << P->gpu[0] << " " << P->gpu[1] << " " << P->gpu[2] << endl;
	  cout << "RAM: " << P->ram << " Gigabytes" << endl;
	  cout << "TYPE: " << P->pcType << endl << endl;
	  P = P->Next;
	}
    }
}

//PURPOSE: Adds a new node and its element to the rear of the list
//PARAMETER: New element that is going to be added to the rear of the list
//ALGORITHM: If there is no elements in the list, then add a node to the front and rear.  Else we can
//           just add to the rear.
void elem_t::addRear(Node NewNum)
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
  //transfer everything from newNum to Rear node 
  Rear->cpu[0] = NewNum.cpu[0];
  Rear->cpu[1] = NewNum.cpu[1];
  Rear->cpu[2] = NewNum.cpu[2];
  Rear->gpu[0] = NewNum.gpu[0];
  Rear->gpu[1] = NewNum.gpu[1];
  Rear->gpu[2] = NewNum.gpu[2];
  Rear->pcType = NewNum.pcType;
  Rear->ram = NewNum.ram;
  Rear->price = NewNum.price;
  Rear->Next = NULL;
  Count++;
}

//PURPOSE: Deletes the node in front of the list
//PARAMETER: Variable that will be passed the old element that will be deleted
//ALGORITHM: If list is empty, than throw error.  Else, if count is equal to 1, then set OldNum.
//           delete front and set it to NULL also read.  Else, if we have count is more than 1, then
//           do the same as before but set a temporary value to front->next and make that node the new front
void elem_t::deleteFront(Node& OldNum)
{
  if(isEmpty()) //case 1 if list is empty, throws underflow error
    {
      throw Underflow();
    }
  else if(Count == 1) //case 2 if there is only one element in the list
    {
      //transfer everything Front node to OldNum node
      OldNum.cpu[0] = Front->cpu[0];
      OldNum.cpu[1] = Front->cpu[1];
      OldNum.cpu[2] = Front->cpu[2];
      OldNum.gpu[0] = Front->gpu[0];
      OldNum.gpu[1] = Front->gpu[1];
      OldNum.gpu[2] = Front->gpu[2];
      OldNum.pcType = Front->pcType;
      OldNum.ram = Front->ram;
      OldNum.price = Front->price;
      delete Front;
      Front = NULL;
      Rear = NULL;
      Count--;
    }
  else //case 3 if there is more than one element in the list
    {
      //transfer everything Front node to OldNum node
      OldNum.cpu[0] = Front->cpu[0];
      OldNum.cpu[1] = Front->cpu[1];
      OldNum.cpu[2] = Front->cpu[2];
      OldNum.gpu[0] = Front->gpu[0];
      OldNum.gpu[1] = Front->gpu[1];
      OldNum.gpu[2] = Front->gpu[2];
      OldNum.pcType = Front->pcType;
      OldNum.ram = Front->ram;
      OldNum.price = Front->price;
      Node *P;
      P = Front->Next;
      delete Front;
      Front = P;
      Count--;
    }
}

//PURPOSE: Deletes the node in the rear of the list
//PARAMETER: Variable that will receive the old element
//ALGORITHM: If list is empty, than throw error. Else if count is equal to 1, then set OldNum, delete the
//           node and set the front and rear to NULL. Else if count is move than 1, then tranverse the
//           list until reached rear, delete rear node, set p->next = NULL;
void elem_t::deleteRear(Node& OldNum)
{
  if(isEmpty()) //case 1 if list is empty, throws underflow error
    {
      throw Underflow();
    }
  else if(Count == 1) //case 2 if there is only one element in the list
    {
      //transfer everything Front node to OldNum node
      OldNum.cpu[0] = Rear->cpu[0];
      OldNum.cpu[1] = Rear->cpu[1];
      OldNum.cpu[2] = Rear->cpu[2];
      OldNum.gpu[0] = Rear->gpu[0];
      OldNum.gpu[1] = Rear->gpu[1];
      OldNum.gpu[2] = Rear->gpu[2];
      OldNum.pcType = Rear->pcType;
      OldNum.ram = Rear->ram;
      OldNum.price = Rear->price;
      delete Rear;
      Front = NULL;
      Rear = NULL;
      Count--;
    }
  else //case 3 if there is more than one element in the list
    {
      //transfer everything Front node to OldNum node
      OldNum.cpu[0] = Rear->cpu[0];
      OldNum.cpu[1] = Rear->cpu[1];
      OldNum.cpu[2] = Rear->cpu[2];
      OldNum.gpu[0] = Rear->gpu[0];
      OldNum.gpu[1] = Rear->gpu[1];
      OldNum.gpu[2] = Rear->gpu[2];
      OldNum.pcType = Rear->pcType;
      OldNum.ram = Rear->ram;
      OldNum.price = Rear->price;
      Node *P = Front;
      while(P->Next != Rear)
	P = P->Next;
      delete Rear;
      Rear = P;
      Rear->Next = NULL;
      Count--;
    }
}

//PURPOSE: Overload = function
//PARAMETER: The original list
//ALGORITHM: If calling list is not the same as OtherOne, if so then empty calling list.  Then build up the list
//           by traversing through the list one element at a time.
elem_t& elem_t::operator=(const elem_t&OtherOne)
{
  Node x;
  if(&OtherOne != this)
    {
      while(!this->isEmpty()) //Makes sure calling object is empty
	{	  
	  this->deleteRear(x);
	}
      Node *P;
      P = OtherOne.Front;
      while(P != NULL)
	{
	  //transfer everything from P node to x node
	  x.cpu[0] = P->cpu[0];
          x.cpu[1] = P->cpu[1];
          x.cpu[2] = P->cpu[2];
          x.gpu[0] = P->gpu[0];
          x.gpu[1] = P->gpu[1];
          x.gpu[2] = P->gpu[2];
          x.pcType = P->pcType;
          x.ram = P->ram;
          x.price = P->price;
	  x.Next = NULL;
	  this->addRear(x);
	  P = P->Next;
	}
    }
  return *this; //return calling object pointer
}

//PURPOSE: Overload > function, checks each object's price to see if calling obejct is greater than OtherOne
//PARAMETER: The original list
bool elem_t::operator>(const elem_t&OtherOne)
{
  Node *X = this->Front; //Front node of calling object
  Node *P = OtherOne.Front; //Front node of OtherOne object
  if(X->price > P->price) //Checks if Node's price is greater than other
    {
      return true; //if "calling object's" price variable is greater than "passed object"
    }
  else //not true
    {
      return false;
    }
}

//PURPOSE: Overload < function, checks each object's price to see if calling obejct is less than OtherOne
//PARAMETER: The original list
bool elem_t::operator<(const elem_t&OtherOne)
{
  Node *X = this->Front; //Front node of calling object
  Node *P = OtherOne.Front; //Front node of OtherOne object
  if(X->price < P->price) //Checks if Node's price is less than other
    {
      return true; //if "calling object's" price variable is greater than "passed object"
    }
  else //not true
    {
      return false;
    }
}

//PURPOSE: Overload == function, checks each object's price to see if calling obejct is similar value to OtherOne
//PARAMETER: The original list
bool elem_t::operator==(const elem_t&OtherOne)
{
  Node *X = this->Front; //Front node of calling object
  Node *P = OtherOne.Front; //Front node of OtherOne object
  if(X->price == P->price) //Checks if Node's price is similar value to other
    {
      return true; //if "calling object's" price variable is similar value to "passed object"
    }
  else //not true
    {
      return false;
    }
}

//PURPOSE: Overload - function, returns float value of object's price minus OtherOne's price
//PARAMETER: The original list
float elem_t::operator-(const elem_t&OtherOne)
{
  Node *X = this->Front; //Front node of calling object
  Node *P = OtherOne.Front; //Front node of OtherOne object
  return (X->price - P->price); //Return value of X's price minus P's price
}

//PURPOSE: Overload cout, display X's price and E's count variables
//PARAMETER: ostream and original list
ostream& operator<<(ostream& os, const elem_t& E)
{
  Node *X = E.Front; //E's front pointer set to Node X
  os << "$" << X->price << "[" << E.Count << "] "; //display message
  return os;
}
