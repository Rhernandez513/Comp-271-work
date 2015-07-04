//
//  Stack.cpp
//  LabFour
//
//  Created by maria saenz on 9/13/14.
//  Copyright (c) 2014 maria saenz. All rights reserved.
//
//  Completed by Robert Hernadnez on 6/15/2015

#include <iostream>
#include "stack.h"

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
  A.display();
  B.display();
  std::system("pause");
  return 1;
}
