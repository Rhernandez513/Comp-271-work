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
    std::cin >> length;
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
    std::cout << "Stack empty!" << std::endl;
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
  if (this->isEmpty()) {
    std::cout << "Cannot display contents of an empty stack." << std:endl;
  } else {
      for (int i = 0; i <= top; i++) {
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
  bool allCopied = true;
  if(this->isEmpty()) {
    std::cout << "Cannot copy empty stack." << std::endl;
    return;
  } else {
    for(int i = 0; i <= dest.top; i++) {
      if(dest.top == (dest.length -1)) {  // Top reaches to the maximum stack size
        allCopied = false;
        break;
      }
      dest.push(this->p[i]);
    }
    if(allCopied) {
      std::cout << "Copy succesfull" << std::endl;
    } else {
    std::cout << "Top of destination stack reached, not all elements copied." << std::endl;
    }
  }
}
