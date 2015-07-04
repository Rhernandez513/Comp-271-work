//
//  Stack.h
//  LabFour
//
//  Created by maria saenz on 9/13/14.
//  Copyright (c) 2014 maria saenz. All rights reserved.
//
//  Completed by Robert Hernadnez on 6/15/2015

#ifndef LabThree_Stack_h
#define LabThree_Stack_h

class Stack
{
private:
    int *p;
    int top, length;
    
public:
    Stack(int = 0);
    ~Stack();
    bool push(int);
    int pop();
    void display();
    bool isEmpty();
    void copy(Stack& stack);
};

#endif // LabThree_Stack_h
