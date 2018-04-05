#include <iostream>
using namespace std;

class Matrix
{
	long m[10][10];
	int row,column;
public:
	Matrix(){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				m[i][j] = 0;
			}
		}	
	}
	int operator ==(Matrix);
	Matrix operator +(Matrix);
	Matrix operator -(Matrix);
	Matrix operator *(Matrix);
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

Matrix Matrix::operator +(Matrix addMat)//Overloading for addition
{
	Matrix temp;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			temp.m[i][j] = m[i][j] + addMat.m[i][j];
		}
		temp.row = row;
		temp.column = column;
	}
	return temp;	
}

Matrix Matrix::operator -(Matrix addMat)//Overloading for subtraction
{
	Matrix temp;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			temp.m[i][j] = m[i][j] - addMat.m[i][j];
		}
		temp.row = row;
		temp.column = column;
	}
	return temp;	
}

Matrix Matrix::operator*(Matrix x)// overloading * for multiplication
{
    Matrix c;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c.m[i][j]=0;
            for(int k=0;k<3;k++)
            {
           	    c.m[i][j]=c.m[i][j]+m[i][k]*x.m[k][j];        
            }
        }
    }
    return c;
}

istream & operator >> (istream &input, Matrix &in)//Overloading for >> cin
{
	cout<<"Enter no of rows : ";
	input>>in.row;
	cout<<"Enter no of columns : ";
	input>>in.column;
	cout<<"Enter the matrix elements \n";
	for(int i = 0; i < in.row; i++){
		cout<<"Enter elements of "<<i+1<<" row : ";
		for(int j = 0; j < in.column; j++){
			input>>in.m[i][j];
		}
	}
	return input;
}

ostream & operator << (ostream &output, Matrix &out)//Overloading for << cout
{
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
	if((m1 == m2)==1)
	{
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
	//bit of error to be corrected... nind aa rha hai bhai...!!!
	else if((m1 == m2)==2)
	{	
		cout<<"Matrices are not identical hence cannot be added or subtracted..!!!!!\n\n";
		m5 = m1 * m2;
		cout<<"Multiplication of matrices is : \n";
		cout<<m5;
	}
	else
	{
		cout<<"Matrices are not identical hence cannot be added or subtracted or multiplied..!!!!!";
	}
}