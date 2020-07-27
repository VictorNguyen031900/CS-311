//==========================================================
//FINAL PROJECT
//Your name: Victor Nguyen
//Complier:  g++
//File type: Header file for elem.cpp
//==========================================================
#include <iostream>
#include <string>
using namespace std;

//Struct is inside elem_t object when initialized
struct Node
{
  Node *Next; //Point to next node in list if same price
  string cpu[3]; //Array to handle individual words
  string gpu[3]; //Array to hanlde individual words
  string pcType; //Computer category
  int ram; //How much memory a computer has
  float price; //Price of computer but also how everything is compared
};

//---------------------------------------------------------

class elem_t
{
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

 public:
  // Exception handling classes
  class Underflow{};
  class OutOfRange{}; //thrown when the specified Node is out of range

  elem_t(); //constructor to make elem_t
  ~elem_t(); //destructor to destroy all nodes

  //PURPOSE: Checks if the list is empty by front and rear being NULL and count being 0
  bool isEmpty();

  //PURPOSE: Displays all the elements in the nodes
  void displayAll();

  //PURPOSE: Adds a new node with its element to the rear of the list
  //PARAMETERS: The new element that we want to add to the rear of the list
  void addRear(Node);

  //PURPOSE: Removes the front node also with its element
  //PARAMETERS: Passing by reference the element that will be deleted
  void deleteFront(Node&);

  //PURPOSE: Removes the rear node also with its element
  //PARAMETERS: Passing by reference the element that will be deleted
  void deleteRear(Node&);

  //Overloading of = (returns a reference to a elem_t)
  elem_t& operator=(const elem_t&);

  //Overloading of > (returns true or false)
  bool operator>(const elem_t&);

  //Overloading of < (returns true or false)
  bool operator<(const elem_t&);

  //Overloading of == (returns true or false)
  bool operator==(const elem_t&);

  //Overloading of - (returns a float value)
  float operator-(const elem_t&);

  //Overloading of cout
  friend ostream& operator<<(ostream&, const elem_t& );
};
