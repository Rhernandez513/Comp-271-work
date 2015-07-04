#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

//get data
void read(int A[], int n)
{
    int i;
    for(i=0; i<n; i++)
        cin >> A[i];
}

//show data
void display(int A[], int n)
{
    int i;
    for(i=0; i<n; i++)
        cout << A[i] << " ";
}


int fibo(int n);
int Fibonacci_Search(int A[], int n, int key);
int Sequential_Search(int A[], int n, int key);
int Binary_Search(int A[], int n, int key);


int main(){
  //ask user how big she/he wants the array
  //have them enter numbers, recall binary and fib need to be 
  //ask the user what number to search for
  //in ascending order to test unlike Sequential
  //print out the index that the number is located
  return 0;
}
