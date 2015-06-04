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

  std::cout << "***** Battleship *****" << std::endl;
  std::cout << "How many rows/columns is the board? ";
  std::cin >> size;

  /* CREATE THE BATTLESHIP BOARD AND SET ALL ELEMENTS TO 0*/
  // Creating the Board
  B = new int * [size];
  for(int i = 0; i < size; i++)
  {
    B[i] = new int[size];
  }
  // Initializing Elements to 0
  for(int tempRow = 0; tempRow < size; tempRow++)
  {
    for(int tempColumn = 0; tempColumn < size; tempColumn++)
    {
      B[tempRow][tempColumn] = 0;
    }
  }


  std::cout << "A " << size << "x" << size << " board has been created.\n";
  std::cout << "How many ships? ";
  std::cin >> num_ships;
  set_ships(B, size, num_ships);

  while (num_hits != num_ships)
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "\n";
    }
    /*DETERMINE IF IT'S A HIT. IF SO, UPDATE INFORMATION & TELL USER.*/
    std::cout << "What row? :";
    std::cin >> row;
    while (row < 0 || row >= size)
    {
      std::cout << "Sorry that's not on the grid.\n";
      std::cout << "What row? :";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin >> row;
    }

    std::cout << "What col?: ";
    std::cin >> col;
    while (col < 0 || col >= size)
    {
      std::cout << "Sorry that's not on the grid.\n";
      std::cout << "What col? :";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin >> col;
    }

    std::cout << "Launch Torpedo! Firing at (" << row << "," << col << ")!\n";
    if (B[row][col] == 1)
    {
      std::cout << "A Hit! At coordinates (" << row << "," << col << ")!\n";
      B[row][col] = 0;
      num_hits++;
    }
    else
    {
      std::cout << "The shot fires off with no impact..." << std::endl;
    }

  }

  std::cout << "You sunk my battleships!" << std::endl;

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
      std::cout << "set ship at " << location << std::endl;
    }
  }
  return true;
}
