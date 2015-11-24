#include<iostream>
using namespace std;
class multiplestack{
	int e[1000];
	int top[10];
	int i;
	int size;
	public:
	void push(int x,int n);
	int pop(int n);
	int isfull(int n);
	int isempty(int n);
	int empty();
	multiplestack(int s){size=s;i=8;for(int j=0;j<i;j++)top[i]=-1;}
};
int multiplestack::pop(int n)
{if(top[n]==-1)cout<<"underflow\n";
else return e[top[n]--];}
int multiplestack::empty()
{int j,k=0;
for(int j=0;j<i;j++)
if(top[j]!=-1)k++;
return k; }
void multiplestack::push(int x,int n)
{if(top[n]+1%(size/i)==0)cout<<"overflow\n";
else e[++top[n]]=x;}
int multiplestack::isempty(int n)
{return top[n]==-1;}
int multiplestack::isfull(int n)
{return top[n]+1%(size/i)==0;}
int main()
{multiplestack s(30);int i,n,l=1;
do{
	cout<<"press the no.of stack to push\n";cin>>i;i--;
	cout<<"enter element\n";cin>>n;
	s.push(n,i);
	cout<<"want to enter another element\npress 1\nelse 0\n";cin>>l;
}while(l==1);l=1;
while(!s.empty( )&&l!=0)
{cout<<"press the no.of stack to pop\n";cin>>i;i--;
cout<<s.pop(i)<<endl;
cout<<"press 1 to pop again\n0 to close\n";cin>>l;
}
}
