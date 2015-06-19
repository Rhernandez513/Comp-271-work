#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

struct conversion{
  string infix;
  string postfix;
  string prefix;
};

//implements there four and should be shown in the menu
string infixToPrefix(string expression);
string infixToPostfix(string expression);
bool fileOption(string filename);
bool readFile(string filename);
bool writeSolutionFile(vector<conversion> & solutions);

//Returns the number for instack priority
int isp(char ch);
//Returns the number for incoming priority
int icp(char ch);

//Should check char to see if it is letter or number (caps,lowercase, and number)
bool isOperand(char C);
//This should return true if isp>icp else false, also should check for right associativity by comapring isp==icp and char is '^'
bool hasHigherPrecedenceInToPre(char op1, char op2);
//This should prompt user to enter 1-3 for a choice or 0 to quit
void menuOption(int &choice);

int main()
{
  /*********
   *Variables you will need: a string for the expression the user will input,
   *string for the output you get from each function, a int for choice of what the user enters. 
   *If a user enters a choice that is NOT part of the menu prompt Not a valid choice try again.
   *A vector that holds conversion data type called solutions
  **********/
  return 0;
}

void menuOption(int &choice){
    
    cout<<"\n\n===Menu=== \n";
    cout<<"1. Infix to Prefix Conversion\n";
    cout<<"2. Infix to Postfix Conversion\n";
    cout<<"3. Read in a file of Infix Equations\n";
    cout<<"0 to quit\n";
    cout<<"Choice: ";
    cin >> choice;
}


