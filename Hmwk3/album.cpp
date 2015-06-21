#include <iostream>
#include <cstring>
#include "ALBUM.h"

using namespace hw2;
// Default constructor initializes all members
Album::Album()
{
  artist = new char[256];
  title = new char[256];
  year_released = 0;
  record_label = new char[256];
  num_songs = 0;
  num_minutes_long = 0;
  genre = new char[256];
};

// Overloaded constructor uses default as delegate
Album::Album(char *& a, char *& t)
  : artist(a)
  , title(t)
{
};

// Deconstructor
// With only primitive members, no special deletes are
// Needed to free all memory contained in the instance
Album::~Album() { } ;

// Setters
bool Album::set_artist(char * a) 
{ 
  if (a) {
    artist = a; 
    return true;
  } else {
    return false;
  }
}
bool Album::set_title(char * t) 
{ 
  if (t) {
    title = t;
    return true;
  } else {
    return false;
  }
}
bool Album::set_year_released(int value)
{
  if (value > 0) {
    year_released = value;
    return true;
  } else {
    return false;
  }
}
bool Album::set_record_label(char *& label) 
{
  if (label) {
    record_label = label; 
    return true;
  } else {
    return false;
  }
}
bool Album::set_num_songs(int value)
{
  if (value > 0) {
    num_songs = value;
    return true;
  } else {
    return false;
  }
}
bool Album::set_num_minutes_long(int value)
{
  if (value > 0) {
    num_minutes_long = value;
    return true;
  } else {
    return false;
  }
}
bool Album::set_genre(char * g)
{
  if (g) {
    genre = g; 
    return true;
  } else {
    return false;
  }
}

// Getters
int Album::get_num_songs() { return num_songs; }
int Album::get_num_minutes_long() { return num_minutes_long; }
int Album::get_year_released() { return year_released; }
bool Album::get_artist(char *& a)
{
  if (artist) {
    a = artist;
    return true;
  } else {
    return false;
  }
}
bool Album::get_title(char *& t)
{
  if (title) { 
    t = title;
    return true;
  } else {
    return false;
  }
}
bool Album::get_record_label(char *& label)
{
  if (record_label) {
    label = record_label;
    return true;
  } else {
    return false;
  }
}
bool Album::get_genre(char *& g)
{
  if (genre) {
    g = genre;
    return true;
  } else {
    return false;
  }
}

/*============ additional functions for homework 3===========================*/

// Prints all album info to the console
// Returns true if Album contains all 7 properties, false otherwise
bool Album::write_console()
{
  int count = 0;
  if (this.title) {
    std::cout << "Title: " << this.title << std::endl;
    count++;  // 1
  }
  if (this.artist) {
    std::cout << "Artist: " << this.artist << std::endl;
    count++;  // 2
  }
  if (this.year_released > 0 ) {
    std::cout << "Year Realeased: " << this.year_released << std::endl;
    count++; // 3
  }
  if (this.record_label) {
    std::cout << "Record Label: " << this.record_label << std::endl;
    count++; // 4
  }
  if (this.num_songs > 0) {
    std::cout << "Number of Songs: " << this.record_label << std::endl;
    count++; // 5
  }
  if (this.num_minutes_long > 0) {
    std::cout << "Number of Minutes Long: " << this.num_minutes_long << std::endl;
    count++; // 6
  }
  if (this.genre) {
    std::cout << "Genre: " << this.genre << std::endl;
    count++; // 7
  }
  if (count == 7) {
    return true;
  } else {
    return false;
  }
}

bool Album::write_file(char * file_name)   	// Grabs all the info like
{                                           // write_console but putting
                                            // It into a file if data exists
}                                           // Return true if 
                                            // A value to write false otherwise
                          
