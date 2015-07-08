#include <iostream>
#include <stack>
#include <exception>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

// Container for equations of data (as strings)
struct conversion
{
  std::string infix;
  std::string postfix;
  std::string prefix;
};

std::vector<conversion> file_Data;
bool isOperand(const char C);
int inStackPriority(const char ch);
int incomingPriority(const char ch);
bool hasHigherPrecedenceInFixToPre(const char op1, const char op2);
bool writeSolutionFile(std::vector<conversion> & solutions);
bool isOperator(const char C);
bool hasHigherPrecedenceInToPost(char op1, char op2);
void writeSolutionsFile(std::vector<conversion> solutions);
int count = 0;

// Business Logic for converting Infix to Postfix
std::string infixToPrefix(std::string expression)
{
  std::stack<char> operatorStack, displayStack;
  std::vector<char> reversedInput(256);
  std::string result;
  int leftParensCount = 0, rightParensCount = 0;
  
  std::reverse_copy(expression.begin(), expression.end(), reversedInput.begin());
  reversedInput.shrink_to_fit();
  
  for (auto i= reversedInput.begin(); *i != '\0'; ++i) {
    // Tracks Parenthesis
    if (*i == ')') {
      ++rightParensCount;
    } else if (*i == '(') {
      ++leftParensCount;
    }

    if (isOperand(*i)) {
      displayStack.push(*i);
    }
    if (*i == ')') {
      while (!operatorStack.empty() && *i != '(') {
        displayStack.push(*i);
        *i = operatorStack.top();
        operatorStack.pop();
      } 
    }
    if (isOperator(*i)) {
      if (operatorStack.empty()) {
        operatorStack.push(*i);
      } else if (hasHigherPrecedenceInFixToPre(*i, operatorStack.top())) {
        operatorStack.push(*i);
      } else {
        while (!operatorStack.empty() &&
               !hasHigherPrecedenceInFixToPre(*i, operatorStack.top())
              ) {
          displayStack.push(operatorStack.top());
          operatorStack.pop();
        }
        operatorStack.push(*i);
      }
    }
  }
  while (!operatorStack.empty()) {
    displayStack.push(operatorStack.top());
    operatorStack.pop();
  }
  while (!displayStack.empty()) {
    char ch = displayStack.top();
    displayStack.pop();
    if (ch != ')' && ch != '(') {
      result += ch;
    }
  }
  if (leftParensCount != rightParensCount) {
    result += "    <-- Parenthesis not matched in input, may not be correct.";
  }
  return result;
}

// Business Logic for converting Infix to Postfix
std::string infixToPostfix(std::string expression) 
{
  std::string result;
  std::stack<char> holdingStack;
  int leftParensCount = 0, rightParensCount = 0;

  for (auto i = std::begin(expression); i != std::end(expression); ++i) {
    if (*i == ')') {
      ++rightParensCount;
    } else if (*i == '(') {
      ++leftParensCount;
    }
    if (*i == ')') {
       *i = holdingStack.top();
        holdingStack.pop();
      while (*i != '(') {
        if (holdingStack.empty()) {
          break;
        } else {
          *i = holdingStack.top();
          holdingStack.pop();
        }
      }
    }
    if (isOperand(*i)) {
      result += *i;
    }
    if (isOperator(*i)) {
      if (!holdingStack.empty()) {
        if (hasHigherPrecedenceInToPost(*i, holdingStack.top())) {
          holdingStack.push(*i);
        } else {
          while (!holdingStack.empty() &&
                 !hasHigherPrecedenceInToPost(*i, holdingStack.top())
                ) {
            result += holdingStack.top();
            holdingStack.pop();
          }
          holdingStack.push(*i);
        }
      } else {
        holdingStack.push(*i);
      }
    }
  }
  while (!holdingStack.empty()) {
    result += holdingStack.top();
    holdingStack.pop();
  }
  if (leftParensCount != rightParensCount) {
    result += "    <-- Parenthesis not matched in input, may not be correct.";
  }
  return result;
}
// Performs file reading & populates the conversion vector with Infix Data
bool readFile(const std::string filename, std::vector<conversion> &file_Data)
{
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
    std::cout << "Contents of the file being read: \n" << std::endl;
    for (int i = 0; i < count; i++) {
      // Places info from the file into memory and writes to screen
      conversion temp_conversion;
      std::getline(inputStream, temp_conversion.infix);
      file_Data.push_back(temp_conversion);
      std::cout << file_Data[i].infix << std::endl;
    }
    // Cleanup
    inputStream.close();
    return true;
  }
  return false;
}
// Calls conversion functions & populates the file_Data struct with 
// processed data
bool fileOption(const std::string filename)
{
  try
  {
    if (readFile(filename, file_Data)) {
      for (int i = 0; i < file_Data.size(); i++) {
        file_Data[i].postfix = infixToPostfix(file_Data[i].infix);
        file_Data[i].prefix = infixToPrefix(file_Data[i].infix);
      }
      return true;
    } else {
      return false;
    }
  }
  catch (std::exception &e)
  {
    std::cout << "Standard Exception: " << e.what() << "\n";
    return true;
  }
}

bool writeSolutionFile(std::vector<conversion> & solutions);

//Returns the number for InStack Priority
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
    default:
      return -2;

  }
}

//Returns the number for InComing Priority
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
    default:
      return -2;
  }
}

// Returns True is Char is Operand, false otherwise
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
// Returns True is Char is Operator, false otherwise
bool isOperator(const char C)
{
  switch (C) {
    case('^') :
    case('*') :
    case('/') :
    case('+') :
    case('-') :
    case(')'):
      return true;
    default:
      return false;
  }
}
// Infix-to-Prefix Priority Checker
bool hasHigherPrecedenceInFixToPre(char op1, char op2)
{
  if (incomingPriority(op1) >= inStackPriority(op2)) {
    return true;
  } else {
    return false;
  }
}
// Infix-to-Postfix Priority Checker
bool hasHigherPrecedenceInToPost(char op1, char op2)
{
  if (incomingPriority(op1) > inStackPriority(op2)) {
    return true;
  } else {
    return false;
  }
}
// Helps with clearing std::cin buffer to prevent infinite loops
void bufferClear()
{
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    std::cout << "Choice:  ";
    std::cin  >>  choice;
    if (choice == 0) {
      return;
    } else if (choice > 3 || choice < 0) {
      std::cout << "Invalid Input Try Again.\n\n";
      bufferClear();
    }
  } while (choice > 3 || choice < 0);
}
// Provides User prompt and Error Checking of User input for writing
void promptUsertoWriteFile()
{
  std::string userReponse;
  std::cout << "Write to text File? (y/n)" << std::endl;
  std::cin >> userReponse;
  if (userReponse == "Y" || userReponse == "y") {
    writeSolutionsFile(file_Data);
  } else if (userReponse == "N" || userReponse == "n") {
      std::cout << "Goodbye.\n" << std::endl;
  } else {
      std::cout << "Invalid Input Try Again.\n\n";
      bufferClear();
      promptUsertoWriteFile();
  }
}
// Allows User to view conversion results from the read-in file
void viewSolutions(std::vector<conversion> solutions)
{
  for (int i = 0; i < solutions.size(); i++) {
    std::cout << "Problem #" << i + 1 << " infix: ";
    std::cout<< solutions[i].infix << std::endl;
    std::cout<< "Problem #" << i + 1 << " postfix: ";
    std::cout<< solutions[i].postfix << std::endl;
    std::cout<< "Problem #" << i + 1 << " prefix: ";
    std::cout<< solutions[i].prefix << std::endl;
    std::cout<< "\n" << std::endl;
  }
}
// Allows User to view conversion results from the read-in file
void promptUsertoViewResults()
{
  std::string userReponse;
  std::cout << "View Solutions? (y/n)" << std::endl;
  std::cin >> userReponse;
  if (userReponse == "Y" || userReponse == "y") {
    viewSolutions(file_Data);
    bufferClear();
  }
}
// Provides User prompt and Error Checking of User input for reading
// Recursive
void promptUserForFileName(std::string temp_string)
{
  bufferClear();
  std::cout << "What is the path to the file?  ";
  std::cin >> temp_string;
  if (fileOption(temp_string)) {
    std::cout << "\nFile read successfully.\n\n" << std::endl;
    promptUsertoViewResults();
    promptUsertoWriteFile();
  } else if (temp_string.c_str() == "0") {
    std::cout << "Goodbye.\n" << std::endl;
  } else {
    std::cout << "File reading failed, try again.\n\n" << std::endl;
    promptUserForFileName(temp_string);
  }
}
// User-Interactive Prefix Conversion
void infixToPrefixOption()
{
  bufferClear();
  std::string result;
  std::cout << "\n\nPlease Enter the Equation you would like to convert"
            << std::endl;
  std::getline(std::cin, result);
  std::cout << "\nResult: " << infixToPrefix(result) << std::endl;
  std::system("pause");
}
// User-Interactive Postfix Conversion
void infixToPostfixOption()
{
  bufferClear();
  std::string result;
  std::cout << "\n\nPlease Enter the Equation you would like to convert"
    << std::endl;
  std::getline(std::cin, result);
  std::cout << "\nResult: " << infixToPostfix(result) << std::endl;
  std::system("pause");
}
// Writes Final solutions to a text file
void writeSolutionsFile(std::vector<conversion> solutions)
{
  std::string fileName = "solutions.txt";
  std::fstream solution_fstream(fileName, std::fstream::out);
  if (solution_fstream.is_open())
  {
    for (int i = 0; i < solutions.size(); i++) {
      solution_fstream << "Problem #" << i + 1 << " infix: ";
      solution_fstream << solutions[i].infix << std::endl;
      solution_fstream << "Problem #" << i + 1 << " postfix: ";
      solution_fstream << solutions[i].postfix << std::endl;
      solution_fstream << "Problem #" << i + 1 << " prefix: ";
      solution_fstream << solutions[i].prefix << std::endl;
      solution_fstream << "\n" << std::endl;
    }
    solution_fstream.close();
  } else {
    std::cout << "Failed to write file." << std::endl;
  }
}
int main()
{
  std::string* userInput = new std::string;
  std::vector<conversion> solutions;
  int choice = -1;
  menuOption(choice);
  if (choice == 0) {
    std::cout << "Goodbye.\n" << std::endl;
  } else if (choice == 1) {
      infixToPrefixOption();
  } else if (choice == 2) {
      infixToPostfixOption();
    } else if (choice == 3) {
    std::string temp_string;
    promptUserForFileName(temp_string);
  }
  std::system("pause");
  return 0;
}
