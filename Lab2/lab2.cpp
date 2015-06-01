/*
 * BattleShip.cpp
 *
 */
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

bool set_ships(int **& matrix, int size, int num1);

int main()
{
  int ** B;
  int size, num_ships, row, col;
  int num_hits = 0;

  cout << "***** Battleship *****" << endl;
  cout << "How many rows/columns is the board? ";
  cin >> size;

  /* CREATE THE BATTLESHIP BOARD AND SET ALL ELEMENTS TO 0*/
  // Creating the Board
  B = new int * [size];
  for(int i = 0; i < size; i++)
  {
    B[i] = new int[size];
  }
  // Initializing Elements to 0
  for(int row = 0; row < size; row++)
  {
    for(int column = 0; column < size; column++)
    {
      B[row][column] = 0;
    }
  }


  cout << "A " << size << "x" << size << " board has been created.\n";
  cout << "How many ships? ";
  cin >> num_ships;
  set_ships(B, size, num_ships);
  cout << "paused" << endl;
  system("pause");
  while (num_hits != num_ships)
  {
    cout << "What row:";
    cin >> row;
    cout << "What col: ";
    cin >> col;

    /*DETERMINE IF ITâS A HIT. IF SO, UPDATE INFORMATION & TELL USER.*/

  }

  cout << "You sunk my battleships!" << endl;

  /*CLEAN UP YOUR MEMORY*/



  return 0;
}
/** Create set_ships function **/
bool set_ships(int **& matrix, int size, int num1)
{
  srand((unsigned)time(NULL));
  for(int i = 0; i < num1; i++)
  {
    int row = (rand() % size);
    int column = (rand() % size);
    int* location = &matrix[row][column];
    if (*location == 1)
    {
      i--;
      continue;
    }
    else
    {
      *location = 1;
      cout << "set ship at " << location << endl;
    }
  }
  return true;
}
