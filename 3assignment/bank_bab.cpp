#include <iostream>
#include <fstream>
#include <iomanip>
#include <istream>
using namespace std;

// this col_width var will be however long the account numbers for this institution will be, assuming that they're constant.
const int col_width = 7;


void welcome(int&);
int arraySize();
void dataIn(int[][col_width], int&);
//void dataSort(int[][col_width]);
//void dataSearch(int[][col_width]);
//void dataPrint(int&,int&);

int main()
{
  int initialize = 0;
  welcome(initialize);
  if (initialize==1)
  {
    int rows = arraySize();
    int datamain[rows][col_width];
    dataIn(datamain,rows);
    //dataSort(datamain);
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

int arraySize()
{
  int rows = 0;
  ifstream inputFile;
  inputFile.open("accounts.txt");
  inputFile>>rows;
  cout<<rows<<endl;
  

  return rows;

}


void dataIn(int datamain[][col_width], int& rows)
{
  cout<<"Hi World"<<endl;
  ifstream inputFile;
  int placeholder, index = 0, indexio = 0, indexia = 0, counter = 0;
  int holddata[10000];
  inputFile.open("accounts.txt");
  for (indexia = 0; indexia>10000; indexia++)
  {
    inputFile>>placeholder;
    cout<<placeholder;
    if (placeholder < 0)
    {
      holddata[indexia] = placeholder;
    }
    cout<<holddata[indexia]<<" ";
  }
  for (index = 0; index<rows; index++)
  {
    for (indexio = 0; indexio<col_width; indexio++)
    {
      datamain[index][indexio] = holddata[counter];
      counter++;
    }
  }
  
  return;
}

