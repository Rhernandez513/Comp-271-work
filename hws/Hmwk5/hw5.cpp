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
  return false;
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

int main()
{
  int index;
  char * c_filename;
  std::string currWord;
  std::string filename;
  std::vector<std::string> words;
  std::vector<word_freq> words_occ;

  word_freq new_word;
  new_word.num_times_occ = 0;

  std::cout << "Please enter a filename: ";
  std::getline(std::cin,filename);
  c_filename = new char[strlen(filename.c_str()) + 1];
  strcpy(c_filename, filename.c_str());


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

  // Show each word and how many times it occurs example: for loop of 'words_occ'
  // Write the file of all the occurrences
  for (auto it = words_occ.begin(); it != words_occ.end(); it++) {
    std::cout << "Occurrences of " << it->word << ": ";
    std::cout << get_num_occ(it->word, words_occ);
    std::cout << std::endl;
  }
  // While loop to ask user "What word do you want to look up or 0 to quit"
  std::cout << "Enter a word to search for: ";
  std::cin >> currWord;
  std::string data = currWord;
  std::transform(data.begin(), data.end(), data.begin(), tolower);
  currWord = data;
  if(!currWord.empty()) {
    if(is_in(currWord, words_occ)) {
      std::cout << "Word " << currWord << " found! It occurred ";
      std::cout << << "(" << get_num_occ(currWord, words_occ) << ") times!";
      std::cout << std::endl;
    } else {
      std::cout << "Bad Input, Try Again." << std::endl;
    }
    currWord.clear();
    std::system("PAUSE");
  }
  // If word is there say word and how many times it occurred
  // Else word not in std::vector or 0 to quit

  return 1;
}

