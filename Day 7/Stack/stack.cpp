#include<iostream>
#include<stdlib.h>
using namespace std;

template <class T>

class Stack
{
	T *items;
	int top;
public:
	int size;
	Stack();
	Stack(int);
	bool empty();
	bool full();
	void push();
	void pop();
	void display();
	void initializeStack();
};

template <class T>
Stack<T>::Stack()
{
	top = -1;
	size = 0;
	items = new T[0];
}

template <class T>
Stack<T>::Stack(int s)
{
	top = -1;
	size = s;
	items = new T[size];
}

template <class T>
bool Stack<T>::empty()
{
	return top == -1;
}

template <class T>
void Stack<T>::initializeStack()
{
	cout<<"Enter the size : ";
	cin>>size;
	Stack s(size);
}

template <class T>
bool Stack<T>::full()
{
	return top == size - 1;
}

template <class T>
void Stack<T>::push()
{
	if(full())
	{
		cout<<"\nOverflow..!!\n\n";
	}
	else
	{
		int elem;
		cout<<"Enter the element : ";
		cin>>elem;
		top++;
		items[top] = elem;
	}
}

template <class T>
void Stack<T>::pop()
{
	if(empty())
	{
		cout<<"\n\nStack Underflow..!\n\n";
	}
	else
	{
		cout<<"\n\nDeleted Element is : "<<items[top]<<"\n";
		top--;		
	}
}

template <class T>
void Stack<T>::display()
{
	if(empty())
	{
		cout<<"\nThe Queue is empty..!\n\n";
		return;
	}
	cout<<"\nThe Stack is : ";
	for(int i = top; i >= 0; i--)
	{
		cout<<items[i]<<" ";
	}
	cout<<"\n\n";
}

int main()
{
	int choice;
	Stack <int>s1;
	//cout<<s1.top<<endl;
	while(1)
	{
		cout<<"\n0. Initialize Stack.\n1. Push.\n2. Pop.\n3. Display.\n4. Exit.\n\n";
		cin>>choice;
		switch(choice)
		{
			case 0: s1.initializeStack();
					break;

			case 1:	s1.push();
					break;

			case 2: s1.pop();
					break;

			case 3:	s1.display();
					break;

			case 4: exit(1);

			default: cout<<"\n\nInvalid Choice..!!\n\n";
		}
	}
	return 0;
}