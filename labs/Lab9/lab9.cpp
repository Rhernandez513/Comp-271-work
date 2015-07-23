#include <iostream>

using namespace std;

#define max 20

class Heap
{
	private:
        int A[max];
        int n;
		void ReHeapUp(int root, int bottom);
		void ReHeapDown(int root, int bottom);
	public:
		Heap()
		{
		    n=0;
			for(int i=0; i<max; i++)
				A[i]=0;
		}
		void Create();
		void Insert(int i);
		void DeleteMaxVal();
		void write_out();
};

void Heap::ReHeapUp(int root, int bottom)
{
	//implement me
}


void Heap::ReHeapDown(int root, int bottom)
{
	//implement me
}


void Heap::DeleteMaxVal()
{
    int temp=A[0];
    A[0]=A[n-1];
    A[n-1]=temp;
    n--;
    ReHeapDown(0,n-1);
}

void Heap::Insert(int x)
{
	A[n]=x;
	ReHeapUp(0,n);
	n++;
}

void Heap::write_out()
{
  //implement me
}

void Heap::Create()
{
    int i,data,size;
    cout << "Enter number of elements: ";
    cin >> size;//n;
    cout << "\nEnter data: ";
    for(i=0; i<size; i++)
    {
        cin>> data;
        Insert(data);
    }
}

int main()
{
    Heap h;
    h.Create();
    h.write_out();
    h.DeleteMaxVal();
    cout << endl;
    h.write_out();
    h.DeleteMaxVal();
    cout << endl;
    h.write_out();
    return 0;
}
