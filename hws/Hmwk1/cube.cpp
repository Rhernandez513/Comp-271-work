#include <iostream>
#include <string>
#include <array>
#include "cube.h"

Cube::Cube() {};

Cube::Cube(int inLength, int inWidth, int inDepth, char* inCubeName)
  : Cube(inLength, inWidth, inDepth)
{
  int arrayLength = (sizeof(inCubeName) / sizeof(inCubeName[0]) + 1);
  char* temp = new char[arrayLength];
  for (int i = 0; i < (arrayLength - 1); i++)
  {
    temp[i] = inCubeName[i];
  }
  temp[arrayLength - 1] = '\0';
  this->cube_name = temp;
};

Cube::Cube(int inLength, int inWidth, int inDepth)
{
  length = inLength;     // Is it really a cube?
  width = inWidth;       // With potentially,
  depth = inDepth;       // Different sides?
  using namespace std;
  array <int, 3> values = { length, width, depth };
  string name[] = { "length", "width", "depth" };
  for (int dimension = 0; dimension < values.size(); dimension++)
  {
    if (values[dimension] < 0)
    {
      string message = "The " + name[dimension] + " is " +
        to_string(values[dimension]) + " less than zero.";
      cout << message << endl;
      throw invalid_argument(message);
    }
  }
};

Cube::~Cube()
{
  if (cube_name)
  {
    delete cube_name;
  }
}

// Getters

// sum of area of all six sides
int   Cube::get_surface_area() { return length * width * 6; }
int   Cube::get_area()         { return length * width * depth; }
int   Cube::get_length()       { return length; }
int   Cube::get_width()        { return width; }
int   Cube::get_depth()        { return depth; }
char* Cube::get_cube_name()    { return cube_name; }

// Setters
bool  Cube::set_length(int l)
{
  if (l > 0)
  {
    length = l;
    return true;
  }
  else
  {
    std::cout << "Length cannot be less than zero" << std::endl;
    return false;
  }
}
bool  Cube::set_width(int w)
{
  if (w > 0)
  {
    width = w;
    return true;
  }
  else
  {
    std::cout << "Width cannot be less than zero" << std::endl;
    return false;
  }
}
bool  Cube::set_cube_name(char* n)
{
  if (n)
  {
    cube_name = n;
    return true;
  }
  else
  {
    return false;
  }
}

