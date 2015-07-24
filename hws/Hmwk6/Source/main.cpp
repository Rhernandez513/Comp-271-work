#include "..\\Headers\\BinaryTree.h"
#include "..\\Headers\\QuarternaryTree.h"
#include <iostream>
#include <fstream>


using namespace hw6;

bool get_words(const char * file_name, std::vector<std::string> &w, char type);
bool get_reads(const char * file_name, std::vector<std::string> &r, char type);
void printDashes();
void bufferClear();

int main() {
  std::vector<std::string> words, wordsQT, reads, readsQT;
  const std::string lines = "--------------------";
  const std::string writeSuccessMsg = "File Write Operation Successful.";
  const std::string mappingMsg = "Beginning Mapping. Press Any Key to Continue...";
  const char * genome_file_name = "Resources\\genome_file.txt";
  const char * reads_file_name = "Resources\\test_file.txt";
  const char * QT_reads_file_name = "Resources\\test_fileQT.txt";

  if (!get_words(genome_file_name, words, 'B')) return 1;
  if (!get_words(genome_file_name, wordsQT, 'Q')) return 1;

  // 1. Create a tree based on either BTreeNode or QTreeNode
  // --> transforming the vector of words into the tree
  BinaryTree * BGenomeTree = new BinaryTree();
  BGenomeTree->insert_vector(words);
  QuarternaryTree * QGenomeTree = new QuarternaryTree();
  QGenomeTree->insert_vector(wordsQT);

  // 2. Read in file BReads or QReads using function
  // get_reads(read_file_name,reads);
  // if doing QTreeNode, pass in 'Q'
  if (!get_reads(reads_file_name, reads, 'B')) return 1;
  if (!get_reads(QT_reads_file_name, readsQT, 'Q')) return 1;

  // 3. for each read, map it through the tree.
  // If it follows a path in the tree, this read belongs to this genome.
  // Write out a file named "BReads_map_results.txt" or "QReads_map_results.txt"
  // listing each read and "Yes" or "No" if it does or doesn't map to the
  // genome.

  printDashes();
  std::cout << lines << "BINARY TREE MAPPING-----" << lines << std::endl;
  printDashes();
  std::cout << mappingMsg << std::endl;
  bufferClear();

  BGenomeTree->compare_vector_to_tree(reads);
  delete BGenomeTree;
  
  printDashes(); 
  std::cout << "\n" << lines << "BINARY TREE ENDED-----" << lines << std::endl;
  printDashes(); 

  std::cout << mappingMsg << std::endl;
  bufferClear();

  printDashes(); 
  std::cout << "\n" << lines << "QUATERNARY TREE MAPPING" << lines << std::endl;
  printDashes(); 

  QGenomeTree->compare_vector_to_tree(readsQT);
  delete QGenomeTree;

  printDashes(); 
  std::cout << lines << "QUATERNARY TREE ENDED. QUIT" << lines << std::endl;
  printDashes(); 

  std::cout << "\nGoodbye!\n";
  bufferClear();

  return 0;
}

/*******************************************************************************
This function takes the genome file name to read and reads all overlapping
words of size 10 that are present in the file and stores each word in a vector.
The vector is passed to this function as a parameter -- by reference such
that the calling function has access to the vector of words.
Type='B' means you are doing a binary tree. Type='Q' means you are doing
the quaternary tree. This function will translate the file such that the
same file can be used for either tree.
*******************************************************************************/
bool get_words(const char *file_name, std::vector<std::string> &w, char type) {
  std::fstream in(file_name, std::fstream::in);
  if (!in.is_open()) {
    std::cout << "The genome file could not be opened. Check the location.\t";
    return false;
  }
  // this is a default, we'll be looking at words of size 10
  char *word = new char[11];

  // Get Length of file
  in.seekg(0, in.end);
  int len = static_cast<int>(in.tellg());
  in.clear(); // Can comment this out if using C++11
  in.seekg(0, in.beg);

  for (int i = 0; i < 10; i++) {
    in >> word[i];
    if (word[i] < 97)
      word[i] += 32;                // makes it lowercase
    if (type == 'B' || type == 'b') // if doing BTree, translates 4 letter code
                                    // into two letter code
    {
      if (word[i] == 'a' || word[i] == 'g')
        word[i] = 'r'; // purine
      else
        word[i] = 'y'; // pyrimidine
    }
  }
  word[10] = '\0';
  w.push_back(word);
  for (int i = 1; i < (len - 10 - 1); i++) { // read until the end of the file
    // shift
    for (int j = 0; j < 9; j++)
      word[j] = word[j + 1];
    in >> word[9];
    if (word[9] < 97)
      word[9] += 32; // makes it lowercase
    if (type == 'B' || type == 'b') {
      if (word[9] == 'a' || word[9] == 'g')
        word[9] = 'r'; // purine
      else
        word[9] = 'y'; // pyrimidine
    }
    word[10] = '\0';
    // strcpy(w[i], word);

    // Redundant w/ write_vector_to_screen
    //std::cout << i << "\t" << word << std::endl;
    //std::cout.flush(); // No Need with endl ^
    w.push_back(word);
  }
  in.clear();
  in.close();

  return true;
}

/*******************************************************************************
This function takes the reads file name to read and reads each individual word
in the file and stores each word in a vector.
The vector is passed to this function as a parameter -- by reference such
that the calling function has access to the vector of words.
Type='B' means you are doing a binary tree. Type='Q' means you are doing
the quaternary tree. This function will translate the file such that the
same file can be used for either tree.
*******************************************************************************/
bool get_reads(const char *file_name, std::vector<std::string> &r, char type) {
  int i;
  std::fstream in(file_name, std::fstream::in);
  if (!in.is_open()) {
    std::cout << "The read file could not be opened. Check the location.\t";
    return false;
  }

  // this is a default, we'll be looking at words of size 10
  char *word = new char[20];

  while (in.peek() != EOF) {
    in.getline(word, 20, '\n');
    for (i = 0; i < 10; i++) {
      if (word[i] < 97)
        word[i] += 32;  // makes it lowercase
    }
    // if doing BTree, translates 4 letter code
    // into two letter code
    if (type == 'B' || type == 'b') {
      for (i = 0; i < 10; i++) {
        if (word[i] == 'a' || word[i] == 'g' || word[i] == 'r')
          word[i] = 'r'; // purine
        else
          word[i] = 'y'; // pyrimidine
      }
    }
    r.push_back(word);
  } // End While
  in.clear();
  in.close();
  delete word;
  return true;
}

bool write_vector_to_file(std::vector<std::string> v, const char *file_name) {
  std::ofstream out (file_name, std::ofstream::out);
  for (int i = 0, s = v.size(); i < s; i++)
    out << i + 1 << '\t' << v[i] << std::endl;
  out.clear();
  out.close();
  return true;
}

bool write_vector_to_screen(std::vector<std::string> v) {
  for (int i = 0, s = v.size(); i < s; i++)
    std::cout << i + 1 << '\t' << v[i] << std::endl;
  return true;
}

// Helps with clearing std::cin buffer to prevent infinite loops
// Can also work like std::cin.get() to accept a Return key press
void bufferClear() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
// Prints 20 dashes to standard output
void printDashes() {
  const char * dashes = "--------------------";
  std::cout << "\n" << dashes << dashes << dashes << "\n" << std:: endl;
}
