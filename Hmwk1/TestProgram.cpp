#include <iostream>
#include "cube.h"

using namespace std;
int main()
{
  int x;
  Cube cubeTest(5, 5, 5);       // Creates a correctly working Cube

  //Uncomment line to check negative values
  // Cube failCubebTest(5, -5, 5); // Should fail and throw an exception

  cout << "The area is: " << cubeTest.get_area() << endl;
  cout << "The length is: " << cubeTest.get_length() << endl;
  cout << "The depth is: " << cubeTest.get_depth() << endl;
  cout << "The width is: " << cubeTest.get_width() << endl;
  cout << "The surface area is: " << cubeTest.get_surface_area() << endl;
  cin >> x;
  return 0;
}
