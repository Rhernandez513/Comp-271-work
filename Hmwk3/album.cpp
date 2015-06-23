#include <iostream>
#include <cstring>
#include "ALBUM.h"
#include <fstream>

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
bool Album::set_record_label(char * label) 
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
  char* temp = new char[256];
  int count = 0;
  if (this->get_title(temp)) {
    std::cout << "Title: " << temp << "\n";
    count++;  // 1
  }
  if (this->get_artist(temp)) {
    std::cout << "Artist: " << temp << "\n";
    count++;  // 2
  }
  if (this->get_year_released() > 0) {
    std::cout << "Year Released: " << this->get_year_released() << "\n";
    count++; // 3
  }
  if (this->get_record_label(temp)) {
    std::cout << "Record Label: " << temp << "\n";
    count++; // 4
  }
  if (this->get_num_songs() > 0) {
    std::cout << "Number of Songs: " << this->get_num_songs() << "\n";
    count++; // 5
  }
  if (this->get_num_minutes_long() > 0) {
    std::cout << "Number of Minutes Long: " << this->get_num_minutes_long() << "\n";
    count++; // 6
  }
  if (this->get_genre((temp))) {
    std::cout << "Genre: " << temp << "\n";
    count++; // 7
  }
  if (count == 7) {
    return true;
  } else {
      return false;
  }
}

// Grabs all the info like 
// write_console but putting
// A value to write 
// Return true if written false otherwise
bool Album::write_file(char * file_name)   	
{
  int count = 0;
  std::fstream albumStream(file_name, std::fstream::out);
  if (!albumStream.is_open()) {
    return false;  
  }
  if (this->title) {
    char* msg = "Album Title: ";
    albumStream << msg << this->title << std::endl;
    count++;  // 1
  }
  if (this->artist) {
    char* msg = "Album Artist: ";
    albumStream << msg << this->artist << std::endl;
    count++;  // 2
  }
  if (this->year_released > 0 ) {
    char* msg = "Year Album Released: ";
    albumStream << msg << this->year_released << std::endl;
    count++; // 3
  }
  if (this->record_label) {
    char* msg = "Record Label: ";
    albumStream << msg << this->record_label << std::endl;
    count++; // 4
  }
  if (this->num_songs > 0) {
    char* msg = "Number of Songs: ";
    albumStream << msg << this->num_songs << std::endl;
    count++; // 5
  }
  if (this->num_minutes_long > 0) {
    char* msg = "Number of Minutes Long: ";
    albumStream << msg << this->num_minutes_long << std::endl;
    count++; // 6
  }
  if (this->genre) {
    char* msg = "Genre: ";
    albumStream << msg << this->genre << std::endl;
    count++; // 7
  }
  if (count == 7) {
    albumStream.close();
    return true;
  } else {
    albumStream.close();
    return false;
  }
}                                            
