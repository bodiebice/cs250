#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

void stringIn(string&, const int*);
void stringManip(string&);
void stringOut(string&);

int main()
{
  const int size = 80;
  const int *sptr = &size;
  string word;
  string key = "quit";
  static bool done = false;
  while (done==false)
  {
    stringIn(word,sptr);
    if (word==key)
    {
      done = true;
    }
    if (done==false)
    {
      stringManip(word);
      stringOut(word);
    }
  }

  return 0;

}

void stringIn(string& word, const int* size )
{
  bool messed = false;
  string verify = "@";
  cout<<"Please enter a word: ";
  getline(cin, word);
  for (int index = 0; index<word.length(); index++)
  {
    if (word[index] < verify[0] )
    {
      messed = true;
    }
  }


  while (messed==true)
  {
    cout<<"Error: Non Alphabetic Character Detected. Please Try Again.";
    getline(cin,word);
    for (int indexio = 0; indexio<word.length(); indexio++)
    {
      if (word[indexio] < verify[0] )
      {
        messed = true;
      }
      else
      {
        messed  = false;
      }
    }  
  }
  return;
}

void stringManip(string& word)
{
  int length = word.length();
  string i = "i";
  string suffix = "es";
  string suffix2 = "s";
  if (word[length-1] == 'y')
  {
    word.replace(length-1, 1, i);
    word.append(suffix);
  }
  else if (word[length-1] == 's')
  {
    word.append(suffix);
  }
  else if (word[length-2] == 'c'&& word[length-1] == 'h'|| word[length-2] == 's' && word[length-1] == 'h')
  {
    word.append(suffix);
  }
  else
  {
    word.append(suffix2);
  }

  return;
}

void stringOut(string& word)
{
  cout<<"Your fixed string is "<<word<<endl;
  return;
}