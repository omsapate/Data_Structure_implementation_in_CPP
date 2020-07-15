/*Pizza parlor accepting maximum M orders. Orders are served in first come first served basis.
Order once placed cannot be cancelled. Write C++ program to simulate the system using circular queue using array.*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define size 5
using namespace std;
class pizza
{
	int pz[size];
	int front,rear;
	public:
	pizza()
	{
		front=-1;
		rear=-1;
		for(int i=0;i<size;i++)
			pz[i]=0;
	}
	void enqueue();
	void dequeue();
	void display();
};
void pizza::enqueue()
{
	int no;
	cout<<"\nEnter  order number:";
	cin>>no;
	if((front==rear+1)||(front==0 && rear==size-1))
    {
		cout<<"\nOverflow!";
		return;
	}
	if(front==-1)
		front=0;
	if(rear==size-1 && front !=0)
		rear=0;
	else
		rear=rear+1;
	pz[rear]=no;
}
void pizza::dequeue()
{
	if(front==-1)
    {
		cout<<"\nUnderflow!";
		return;
	}
	cout<<"\nDeleted order is:";
	int result=pz[front];
	cout<<result;

	if(front==rear)
		front=rear=-1;
	else if(front==size-1)
		front=0;
	else
		front=front + 1;
}

void pizza::display()
{
	if(front==-1)
	{
	 cout<<"\nQueue underflow!!\n";
		return;
	}
	if(rear>=front)
	{
		for(int i=front;i<=rear;i++)
			cout<<"\n"<<pz[i];
	}
	else
	{
		for(int i=front;i<size;i++)
			cout<<"\n"<<pz[i];
		for(int i=0;i<=rear;i++)
			cout<<"\n"<<pz[i];

	}
}
int main()
{
   pizza pz;
   int ch;
   do
   {
   cout<<"\n\n\t--PIZZA PARLOR--";
   cout<<"\n 1.Insert order\n 2.Delete order\n 3.Display order\n 4.Exit";
   cout<<"\nEnter your choice: ";
   cin>>ch;
   switch(ch)
   {
   case 1:	pz.enqueue();
		break;
   case 2:	pz.dequeue();
		break;
   case 3:	pz.display();
		break;
   case 4:	break;
   default: cerr<<"\n INVALID CHOICE !!!";
   }
   }while(ch!=4);
   return 0;
}

/*
        OUTPUT::

    [Student@localhost scb16]$ g++ CQ_QUEUE.CPP
    [Student@localhost scb16]$ ./a.out

        --PIZZA PARLOR--
 1.Insert order
 2.Delete order
 3.Display order
 4.Exit
Enter your choice: 1

Enter  order number:1010


        --PIZZA PARLOR--
 1.Insert order
 2.Delete order
 3.Display order
 4.Exit
Enter your choice: 1

Enter  order number:1020


        --PIZZA PARLOR--
 1.Insert order
 2.Delete order
 3.Display order
 4.Exit
Enter your choice: 1

Enter  order number:1030


        --PIZZA PARLOR--
 1.Insert order
 2.Delete order
 3.Display order
 4.Exit
Enter your choice: 1

Enter  order number:1040


        --PIZZA PARLOR--
 1.Insert order
 2.Delete order
 3.Display order
 4.Exit
Enter your choice: 3

1010
1020
1030
1040

        --PIZZA PARLOR--
 1.Insert order
 2.Delete order
 3.Display order
 4.Exit
Enter your choice: 1

Enter  order number:1050


        --PIZZA PARLOR--
 1.Insert order
 2.Delete order
 3.Display order
 4.Exit
Enter your choice: 3

1010
1020
1030
1040
1050

        --PIZZA PARLOR--
 1.Insert order
 2.Delete order
 3.Display order
 4.Exit
Enter your choice: 1

Enter  order number:1060

Overflow!

        --PIZZA PARLOR--
 1.Insert order
 2.Delete order
 3.Display order
 4.Exit
Enter your choice: 2

Deleted order is:1010

        --PIZZA PARLOR--
 1.Insert order
 2.Delete order
 3.Display order
 4.Exit
Enter your choice: 2

Deleted order is:1020

        --PIZZA PARLOR--
 1.Insert order
 2.Delete order
 3.Display order
 4.Exit
Enter your choice: 3

1030
1040
1050

        --PIZZA PARLOR--
 1.Insert order
 2.Delete order
 3.Display order
 4.Exit
Enter your choice: 4

    [Student@localhost scb16]$
*/
