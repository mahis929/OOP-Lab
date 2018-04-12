#include<iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
class Queue
{
	T *items;
	int front, rear;
public:
	int size;
	Queue();
	Queue(int);
	bool empty();
	bool full();
	void initialiseQueue();
	void enqueue();
	void dequeue();
	void peek();
	void display();
};

template <class T>
Queue<T>::Queue()
{
	front = -1;
	rear = -1;
	items = new int[0];
}

template <class T>
Queue<T>::Queue(int size)
{
	front = -1;
	rear = -1;
	items = new int[size];
}

template <class T>
void Queue<T>::initialiseQueue()
{
	cout<<"Enter size of queue : ";
	cin>>size;
	Queue q(size);
}

template <class T>
bool Queue<T>::empty()
{
	return (front == -1 || front > rear);
}

template <class T>
bool Queue<T>::full()
{
	return (rear == size-1);
}

template <class T>
void Queue<T>::enqueue()
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
		rear++;
		items[rear] = elem;
	}
}

template <class T>
void Queue<T>::dequeue()
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

template <class T>
void Queue<T>::peek()
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

template <class T>
void Queue<T>::display()
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
	Queue <int>q;
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