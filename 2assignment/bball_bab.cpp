#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

const int row_length = 10;
const int col_length = 7;

void welCome(int&);
void dataIn(float[row_length][col_length]);
void dataOut(float[col_length], float [row_length], float&);
void averageGame(float[row_length][col_length], float [col_length]);
void averagePlayer(float[row_length][col_length], float[row_length]);
void averagePPG(float[row_length][col_length], float&);

int main ()
{
  float stats[row_length][col_length];
  float ppg[7];
  float ppp[10];
  float appg = 0;
  int welcome = -1;

  welCome(welcome);
  if (welcome == 1)
  {
    dataIn(stats);
    averageGame(stats, ppg);
    averagePlayer(stats, ppp);
    averagePPG(stats, appg);
    dataOut(ppg,ppp,appg);
  }
  
  
  

  return 0;
}

void welCome(int& welcome)
{
  cout<<endl<<"Welcome to this program. This program takes in Basketball Stats and will eventually spit out macro stats using your stats. Please"<<endl<<"verify that your text file is named game_data.txt and that your text file does not have any non-integers in it. Thanks - Bodie Bice."<<endl<<" Press 1 to accept or any other character to exit."<<endl;
  cin>>welcome;
  while (cin.fail() == true)
    {
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
      cin>>welcome;
    }
  return;
}


void dataIn(float stats[row_length][col_length])
{
  ifstream inputFile;
  inputFile.open("game_data.txt");
  int index = 0, indexy = 0, indexo = 0, count  = 0;
  float intake[70];
  
  for (indexo=0; indexo<70; indexo++)
  {
    inputFile >> intake[indexo];
    //cout << intake[indexo] << " " << indexo <<endl;
  }
  // this following float for loop will read in the data of a file and put it into a 2d array.
  for (index = 0; index<row_length; index++)
  {
    for (indexy = 0; indexy<col_length; indexy++)
    {
      stats [index][indexy] = intake[count];
      count++;
      //cout << stats[index][indexy]<<" "<<index<<indexy<<endl;
      
    }
  inputFile.close();
  }
  return;
}

void averageGame(float stats[row_length][col_length], float ppg[col_length])
{
  int index = 0;
  int indexy = 0;
  float tally = 0, counter = 0;
  
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

void averagePlayer(float stats[row_length][col_length], float ppp[row_length])
{
  int index = 0, indexy = 0;
  float tally = 0, counter = 0;
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

void averagePPG(float stats[row_length][col_length], float &appg)
{
  int index = 0, indexy = 0;
  float tally = 0, counter = 0;
  for (index = 0; index<row_length; index++)
  {
    for (indexy = 0; indexy<col_length; indexy++)
    {
      tally += stats[index][indexy];
      counter++;
    }
    //cout<<tally<<endl;
  }
  appg = tally/counter;
  //1cout<<appg<<endl;

  return;
}

void dataOut(float ppg [col_length], float ppp [row_length], float &appg)
{
  int menu = -1;
  int index = 0;
  int gamecount = 0;
  bool done = false;
  cout.precision(3);
  cout<<endl<<"Enter 1 for the average points scored per game, 2 for the average points a player scored over a length of games \n";
  cout<<"or 3 for the average points all players scored over the length of games indicated on the data file entered. Enter 4 to end program. \n "<<endl;
  while (done==false)
  {
    cin>> menu;
    while (cin.fail() == true)
    {
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
      cin>>menu;
    }
    switch (menu) {
      case 1:
        gamecount = 0;
        index = 0;
        for (index = 0; index<col_length; index++)
        {
          gamecount++;
          cout<<"Game "<<gamecount<<": "<<ppg[index]<<endl;
        }
      break;
      case 2: 
        gamecount  = 0;
        index = 0;
        for (index  = 0; index<row_length; index++)
        {
          gamecount++;
          cout<<"Player "<<gamecount<<": "<<ppp[index]<<endl;
        }
      break;
      case 3:
        cout<<"The average points scored per player per game was "<<appg<<endl;
      break;
      case 4:
        done = true;
      break;
      default: 
        cout<<"Sorry, the integer you entered was not valid, enter a valid integer."<<endl;
      break;
    }
  }
  return;
}





