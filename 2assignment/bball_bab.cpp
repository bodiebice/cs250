#include <iostream>
#include <fstream>
using namespace std;

const int row_length = 10;
const int col_length = 7;

void dataIn(double[row_length][col_length]);
void dataOut(double[col_length], double [row_length], double&);
void averageGame(double[row_length][col_length], double [col_length]);
void averagePlayer(double[row_length][col_length], double[row_length]);
void averagePPG(double[row_length][col_length], double&);

int main ()
{
  double stats[row_length][col_length];
  double ppg[7];
  double ppp[10];
  double appg = 0;
  int test = 0;
  cout<<"Welcome to my program."<<endl;
  dataIn(stats);
  //averageGame(stats, ppg);
  //averagePlayer(stats, ppp);
  //dataOut(ppg,ppp,appg);
  
  

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
      cout << stats[index][indexy]<<index<<indexy<<endl;
      
    }
  inputFile.close();
  }
  return;
}

void averageGame(double stats[row_length][col_length], double ppg[col_length])
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
      cout<<stats[indexy][index]<<" ";
      tally +=stats[indexy][index];
      counter++;
      
      // the code below was my test when debugging to make sure that tally was being added up correctly.
      //cout<<tally<<endl;
    }
    cout<<endl<<tally<<endl;
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

void averagePPG(double stats[row_length][col_length], double &appg)
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
    cout<<tally<<endl;
  }
  appg = tally/counter;
  cout<<appg<<endl;

  return;
}

void dataOut(double ppg [col_length], double ppp [row_length], double &appg)
{
  int menu = -1;
  int index = 0;
  int gamecount = 0;
  bool done = false;
  cout<<"Welcome to our program: Enter 1 for the average points scored per game, 2 for the average points a player scored over a length of games \n";
  cout<<"or 3 for the average points all players scored over the length of games indicated on the data file entered. Enter 4 to end program. \n "<<endl;
  while (done==false)
  {
    cin>> menu;
    switch (menu) {
      case 1:
        gamecount = 0;
        index = 0;
        for (index = 0; index<col_length; index++)
        {
          gamecount++;
          cout<<"Game"<<gamecount<<": "<<ppg[index]<<endl;
        }
      break;
      case 2: 
        gamecount  = 0;
        index = 0;
        for (index  = 0; index<row_length; index++)
        {
          gamecount++;
          cout<<"Player"<<gamecount<<": "<<ppp[index]<<endl;
        }
      break;
      case 3:
        cout<<"The average points scored per player per game was"<<appg<<endl;
      break;
      case 4:
        done = true;
      break;
      default: 
        cout<<"Sorry, the integer you entered was not valid, enter a valid intiger."<<endl;
      break;
    }
  }
  return;
}





