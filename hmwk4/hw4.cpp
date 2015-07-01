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
std::string infixToPrefix(const std::string expression);
std::string infixToPostfix(const std::string expression);
bool fileOption(const std::string filename)
{
  int choice;
}

bool readFile(const std::string filename)
{
  int count = 0;
  std::fstream inputStream(filename, std::fstream::in);
  bool openCheck = inputStream.is_open() ? true : false;
  if (openCheck) {
    // Reads the file to the end of the line and determines # of lines
    std::string line;
    while (inputStream.peek() != EOF) { 
      std::getline(inputStream, line);
      count++;
    }
    // Holds all of the data of the file in a string array
    conversion* fileData = new conversion[count];
    // Reset back to beginning of file
    inputStream.clear();
    inputStream.seekg(0);
    for (int i = 0; i <= count; i++;) {
      // Places info from the file into memory and writes to screen
      std::getline(inputStream, fileData[i].infix);
      std::cout << fileData[i].infix << std::endl;
    }
  }
  // Cleanup
  inputStream.close();
//  for (int i = 0; i < count; i++) {
//    delete lines[i];
//  }
//  delete[] lines;

  return openCheck;
}

bool writeSolutionFile(std::vector<conversion> & solutions);

//Returns the number for instack priority
int inStackPriority(const char ch)
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
int incomingPriority(const char ch)
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
bool isOperand(const char C)
{
  switch(C) {
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
}

//This should return true if isp>icp else false, also should check for right associativity by comapring isp==icp and char is '^'
bool hasHigherPrecedenceInToPre(const char op1, const char op2)
{
  /* ===== INCOMPLETE ===== */
  op1 > op2 ? return true : return false;
}

//This should prompt user to enter 1-3 for a choice or 0 to quit
void menuOptionWithFile(int &choice)
{
  do {
    std::cout << "\n\n===Menu=== \n" << std::endl;
    std::cout << "1. Infix to Prefix Conversion" << std::endl;
    std::cout << "2. Prefix to Infix Conversion" << std::endl;
    std::cout << "3. Postfix to Prefix Conversion" << std::endl;
    std::cout << "4. Prefix to Postfix Conversion" << std::endl;
    std::cout << "0 to quit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;
    if (choice > 4 || choice < 0) {
      std::cout << "Invalid Input Try Again." << std::endl;
    }
  } while (choice > 4 || choice < 0);
}

void menuOption(int &choice)
{  
  std::cout << "\n\n===Menu=== \n" << std::endl;
  std::cout << "1. Infix to Prefix Conversion\n" << std::endl;
  std::cout << "2. Infix to Postfix Conversion\n" << std::endl;
  std::cout << "3. Read in a file of Infix Equations\n" << std::endl;
  std::cout << "0 to quit\n" << std::endl;
  std::cout << "Choice: ";
  std::cin  >>  choice;
}

int main()
{
  /*********
   *Variables you will need: a string for the expression the user will input,
   *string for the output you get from each function, a int for choice of what the user enters. 
   *If a user enters a choice that is NOT part of the menu prompt Not a valid choice try again.
   *A vector that holds conversion data type called solutions
  **********/
  std::string* userInput = new std::string;
  int choice;
  menuOption(choice);
  if (choice == 3) {
  
  }
  
  return 0;
}

