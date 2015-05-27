#include <iostream>
#include "cqueue.h"

using namespace std;

int Cqueue::Is_Empty()
{
    if(Size==0) return true;
    else return false;
}

int Cqueue::Is_Full()
{
    if(Size==Max) return true;
    else return false;
}

void Cqueue::Add(int Element)
{
    if(!Is_Full()) Rear=(Rear+1)%Max;
    Queue[Rear]=Element;
    Size++;
}

int Cqueue::Delete()
{
    if(Is_Empty())
    {
        cout << "The Cqueue is empty." << endl;
        return -1;
    }
    else
    {
        Front=(Front+1)%Max;
        Size--;
        return Queue[Front];
    }
}

int Cqueue::getFront()
{
    int Temp;
    if(Is_Empty())
    {
        return -1;
    }
    else
    {
        Temp=(Front+1)%Max;
        return Queue[Front];
    }
}

void Cqueue::write_Cqueue_to_Console()         //write all of the class variables to the console
{
    int i;
    int Temp;
    if(Is_Empty())
        cout << "Queue is empty.\n";
    else
    {
        for(i=1; i<=Size; i++)
        {
            Temp=(Front+i)%Max;
            cout << Queue[Temp] << " ";
        }
        cout << endl;
    }
}
