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
  for(int tempRow = 0; tempRow < size; tempRow++)
  {
    for(int tempColumn = 0; tempColumn < size; tempColumn++)
    {
      B[tempRow][tempColumn] = 0;
    }
  }


  cout << "A " << size << "x" << size << " board has been created.\n";
  cout << "How many ships? ";
  cin >> num_ships;
  set_ships(B, size, num_ships);
  //cout << "paused" << endl;
  //system("pause");
  while (num_hits != num_ships)
  {
    cout << "What row? :";
    cin >> row;
	while (row < 0)
	{
		cout << "Sorry that's not on the grid.\n";
		cout << "What row? :";
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> row;
		cout << " row: " << row << endl;
	}
	system("pause");
    cout << "What col?: ";
    cin >> col;
	while (col > size || col < 0)
	{
		cout << "Sorry that's not on the grid." <<endl;
		cout << "What col? :";
		cin >> col;
	}
    /*DETERMINE IF IT'S A HIT. IF SO, UPDATE INFORMATION & TELL USER.*/
    if (B[row][col] == 1)
	{
        cout << "A Hit! At coordinates (" << row << "," << col << ")!" << endl;
        B[row][col] = 0;
	}
    else
    {
        cout << "The shot fires off with no impact..." << endl;
    }

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
