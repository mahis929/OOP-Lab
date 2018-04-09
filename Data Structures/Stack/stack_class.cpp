#include<iostream>
#include <stdlib.h>
using namespace std;

class Stack
{
	int *items;
	int top;
	int empty();
	int full();
public:
	int size;
	Stack();
	Stack(int);
	void push();
	void pop();
	void display();
	void initializeStack();
};

int Stack::full()
{
	if(top == size-1)
	{
		return 1;
	}
	return 0;
}

int Stack::empty()
{
	if(top == -1)
	{
		return 1;
	}
	return 0;
}

Stack::Stack()
{
	top = -1;
	items = new int[0];
}

Stack::Stack(int s){
	top = -1;
	size = s;
	items = new int[size];
}

void Stack::initializeStack()
{
	cout<<"Enter the size : ";
	cin>>size;
	Stack s(size);
}

void Stack::push()
{
	if(full())
	{
		cout<<"\n\nStack Overflow..!!\n\n";
		return;
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

void Stack::pop()
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

void Stack::display()
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
	Stack s1;
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