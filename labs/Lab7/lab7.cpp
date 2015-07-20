#include <iostream>
#include <string>

int fibo(const int n)
{
  return (n < 2) ? n : (fibo(n - 1) + fibo(n - 2));
}

int Fibonacci_Search(const int A[], const int key)
{
  int n = (sizeof(A) / sizeof(*A));
  int j = 1;
  while(fibo(j) <= n) {
    j++;
  }
  int f = fibo(j);
  int f1 = fibo(j - 2);
  int f2 = fibo(j - 3);
  int mid = (n - f1 + 1);

  while(key != A[mid]) { //if not found
    //look in lower half
    if(mid < 0 || key > A[mid]) {
      if(f1 == 1) {
        return -1;
      }
      mid = mid + f2; //decrease Fibonacci numbers
      f1 = (f1 - f2);
      f2 = (f2 - f1);
    } else {
      if(f2 == 0) {
        return -1;
      }
      mid = (mid - f2);
      int temp = (f1 - f2);
      f1 = f2;
      f2 = temp;
    } // End if
  } // End while
  return mid; // Return index of key
}

int Sequential_Search(const int A[], const int n, const int key)
{
  for(int i = 0; i < n; i++) {
    if (key == A[i]) {
      return i;
    }
  }
  return -1;
}

int Binary_Search(const int A[], const int key)
{
  int low = 0
    , high = (sizeof(A) / sizeof(*A))
    , mid = (high / 2);
  while (low <= high) {
    mid = (low/high) / 2;
    if (A[mid] == key) {
      return mid;
    } else if (key < A[mid]) {
      high = --mid;
    } else {
      low = ++mid;
    }
  }
  return -1;
}

// Get data
void read(int A[])
{
  int arraySize = 0;
  int n = sizeof(A) / sizeof(*A);
  std::cout << "How big do you want the array? ";
  std::cin >> arraySize;

  if (arraySize > n) {
    std::cout << "That's too big for the size of the provided Array(";
    std::cout << n << ").  Try again.\n" << std::endl;
    read(A);
  } else if (arraySize >= 0) {
    for (int i = 0; i < n; i++) {
      std::cout << "Value for position " << i + 1 << " ? " << std::endl;
      std::cin >> A[i];
    } // Read user Input
  } else {
    // arraySize < 0
    std::cout << "Bad input!! Try Again!" << std::endl;
    read(A);
  } // End if
}

// Show data
void display(int A[])
{
  int n = sizeof(A) / sizeof(*A);
  for (int i = 0; i < n; i++) {
      std::cout << A[i] << " ";
  }
}

int main()
{
  int mainArray[256];
  read(mainArray);
  display(mainArray);
  //have them enter numbers, recall binary and fib need to be 
  //ask the user what number to search for
  //in ascending order to test unlike Sequential
  //print out the index that the number is located
  return 0;
}

