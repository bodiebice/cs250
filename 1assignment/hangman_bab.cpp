//this code allows for the user to play hangman against a computer with a set program.

#include <iostream>
#include <iomanip>
using namespace std;

int checkPlease(char[5], char &);
int verifyWinner(char[5], char &);
int countLoss(char[5], char &);
int main()
{
  char word[5] = {'v','e','n','u','s'};

  char guessed[5]={'*','*','*','*','*'};
  char guess;
  bool game = true; 
  int bingo = -1;
  int corr = 0;
  int incor = 0;
  int attleft = 5;

    // this while loop will send the user through picking a letter to guess and then 
    // it will determine at the end if the game is over, if it is through the two conditions,
    // it will set bool *game* to true.

  while (game==true)
  {
    cout<<"\nEnter a character to guess for Hangman (undercase letters only)\n";
    cin>>guess;

    bingo = checkPlease(word, guess);

    // depending on the input code from the function checkPlease, it will send the variable guess along
    // with the respective array to either verifyWinner in case of a hit, and countLoss in case of a miss

    switch (bingo) {
      case 1: 
        corr++;
        cout<<"Correct! You have correctly guessed "<<corr<<" letters correct out of 5! \n";
        bingo = verifyWinner(word, guess);
      break;
      case -1:
        incor++;
        attleft = attleft - incor;
        cout<<"Incorrect, you have "<<attleft<<" attempts left! \n";
        bingo = countLoss(guessed, guess);
        attleft = 5;
      break;
    }

    // this section of while loop determines if either switch case function 
    // gave a code that signals that the user either won or lost.
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
    // this function checks the guessed character against the word being guessed.

int checkPlease(char word[5], char &guess)
{
  int index = 0;
  int bingo = -1;
    // go through the word venus to see if the word guessed is in the array
  for (index=0;index<=4;index++){
    if (guess==word[index]){
      bingo=1;
      word[index] = '*';
    }
  }
  index=0;
  return bingo;
}

    // this function keeps track of what characters have been guessed correctly 
    // and accurately tells the computer when the word has been guessed.

int verifyWinner(char word[5], char &guess)
{
  int bingo = 1;
  if (word[4]=='*'){
    bingo = 2;
  }
  return bingo;
}
    // this function will keep trach of incorrect characters guessed and will detect when a user looses

int countLoss(char guessed[5], char&guess)
{
  int index = 0;
  int bingo = -1;
  bool gotcha = false;
  gotcha = false;
  for (index =0; index<=4; index++)
  { 
    if (guessed[index]=='*'&&gotcha==false){
      guessed[index]=guess;
      gotcha=true;
    }
  }
  if (guessed[4]!='*'){
    bingo=3;
  }
  ;
  return bingo;
}
