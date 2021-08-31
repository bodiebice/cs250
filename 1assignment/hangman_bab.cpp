//this code allows for the user to play hangman against a computer with a set program.

#include <iostream>
#include <iomanip>
using namespace std;

int checkplease(char[5], char &);
int verifywinner(char[5], char &, int &,);
int checkloss
int main()
{
  char word[5] = {'t','i','t','a','n'};
  char guessed;
  bool won = false; 
  int bingo = 0;
  //while (won==false)
  //{
    cout<<"Enter a character to guess for Hangman\n";
    cin>>guessed;

    bingo = checkplease(word, guessed);
    cout<<bingo<<"\n";
  //}
  return 0;
}

int checkplease(char word[5], char &guessed)
{
  int index = 0;
  int bingo = -1;
  //go through the word titan to see if the word guessed is in the array
  for (index=0;index<=5;index++){
    if (guessed==word[index]){
      bingo=index;
      word[index] = '*';
    }
  }
  index=0;
  return bingo;
}

