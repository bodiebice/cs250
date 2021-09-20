#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// this col_width var will be however long the account numbers for this institution will be, assuming that they're constant.
const int col_width = 7;
int rows = 0;

void welcome(int&);
int arraySize();
void dataIn(int[][col_width]);
void dataSort(int[][col_width]);
void dataSearch(int[][col_width]);
void dataPrint(int&,int&);

int main()
{
  int initialize = 0;
  welcome(initialize);
  if (initialize==true)
  {
    const int rows = arraySize();
    int datamain[rows][col_width];
    dataIn(datamain);
    dataSort(datamain);
    dataSearch(datamain);
  }

  return 0;
}

void welcome(int &initialize)
{
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