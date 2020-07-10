/*Problem Statement: 
	A palindrome is a string  of character  that‘s  the same forward  and backward. Typically,
punctuation, capitalization, and spaces are ignored. 
For example, ‖Poor Dan is in a droop‖is a palindrome, as can  be seen by  
examining  the characters ―poor dan is in a droop‖and observing  that  they  are 
the  same  forward  and  backward.  One  way to check for a palindrome  is  to  reverse    the  characters  
in  the  string  and  then  compare  with  them  the original-in a palindrome, the sequence will be identical. 
Write C++ program with functions-
1. Tocheck whether given string is palindrome or not that uses a stack to determine whethera string is a palindrome.
2. to  remove  spaces  and punctuation in string, convert all the Characters to lowercase, and then callabove Palindrome checking function to check for a palindrome
3. to print string in reverse order using stack*/

#include <iostream>
#include <string.h>
#define size 150
using namespace std;

class stack
{
	int top;
public:
	char stk[size];
	stack()
	{
		top=-1;
		strcpy(stk,"");
	}

	void push(char x);
	char pop();
	int isempty();
	int isfull();
	void convert_string(char[], char[]);
	int ispalindrome(char[]);
	void reverse(char[]);
};

int stack:: isfull()
{
	if(top == size-1)
	return 1;
	else
	return 0;
}

int stack:: isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
void stack :: push(char x)
{
	if(!isfull())
	{
		top++;
		stk[top]=x;
	}
	else
	cerr<<"\n Stack overflow!! error!!";
}

char stack :: pop()
{
	char x;
	x=stk[top];
	top--;
	return x;
}

void stack:: convert_string(char str[], char str1[])
{
	int i=0,j=0;
	while(str[i]!='\0')
	{
		if(str[i]>='a' && str[i]<='z')
		str1[j++]= str[i++];
		else if(str[i]>='A' && str[i]<='Z')
		str1[j++]= str[i++]+32;
		else if(!isalpha(str[i]) || str[i]==' ')
		i++;
	}
	str1[j]='\0';
}

void stack::  reverse(char str[])
{
	char rev[size];
	for(int i=0;str[i]!='\0';i++)
	{
		push(str[i]);
	}
    int i=0;
	while(!isempty())
	{
		rev[i]=pop();
		i++;
	}

	rev[i]='\0';
	cout<<"\n\t Original string is: "<<stk;
	cout<<"\n\t reverse string is: "<<rev;
}

int stack:: ispalindrome(char str[])
{

	int i, flag=1;
	for(i=0;str[i]!='\0';i++)
	{
		push(str[i]);
	}
	i=0;
	while(!isempty())
	{
		if(str[i++]!=pop())
		{
			flag=0;
			top=-1;
			break;
		}
	}
	return flag;
}

int main()
{
	stack s, s1;
	char str[30], str1[30];
	 int ch;

	 do
	 {
	 	cout<<"\n\n\t\t--STACK--"
            <<"\n\t1.Check string is palindrome"
            <<"\n\t2.Reverse"
     		<<"\n\t3.Remove space, punctuations in string"
     		<<"\n\t4.Exit"
     		<<"\n\t Enter your choice: ";
        cin>>ch;

     		switch(ch)
     		{
     			case 1:
     				cout<<"\n\t Enter string: ";
     				cin.ignore();
     				cin.getline(str,30);
     				if(s.ispalindrome(str))
     				cout<<"\n\t String is palindrome";
     				else
     				cout<<"\n\t String is not palindrome";

     			break;
     			case 2:
     				cout<<"\n\t Enter string: ";
     				cin.ignore();
     				cin.getline(str,30);
     				s.reverse(str);
     			break;
     			case 3:
     				cout<<"\n\t Enter string: ";
     				cin.ignore();
     				cin.getline(str,30);
     				s.convert_string(str,str1);
     				cout<<"\n\t NEw string: "<<str1;

     			break;
     			case 4: break;
     			default: cerr<<"\n INVALID CHOICE !!!";
     			break;

     		}
	 }while(ch!=4);
}

/*
    OUTPUT:
    [Student@localhost scb16]$ g++ STACK.CPP
    [Student@localhost scb16]$ ./a.out


                --STACK--
        1.Check string is palindrome
        2.Reverse
        3.Remove space, punctuations in string
        4.Exit
         Enter your choice: 1

         Enter string: Poor Dan is in a droop

         String is not palindrome

                --STACK--
        1.Check string is palindrome
        2.Reverse
        3.Remove space, punctuations in string
        4.Exit
         Enter your choice: 2

         Enter string: Poor Dan is in a droop

         Original string is: Poor Dan is in a droop
         reverse string is: poord a ni si naD rooP

                --STACK--
        1.Check string is palindrome
        2.Reverse
        3.Remove space, punctuations in string
        4.Exit
         Enter your choice: 3

         Enter string: Poor Dan is in a droop

         NEw string: poordanisinadroop

                --STACK--
        1.Check string is palindrome
        2.Reverse
        3.Remove space, punctuations in string
        4.Exit
         Enter your choice: 1

         Enter string: poordanisinadroop

         String is palindrome

                --STACK--
        1.Check string is palindrome
        2.Reverse
        3.Remove space, punctuations in string
        4.Exit
         Enter your choice: 4
    [Student@localhost scb16]$
*/
