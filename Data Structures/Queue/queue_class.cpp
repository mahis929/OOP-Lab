#include<iostream>
#include <stdlib.h>
using namespace std;

class Queue
{
	int *items;
	int front, rear;
	int empty();
	int full();
public:
	int size;
	Queue();
	Queue(int);
	void initialiseQueue();
	void enqueue();
	void dequeue();
	void peek();
	void display();
};

Queue::Queue()
{
	front = -1;
	rear = -1;
	items = new int[0];
}

Queue::Queue(int size)
{
	front = -1;
	rear = -1;
	items = new int[size];
}

void Queue::initialiseQueue()
{
	cout<<"Enter size of queue : ";
	cin>>size;
	Queue q(size);
}

int Queue::empty()
{
	if(front == -1 || front > rear)
	{
		return 1;
	}
	return 0;
}

int Queue::full()
{
	if(rear == size-1)
	{
		return 1;
	}
	return 0;
}

void Queue::enqueue()
{
	if(full())
	{
		cout<<"\nOverflow..!\n";
		return;
	}
	else
	{
		int elem;
		cout<<"Enter element : ";
		cin>>elem;
		if(front == -1)
		{
			front++;
		}
		items[++rear] = elem;
	}
}

void Queue::dequeue()
{
	if(empty()){
		cout<<"\nUnderflow..!\n";
		return;
	}
	else
	{
		cout<<"\n Deleted element is : "<<items[front]<<"\n\n";
		front++;
	}
}

void Queue::peek()
{
	if(empty())
	{
		cout<<"\nQueue is empty..!\n\n";
		return;
	}
	else
	{
		cout<<"\nFirst element is : "<<items[0]<<"\n\n";
	}
}

void Queue::display()
{
	if(empty())
	{
		cout<<"\nThe Queue is empty..!\n\n";
		return;
	}
	cout<<"The queue is : ";
	for(int i=front; i<=rear; i++)
	{
		cout<<items[i]<<" ";
	}
	cout<<"\n\n";
}

int main()
{	
	int choice;
	Queue q;
	while(1)
	{
		cout<<"1. Initialise Queue.\n2. Enqueue.\n3. Dequeue.\n4. Peek.\n5. Display.\n6. Exit.\n\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:	q.initialiseQueue();
					break;

			case 2:	q.enqueue();
					break;

			case 3: q.dequeue();
					break;

			case 4:	q.peek();
					break;

			case 5: q.display();
					break;

			case 6: exit(1);
					break;			

			default : cout<<"\nInvalid Choice..!!\n\n";
		}
	}
	cout<<"\nThanks";
	return 0;
}