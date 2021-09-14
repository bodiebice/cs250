#include <iostream>
#include <fstream>
using namespace std;

const int row_length = 10;
const int col_length = 7;

void dataIn(double[row_length][col_length]);
void dataOut(double[row_length][col_length], double [col_length], int [row_length]);
void averageGame(double[row_length][col_length], double [col_length]);
void averagePlayer(double[row_length][col_length], double[row_length]);
void averagePPG(double[row_length][col_length], int&);

int main ()
{
  double stats[row_length][col_length];
  double ppg[7];
  double ppp[10];
  int appg = 0;
  int test = 0;
  
  dataIn(stats);
  averageGame(stats, ppg);
  averagePlayer(stats, ppp);
  
  

  return 0;
}

void dataIn(double stats[row_length][col_length])
{
  ifstream inputFile;
  inputFile.open("game_data.txt");
  int index = 0;
  int indexy = 0;
  int placeholdervalue;
  // this following double for loop will read in the data of a file and put it into a 2d array.
  for (index = 0; index<row_length; index++)
  {
    for (indexy = 0; indexy<col_length; indexy++)
    {
      inputFile >> placeholdervalue;
      stats [index][indexy] = placeholdervalue;
      //cout << stats[index][indexy]<<endl;
    }
  inputFile.close();
  }
  return;
}

void averageGame(double stats[10][7], double ppg[7])
{
  int index = 0;
  int indexy = 0;
  double tally = 0;
  double counter = 0;
  for (index = 0; index<col_length; index++)
  {
    tally = 0;
    counter = 0;
    for (indexy = 0; indexy<row_length; indexy++)
    {
      tally +=stats[indexy][index];
      counter++;
      // the code below was my test when debugging to make sure that tally was being added up correctly.
      //cout<<tally<<endl;
    }
    ppg[index] = tally/counter;
    //the code below was my test to make sure that the index was being put into points per game correctly.
    //cout<<ppg[index]<<endl;
  }
  return;
}

void averagePlayer(double stats[row_length][col_length], double ppp[row_length])
{
  int index = 0, indexy = 0;
  double tally = 0, counter = 0;
  for (index = 0; index<row_length; index++)
  {
    tally = 0;
    counter = 0;
    for (indexy = 0; indexy<col_length; indexy++)
    {
      tally +=stats[index][indexy];
      counter++;
    }
    ppp[index] = tally/counter;
  }
  return;
}

void averagePPG(double stats[row_length][col_length], int& appg)
{
  int index = 0, indexy = 0;
  double tally = 0, counter = 0;
  for (index = 0; index<row_length; index++)
  {
    for (indexy = 0; indexy<col_length; indexy++)
    {
      tally += stats[index][indexy];
      counter++;
    }
  }
  appg = tally/counter;

  return;
}



