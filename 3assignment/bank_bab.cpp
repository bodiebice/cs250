#include <iostream>
#include <fstream>
#include <iomanip>
#include <istream>
#include <limits>
using namespace std;

// this col_width var will be however long the account numbers for this institution will be, assuming that they're constant.
static int rows = 0;
int* rptr = &rows;

void welcome(int&);
void arraySize(int*);
void dataIn(int*, int*);
void dataSort(int*);
//void dataSearch(int[]);
//void dataPrint(int&,int&);

int main()
{
  int initialize = 0;
  welcome(initialize);
  if (initialize==1)
  {
    arraySize(rptr);
    int datamain[*rptr];
    int *dptr = datamain;

    dataIn(rptr, dptr);
    dataSort(dptr);
    //dataSearch(datamain);
  }

  return 0;
}

// ****************************************************************** //
// this function welcomes the user to the program and will tell them  //
// what the requirements to use the program are before they continue  //
// to make sure that the user knows what they need for the program.   //
// ****************************************************************** //

void welcome(int &initialize)
{
  cout<<endl;
  cout<< "Welcome to this Program! To Continue, you must have a txt file named accounts.txt"<<endl;
  cout<< "and within that file the first line should have the number of accounts in the dataset."<<endl;
  cout<<endl<<"If you acknowledge this, Press 1, press any other character to exit the program."<<endl;
  cin>>initialize;
  while (cin.fail() == true)
    {
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
      cin>>initialize;
    }
  return;
}

// ******************************************************************   //
// this function will take the integer in accounts.txt that determines  //
// how many rows of data the 2d array will need to hold account numbers //
// and inputs that into a global constant varaible titled 'rows'        //
// ******************************************************************   //

void arraySize(int *rptr)
{
  int rows = 0;
  ifstream inputFile;
  inputFile.open("accounts.txt");
  inputFile>>*rptr;
  cout<<*rptr<<endl;
  inputFile.close();

  return;

}

// ********************************************************************   //
// this function will take the integers in accounts.txt and through       //
// a pointer will store it inside of datamain inside of main. datamin is  //
// made using rows before it as how big the array is.                     //
// ********************************************************************   //

void dataIn(int *rptr, int *dptr)
{
  
  cout<<"Hi World"<<endl;
  ifstream inputFile;
  int placeholder, index = 0, indexio = 0,counter = 0;
  int holddata[rows];
  inputFile.open("accounts.txt");
  inputFile>>counter;
  //this for loop is to 
  for (index = 0; index<rows; index++)
  {
    inputFile>>dptr[index];
    cout<<dptr[index]<<endl;
    
  }
  return;
}

void dataSort(int *dptr)
{
  
  return;
}