//=============================================================
// CS 311 Final Project
// Your name: Victor Nguyen
// Compiler: g++
// File type: Client file
//=============================================================

#include <iostream>
#include <fstream>
#include "binstree.h"


using namespace std;

int main()
{
  //Variables used make a computer node
  string fname;
  string cpuName, cpuNum, cpuCat, gpuName, gpuNum, gpuCat, pctype;
  int ram;
  float price;
  //Variables used for user physical input
  float searchValue;
  bool quit = false;
  int menuKey;
  //user enter in file name
  cout << "Enter a file name: ";
  cin >> fname;
  //make binary search tree object
  BST MyTree;
  //open file based from string enter by user
  ifstream fin (fname.c_str(), ios::in);
  //while loop to automatically enter in data into nodes then to binary search tree 
  while(fin >> cpuName)
  {
    fin>> cpuNum;
    fin >> cpuCat;
    fin >> gpuName;
    fin >> gpuNum;
    fin  >> gpuCat;
    fin >> ram;
    fin >> pctype;
    fin >> price;
    Node hold; //Make node to hold data
    hold.cpu[0] = cpuName;
    hold.cpu[1] = cpuNum;
    hold.cpu[2] = cpuCat;
    hold.gpu[0] = gpuName;
    hold.gpu[1] = gpuNum;
    hold.gpu[2] = gpuCat;
    hold.pcType = pctype;
    hold.ram = ram;
    hold.price = price;
    hold.Next = NULL;
    MyTree.InsertVertex2(hold); //insert node to binary search tree
    //cout << "added vertex" << endl;
  }
  cout << "All entries from " << "\"" << fname << "\""<< " were entered into tree successfully!." << endl;
  //while loop to show user options
  while(quit == false)
    {
      cout << "=============================="<< endl;
      cout << "╔══════════╗" << endl;
      cout << "║   Menu   ║" << endl;
      cout << "╚══════════╝" << endl;
      cout << "1. Display all computers." << endl;
      cout << "2. Search for computer based from price." << endl;
      cout << "3. Quit Program." << endl;
      cout << "Enter option: ";
      cin >> menuKey;
      cout << "==============================" << endl;
      //switch case to handle user inputs
      switch(menuKey)
	{
	case 1: //option 1 is used to display the whole binary search tree
	  cout << "╔═════════════╗" << endl;
          cout << "║  Computers  ║" << endl;
          cout << "╚═════════════╝" << endl;
	  //all computers will be displayed in order
	  MyTree.Display2();
	  break;
	case 2: //option 2 is used to search for computer equal or closest to user's input
	  cout << "Enter in a price: $";
	  cin >> searchValue;
	  cout << "searching for a computer $" << searchValue<< endl;
	  cout << "╔═══════════════╗" << endl;
	  cout << "║  Computer(s)  ║" << endl;
	  cout << "╚═══════════════╝" << endl;
	  //computers closest to price will diplayed after this
	  MyTree.Search2(searchValue);
	  break;
	case 3: //option 3 is used to quit program
	  quit = true;
	  break;
	default:
	  cout << "Invalid menu option!" << endl;
	}
    }
  return 0;
}
