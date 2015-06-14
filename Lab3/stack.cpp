//
//  Stack.cpp
//  LabFour
//
//  Created by maria saenz on 9/13/14.
//  Copyright (c) 2014 maria saenz. All rights reserved.
//

#include <iostream>
#include "Stack.h"

using namespace std;
Stack::Stack(int size)
{
  top = -1;
  length = size;
  if (size == 0) {
      p = 0;
  } else {
      p = new int[length];
  }
}

Stack::~Stack()
{
  if (p != 0) {
    delete [] p;
  }
}

void Stack::push(int elem)
{
                   // If the stack size is zero, allow user to
  if (p == 0) {    // Mention it at runtime
    std::cout << "Stack of zero size" << std::endl;
    std::cout << "Enter a size for stack : ";
    std::in >> length;
    p = new int[length];
  }
  if (top == (length - 1)) {  // Top reaches to the maximum stack size
    std::cout << "\nCannot push " << elem << ", Stack full" << std::endl;
    return;
  } else {
      top++;
      p[top] = elem;
  }
}
int Stack::pop()
{
  if (p == 0 || top == -1) {
    std::cout << "Stack empty!";
    return -1;
  }
  int ret = p[top];
  top--;
  length--;
  return ret;
}

void Stack::display()
{
  //1. Create a display function
  if (this.isEmpty()) {
    std::cout << "Cannot display contents of an empty stack." << std:endl;
  } else {
      for (int i = 0; i < top; i++) {
        std::cout << "Element #" << i + 1 << ": " << p[i] << std::endl;
  }
}

bool Stack::isEmpty()
{
  if (top == -1) {
    return true;
  } else {
      return false;
  }
}

void Stack::copy(Stack& dest)
{
    //2. Create a copy function
}

int main()
{
  Stack B; //We are creating a stack of size 'zero'
  Stack A;
  B.push(1);
  B.push(2);
  B.push(3);
  B.push(4);
  B.push(5);
  std::cout << "Copy B into A and Display\n" << std::endl;
  B.copy(A);
  //3.Write Display A and Display B
  return 1;
}

