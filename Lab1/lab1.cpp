/*
* ExOne.cpp
*
*  Created on: Jan 16, 2014
*      Author: mdcsaenz
*/

#include <cmath>
#include <time.h>
#include <iostream>
using namespace std;

/**
* 1. There are 7 syntax errors and 1 logical error fix them
* 2. Create this function below, that will create a random number and if it is 0 then return 'r', etc etc
**/
char get_comp_val()
{
  int value = rand() % 3;
  char chars[] { 'r', 'p', 's' };
  return chars[value];
}


int main()
{
  char compval;
  char user_val = 'a';
  srand(time(NULL));
  cout << "We are going to play a game!";
  cout << "Rock, Scissors, Paper!";

  while (user_val != 'q')
  {
    cout << "On the count of three, you'll choose." << endl;
    cout << "For Rock, type an r. For Scissors, s. For Paper, p. or to quit, q";
    cout << "\n" << "1.. 2.. 3.." << endl;
    cin >> user_val;
    char comp_val = get_comp_val();
    if (comp_val == user_val)
    {
      cout << "TIE!" << endl;
    }
    else if (user_val == 'q')
    {
      cout << "Quitting thanks for playing" << endl;
    }
    else
    {
      if (comp_val == 'r')
      {
        if (user_val == 's')
        {
          cout << "Rock beats Scissor. You lose.\n";
        }
        else
        {
          cout << "Paper beats Rock. You win!\n";
        }
      }
      if (comp_val == 's')
      {
        if (user_val == 'r')
        {
          cout << "Rock beats Scissor. You lose!\n";
        }
        else
        {
          cout << "Scissor beats Paper. You lose.\n";
        }
      }
      if (comp_val == 'p')
      {
        if (user_val == 's')
        {
          cout << "Scissor beats Paper. You win!\n";
        }
        else
        {
          cout << "Paper beats Rock. You lose.\n";
        }
      }
    }
  }
  return 0;
}