#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node * next;
};

class Stack
{
	struct node * top;
public:
	Stack();
	void push();
	void pop();
	void display();
};

Stack::Stack()
{
	top = NULL;
}

void Stack::push()
{
	int item;
	cout<<"Enter item : ";
	cin>>item;
	struct node * temp = new node;
	if(temp == NULL)
	{
		cout<<"\nStack Overfow..!\n\n";
		return;
	}
	temp->data = item;
	temp->next = NULL;
	if(top!=NULL)
	{
		temp->next = top;
	}
	top = temp;
}

void Stack::pop()
{
	if(top == NULL)
	{
		cout<<"\nStack Underflow.!\n\n";
		return;
	}
	struct node *temp = top;
	top = temp->next;
	cout<<"\nDeleted : "<<temp->data<<"\n";
	free(temp);

}

void Stack::display()
{
	struct node *temp = top;
	if(temp == NULL)
	{
		cout<<"\nThe Stack is empty..!\n\n";
		return;
	}
	cout<<"\nStack is : ";
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n\n";
}

int main()
{
	Stack s1;
	int choice;
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