#include<iostream>
#include<string.h>

using namespace std;

class MyString
{
	char *value;
	int len;
	string str;

	public:

	MyString()
	{
		len=0;
		value=0;
	}
	~MyString(){}

	//String From Array
	MyString(char *s)
	{
		len=strlen(s);
		value=new char[len+1];
		strcpy(value,s);
	}

	//String using Copy Constructor
	MyString(MyString & s)
	{
		len=s.len;
		value=new char[len+1];
		strcpy(value,s.value);
	}

	//str3=str1+str2
	friend MyString operator+(MyString obj1,MyString obj2)
	{
		MyString obj3;
		obj3.len=obj1.len+obj2.len;
		obj3.value=new char[obj3.len+1];

		strcpy(obj3.value,obj1.value);
		strcat(obj3.value,obj2.value);

		return obj3;
	}

	friend ostream & operator << (ostream &output, MyString &s);
	friend istream & operator >> (istream &input, MyString &s);

	char operator[](int val)
	{
		char rel;
		if(val > len)
		{
			cout<<"\nInvalid index position \n";
		}
		else
		{
			rel = value[val];
			cout<<"\nThe result is : "<<rel<<"\n";
		}
		return rel;
	}

	void display()
	{
		if(len==0)
		{
			cout<<"String is Empty \n";
		}
		else
		{
			cout<<"The result is:"<<value<<"\n";
		}
	}
};

ostream & operator << (ostream &output, MyString &s)
{
	output<<"Input string is : "<<s.str<<"\n";
	return output;
}

istream & operator >> (istream &input, MyString &s)
{
	input>>s.str;
	return input;
}

int main()
{
	//Use + overloaded operator
	cout<<"Enter two strings to concatenate : \n";
	char a[20],b[20];
	cin>>a>>b;
	MyString str1(a);
	MyString str2(b);
	MyString str3;
	str3=str1+str2;
	str3.display();
	MyString str4;

	//Use >> and << overloaded operator
	cout<<"Enter a string : ";
	cin>>str4;
	cout<<str4;
	return 0;
}