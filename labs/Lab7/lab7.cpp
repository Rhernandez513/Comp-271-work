#include <iostream>

const int max = 256;

void bufferClear()  // Syntactic sugar
{
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int fibo(const int n)
{ 
  if (n < 0) return -1;
  return (n < 2) ? n : (fibo(n - 1) + fibo(n - 2));
}

int Fibonacci_Search(const int A[], const int n, const int key)
{
  int j = 1;
  while(fibo(j) <= n) {
    j++;
  } // End while
  // int f = fibo(j);
  int f1 = fibo(j - 2);
  int f2 = fibo(j - 3);
  int mid = (n - f1 + 1);

  while(key != A[mid]) { //if not found
    //look in lower half
    if(mid < 0 || key > A[mid]) {
      if(f1 == 1) {
        return -1;
      } // End if
      mid = mid + f2; //decrease Fibonacci numbers
      f1 = (f1 - f2);
      f2 = (f2 - f1);
    } else {
      if(f2 == 0) {
        return -1;
      } // End if
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
    } // End if
  } // End for
  return -1; // If data not found
}

int Binary_Search(const int A[], const int n, const int key)
{
  int low = 0
    , high = n
    , mid;
  while (low <= high) {
    mid = (low/high) / 2;
    if (A[mid] == key) {
      return mid;
    } // End if
    if (key < A[mid]) {
      high = --mid;
    } else {
      low = ++mid;
    } // End if
  } // End while
  return -1;  // If data not found
}

// Get data
int read(int A[], const int n)
{
  int arraySize;
  while (true) {
    arraySize = 0;
    std::cout << "\nHow big should the array be? (Max 256) ";
    if (std::cin >> arraySize) {  // Input works
      if (arraySize > 255 || arraySize < 0) {  // Save final position
        std::cout << "\nInvalid input! How big again? " << std::endl;
      } else if (arraySize > n) {
        std::cout << "\sThat's too big for the size of the provided Array(";
        std::cout << n << ").\nTry again: " << std::endl;
      } else { // Begin Happy path
        // Read user Input
        int i = 0;
        while (i < arraySize) {
          std::cout << "\nValue for position " << i + 1 << "? ";
          if (std::cin >> A[i]) {
            bufferClear();
            // Input works
          } else {
            std::cout << "\nBad input!! Try Again!" << std::endl;
            bufferClear(); // Bad input, reset input stream
            --i;
          } // End if
          ++i;
        } // End while
        A[i] = std::numeric_limits<int>::max(); // On final position
        bufferClear(); // Strip \n just in case
        return i;  // End Happy path
      } // End inner if
    } else {
      std::cout << "\nInvalid input! How big again? " << std::endl;
    } // End outer if
    bufferClear(); // Bad input, reset input stream
  } // End while
}

// Show data
void display(int A[], const int n)
{
  for (int i = 0; A[i] != A[n]; i++) {
    std::cout << A[i] << " ";
  } // End for
  std::cout << std::endl;
}

int main()
{
  int key;
  int mainArray[max] = { };  // Instantiate all indices to zero
  int n = read(mainArray, max);  // n = (index with data + 1)
  std::cout << "\nDisplay: ";
  display(mainArray, n);
  std::cout << std:: endl;
  bufferClear();
  std::cout << "\nWhat number do you want to search for? ";
  std::cin >> key;
  std::cout << "\nBinary Search: " << Binary_Search(mainArray, n, key);
  std::cout << "\nFibonacci Search: " << Fibonacci_Search(mainArray, n, key);
  std::cout << "\nSequential Search: " << Sequential_Search(mainArray, n, key);
  std::cout << "\nGoodbye!" << std::endl;
  return 0;
}

