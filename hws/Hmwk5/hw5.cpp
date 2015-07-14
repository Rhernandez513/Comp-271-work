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
    if (tempLineString == "") {
      std::cout << std::endl;
    } else {
    std::cout << "Parsing: " << tempLineString << std::endl;
    parse_line(tempLineString.c_str(), w);
    }
  }
  std::cout << std::endl;
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
      } else if (ispunct(currentChar) || isdigit(currentChar)) {
        // Discards punctuation & numbers
        currentChar = line[++_char];
        _char--;
        continue;
      } else if (isalpha(currentChar)){
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
    if(!tempString.empty()) {
      w.push_back(tempString);
    }
    tempString.clear();  // Reset String for next iteration
  } // End outer Loop
  return true;
}

int main()
{
  // Some vars
  int index;
  std::string filename, userInput, userPrompt, filePrompt, userOptions, 
              write_filename, tryAgainMsg;
  filePrompt = "Please enter a filename ";
  std::vector<std::string> words;
  std::vector<word_freq> words_occ;
  word_freq new_word;
  new_word.num_times_occ = 0;
  
/*===========================================================================*/

  // Prep for file Reading
  std::cout << filePrompt << "to read: ";
  std::getline(std::cin,filename);
  char * c_filename = new char[strlen(filename.c_str()) + 1];
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
      } // End inner if
    } // End loop
  } // End outer if
  delete [] c_filename;  // Cleanup

/*===========================================================================*/

  // Logic for viewing or writing the text file
  userPrompt = 
    "\nWould you like to see the Occurrences or Write to a text file?";
  userOptions = 
    "\n(s to view, or w to write, or 1 to search, 0 again to quit): ";
  tryAgainMsg = "\nPlease try again";
  while(userInput != "0") {
    std::cout << userPrompt << userOptions << std::endl;
    std::getline(std::cin, userInput);
    if (userInput == "s" || userInput == "S") {
      // Show each word and how many times it occurs
      // Example: for loop of 'words_occ'

      // Print to screen, all the occurrences
      for (auto it = words_occ.begin(); it != words_occ.end(); it++) {
        std::cout << "Occurrences of " << it->word << ": ";
        std::cout << get_num_occ(it->word, words_occ) << std::endl;
      } // End loop
    } else if (userInput == "w" || userInput == "W") {
      // Prompt for string to name the file
      // Write all occurrences to the text file
      std::cout << "\n" << filePrompt <<  " to write: ";
      std::getline(std::cin, write_filename);
      char * c_write_filename = new char[strlen(write_filename.c_str()) + 1];
      strcpy(c_write_filename, write_filename.c_str());
      if (write_file(c_write_filename, words_occ)) {
        std::cout << "\nFile " << c_write_filename << " successfully written.";
        userPrompt =
          "\n Would you like to search the new file? (1 to search, 0 to quit) ";
        std::cout << userPrompt;
        std::getline(std::cin, userInput);
        break;  // If file is successfully written, move to search/quit
      } else {
        std::cout << "\nWriting " << c_write_filename << " failed.";
        std::cout <<  tryAgainMsg << std::endl;
        continue;  // Prompt for user input again
      } // End inner if
      delete [] c_write_filename;  // Cleanup
    } else if (userInput == "0" || userInput == "1") {
      // Break on 0 and 1, 1 takes you to search, 0 ends program
      // See next if block
      break;
    } else {
      std::cout << "Bad Input! File Operations Aborted!" << std::endl;
      std::cout << tryAgainMsg << std::endl;
    } // End outer if
  } // End while loop

/*===========================================================================*/

  // While loop to ask user "What word do you want to look up or 0 to quit"
  // Else word not in std::vector or 0 to quit

  // Logic for counting occurrences
  if (userInput == "1") {
    std::string currWord = ""; // Start with an empty string
    userPrompt = "\nEnter a word to search for, (Enter 0 to quit): ";
    while(currWord != "0") {
      std::cout << userPrompt;
      std::getline(std::cin, currWord);
      if (currWord == "0") {
        break;  //Leave loop on user input
      } // End if
      // Convert to lowercase
      std::string data = currWord;
      std::transform(data.begin(), data.end(), data.begin(), tolower);
      currWord = data;
      if(!currWord.empty()) {
        // If word is there say word and how many times it occurred
        if(is_in(currWord, words_occ) >= 0) {  //is_in returns an index
          std::cout << "\nWord " << currWord << " found! It occurred ";
          std::cout << "(" << get_num_occ(currWord, words_occ) << ") times!";
          std::cout << std::endl;
        } else {
          std::cout << "\nWord \"" << currWord << "\" not found!" << std::endl;
        } // End inner if
      } // End if
    } // End While
  }

  std::cout << "\nGoodbye!" << std::endl;
  std::cin.get();
  return 1;
} //End main

