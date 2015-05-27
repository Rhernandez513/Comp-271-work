#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line();   // This is the constructor declaration
      ~Line();  // This is the destructor: declaration
 
   private:
      double length;
};
 
// Member functions definitions including constructor
Line::Line(void)
{
    cout << "Object is being created" << endl;
}
Line::~Line(void)
{
    cout << "Object is being deleted" << endl;
}
 
void Line::setLength( double len )
{
    length = len;
}
 
double Line::getLength( void )
{
    return length;
}
// Main function for the program
int main( )
{
   Line line;
   // set line length
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
   
   cout <<"Calling a line with memory from heap"<<endl;
   Line * heap_line = new Line();
   cout <<" Memory is located at: "<< heap_line << endl;
   heap_line->setLength(24);
   cout<<" Length of line on heap: "<<heap_line->getLength();
   cout<< "\nDeleting the heap line which is the first delete, the second is of the Line object created in the beginning"<<endl;
   delete heap_line;
   return 0;
}
