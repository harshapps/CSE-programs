#include<iostream>
using namespace std;
union prototype
{
	int i;
	char ch;
	float f;
	char c[10];
};
class Genericstack
{  prototype element[30];
	int size;
	int top;
    int tag[30];
    public :
		void push(prototype u);
		prototype pop();
		void display();
		Genericstack()
		{
			top=-1;
			size=0;
		}
		void input();
};
void Genericstack :: input()
{
    cout<<"1. int\n2. char\n3. float\n4.string\n";
		cout<<"Enter choice : ";
		cin>>tag[size];
		if(tag[size]==1)
		{
			cin>>element[size].i;
		}
		else if(tag[size]==2)
		{
			cin>>element[size].ch;
		}
		else if(tag[size]==3)
		{
			cin>>element[size].f;
		}
		else if(tag[size]==4)
		{
			cin>>element[size].c;
		}
		else
		{
		cout<<"Wrong input!";
		size--;
	    }
		size++;
}
prototype Genericstack :: pop()
{
	if(size>=0)
	return element[size--];
	else
	cout<<"Stack is empty";
}
void Genericstack :: display ()
{
	for(int j=0;j<size;j++)
	{
		if(tag[j]==1)
		{
			cout<<element[j].i<<" ";
		}
		else if(tag[j]==2)
		{
			cout<<element[j].ch<<" ";
		}
		else if(tag[j]==3)
		{
			cout<<element[j].f<<" ";
		}
		else
		{
			cout<<element[j].c<<" ";
		}
	}
	cout<<endl;
}
int main()
{
	Genericstack s;
	int choice;
	cout<<"1. push\n2. pop\n3. display\n4. - exit\n";
	cout<<"choice : ";
	cin>>choice;
	while(choice!=4)
	{
		if(choice==1)
		s.input();
		else if(choice==2)
		s.pop();
		else if(choice==3)
		s.display();
		else
		cout<<"Enter choice: ";
		cout<<"1. push\n2. pop\n3. display\n4. - exit\n";
		cin>>choice;
	}
	return 0;
}
