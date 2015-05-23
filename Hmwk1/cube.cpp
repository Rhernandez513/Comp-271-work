#include <iostream>
#include "cube.h"

Cube::Cube(int inLength, int inWidth, int inDepth)
  : length(inLength),      // Is it really a cube?
  width(inWidth),          // With potentially 
  depth(inDepth)           // Different sides?
{
}

// return length of cube
int Cube:: get_length() 
{
  return length;
}
// return width of cube
int Cube:: get_width()
{
  return width;
}
// return depth of cube
int Cube:: get_depth()
{
  return depth;
}
// length x width x depth
int Cube:: get_area() 
{
  return length * width * depth;
}
// sum of area of all six sides
int Cube:: get_surface_area()
{
  return length * width * 6;
}
