#include <iostream>

using namespace std;

int main(){
int x=5;
int *p=&x;

printf("This is is dereferencing of x: %d \n", *p); //6
cout <<"This is is pointer of x called p:" << p <<endl; //memory_location
cout <<"This is is reference of x:" << &x << endl; //memory_location
cout <<"This is is reference of p:" << &p << "\n" << endl; //memory_location

cout << "Let change x by using its dereferencing of p to 24" <<endl;
*p=24;

printf("This is is dereferencing of x: %d \n", *p); //6
cout <<"This is is pointer of x called p:" << p <<endl; //memory_location
cout <<"This is is reference of x:" << &x << endl; //memory_location
cout <<"This is is reference of p:" << &p <<"\n"<< endl; //memory_location

cout <<"Lets make a pointer to the pointer so **q=&p"<<endl;
int ** q= &p;
cout <<"This is is pointer of x called p:" << p <<endl; //memory_location
cout <<"This is is reference of x:" << &x << endl; //memory_location
cout <<"This is is reference of p:" << &p <<"\n"<< endl; //memory_location
cout<<endl;
cout <<"This is just q:" << q << endl; //memory_location
cout <<"This is *q :" << *q << endl; //memory_location
cout <<"This is **q :" << **q << endl; //memory_location



return 0;
}
