#include <iostream>
using namespace std;

class Matrix
{
	long **m;
public:
	int row,column;
	Matrix(int i=0, int j=0){ //constructor
		row = i;
		column = j;
		m = new long*[row];
		for(int i = 0; i < row; i++) {
			m[i] = new long[column];
		}	
	}
	Matrix(Matrix &x) { //copy constructor
		row = x.row;
		column = x.column;
		m = new long*[row];
		for(int i = 0; i < row; i++) {
			m[i] = new long[column];
		}
		//also copying the values
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < column; j++)
				m[i][j] = x.m[i][j];
		}
	}

	int operator ==(Matrix);
	Matrix operator +(Matrix);
	Matrix operator ++(int);
	Matrix operator -(Matrix);
	Matrix operator --(int);
	Matrix operator *(Matrix);
	void operator ~(void);
	friend istream & operator >> (istream &, Matrix &);
	friend ostream & operator << (ostream &, Matrix &);
};

int Matrix:: operator == (Matrix m1)
{
	if(row == m1.row && column == m1.column)
	{
		return 1;
	}
	if(row == m1.column && column == m1.row)
	{
		return 2;
	}
	return 0;
}

Matrix Matrix::operator+(Matrix addMat)//Overloading for addition
{	
	Matrix temp(row, column);
	cout<<addMat;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			temp.m[i][j] = m[i][j] + addMat.m[i][j];
		}
	}
	return temp;	
}

Matrix Matrix::operator-(Matrix addMat)//Overloading for subtraction
{
	Matrix temp(row, column);
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			temp.m[i][j] = m[i][j] - addMat.m[i][j];
		}
	}
	return temp;	
}

Matrix Matrix::operator*(Matrix x)// overloading * for multiplication
{
    Matrix c(row, x.column);

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<x.column;j++)
        {
            c.m[i][j]=0;
            for(int k=0;k<column;k++)
            {
           	    c.m[i][j]=c.m[i][j] + m[i][k] * x.m[k][j];        
            }
        }
    }
    return c;
}

Matrix Matrix::operator ++(int )//overloading ++ for incrementing
{
	for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            m[i][j] = m[i][j]+1;
        }
    }
}

Matrix Matrix::operator --(int )//overloading -- for decrementing
{
	for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            m[i][j] = m[i][j]-1;
        }
    }
}

void Matrix::operator ~(void)//overloading ~ for negation
{
	for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            m[i][j] = m[i][j]*-1;
        }
    }	
}

istream & operator >> (istream &input, Matrix &in)//Overloading for >> cin
{	int r,c;
	cout<<"Enter no of rows : ";
	input>>r;
	cout<<"Enter no of columns : ";
	input>>c;
	Matrix temp(r,c);
	cout<<"Enter the matrix elements \n";
	for(int i = 0; i < r; i++){
		cout<<"Enter elements of "<<i+1<<" row : ";
		for(int j = 0; j < c; j++){
			input>>temp.m[i][j];
		}
	}
	in = temp;
	return input;
}

ostream & operator << (ostream &output, Matrix &out)//Overloading for << cout
{
	//cout<<out.row<<" "<<out.column<<"\n\n";
	for(int i = 0; i < out.row; i++){
		for(int j = 0; j < out.column; j++){
			output<<out.m[i][j];
			cout<<" ";
		}
		cout<<endl;
	}
	return output;
}

int main()
{
	Matrix m1,m2,m3,m4,m5;
	cin>>m1;
	cin>>m2;
	
	if((m1 == m2)==1) {
		cout<<"Case 1:"<<endl;
		m3 = m1 + m2;
		m4 = m1 - m2;
		m5 = m1 * m2;
		cout<<"Addition of matrices is : \n";
		cout<<m3;
		cout<<"Subtraction of matrices is : \n";
		cout<<m4;
		cout<<"Multiplication of matrices is : \n";
		cout<<m5;
	}
	else if((m1 == m2)==2) {
		cout<<m1;
		cout<<m2;
		cout<<"Case 2\n";
		m5 = m1 * m2;
		cout<<"\nMultiplication of matrices is : \n";
		cout<<m5;
	}
	else
	{
		cout<<"\nMatrices are not identical hence cannot be added or subtracted or multiplied..!!!!!";
	}
	cout<<"\nIncrementing first matrix \n\n";
	m1++;
	cout<<m1;

	cout<<"\nDecrementing second matrix\n\n";
	m2--;
	cout<<m2;

	cout<<"\nNegation of second matrix\n\n";
	~m2;
	cout<<m2;

	return 0;
}