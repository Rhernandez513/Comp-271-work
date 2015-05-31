#include <iostream>
#include <time.h>
#include <cmath>
#include "cube.h"

using namespace std;

Cube* CubeCreator();

void main()
{
  Cube cubeTest(5, 5, 5);       // Creates a correctly working Cube
  char y[] =  { 't', 'e', 's', 't' };
  Cube* cubeTest2 = new Cube(3, 2, 4, y);
  //delete cubeTest2;
  //Uncomment line to check negative values
  // Cube failCubebTest(5, -5, 5); // Should fail and throw an exception
  cout << "Cube Test Portion\n" << endl;
  cout << "The area is: " << cubeTest.get_area() << endl;
  cout << "The length is: " << cubeTest.get_length() << endl;
  cout << "The depth is: " << cubeTest.get_depth() << endl;
  cout << "The width is: " << cubeTest.get_width() << endl;
  cout << "The surface area is: " << cubeTest.get_surface_area() << endl;
  
  // User inputs begin here
  cout << "\nHow many cube's would you like to create?\n" << endl;
  int numberOfCubes;
  cin >> numberOfCubes;
  Cube* cubeArray = new Cube[numberOfCubes];
  for (int i = 0; i < numberOfCubes; i++)
  {
    cout << "Constructing Cube #" << i + 1 << endl;
    cubeArray[i] = *CubeCreator();
    cout << "The Cube's area of a side is " << cubeArray[i].get_area() << endl;
    cout << "The Surface Area is " << cubeArray[i].get_surface_area() << endl;
  }

  // Randomly changing values of the cubes
  cout << "\nRandom number portion\n" << endl;
  srand((unsigned)time(NULL));
  for (int i = 0; i < numberOfCubes; i++)
  {
    cubeArray[i].set_length(rand() % 40);
    cubeArray[i].set_width(rand() % 40);
  }
  for (int i = 0; i < numberOfCubes; i++)
  {
    cout << "Length of " << cubeArray[i].get_cube_name() << " after " << 
         "modification " << cubeArray[i].get_length() << endl;
    cout <<  "Width of " << cubeArray[i].get_cube_name() << " after " <<
         "modification " << cubeArray[i].get_width() << endl;
  }
  // Delete all cubes
  delete [] cubeArray;
  system("pause");
}

Cube* CubeCreator()
{
  using namespace std;
  int length, width, depth;
  char name[256];
  cout << "Please enter the desired length" << endl;
  cin >> length;
  cout << "Length set to: " << length << endl;
  cout << "Please enter the desired width" << endl;
  cin >> width;
  cout << "Width set to: " << width<< endl;
  cout << "Please enter the desired depth" << endl;
  cin >> depth;
  cout << "Depth set to: " << depth << endl;
  cout << "Please enter the desired name" << endl;
  std::cin.getline(name,256);
  cin >> name;
  cout << "Name set to: " << name << endl;
  return new Cube(length, width, depth, name);
}
