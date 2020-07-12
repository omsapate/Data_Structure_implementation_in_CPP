#include<iostream>
using namespace std;

class Binary
{
	public:
	int digit;
	Binary *next,*prev;
	Binary(int n)
	{
		digit=n;
		next=NULL;
		prev=NULL;
	}
};

class DLL
{
	Binary *head;
	public:
	DLL()
	{
		head=NULL;
	}
    void insert_end(Binary *);
	void insert_beg(Binary *);
	void create();
	void display();
	DLL one_comp();
	DLL two_comp();
	DLL add(DLL);
};
void DLL::create()
{
	int no;
	cout<<"\n\t\tEnter Number: ";
	cin>>no;
	while(no>0)
	{
		int n=no%2;
		no=no/2;
		Binary *newnode=new Binary(n);
		if(head==NULL)
			head=newnode;
		else
		{
			newnode->next=head;
			head->prev=newnode;
			head=newnode;
		}
	}
}
void DLL::display()
{
	if(head==NULL)
		cout<<"\n\t\t List is empty!";
	else
	{
		Binary *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->digit;
			temp=temp->next;
		}
	}
}
void DLL::insert_end(Binary *newnode)
{
	if(head==NULL)
		head=newnode;
	else
	{
		Binary *temp=head;
		while(temp->next!=NULL)
			temp=temp->next;

		temp->next=newnode;
		newnode->prev=temp;
	}
}

void DLL::insert_beg(Binary *newnode)
{
	if(head==NULL)
		head=newnode;
	else
	{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
}
DLL DLL::add(DLL d)
{
	DLL res;
	Binary *temp1=head;
	while(temp1->next!=NULL)
		temp1=temp1->next;

	Binary *temp2=d.head;
	while(temp2->next!=NULL)
		temp2=temp2->next;

	int carry=0,ans=0;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(carry==0 && temp1->digit==0 && temp2->digit==0)
		{
			ans=0;
			carry=0;
		}
		else if(carry==0 && temp1->digit==0 && temp2->digit==1)
		{
			ans=1;
			carry=0;
		}
		else if(carry==0 && temp1->digit==1 && temp2->digit==0)
		{
			ans=1;
			carry=0;
		}
		else if(carry==0 && temp1->digit==1 && temp2->digit==1)
		{
			ans=0;
			carry=1;
		}
		else if(carry==1 && temp1->digit==0 && temp2->digit==0)
		{
			ans=1;
			carry=0;
		}
		else if(carry==1 && temp1->digit==0 && temp2->digit==1)
		{
			ans=0;
			carry=1;
		}
		else if(carry==1 && temp1->digit==1 && temp2->digit==0)
		{
			ans=0;
			carry=1;
		}
		else if(carry==1 && temp1->digit==1 && temp2->digit==1)
		{
			ans=1;
			carry=1;
		}
		temp1=temp1->prev;
		temp2=temp2->prev;

		Binary *newnode=new Binary(ans);
		res.insert_beg(newnode);
	}

	while(temp1!=NULL)
	{
		if(carry==1 && temp1->digit==0)
		{
			ans=1;
			carry=0;
		}
		else if(carry==1 && temp1->digit==1)
		{
			ans=0;
			carry=1;
		}
		else
		{
			ans=temp1->digit;
		}
		temp1=temp1->prev;

		Binary *newnode=new Binary(ans);
		res.insert_beg(newnode);
	}

	while(temp2!=NULL)
	{
		if(carry==1 && temp2->digit==0)
		{
			ans=1;
			carry=0;
		}
		else if(carry==1 && temp2->digit==1)
		{
			ans=0;
			carry=1;
		}
		else
		{
			ans=temp2->digit;
		}
		temp2=temp2->prev;

		Binary *newnode=new Binary(ans);
		res.insert_beg(newnode);
	}
	if(temp1==NULL && temp2==NULL && carry==1)
	{
		ans=1;
		Binary *newnode=new Binary(ans);
		res.insert_beg(newnode);
	}
	return res;
}
DLL DLL::one_comp()
{
	Binary *newnode,*temp;
	DLL res;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->digit==1)
		{
			newnode=new Binary(0);
		}
		else if(temp->digit==0)
		{
			newnode=new Binary(1);
		}
		temp=temp->next;
		res.insert_end(newnode);
	}
	return res;
}
DLL DLL::two_comp()
{
	int carry=0;
	DLL ones_c,one,res;
	Binary *temp=head;
	while(temp->next!=NULL)
	{
		Binary *newnode=new Binary(0);
		temp=temp->next;
		one.insert_end(newnode);
	}
	Binary *newnode=new Binary(1);
	one.insert_end(newnode);
	ones_c=one_comp();
	res=ones_c.add(one);
	return res;
}
int main()
{
	DLL d1, d2, d3;
	int ch;
	do
    {
        cout<<"\n\n\t\t--{OPERATION'S ON BINARY NUMBERS}--";
        cout<<"\n\t 1.Convert Decimal to Binary\n\t 2.One's Complement of Binary"
            <<"\n\t 3.Two's Complement of Binary\n\t 4.Addition of Two Binary\n\t 5.Exit";
        cout<<"\n\t Enter choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: d1.create();
                    cout<<"\n\t\tBinary number: ";
                    d1.display();
            break;
            case 2: d3=d1.one_comp();
                    cout<<"\n\t\tOne's complement: ";
                    d3.display();
            break;
            case 3: d3=d1.two_comp();
                    cout<<"\n\t\tTwo's complement:";
                    d3.display();
            break;
            case 4: d2.create();    d2.display();
                    d3=d1.add(d2);
                    cout<<"\n\t\tAddition is: ";
                    d3.display();
            break;
            case 5: break;
            default: cerr<<"\n\t\tINVALID CHOICE !!!";
            break;
        }
    }while(ch!=5);

}

/*
    OUTPUT:
    [Student@localhost scb16]$ g++ DLL.CPP
    [Student@localhost scb16]$ ./a.out

                --{OPERATION'S ON BINARY NUMBERS}--
         1.Convert Decimal to Binary
         2.One's Complement of Binary
         3.Two's Complement of Binary
         4.Addition of Two Binary
         5.Exit
         Enter choice: 1

                Enter Number: 25

                Binary number: 11001

                --{OPERATION'S ON BINARY NUMBERS}--
         1.Convert Decimal to Binary
         2.One's Complement of Binary
         3.Two's Complement of Binary
         4.Addition of Two Binary
         5.Exit
         Enter choice: 2

                One's complement: 00110

                --{OPERATION'S ON BINARY NUMBERS}--
         1.Convert Decimal to Binary
         2.One's Complement of Binary
         3.Two's Complement of Binary
         4.Addition of Two Binary
         5.Exit
         Enter choice: 3

                Two's complement:00111

                --{OPERATION'S ON BINARY NUMBERS}--
         1.Convert Decimal to Binary
         2.One's Complement of Binary
         3.Two's Complement of Binary
         4.Addition of Two Binary
         5.Exit
         Enter choice: 4

                Enter Number: 12
1100
                Addition is: 100101

                --{OPERATION'S ON BINARY NUMBERS}--
         1.Convert Decimal to Binary
         2.One's Complement of Binary
         3.Two's Complement of Binary
         4.Addition of Two Binary
         5.Exit
         Enter choice: 5
    [Student@localhost scb16]$

*/
