using namespace std;
#include <iostream>
#include <vector>

//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Victor Nguyen
//Compiler: g++
//--------------------------------------------

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
  //**
  int ia = 0;
  int ib = 0;
  int ir = 0;
  while (ia < A.size() && ib < B.size())
    {
      if(A[ia] < B[ib])
	{
	  R[ir] = A[ia];
	  ia++;
	}
      else
	{
	  R[ir] = B[ib];
	  ib++;
	}
      cout << "comparison" << endl;
      ir++;
    }
  // ** // be careful -- R comes in as an empty vector
  if(ia < A.size())
    {
      cout << "The rest of the first one does down." << endl;
      while(ia < A.size())
	{
	  R[ir] = A[ia];
	  ia++;
	  ir++;
	}      
    }
  else
    {
      cout << "The rest of the first one does down." << endl;
      while(ib < B.size())
        {
          R[ir] = B[ib];
          ib++;
          ir++;
        }
    }
}


int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  

  // call combine here to combine L1 and L2 into L3

  L3.resize(N*2);

  combine(L1, L2, L3);
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

}// end of main
