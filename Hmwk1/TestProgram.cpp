#include <iostream>
#include "cube.h"

using namespace std;
int main()
{
  int x;
  Cube cubetest(5, 5, 5);
  cout << "The area is: " << cubetest.get_area() << endl;
  cout << "The length is: " << cubetest.get_length() << endl;
  cout << "The depth is: " << cubetest.get_depth() << endl;
  cout << "The width is: " << cubetest.get_width() << endl;
  cout << "The surface area is: " << cubetest.get_surface_area() << endl;
  cin >> x;
  return 0;
}