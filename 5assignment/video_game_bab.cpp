#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
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
void initializeData(videogame*);
void userMenu(videogame*);
void menuOne(videogame*);
void videogameSort(videogame*);
void dataSwap(videogame*, videogame*);
void menuTwo(videogame*);
void menuThree(videogame*);
void menuFour(videogame*);

int main()
{
  videogame* vptr;
  initializeData(vptr);
  userMenu(vptr);
  return 0;
}

void initializeData(videogame* vptr)
{
  videogame library[5] = {
    {"League of Legends",Strategy,3,9.50},
    {"Team Fortress 2",FPS,5,16.75},
    {"Ultima 7: The Black Gate",RolePlay,1,4.25},
    {"Halo",FPS,2,.75},
    {"Command and Conquer: Red Alert",Strategy,4,6.75}
  };
  vptr = library;
  return;
}

void userMenu(videogame* vptr)
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
      menuOne(vptr);
    }
    else if (menu==2)
    {
      menuTwo(vptr);
    }
    else if (menu==3)
    {
      menuThree(vptr);
    }
    else if (menu==4)
    {
      menuFour(vptr);
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

void menuOne(videogame* vptr)
{
  videogameSort(vptr);
  string placeholder[sizeof(vptr)];
  string toprint[(sizeof(vptr))];
  for (int index = 0; index<sizeof(vptr); index++)
  {
    switch (vptr[index].gameType)
    {
    case FPS : placeholder[index] = "FPS";
    break;
    case RolePlay : placeholder[index] = "RolePlay";
    break;
    case Strategy : placeholder[index] = "Strategy";
    break;
    }

  }
  for (int indexio = 0; indexio<sizeof(vptr); indexio++)
  {
    toprint[indexio].append(vptr[indexio].title);
    toprint[indexio].append(placeholder[indexio]);
    toprint[indexio].append(to_string(vptr[indexio].rank));
    toprint[indexio].append(to_string (vptr[indexio].time));

    cout<<toprint[indexio]<<endl;
  }
  return;
}


void videogameSort(videogame* vptr)
{
  int minindex, minvalue;
  int rows = sizeof(vptr);

  for (int start = 0; start<(rows-1);start++)
  {
    minindex = start;
    minvalue = vptr[start].rank;
    for (int index = start + 1; index < rows; index++)
      {
        if (vptr[index].rank < minvalue)
          {
            minvalue = vptr[index].rank;
            minindex = index;
          }
    
    }
    videogame* ptr1 = &vptr[minindex];
    videogame* ptr2 = &vptr[start];

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

void menuTwo(videogame* vptr)
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
  for (int indexia = 0; indexia<sizeof(vptr); indexia++)
  {
    int found;
    found = query.find(vptr[indexia].title);
    if (found!=string::npos)
    {
      bingo = indexia;
    }
    else if (query.compare(vptr[indexia].title) > 0)
    {
      bingo = indexia;
    }
    else
    {
      bingo = -2;
    }
  }
  string placeholder;
  
  switch (vptr[bingo].gameType)
  {
  case FPS : placeholder = "FPS";
  break;
  case RolePlay : placeholder = "RolePlay";
  break;
  case Strategy : placeholder = "Strategy";
  break;
  }

  string toprint;

  toprint.append(vptr[bingo].title);
  toprint.append(placeholder);
  toprint.append(to_string(vptr[bingo].rank));
  toprint.append(to_string (vptr[bingo].time));


  return;
}

void menuThree(videogame* vptr)
{

  double bucket;

  for (int index = 0; index<sizeof(vptr); index++)
  {
    bucket = bucket + vptr[index].time;
  }

  cout<<"The total time spent on all games is ";
  cout<<setprecision(2)<<fixed<<bucket;
  cout<<" days"<<endl;

  return;
}

void menuFour(videogame* vptr)
{
  int counter, bucket;
  double total;
  for (int index = 0; index<sizeof(vptr); index++)
  {
    bucket = bucket + vptr[index].rank;
    counter++;
  }
  total = bucket / counter;
  cout<<"The average rank is";
  cout<<setprecision(2)<<fixed<<total;
  return;
}

