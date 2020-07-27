//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

//=======================================================
// HW#: HW3P1 llist
// Your name: Victor Nguyen
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //PURPOSE: Checks if the list is empty by front and rear being NULL and count being 0
  bool isEmpty();
    
  //PURPOSE: Displays all the elements in the nodes
  void displayAll();

  //PURPOSE: Adds a new node with its element to the front of the list
  //PARAMETERS: The new element that we want to add to the front of the list
  void addFront(el_t);
    
  //PURPOSE: Adds a new node with its element to the rear of the list
  //PARAMETERS: The new element that we want to add to the rear of the list
  void addRear(el_t);

  //PURPOSE: Removes the front node also with its element
  //PARAMETERS: Passing by reference the element that will be deleted
  void deleteFront(el_t&);
    
  //PURPOSE: Removes the rear node also with its element
  //PARAMETERS: Passing by reference the element that will be deleted
  void deleteRear(el_t&);
    
  //PURPOSE: Deletes the desired node and its element
  //PARAMETERS: The node that is going to be deleted and a variable to receieve the old element
  void deleteIth(int, el_t&);  // calls moveTo

  //PURPOSE: Adds a node and its element before the desired node
  //PARAMETERS: The node and the variable to send the old number to
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
