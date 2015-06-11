#include <iostream>
#include <cstring>
#include "hw2.h"

using namespace std;

Album::Album()
{
  artist = new char[256];
  title = new char[256];
  year_released = 0;
  record_label = new char[256];
  num_songs = 0;
  num_minutes_long = 0;
  genre = new char[256];
}

Album::Album(char *& a, char *& t)
  : Album()
{
  artist = a;
  title = t;
}

//deconstructor
Album::~Album()
{
  delete[] artist;
  delete[] title;
  delete[] record_label;
  delete[] genre;
}

// Setters
bool Album::set_artist(char * a) { artist = a; }
bool Album::set_title(char * t) { title = t; }
bool Album::set_year_released(int value) { year_released = value; }
bool Album::set_record_label(char *& label) { record_label = label; }
bool Album::set_num_songs(int value) { num_songs = value; }
bool Album::set_num_minutes_long(int value) { num_minutes_long = value; }
bool Album::set_genre(char * g) { genre = g; }

// Getters
int Album::get_num_songs() { return num_songs; }
int Album::get_num_minutes_long() { return num_minutes_long; }
int Album::get_year_released() { return year_released; }
bool Album::get_artist(char *& a)
{
  if (artist)
  {
    a = artist;
    return true;
  }
  else
  {
    return false;
  }
}
bool Album::get_title(char *& t)
{
  if (title)
  {
    t = title;
    return true;
  }
  else
  {
    return false;
  }
}
bool Album::get_record_label(char *& label)
{
  if (record_label)
  {
    label = record_label;
    return true;
  }
  else
  {
    return false;
  }
}
bool Album::get_genre(char *& g)
{
  if (genre)
  {
    g = genre;
  }
  return genre;
};
