#include <iostream>

using namespace std;

//This is your Header
class Rectangle {
	private:
		//class variables that are private below
		double length;
		double width;
		char * rect_name;
	public:
		Rectangle(double l, double w); //your constructor that takes in 2 parameters
		~Rectangle(); //this is a destructor
		//you accessors
		double get_area();
		double get_length();
		double get_width();
		char * get_rect_name();
		//your mutators
		bool set_length(double l);
		bool set_width(double w);
		bool set_rect_name(char * n);
};

//This is your class that has a scope of Header Rectangle
Rectangle::Rectangle(double l, double w)
{
	if(l<=0){
		cout << "Length must be a positive integer" << endl;
	}
	else
	{
		if(w<=0){
			cout << "Width must be a positive integer" << endl;
		}
		else
		{
			length=l;
			width=w;
		}
	}
}

//Destructors get rid of any pointers that are created like rect_name, you can set other things to NULL and/or 0.
Rectangle::~Rectangle(){
	cout << "Destroying Rectangle"<<endl;
	if (length!=0){
		length=0;
	}
	if(width!=0){
		width=0;
	}
	if(rect_name!=NULL){
		delete rect_name;
	}
}

double Rectangle::get_length()
{
	return length;
}

double Rectangle::get_width()
{
	return width;
}

bool Rectangle::set_length(double l)
{
	if(l !=0){
		length=l;
		return true;
	}
	return false;
}

bool Rectangle::set_width(double w)
{
	if(w != 0){
		width=w;
		return true;
	}
	return false;
}

double Rectangle::get_area()
{
	return length*width;
}

char * Rectangle::get_rect_name(){
	return rect_name;
}

bool Rectangle::set_rect_name(char * n){
	if(rect_name!=NULL){
		delete [] rect_name;
	}	
  rect_name = new char[strlen(n) + 1];
  strcpy(rect_name, n);
  return true;
}


//your main to test your class implemented the header correctly
int main()
{

	Rectangle * r=new Rectangle(5.5,3.3);
	char * r_name="Ms. Rectangle";
	r->set_rect_name(r_name);
	cout << "Width is " ;
	cout << r->get_width() << endl;
	cout << "Length is ";
	cout << r->get_length() << endl;
	cout << "Area is ";
	cout << r->get_area() << endl;
	cout <<"Name is ";
	cout <<r->get_rect_name()<<endl;
	delete r;
	return 1;
}