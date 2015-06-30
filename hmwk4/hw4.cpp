#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>

//using namespace std;

struct conversion{
  std::string infix;
  std::string postfix;
  std::string prefix;
};

//implements there four and should be shown in the menu
std::string infixToPrefix(std::string expression);
std::string infixToPostfix(std::string expression);
bool fileOption(std::string filename);

bool readFile(const std::string filename)
{
  /* ===== INCOMPLETE ===== */
  int count = 0;
  std::string line;
  std::fstream inputStream(filename, std::fstream::in);
  bool openCheck = inputStream.is_open() ? true : false;
  if (openCheck) {
    while (inputStream.peek() != EOF) { 
      std::getline(inputStream, line);
      count++;
    }
    std::string* lines = new std::string[count];
    // Reset back to beginning of file
    inputStream.clear();
    inputStream.seekg(0);
    for (int i = 0; i <= count; i++;) {
      std::getline(inputStream, lines[i]);
      std::cout << lines[i] << std::endl;
    }
  }
  inputStream.close();
  return openCheck;
}

bool writeSolutionFile(std::vector<conversion> & solutions);

//Returns the number for instack priority
int isp(char ch)
{
  switch (ch) {
    case('^'):
      return 3;
    case('*'):
    case('/'):
      return 2;
    case('+'):
    case('-'):
      return 1;
    case('('):
      return 0;
    case(')'):
      return -1;
  }
}
//Returns the number for incoming priority
int icp(char ch)
{
  switch (ch) {
    case('^'):
    case('('):
      return 4;
    case('*'):
    case('/'):
      return 2;
    case('+'):
    case('-'):
      return 1;
    case(')'):
      return -1;
  }
}

//Should check char to see if it is letter or number (caps,lowercase, and number)
bool isOperand(char C)
{
    case('^'):
    case('('):
    case('*'):
    case('/'):
    case('+'):
    case('-'):
    case(')'):
      return false;
    default:
      return true;
}

//This should return true if isp>icp else false, also should check for right associativity by comapring isp==icp and char is '^'
bool hasHigherPrecedenceInToPre(char op1, char op2)
{
  /* ===== INCOMPLETE ===== */
  op1 > op2 ? return true : return false;
}

//This should prompt user to enter 1-3 for a choice or 0 to quit
void menuOption(int &choice)
{
  /* ===== INCOMPLETE ===== */
  do {
    std::cout << "Enter 1, 2, or 3 \n 0 to quit." << std:: endl;
    std::cout << "1. Infix to Prefix Conversion" << std::endl;
    std::cout << "2. Prefix to Infix Conversion" << std::endl;
    std::cout << "3. Postfix to Prefix Conversion" << std::endl;
    std::cout << "4. Prefix to Postfix Conversion" << std::endl;
    std::cout << "0 to quit" << std::endl;
    std::cout << "Choice: " << std::endl;
    std::cin >> choice;
    if (choice > 4 || choice < 0) {
      std::cout << "Invalid Input Try Again." << std::endl;
    }
  } while (choice > 4 || choice < 0);
}

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
    
    std::cout << "\n\n===Menu=== \n";
    std::cout << "1. Infix to Prefix Conversion\n";
    std::cout << "2. Infix to Postfix Conversion\n";
    std::cout << "3. Read in a file of Infix Equations\n";
    std::cout << "0 to quit\n";
    std::cout << "Choice: ";
    std::cin  >>  choice;
}


