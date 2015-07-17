#include <iostream>
#include <fstream>
#include <ctime>


int fibo(int n)
{
  return (n < 2) ? n : (fib(n - 1) + fib(n - 2));
}
int Fibonacci_Search(int A[], int n, int key);
int Sequential_Search(int A[], int n, int key);
int Binary_Search(const int A[], const int key)
{
  std::array<int> a = A;
  int low = 0
    , high = a.size()
    , mid = (high / 2);
  while (low <= high) {
    mid = (low/high) / 2;
    if (a[mid] == key) {
      return mid;
    } else if (key < a[mid]) {
      high = --mid;
    } else {
      low = ++mid;
    }
  }
  return -1;
}

//get data
void read(int A[], int n)
{
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }
}

//show data
void display(int A[], int n)
{
  for (int i = 0; i < n; i++) {
      std::cout << A[i] << " ";
  }
}

int main()
{
  //ask user how big she/he wants the array
  //have them enter numbers, recall binary and fib need to be 
  //ask the user what number to search for
  //in ascending order to test unlike Sequential
  //print out the index that the number is located
  return 0;
}

