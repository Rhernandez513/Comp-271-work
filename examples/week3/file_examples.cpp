#include<fstream>
#include<iostream>
#include<string>

using namespace std;

/**
 * ifstream-open the file for input
 * ofstream-open the file for output
 * fstream-open the file for input/output/both
 *
 * Some Advice:
 * Never ever declare a fstream variable globally. It is a bad habit.
 * If you are doing databases or any file handling for that matter never put any file i/o into classes.
 * Any variable declared with ifstream,ofstream or fstream is called a file handle
 *
 * Usages for reading a File:
 *file>>char *;       //ie an array
 *file>>char;         //single char
 *file.get(char);     //single char
 *file.get(char *,int);   //read a string
 *file.getline(char *,int sz);
 *file.getline(char *,int sz,char eol);
 ***/

bool test_output(string filename, string sentence);
bool test_input_simple();
bool test_input_whole();
bool test_input_insertObj();

int
main()
{

  /* string filename;
   string sentence;
   cout << "Enter a filename: ";
   getline(cin, filename);
   cout << "Enter a sentence to put into the file: ";
   getline(cin, sentence);
   bool output_finished = test_output(filename, sentence);
   cout << "Outcome of Output test: " << output_finished << endl;
  */ 
   //Simple Input test
   //test_input_simple();
  
   //Input whole file test
   //test_input_whole();
  return 0;

}

bool
test_output(string filename, string sentence)
{
  ofstream file;
  file.open(filename.c_str()); //open takes in const char * change string to char *
  file << sentence << "\n";
  file.close();
  return true;
}

bool
test_input_simple()
{
  string filename;
  string movie;
  string director;
  string runtime;
  string year;
  string genre;
  string rating;
  ifstream fin;
  do
    {
      fin.clear(); //reset connect fail bit 1 or 0 remember
      cout << "Enter a filename: ";
      getline(cin, filename);
      fin.open(filename.c_str());
      if (fin.is_open())
        {
          getline(fin, movie, ',');
          getline(fin, director, ',');
          getline(fin, runtime, ',');
          getline(fin, year, ',');
          getline(fin, genre, ',');
          getline(fin, rating, '\n');
          cout << movie << " " << director << " " << runtime << " " << year
              << " " << genre << " " << rating << "\n";
        }
   fin.close();    
    }
  while (!fin); //checks the connection
 
 return true;
}

bool
test_input_whole()
{
  string filename;
  string line;
  ifstream fin;
  do
    {
      fin.clear(); //reset connect fail bit 1 or 0 remember
      cout << "Enter a filename: ";
      getline(cin, filename);
      fin.open(filename.c_str());
      if (fin.is_open())
        {
          while (!fin.eof())
            {
              getline(fin, line, '\n');
              cout << line << endl;
            }
        }
      fin.close();  
    }
  while (!fin); //checks the connection
 
  return true;
}


/**
 sizeof() is a compile-time expression giving you the size of a type or a variable's type.
 It doesn't care about the value of the variable.
 strlen() is a function that takes a pointer to a character, and walks the memory from this character on, looking for a NUL character.
 It counts the number of characters before it finds the NUL character.
 In other words, it gives you the length of a C-style NUL-terminated string.
 The two are entirely different in purpose and have nearly nothing to do with each other.
 In C++, you shouldn't need either very much; strlen() is for C-style strings, which should be replaced by C++-style std::strings, whereas the primary application for sizeof() in C is as an argument to functions
 like malloc(), memcpy() or memset(), all of which you shouldn't use in C++ (use new, std::copy(), and std::fill() or constructors).
 **/
