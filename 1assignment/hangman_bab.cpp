//this code allows for the user to play hangman against a computer with a set program.

#include <iostream>
#include <iomanip>
using namespace std;

int checkplease(char[5], char &);
int verifywinner(char[5], char &);
int countloss(char[5], char &);
int main()
{
  char word[5] = {'v','e','n','u','s'};
  char guessed[5]={'*','*','*','*','*'};
  char guess;
  bool game = true; 
  int bingo = 0;
  while (game==true)
  {
    cout<<"Enter a character to guess for Hangman\n";
    cin>>guess;

    bingo = checkplease(word, guess);
    switch (bingo) {
      case 1: bingo = verifywinner(word, guess);
      break;
      case -1: bingo = countloss(guessed, guess);
      break;
    }
    if (bingo==2){
      game = false;
      cout<<"Congrats, You've won!\n";
    }
    else if (bingo==3){
      game = false;
      cout<<"Sorry, You've guessed too many times!\n";
    }
    else{
      game = true;
    }
  }
  return 0;
}
//this function checks the guessed character against the word being guessed.
int checkplease(char word[5], char &guess)
{
  int index = 0;
  int bingo = -1;
  //go through the word venus to see if the word guessed is in the array
  for (index=0;index<=5;index++){
    if (guess==word[index]){
      bingo=1;
      word[index] = '*';
    }
  }
  index=0;
  return bingo;
}

//this function keeps track of what characters have been guessed correctly and accurately tells the computer when the word has been guessed.
int verifywinner(char word[5], char &guess)
{
  int index = 0;
  int bingo = 1;
  cout<<word<<"\n";
  return bingo;
}

