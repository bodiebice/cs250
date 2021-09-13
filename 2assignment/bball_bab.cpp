#include <iostream>
#include <fstream>
using namespace std;

void dataIn(int[][7]);
void dataOut(int[][7], int [], int []);
void averageGame(int[][7], int []);
void averagePlayer(int[][7], int[]);
void averagePPG(int[][7], int&);

int main ()
{
  int stats[10][7];
  int ppg[7];
  int ppp[10];
  int appg = 0;
  int test = 0;
  
  dataIn(stats);
  averageGame(stats, ppg);
  
  

  return 0;
}

void dataIn(int stats[10][7])
{
  ifstream inputFile;
  inputFile.open("game_data.txt");
  int index = 0;
  int indexy = 0;
  int placeholdervalue;
  // this following double for loop will read in the data of a file and put it into a 2d array.
  for (index = 0; index<=9; index++)
  {
    for (indexy = 0; indexy<=6; indexy++)
    {
      inputFile >> placeholdervalue;
      stats [index][indexy] = placeholdervalue;
    }
  }

  return;
}

void averageGame(int stats[10][7], int ppg[7])
{
  int index = 0;
  int indexy = 0;
  int tally = 0;
  int counter = 0;
  for (index = 0; index<=6; index++)
  {
    for (indexy = 0; indexy<=9; indexy++)
    {
      tally = tally + stats[indexy][index];
      counter++;
    }
    ppg[index] = tally/counter;
    cout<<ppg[index]<<"\n";
  }


  return;
}

