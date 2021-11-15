#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

enum genre {FPS, Strategy, RolePlay};
struct videogame
{
  string title;
  genre gameType;
  int rank;
  double time;
};

void fileCreate();
void programMenu();
void menuOne();
void menuTwo();
void menuThree();
void menuFour();
void menuFive();



int main()
{
  fileCreate();
  programMenu();
  return 0;
}

void fileCreate()
{
  fstream dataFile;
  dataFile.open("game.dat", ios::in | ios::out | ios::binary);
  if (!dataFile)
  {
    dataFile.clear();
    dataFile.open("game.dat", ios::out);
  }
  dataFile.close();
  return;
}

void programMenu()
{
  int menu;
  bool clip = false;
  cout<<"Welcome to this program. Please press 1 to enter new entry, 2 to see all entries, 3 to see total time played, and 4 to see the average of all games played."<<endl;
  cout<<"Press 6 to exit program"<<endl;
  while (!clip)
  {
    cout<<" Please press 1 to enter new entry, 2 to see all entries, 3 to see total time played, and 4 to see the average of all games played."<<endl;
    cout<<"Press 6 to exit program"<<endl;
    cin>>menu;
    switch (menu)
    {
      case 1 : menuOne();
      break;
      case 2 : menuTwo();
      break;
      case 3 : menuThree();
      break;
      case 4 : menuFour();
      break;
      case 6 : clip = true;
      break;
      default : cout<<"Invalid Integer, Try Again.";
      break;
    }
  }
  return;
}

void menuOne()
{
  fstream dataFile;
  dataFile.open("games.dat", ios::out | ios::binary);

  videogame placeholder;
  int placeholderenum;
  bool flag = false;

  cout<<"Enter the title";
  getline(cin, placeholder.title);
  cout<<"Enter 0 for FPS, 1 for Strategy, and 2 for Roleplay";
  cin>>placeholderenum;
  switch (placeholderenum)
  {
    case 0 : placeholder.gameType = FPS;
    break;
    case 1 : placeholder.gameType = Strategy;
    break;
    case 2 : placeholder.gameType = RolePlay;
    break;
    default : cout<<"please enter valid integer";
    cin>>placeholderenum;
    flag = true;
    while (flag == true)
    {
      switch (placeholderenum)
      {
        case 0 : placeholder.gameType = FPS;
        flag = false;
        break;
        case 1 : placeholder.gameType = Strategy;
        flag = false;
        break;
        case 2 : placeholder.gameType = RolePlay;
        flag = false;
        break;
        default: cout<<"please enter valid integer";
        cin>>placeholderenum;
        break;
      }
    
    }
    break;
  }
  cout<<"Give this game a rating.";
  cin>>placeholder.rank;
  cout<<"How much time did you spend playing the game?";
  cin>>placeholder.time;

  dataFile.write(reinterpret_cast<char *>(&placeholder), sizeof(placeholder));

  dataFile.close();

  return;
}

void menuTwo()
{
  fstream dataFile;
  dataFile.open("games.dat", ios::out | ios::binary);
  videogame placeholder;

  while (!dataFile.eof())
  {
    dataFile.read(reinterpret_cast<char *>(&placeholder), sizeof(placeholder));

    cout<<"Title: ";
    cout<<placeholder.title<<endl;
    cout<<"Genre: ";
    switch (placeholder.gameType)
    {
      case 0: cout<<"FPS"<<endl;
      break;
      case 1: cout<<"Strategy"<<endl;
      break;
      case 2: cout<<"RolePlay"<<endl;
      break;
    }
    cout<<"Rank: ";
    cout<<placeholder.rank;
    cout<<"Time Played: ";
    cout<<fixed<<setprecision(2)<<placeholder.time;
  }
  dataFile.close();
  return;
}

void menuThree()
{
  fstream dataFile;
  dataFile.open("games.dat", ios::out | ios::binary);
  int counter, tally;
  double finaly;
  videogame placeholder;
  dataFile.read(reinterpret_cast<char *>(&placeholder), sizeof(placeholder));

  while(!dataFile.eof())
  {
    counter = placeholder.rank;
    tally++;

    dataFile.read(reinterpret_cast<char *>(&placeholder), sizeof(placeholder));
  }

  finaly = counter/tally;
  cout<<"The average rank of all games you have is: ";
  cout<<finaly<<endl;
  dataFile.close();
  return;
}

void menuFour()
{
  return;
}