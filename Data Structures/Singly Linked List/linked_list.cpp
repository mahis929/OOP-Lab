#include<iostream>
#include<stdlib.h>
using namespace std;

//Node Class
class Node
{
	int data;
	Node *next;
public:
	Node(){};
	void setData(int );
	void setNext(Node *);
	int Data();
	Node *Next()
	{
		return next;
	}
};

void Node::setData(int dat)
{
	data = dat;
}

void Node::setNext(Node *nex)
{
	next = nex;
}

int Node::Data()
{
	return data;
}

/*Node Node::*Next()
{
	return next;
}*/

class List
{
	Node *head;
public:
	List();
	void Print();
	void Append();
	void Delete();
};

List::List()
{
	head = NULL;
}

void List::Print()
{
	Node *temp = head;
	if(temp == NULL)
	{
		cout<<"\nThe list is empty..!\n\n";
		return;
	}
	cout<<"\nThe List is : ";
	while(temp != NULL)
	{
		cout<<temp->Data()<<" ";
	}
	cout<<"\n\n";
}

void List::Append()
{
	Node *newNode = new Node();
	if(newNode == NULL)
	{
		cout<<"\nOverflow\n\n";
		return;
	}
	int dat1;
	cout<<"Enter element : ";
	cin>>dat1;
	newNode->setData(dat1);
	newNode->setNext(NULL);
	Node *temp = head;
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		while(temp->Next() != NULL)
		{
			temp = temp->Next();
		}
		temp->setNext(newNode);
	}
}

void List::Delete()
{
	
}

int main()
{
	
	return 0;
}