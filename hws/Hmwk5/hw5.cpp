//
//  main.cpp
//  Homework_5
//
//  Created by maria saenz on 10/8/14.
//  Copyright (c) 2014 maria saenz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

struct word_freq{
    string word;
    int num_times_occ;
};

//this function reads the file and puts it in the vector
bool read_file(char * file_name,vector<string> & w);

//this function finds if the word is already in the array and returns the index
int is_in(string w, vector<word_freq> & wf);

//this function finds how many times a word occurs
int get_num_occ(string w, vector<word_freq> & wf);

//this function will write a file called 'word_stats.txt'
//and have all the UNIQUE words and how many times they show up
bool write_file(char * file_name,vector<word_freq> & wf);

//this function will check each line and get each word, getting rid of punctuation, newline,tabs, and carriage returns
bool parse_line(char * word, vector<string> &w);

int main() {

    int i;
    int index;
    string word;
    vector<string> words;
    vector<word_freq> words_occ;
    word_freq new_word;
    string filename;
    char * c_filename;
    cout << "Please enter a filename: ";
    getline(cin,filename);
    c_filename=new char[strlen(filename.c_str())+1];
    strcpy(c_filename, filename.c_str());
    //if file has been read and all the words are in the "words" vector 
    //for loop to go through vector words, check is word with is_in function and it should return an index
    //if index is greater than or equal to 0 the words_occ[index].num_times_occ increased
    //else new word set the word and occurences to 1 and pushback into '"words_occ"
   
    //Show each word and how many times it occurs example: for loop of 'words_occ'
    //Write the file of all the occurences
  
    //while loop to ask user "What word do you want to look up or 0 to quit"
    //if word is there say word and how many times it occured
    //else word not in vector or 0 to quit

    return 1;
}
