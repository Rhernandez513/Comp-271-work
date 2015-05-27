#include <fstream> 
#include <cstring>

using namespace std; 

int  main( ) 
{ 
	ifstream in; 
	ofstream out; 
        char text [100];
	in.open("file1.txt"); 
	out.open("file2.txt"); 
	while(in.peek()!=EOF) 
	{ 
		in.getline(text,100,'\n'); 
		out << text << endl; 
	} 
	in.clear(); in.close(); 
	out.clear(); out.close(); 
  return 0;
}

