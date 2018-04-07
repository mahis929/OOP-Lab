#include<iostream>
using namespace std; 

class Stack
{
	int *items;
	int top;
	int full();
	int empty();
public:
	int size;
	Stack()
	{
		top = -1;
	}
	Stack(int);
	Stack operator --(int);
	Stack operator ++(int);
	friend Stack operator +(Stack s, int elem);
	friend Stack operator -(Stack &s);
	friend ostream & operator <<(ostream &, Stack &);
	int operator[](int val)
	{
		int rel;
		//cout<<top<<endl;
		if(val > top+1)
		{
			cout<<"\nInvalid index position \n";
		}
		else
		{
			rel = items[top-val+1];
			cout<<"\nThe result is : "<<rel<<"\n";
		}
		return rel;
	}
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

Stack::Stack(int s)
{
	top = -1;
	size = s;
	items = new int[size];
}

Stack operator +(Stack s1, int elem)
{
	if (s1.full())
	{
		cout<<"Stack Overflow..!\n\n";
	}
	else
	{
		s1.items[++(s1.top)] = elem;
	}
	return s1;
}

Stack operator -(Stack &s1)
{
	if(s1.empty())
	{
		cout<<"\nStack Underflow..!\n\n";
	}
	else
	{
		cout<<"\nThe element deleted is : "<<s1.items[s1.top]<<"\n";
		--s1.top;
	}
	return s1;
}

Stack Stack::operator --(int )
{
	for(int i = top; i>=0; i--)
	{
		items[i] = items[i] - 1;
	}
}

Stack Stack::operator ++(int )
{
	for(int i = top; i>=0; i--)
	{
		items[i] = items[i] + 1;
	}
}

ostream & operator <<(ostream &out, Stack &s1)
{
	for(int i = s1.top; i >= 0; i--)
	{
		out<<s1.items[i]<<" ";
	}
	cout<<"\n";
	return out;
}

int main()
{
	int size;
	cout<<"Enter the size of the stack : ";
	cin>>size;
	Stack s1(size);
	int choice, elem, index;
	while(1)
	{
		cout<<"1. Push.\n2. Pop.\n3. Index. \n4. Decrement. \n5. Increment.\n6. Display\n\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter an element : ";
					cin>>elem;
					s1 = s1 + elem;
					break;
			case 2: s1 = -s1;
					break;
			case 3: cout<<"Enter the index of element : ";
					cin>>index;
					s1[index];
					break;
			case 4: s1--;
					break;
			case 5: s1++;
					break;
			case 6: cout<<"\nThe elements are : "<<s1<<"\n";
					break;
			default : cout<<"Invalid Choice..!\n\n";
		}
	}
	return 0;
}