#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <limits>
using namespace std;


void stringIn(char*, const int*);
void stringManip(char*);
void stringOut(char*);



int main()
{
  const int size = 80;
  const int * sptr = &size;
  static char word[size];
  char* aptr = word;
  char key[5] = "quit";
  static bool done = false;
  while (done == false)
  {
    stringIn(aptr,sptr);
    if (strcmp(aptr,key) == 0)
    {
      done = true;
    }
    if (done == false)
    {
      stringManip(aptr);
      stringOut(aptr);
    }
  }

  return 0;
}

//This function will have the user input a word. It will check to make sure that the word is an alphabetic character.

void stringIn(char* aptr, const int* size)
{
  bool messed = false;
  cout<<"Please enter a word: ";
  cin.getline(aptr, *size);
  for (int index = 0; index<strlen(aptr); index++)
  {
    if (isalpha(aptr[index]) == false)
    {
      messed = true;
    }
  }
  // this while loop will have the user start over again if any character in their array is not an alphabetic character.
  while (messed==true)
  {
    cout<<"Error: Non Alphabetic Character Detected. Please Try Again.";
    cin.getline(aptr, *size);
    for (int indexio = 0; indexio<strlen(aptr); indexio++)
    {
      if (isalpha(aptr[indexio]))
      {
        messed = true;
      }
    }
  }
  return;
}

// this function will take the paramaters outlined in the instructions and change the user input based on those
// instructions

void stringManip(char* aptr)
{
  int length = strlen(aptr);
  if (aptr[length-1] == 'y')
  {
    aptr[length-1] = 'i';
    strcat(aptr,"es");
  }
  else if (aptr[length-1] == 's')
  {
    strcat(aptr, "es");
  }
  else if (aptr[length-2] == 'c'&&aptr[length-1]== 'h'|| aptr[length-2] == 's' && aptr[length-1]=='h')
  {
    strcat(aptr, "es");
  }
  else
  {
    strcat(aptr, "s");
  }

  return;
}

// this short function prints the fixed  cstring.

void stringOut(char* aptr)
{
  cout<<"Your fixed cstring is "<<aptr<<endl;
  return;
}