#include <iostream>
#include <stack>
#include <exception>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>


struct conversion
{
  std::string infix;
  std::string postfix;
  std::string prefix;
};
bool isOperand(const char C);
int inStackPriority(const char ch);
int incomingPriority(const char ch);
bool hasHigherPrecedenceInToPre(const char op1, const char op2);
bool writeSolutionFile(std::vector<conversion> & solutions);

std::string infixToPrefix(std::string expression)
{
  std::stack<char> operatorStack, displayStack;
  std::vector<char> reversedInput;
  std::reverse_copy(expression.begin(), expression.end(), reversedInput.begin());
  std::string result;
  for (auto i= reversedInput.begin(); i != reversedInput.end(); i++) {
    if (isOperand(*i)) {
      displayStack.push(*i);
    }
    if (*i == ')') {
        *i = operatorStack.top();
        operatorStack.pop();
      while (*i != '(') {
        displayStack.push(*i);
        *i = operatorStack.top();
        operatorStack.pop();
      } 
    }
    if (!isOperand(*i)) {
      if (incomingPriority(*i) >= inStackPriority(operatorStack.top())) {
        operatorStack.push(*i);
      } else {
        *i = operatorStack.top();
        operatorStack.pop();
        while (!hasHigherPrecedenceInToPre(*i, operatorStack.top())) {
          displayStack.push(operatorStack.top());
          operatorStack.pop();
        }
      }
    }
  }
  while (!operatorStack.empty()) {
    displayStack.push(operatorStack.top());
    operatorStack.pop();
  }
  while (!displayStack.empty()) {
    result += displayStack.top();
    displayStack.pop();
  }
  return result;
}


std::string infixToPostfix(std::string expression) 
{
  std::string result;
  std::stack<char> holdingStack;
  for (auto i= std::begin(expression); i != std::end(expression); i++) {
    if (*i == ')') {
       *i = holdingStack.top();
        holdingStack.pop();
      while (*i != '(') {
       *i = holdingStack.top();
        std::cout << *i;
        holdingStack.pop();
      }
    }
    if (isOperand(*i)) {
      std::cout << *i;
    } else {
      if (hasHigherPrecedenceInToPre(*i, holdingStack.top())) {
        holdingStack.push(*i);
      } else {
        while (!hasHigherPrecedenceInToPre(*i, holdingStack.top())) {
        std::cout << holdingStack.top();
        holdingStack.pop();
        }
      }
    }
  }
  while (!holdingStack.empty()) {
    std::cout << holdingStack.top();
    result += holdingStack.top();
    holdingStack.pop();
  }
  return result;
}


conversion* readFile(const std::string filename)
{
  int count = 0;
  std::fstream inputStream(filename.c_str(), std::fstream::in);
  bool openCheck = inputStream.is_open() ? true : false;
  if (openCheck) {
    // Reads the file to the end of the line and determines # of lines
    std::string line;
    while (inputStream.peek() != EOF) { 
      std::getline(inputStream, line);
      count++;
    }
    std::cout << "Count: " << count << std::endl;
    // Reset back to beginning of file
    inputStream.clear();
    inputStream.seekg(0);
    // Holds all of the data of the file in a string array
    conversion* fileData = new conversion[count];
    for (int i = 0; i < count; i++) {
      // Places info from the file into memory and writes to screen
      system("pause");
      std::getline(inputStream, fileData[i].infix);
      std::cout << fileData[i].infix << std::endl;
    }
    // Cleanup
    inputStream.close();
    return fileData;
  } else {
    return nullptr;
  }
}

bool fileOption(const std::string filename)
{
  try
  {
    conversion * fileData = readFile(filename);
    for (int i= 0; &fileData[i] != nullptr; i++) {
      fileData[i].postfix = infixToPostfix(fileData[i].infix);
      fileData[i].prefix = infixToPrefix(fileData[i].infix);
    }
    return true;
  }
  catch (std::exception &e)
  {
    std::cout << "Standard Exception: " << e.what() << "\n";
  }
  return false;
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
    case('\n'):
      return -2;
  }
}

//Returns the number for incoming priority
int incomingPriority(const char ch)
{
  switch (ch) {
    case('('):
    case('^'):
      return 4;
    case('*'):
    case('/'):
      return 2;
    case('+'):
    case('-'):
      return 1;
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

//This should return true if isp>icp else false, also should check for right 
// associativity by comapring isp==icp and char is '^'
bool hasHigherPrecedenceInToPre(char op1, char op2)
{
  /* ===== INCOMPLETE ===== */
 bool result_b = incomingPriority(op1) > inStackPriority(op2) ? true : false;
 return result_b;
}

//This should prompt user to enter 1-3 for a choice or 0 to quit
void menuOption(int &choice)
{  
  do {
    std::cout << "\n\n===Menu=== \n" << std::endl;
    std::cout << "1. Infix to Prefix Conversion\n" << std::endl;
    std::cout << "2. Infix to Postfix Conversion\n" << std::endl;
    std::cout << "3. Read in a file of Infix Equations\n" << std::endl;
    std::cout << "0 to quit\n" << std::endl;
    std::cout << "Choice: ";
    std::cin  >>  choice;
    if (choice > 3 || choice < 0) {
      std::cout << "Invalid Input Try Again." << std::endl;
    }
    // This makes an infinite loop, fix
  } while (choice > 3 || choice < 0);
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
  std::vector<conversion> solutions;
  int choice;
  menuOption(choice);
  if (choice == 3) {
    std::string temp_string;
    std::cout << "What is the path to the file? ";
    std::cin >> temp_string;
    if (fileOption(temp_string)) {
      std::cout << "File read successfully." << std::endl;
    } else {
      std::cout << "File reading failed, try again." << std::endl;
    }
  }
  system("pause");
  return 0;
}

