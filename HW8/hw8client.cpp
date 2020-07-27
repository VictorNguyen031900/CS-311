// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Victor Nguyen
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include<iostream>
#include<fstream>
#include<string>
#include "htable.h"


// This tester gets input data interactively but
// for a useful client, input should come from a file.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+name to add to the table. e.g. el_t X(30, "mary");
int main()
{
  //Loop:  
  //Interactively add about 20 keys and names to the table,
  //making sure some of them  collide. (function add)
  //You can create el_t containing a key and name using a constructor.
  //DisplayTable.
  //Loop:
  //Interactively look up names using keys. (function find)
  //Cout the key + name if found else (blank element was returned)
  //an error message.
  htable table1; //htable object
  el_t blank; //el_t object to used later to compare
  int searchKey; //key variable to send to hash function
  int objKey;
  string objName;
  //int key1; //key variable to send to hash function //USED FOR IFSTREAM
  //string name1; //name variable to make el_t object //USED FOR IFSTREAM
  //string fname; //file name variable to get input file //USED FOR IFSTREAM
  //╔═══════════════════════════════╗
  //║                               ║
  //║IFSTREAM TO MAKE TESTING EASIER║
  //║                               ║
  //╚═══════════════════════════════╝
  //cout << "Enter a file name: ";
  //cin >> fname;
  //ifstream fin (fname.c_str(), ios::in);
  //while(fin >> name1)
  //{
  //fin >> key1;
  //el_t test(key1, name1);
  //table1.add(test);
  //}
  //fin.close();
  cout << "╔═════════════════════════════════════════════════╗" << endl;
  cout << "║        Enter an account #(0-999) and name       ║" << endl;
  cout << "╚═════════════════════════════════════════════════╝" << endl;
  for(int i = 1; i <= 20; i++) // For-Loop enter in names and account numbers
    { 
      cout << "Person #" << i << " name: ";
      cin >> objName;
      cout << objName << "'s account number: ";
      cin >> objKey;
      el_t account(objKey, objName); // initialize an object with account number and name
      table1.add(account); //add object to table
    }

  cout << endl;
  cout << "╔═════════╗" << endl;
  cout << "║  Table  ║" << endl;
  cout << "╚═════════╝" << endl;
  table1.displayTable(); //display table

  cout << endl;
  cout << "╔═════════════════════════════════════════════════════════╗" << endl;
  cout << "║  Note to exit program, enter -1 when looking for a key. ║" << endl;
  cout << "╚═════════════════════════════════════════════════════════╝" << endl;
  while(searchKey != -1) //While-Loop search for a name based from a key
    {
      cout << "Look for?: ";
      cin >> searchKey; //variable used as a key
      if(searchKey != -1)
	{
	  el_t tester = table1.find(searchKey); //find function returns object based from key and operator= to a blank test object
	  if(blank == tester) //checks if each object's key is the same as -1(meaning empty/blank objects)
	    {
	      cout << searchKey << " not found." << endl; //display cannot find because object is basically empty
	    }
	  else //object's key is not -1(meaning object was found)
	    {
	      cout << "Found " << searchKey << ": " << tester << endl; //display key and object because it was found
	    }
	}
      else //if the user enters in -1 as the search key to quit the program, using -1 to exit because -1 is an invalid slot number
	{
	  cout << "Quit Program." << endl;
	  break;
	}
    }
  return 0;
}
