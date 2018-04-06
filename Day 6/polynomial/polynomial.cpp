#include<bits/stdc++.h>

using namespace std;

struct poly
{
	int power,cf;
	struct poly *next;
};
class polynomial
{	
	int val;
	struct poly* head;
public:
	polynomial(struct poly* &headd)
	{
		head = headd;
	}
	polynomial(struct poly* &node,int x)
	{	val = 0;
		head = node;
			while(node)
			{
				val += (node->cf)*(pow(x,node->power));
				node = node->next;
			}

	}
	polynomial()
	{
		head = NULL;
	}
	struct poly* addition(struct poly *,struct poly *);
	int v(){
		cout << val << endl;
	}
	void display()
	{	cout << "Display" << endl;
		struct poly*head3 = head;
		while(head3)
		{
				{	
					if(head3->next)
					cout << head3->cf <<  "x^" << head3->power << " + " ;
					else
					cout << head3->cf <<  "x^" << head3->power;
					head3 = head3->next;

				}
		
		}
		cout << "\n";
	}
	polynomial operator+(polynomial);
	polynomial operator*(polynomial);

	
};
polynomial polynomial::operator +(polynomial p)//Overloading for addition
{
	
	struct poly*node = NULL;
	
	struct poly* node1 = p.head;
	struct poly* node2 = head;
		while(node1&&node2)
	{
		if(node1->power < node2->power)
		{
			struct poly*temp = (struct poly*)malloc(sizeof(struct poly));

			temp->cf = node1->cf;
			temp->power = node1->power;
			temp->next = node;
			node = temp;
			node1 = node1->next;
		}
		else if (node1->power > node2->power)
		{
			/* code */
			struct poly*temp = (struct poly*)malloc(sizeof(struct poly));

			temp->cf = node2->cf;
			temp->power = node2->power;
			temp->next = node;
			node = temp;
			node2 = node2->next;
		}
		else
		{
			struct poly*temp = (struct poly*)malloc(sizeof(struct poly));

			temp->cf = node1->cf + node2->cf;
			temp->power = node1->power;
			temp->next = node;
			node = temp;
			node1 = node1->next;
			node2 = node2->next;
		}
	}
	while(node1)
	{
		struct poly*temp = (struct poly*)malloc(sizeof(struct poly));

			temp->cf = node1->cf;
			temp->power = node1->power;
			temp->next = node;
			node = temp;
			node1 = node1->next;
	}
	while(node2)
	{
		struct poly*temp = (struct poly*)malloc(sizeof(struct poly));

			temp->cf = node2->cf;
			temp->power = node2->power;
			temp->next = node;
			node = temp;
			node2 = node2->next;

	}
	polynomial pp(node);
	return pp;	
}
polynomial polynomial::operator *(polynomial p)//Overloading for addition
{
	
	struct poly*node = NULL;
	
	struct poly* node1 = p.head;
	
	map<int,int>m;
	while(node1)
	{
		struct poly* node2 = head;
		while(node2)
		{
			int coeff = node2->cf*node1->cf;
			int exp =  node2->power + node1->power;
			m[exp] += coeff;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	map<int,int>::iterator it;
	for(it = m.begin();it!=m.end();++it)
	{
		struct poly*temp = (struct poly*)malloc(sizeof(struct poly));
		temp->cf = it->second;
		temp->power = it->first;
		temp->next = node;
		node = temp;
	}
	polynomial pp(node);
	return pp;
}

int main()
{
	struct poly * head1=NULL,*head2=NULL,*head3;
	int cf,power;
	
	printf("Enter data for polynomial 1\n");
	while(1)
	{
		
		cin >> cf >> power;
		if(cf==0)
			break;
		struct poly*temp = (struct poly*)malloc(sizeof(struct poly));

			temp->cf = cf;
			temp->power = power;
			temp->next = head1;
			head1 = temp;

	}
	polynomial p1(head1);
	//p1.display();
	printf("Enter data for polynomial 2\n");
	while(1)
	{
		
		cin >> cf >> power;
		if(cf==0)
			break;
		struct poly*temp = (struct poly*)malloc(sizeof(struct poly));

			temp->cf = cf;
			temp->power = power;
			temp->next = head2;
			head2 = temp;

	}
	polynomial p2(head2);
	//p2.display();
	
	polynomial p3,p4;
	p3 = p1+p2;
	p4 = p1*p2;
	p4.display();
	//p4.display();
	//p4.display();
	
}