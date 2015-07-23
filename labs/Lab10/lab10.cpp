#include <iostream>

using namespace std;

void hanoi(int n, char *s,char *i,char *d);
int num_moves=0;

int main()
{
    int disks;
    cout << "How many disks? ";
    cin >> disks;
    hanoi(disks, "Tower 1", "Tower 2", "Tower 3");
    cout << "It took " << num_moves << " to do this." <<endl;
    return 0;
}

void hanoi(int n,char *s,char *i,char *d) // s stands for source tower; d stands for destination tower; i stands for intermediate tower
{

}
