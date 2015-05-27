#include <iostream>

using namespace std;

template <class T>
class Stack{
	private:
		T * Stack;		//stack using a pointer
		int top;
		int Size;
	public:
		Stack(int StackSize=20);
		T& getTop();
		T& pop();
		void push(const T& Element);
		bool IsEmpty();
		int CurrSize();
};

template <class T>
Stack<T>::Stack(int StackSize):Size(StackSize)
{
	Stack=new T(Size);
	top=-1;
}

template <class T>
T& Stack::getTop()
{
	if (!IsEmpty()) return (Stack[top]);
	else cout << "Stack is Empty!" << endl;
}

template <class T>
T& Stack::pop()
{
	if (!IsEmpty()) return (Stack[top--]);
	else cout << "Stack is Empty!" << endl;
}


bool Stack::IsEmpty()
{
	if(top==-1) return 1;
	else return 0;
}

bool Stack::IsFull()
{
	if(top==MaxCapacity-1) return 1;
	else return 0;
}

int Stack::CurrSize()
{
	return(top+1);
}

void Stack::push(const T & Element)
{
	if(!IsFull()) cout << "Stack is Full" << endl;
	else Stack[++top]=Element;
}

int main (){
	Stack<int> test_stack;
	test_stack.push(3);
	test_stack.push(15);
	test_stack.push(44);
	cout <<" Are you empty? "<< test_stack.IsEmpty()<<endl;
	cout << "Are you full? "<<test_stack.IsFull()<<endl;
	cout << " TOP? "<<test_stack.top()<<endl;
	return 0;
}
