#include <iostream>
#include <fstream>
#include <iomanip>
#include <istream>
#include <limits>
using namespace std;

// this col_width var will be however long the account numbers for this institution will be, assuming that they're constant.
static int rows = 0;
int* rptr = &rows;
static bool done = false;

void welcome(char*);
void arraySize(int*);
void dataIn(int*, int*);
void dataSort(int*);
void dataSwap(int*, int*);
void dataQuery(int*);
void dataSearch(int*, int*, int*, int*);
void dataPrint(int*, int*);

int main()
{
  char initialize = 0;
  char* cptr = &initialize;
  welcome(cptr);
  if (initialize=='1')
  {
    arraySize(rptr);
    int datamain[*rptr];
    int *dptr = datamain;

    dataIn(rptr, dptr);
    dataSort(dptr);
    //  below is my extremely lazy check for if the inital sort function worked on the data provided for the test.
    //  cout<<dptr[0]<<endl<<dptr[1]<<endl<<dptr[2]<<endl<<dptr[3]<<endl<<dptr[4]<<endl;
    if (done == false)
      {
        dataQuery(dptr);
      }
  }

  return 0;
}

// ****************************************************************** //
// this function welcomes the user to the program and will tell them  //
// what the requirements to use the program are before they continue  //
// to make sure that the user knows what they need for the program.   //
// ****************************************************************** //

void welcome(char *cptr)
{
  cout<<endl;
  cout<< "Welcome to this Program! To Continue, you must have a txt file named accounts.txt"<<endl;
  cout<< "and within that file the first line should have the number of accounts in the dataset."<<endl;
  cout<<endl<<"If you acknowledge this, Press 1, press any other character to exit the program."<<endl;
  cin>>*cptr;
  while (cin.fail() == true)
    {
      cout<<"invalid character"<<endl;
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
      cin>>*cptr;
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
  // puts the first integer that designates how big the array is into a pointer back to rows, a global static.
  inputFile>>*rptr;
  // below is my check to make sure the thing works.
  // cout<<*rptr<<endl;
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
  ifstream inputFile;
  int placeholder, index = 0, garbagevalue = 0, trashvalue = 0;;
  inputFile.open("accounts.txt");
  // this inputFile will take the number that designates how big the array is into a garbage integer
  inputFile>>garbagevalue;
  // this for loop is to put the rest of the input into the array in main through pointers
  for (index = 0; index<rows; index++)
  {
    inputFile>>trashvalue;
    if (trashvalue>0)
    {
      dptr[index] = trashvalue;
    }
    //cout<<dptr[index]<<endl;
  }
  return;
}

void dataSort(int *dptr)
{
  int minindex, minvalue;
  for (int start = 0; start<(rows-1);start++)
  {
    minindex = start;
    minvalue = dptr[start];
    for (int index = start + 1; index < rows; index++)
      {
        if (dptr[index] < minvalue)
          {
            minvalue = dptr[index];
            minindex = index;
          }
    
    }
    int* a = &dptr[minindex];
    int* b = &dptr[start];

    dataSwap(a,b);
  
  }
  return;
}

void dataSwap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}

void dataQuery(int* dptr)
{
  int searched = 0;
  int* sptr = &searched;
  cout<<endl<<endl<<"Enter an account number you'd like to search. Enter -1 if you'd like to exit the program."<<endl;
  cin>>*sptr;
  while (cin.fail() == true)
    {
      cout<<"invalid input, please enter an integer of the account number: "<<endl;
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
      cin>>*sptr;
    }
  if (*sptr==-1)
  {
    done = true;
    cout<<"Program is Closing, Have a Good Day!"<<endl;
  }
  int flagio;
  int* fptr = &flagio;
  dataSearch(dptr,rptr,sptr,fptr);
  dataPrint(sptr, fptr);
  
  
  return;
}

void datasearch(int* dptr,int* rptr, int* sptr, int* fptr)

{
  int first = 0;
  int last = *rptr - 1;
  int middle;
  int position = -1;
  bool found = false;

  while (!found && first<=last)
  {
    middle = (first+last)/2;
    if (dptr[middle]== *sptr)
    {
      found = true;
      position = middle;
    }
    else if(dptr[middle]>middle)
    {
      last = middle-1;
    }
    else
    {
      first = middle+1;
    }
  }

  if (found==true)
  {
    *fptr = 1;
  }
  else if (found==false)
  {
    *fptr = 2;
  }

  return;
}

void dataPrint(int* sptr, int* fptr)
{
  if (*fptr ==1)
  {
    cout<<"The number you entered is a valid account number"<<endl;
  }
  else
  {
    cout<<"The account number you entered is not in our system, try again?"<<endl;
  }
}