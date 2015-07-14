#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

bool parse_line(const char * line, std::vector<std::string> &w);

struct word_freq
{
  std::string word;
  int num_times_occ;
};

// This function reads the file and puts it in the std::vector
bool read_file(char * file_name, std::vector<std::string> & w)
{
  std::fstream fileReader(file_name, std::fstream::in);
  if (!fileReader.is_open()) {
    return false;
  }
  std::string tempLineString;
  while (fileReader.peek() != EOF) {
    std::getline(fileReader, tempLineString);
    std::cout << "Parsing: " << tempLineString << std::endl;
    parse_line(tempLineString.c_str(), w);
  }
  fileReader.close();
  return true;
}

// This function finds if the word is already
// In the array and returns the index
int is_in(std::string w, std::vector<word_freq> & wf)
{
  int count = 0;
  for (auto it = wf.begin(); it != wf.end(); it++) {
    if (w == wf[count].word) {
      return count;  // Index of
    }
    count++;
  }
  // If word is not within the vector
  return -1;
}

// This function finds how many times a word occurs
int get_num_occ(std::string w, std::vector<word_freq> & wf)
{
  int count = 0;
  for (auto it = wf.begin(); it != wf.end(); it++) {
    if (it->word == w) {
      return wf[count].num_times_occ;
    }
    count++;
  }
  return 0; // If not found
}

// This function will write a file called 'word_stats.txt'
// And have all the UNIQUE words and how many times they show up
bool write_file(char * file_name, std::vector<word_freq> & wf)
{
  std::fstream fileWriter(file_name, std::fstream::out);
  if(!fileWriter.is_open()) {
  return false;
  }
  for (auto it = wf.begin(); it != wf.end(); it++) {
    fileWriter << "Occurrences of " << it->word << ": ";
    fileWriter << get_num_occ(it->word, wf) << std::endl;
  }
  fileWriter.close();
  return true;
}

// This function will check each line and get each word, getting rid of
// Punctuation, newline,tabs, and carriage returns
bool parse_line(const char * line, std::vector<std::string> &w)
{
  if (line == nullptr) {
    return false;
  }
  char currentChar = 'a';
  int _char = -1;
  std::string tempString;
  for (int word = 0; currentChar != '\0'; word++) {
    while (!isspace(currentChar)) {
      currentChar = line[++_char];
      currentChar = tolower(currentChar);
      if (currentChar == '\0' || isspace(currentChar)) {
        // Checks for end of cstring & whitespace
        break;
      } else if (ispunct(currentChar)) {
        // Discards punctuation
        currentChar = line[++_char];
        _char--;
        continue;
      } else {
        // Check for letters and put them in the string
        tempString += currentChar;
      } // End if
    } // End inner loop
    if (isspace(currentChar)) {
      // Discards ' ', '\t',  '\r', '\f', '\n', '\v'
      // But still allows outer loop to check for '\0'
      //
      // Reassign currentChar because at this point the innerLoop
      // Has ended or broken due to whitespace
      currentChar = 'a';
    }
    // Put it into the vector of strings
    w.push_back(tempString);
    tempString.clear();  // Reset String for next iteration
  } // End outer Loop
  return true;
}

void bufferClear()
{
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int main()
{
  // Some vars
  int index;
  char * c_filename;
  std::string filename;
  std::vector<std::string> words;
  std::vector<word_freq> words_occ;
  word_freq new_word;
  new_word.num_times_occ = 0;

/*===========================================================================*/

  // Prep for file Reading
  std::cout << "Please enter a filename to read: ";
  std::getline(std::cin,filename);
  bufferClear();
  c_filename = new char[strlen(filename.c_str()) + 1];
  strcpy(c_filename, filename.c_str());

  // Read the file then process the data
  if(read_file(c_filename, words)) {
  // If file has been read and all the words are in the "words" std::vector
    for (auto it = words.begin(); it != words.end(); it++) {
      index = is_in(*it, words_occ);      // Check if word is in words_occ
      if (index >= 0) {                   // Meaning the word IS in words_occ
        words_occ[index].num_times_occ++; // Increment
      } else {
         // If the word is not in the word_freq struct, add it
         // And Set occurrences to one
        new_word.word = *it;
        new_word.num_times_occ = 1;
        words_occ.push_back(new_word);
      }
    } // End loop
  } // End if
  delete c_filename;

/*===========================================================================*/

  // Logic for viewing or writing the text file
  std::string userInput;
  std::cout << "Would you like to see the Occurrences or write to a text file?";
  std::cout << " (s to see, or w to write): ";
  std::getline(std::cin, userInput);
  bufferClear();
  if (userInput == "s" || userInput == "S") {
    // Show each word and how many times it occurs example: for loop of 'words_occ'
    // Write the file of all the occurrences
    for (auto it = words_occ.begin(); it != words_occ.end(); it++) {
      std::cout << "Occurrences of " << it->word << ": ";
      std::cout << get_num_occ(it->word, words_occ) << std::endl;
    } // End loop
  } else if (userInput == "w" || userInput == "W") {
    // Prompt for string to name the file
    // Write all occurences to the text file
    std::string write_filename;
    std::cout << "Please enter a filename to write: ";
    std::getline(std::cin, write_filename);
    bufferClear();
    c_write_filename = new char[strlen(write_filename.c_str()) + 1];
    strcpy(c_write_filename, write_filename.c_str());
    if (write_file(c_write_filename, words_occ) {
      std::cout << "File " << c_write_filename << " successfully written.";
      std::cout << std::endl;
    } else {
      std::cout << "Writing " << c_write_filename << " failed." << std::endl;
    } // End inner if
    delete c_write_filename;
  } else {
    std::cout << "Bad Input! File Operations Aborted!" << std::endl;
  } // End outer if

/*===========================================================================*/

  // While loop to ask user "What word do you want to look up or 0 to quit"
  // Else word not in std::vector or 0 to quit

  // Logic for counting occurences
  std::string currWord = ""; // Start with an empty string
  while(currWord != "0") {
    std::cout << "Enter a word to search for (Enter 0 to quit): ";
    std::getline(std::cin, currWord);
    bufferClear();
    if (currWord == "0") {
      break;
    }
    // Convert to lowercase
    std::string data = currWord;
    std::transform(data.begin(), data.end(), data.begin(), tolower);
    currWord = data;
    if(!currWord.empty()) {
      // If word is there say word and how many times it occurred
      if(is_in(currWord, words_occ)) {
        std::cout << "Word " << currWord << " found! It occurred ";
        std::cout << "(" << get_num_occ(currWord, words_occ) << ") times!";
        std::cout << std::endl;
      } else {
        std::cout << "Word \"" << currWord << "\" not found!" << std::endl;
      } // End inner if
    } // End if
  } // End While

  std::cout << "Goobye!" << std::endl;
  return 1;
} //End main

