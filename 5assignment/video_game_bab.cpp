#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <array>
using namespace std;

//the following code is my enumerated type and structure that the program request file manages
enum genre {FPS, Strategy, RolePlay};
struct videogame
{
  string title;
  genre gameType;
  int rank;
  double time;
};

//prototypes
void initializeData(videogame[]);
void userMenu(videogame[]);
void menuOne(videogame[]);
void videogameSort(videogame[]);
void dataSwap(videogame*, videogame*);
void menuTwo(videogame[]);
void menuThree(videogame[]);
void menuFour(videogame[]);

int main()
{
  
  videogame library[5];
  initializeData(library);
  userMenu(library);
  return 0;
}

void initializeData(videogame library[])
{
  
  library[0] = {"League of Legends",Strategy,3,9.50};
  library[1] = {"Team Fortress 2",FPS,5,16.75};
  library[2] = {"Ultima 7: The Black Gate",RolePlay,1,4.25};
  library[3] = {"Halo",FPS,2,.75};
  library[4] = {"Command and Conquer: Red Alert",Strategy,4,6.75};
  
  return;
}

void userMenu(videogame library[])
{
  int menu = -1;
  bool cash = false;
  cout<<"Welcome to this database. To print info for all games sorted by rank, press ""1"", to"<<endl;
  cout<<"search and print specific game stats, press ""2"", to print the total time spent for all games"<<endl;
  cout<<"press ""3"". To print the average rank for all games, press ""4"". To exit the program press -1"<<endl;

  cin>>menu;
  while (cin.fail() == true)
    {
      cout<<"invalid value."<<endl;
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
      cin>>menu;
    }
  while (cash==false)
  {
    if (menu==1)
    {
      menuOne(library);
    }
    else if (menu==2)
    {
      menuTwo(library);
    }
    else if (menu==3)
    {
      menuThree(library);
    }
    else if (menu==4)
    {
      menuFour(library);
    }
    else if (menu == -1)
    {
      cash=true;
    }
    else if (menu < -1 && menu > 4)
    {
      cout<<"Please enter a number corresponding to menu actions, or -1 to exit the loop";
      cin>>menu;
      while (cin.fail() == true)
      {
      cout<<"invalid character"<<endl;
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
      cin>>menu;
      }
    }
  }
  return;
}

void menuOne(videogame library[])
{
  videogameSort(library);
  string placeholder[5];
  string toprint[5];
  for (int index = 0; index<5; index++)
  {
    switch ((library[index]).gameType)
    {
    case FPS : placeholder[index] = "FPS";
    break;
    case RolePlay : placeholder[index] = "RolePlay";
    break;
    case Strategy : placeholder[index] = "Strategy";
    break;
    }

  }
  for (int indexio = 0; indexio<5; indexio++)
  {
    toprint[indexio].append(library[indexio].title);
    toprint[indexio].append(placeholder[indexio]);
    toprint[indexio].append(to_string(library[indexio].rank));
    toprint[indexio].append(to_string (library[indexio].time));

    cout<<toprint[indexio]<<endl;
  }
  return;
}


void videogameSort(videogame library[])
{
  int minindex, minvalue;
  int rows = 5;

  for (int start = 0; start<(rows-1);start++)
  {
    minindex = start;
    minvalue = (library[start]).rank;
    for (int index = start + 1; index < rows; index++)
      {
        if (library[index].rank < minvalue)
          {
            minvalue = (library[index]).rank;
            minindex = index;
          }
    
    }
    videogame* ptr1 = &library[minindex];
    videogame* ptr2 = &library[start];

    dataSwap(ptr1,ptr2);
  } 
  return;
}

void dataSwap(videogame* a, videogame* b)
{
  videogame temp = *a;
  *a = *b;
  *b = temp;
  return;
}

void menuTwo(videogame library[])
{
  int bingo = -1;
  bool messed;
  string query;
  string verify = "@";
  cout<<"Enter a partial or full title name to bring up details";
  getline(cin,query);
  for (int index=0; index<query.length(); index++)
  {
    if (query[index] < verify [0])
    {
      messed = true;
    }
    else
    {
      messed = false;
    }
  }
  while (messed==true)
  {
    cout<<"Error: Non Alphabetic Character Detected. Please Try Again.";
    getline(cin,query);
    for (int indexio = 0; indexio<query.length(); indexio++)
    {
      if (query[indexio] < verify[0] )
      {
        messed = true;
      }
      else
      {
        messed  = false;
      }
    }
  }
  for (int indexia = 0; indexia<5; indexia++)
  {
    int found;
    found = query.find(library[indexia].title);
    if (found==0)
    {
      bingo = indexia;
    }
    else if (query.compare(library[indexia].title) > 0)
    {
      bingo = indexia;
    }
    else
    {
      bingo = -2;
    }
  }
  string placeholder;
  
  switch (library[bingo].gameType)
  {
  case FPS : placeholder = "FPS";
  break;
  case RolePlay : placeholder = "RolePlay";
  break;
  case Strategy : placeholder = "Strategy";
  break;
  }

  string toprint;

  toprint.append(library[bingo].title);
  toprint.append(placeholder);
  toprint.append(to_string(library[bingo].rank));
  toprint.append(to_string (library[bingo].time));

  cout<<toprint<<endl;

  return;
}

void menuThree(videogame* library)
{

  double bucket;

  for (int index = 0; index<sizeof(library); index++)
  {
    bucket = bucket + library[index].time;
  }

  cout<<"The total time spent on all games is ";
  cout<<setprecision(2)<<fixed<<bucket;
  cout<<" days"<<endl;

  return;
}

void menuFour(videogame library[])
{
  int counter, bucket;
  double total;
  for (int index = 0; index<5; index++)
  {
    bucket = bucket + library[index].rank;
    counter++;
  }
  total = bucket / counter;
  cout<<"The average rank is";
  cout<<setprecision(2)<<fixed<<total;
  return;
}

