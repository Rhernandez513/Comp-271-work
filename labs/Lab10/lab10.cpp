#include <iostream>

using namespace std;

void hanoi(int n, char *s,char *i,char *d);
int num_moves = 0;

int main()
{
    int disks;
    char * stars = "*****";
    std::cout << "\t\t" << stars << "The Amazing Tower of Hanoi!" << stars;
    std::cout << "\n\t\t" << stars << stars << "How many disks? "
              << stars << stars << "*\n\t\t\t\t";
    std::cin >> disks;
    hanoi(disks, "Tower 1", "Tower 2", "Tower 3");
    std::cout << "\t\tIt took " << num_moves << " movements to do this." << std::endl;
    return 0;
}
// s stands for source tower
// i stands for intermediate tower
// d stands for destination tower
void hanoi(int n, char *s, char *i, char *d)
{
  if (n == 0) {
    std::cout << "\t\tMove disk " << n << " from " << s << " to " << d << ".\n";
    ++num_moves;
    return;
  } else {
    hanoi(n-1, s, d, i); 
    std::cout << "\t\tMove disk " << n << " from " << s << " to " << d << ".\n";
    ++num_moves;
    hanoi(n-1, i, s, d);
  }
}

