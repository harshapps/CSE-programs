#include <iostream>
using namespace std;
class Bothsidedstack
{
	int top1,top2;
	int element[50];
	public:
		Bothsidedstack()
		{
			top1=-1;
			top2=50;
		}
		void push1(int num);
		int pop1();
		void push2(int num);
		int pop2();
		void display1();
		void display2();
};

int main()
{
	Bothsidedstack s;
	int choice;
	cout<<"1.push to stack1\n2.pop stack 1\n3.displaystack1\n4.push to stack2\n5.pop stack2\n6.display stack2\n7.exit";
	cout<<"choice : ";
	cin>>choice;
	while(choice!=7)
	{
		if(choice==1)
		{
			int n;
			cout<<"Enter no. ";
			cin>>n;
			s.push1(n);
		}
		else if(choice==2)
		s.pop1();
		else if(choice==3)
		s.display1();
		else if(choice==4)
		{
			int n;
			cout<<"Enter no. ";
			cin>>n;
			s.push2(n);
		}
		else if(choice==5)
		s.pop2();
		else if(choice==6)
		s.display2();
		else;
		cout<<"Enter choice: ";
		cin>>choice;
	}
	return 0;
}

void Bothsidedstack:: push1(int num)
{
	if(top1+1<top2)
	element[++top1]=num;
	else
	cout<<"Stack is full";
}
void Bothsidedstack:: push2(int num)
{
	if(top2>top1+1)
	element[--top2]=num;
	else
	cout<<"Stack is full";
}
int Bothsidedstack::pop1()
{
	if(top1>-1)
	return top1--;
	else
	cout<<"Stack is empty";
}
int Bothsidedstack:: pop2()
{
	if(top2<50)
	return top2++;
	else
	cout<<"Stack is empty";
}
void Bothsidedstack :: display1()
{
	for(int i=0;i<=top1;i++)
	cout<<element[i]<<" ";
}
void Bothsidedstack:: display2()
{
	for(int i=49;i>=top2;i--)
	cout<<element[i]<<" ";
}
