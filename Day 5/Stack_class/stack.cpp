#include<iostream>
using namespace std;
#define size 5

class Stack
{
	int items[size];
	int top;
	int empty();
	int full();
public:
	Stack();
	void push();
	void pop();
	void display();
};

Stack::Stack()
{
	top = -1;
}

int Stack::empty()
{
	if(top == -1)
	{
		return 1;
	}
	return 0;
}

int Stack::full()
{
	if(top == size-1)
	{
		return 1;
	}
	return 0;
}

void Stack::push()
{
	if(full()){
		cout<<"\nStack Overflow..!\n\n";
	}
	else
	{
		int elem,temp;
		cout<<"Enter element : ";
		cin>>elem;
		top++;
		items[top] = elem;		
	}
}

void Stack::pop()
{
	if(empty())
	{
		cout<<"\nStack Underflow..!\n\n";
	}
	else
	{
		cout<<"\nDeleted Element is : "<<items[top]<<"\n";
		top--;		
	}
}

void Stack::display()
{
	cout<<"\nThe Stack is : ";
	for(int i = top; i >= 0; i--)
	{
		cout<<items[i]<<" ";
	}
	cout<<"\n\n";
}

int main()
{
	Stack s1;
	int choice,temp;
	while(1)
	{
		cout<<"1. Push.\n2. Pop.\n3. Display.\n";
		cout<<"\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1: s1.push();
					break;

			case 2: s1.pop();
					break;
			
			case 3: s1.display();
					break;
			
			default: cout<<"\nInvalid Choice..!!\n\n";
		}
	}
	return 0;
}