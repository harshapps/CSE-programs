#include<iostream>
#include<cstdlib>
using namespace std;

class stack_implementation
{int topval;
 int element[50];
 int size;
public:
stack_implementation() {topval=-1;size=50;}
 void push(int el);
 void pop();
 int top();
 void display()
 { for(int i=0;i<=topval;i++)
    cout<<element[i]<<"  ";
 }

};


int main()
{stack_implementation s;
cout<<"\t\t***************************\n";
cout<<"\t\t*    stack operations     *\n";
cout<<"\t\t***************************\n";
int choice,el;
cout<<"1.push\t 2.top \t 3.pop \n4.Display contents 5.exit\n ";
do
{
  cout<<"\n\t\tEnter choice : ";
  cin>>choice;
    switch(choice)
    {case 1: cout<<"Enter element :";cin>>el;s.push(el);break;
    case 2: cout<<"top value :"<<s.top();break;
    case 3: s.pop();break;
    case 4: s.display();break;
    case 5: exit(1);
    }
}while(choice!=5);
}

void stack_implementation::push(int el)
 {if(topval<size-1)
    element[++topval]=el;
    else
    cout<<"stack is full";
 }
 void stack_implementation::pop()
 {if(topval>-1)
  topval--;
  else
  cout<<"Stack is empty";
  }
int stack_implementation::top()
{if(topval>-1)
 return element[topval];
  else
  cout<<"stack is empty";
}
