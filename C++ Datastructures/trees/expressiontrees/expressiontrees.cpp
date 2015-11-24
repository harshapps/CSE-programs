#include<iostream>
using namespace std;

struct expnode
{expnode *lchild,*rchild;
   union
   {int operand;
    char operato;
   }data;
   int tag;
};

class estack
{int topval;
 expnode *element[50];
 int tag[50];
 int size;
public:
estack()
{topval=-1;
size=50;
}

void push(expnode *ch);
void pop();
expnode *top();
};

void estack::push(expnode *ch)
{ if(topval<size)
   element[++topval]=ch;
   else
   cout<<"stack is full";
}
expnode *estack:: top()
{if(topval>-1) return element[topval];
}

void estack::pop()
{if(topval>-1)
  topval--;
  else
  cout<<"stack is empty";
}
int calc(char operat,int a,int b)
{
	if(operat=='*')
	return a*b;
	else if(operat=='/')
	return a/b;
	else if(operat=='+')
	return a+b;
	else
	return a-b;
}

int eval_exptree(expnode *t)  //post order traversal -first children and then its parent
{ int a,b;
	if(t->tag==2)     //tag= 2  for operator
	{
		a=eval_exptree(t->lchild);
		b=eval_exptree(t->rchild);
		return (calc(t->data.operato,a,b));
	}
	else
	return t->data.operand;

}


int main()
{estack  s;
expnode *t;
char ch[50];
cout<<"Enter postfix expression :";
cin.getline(ch,50);
expnode *first,*second;
//storing postfix exp in the form of expression tree
for(int i=0;ch[i]!=NULL;i++)
{ t=new expnode;
if(ch[i] >'0' &&  ch[i]<='9')
    {t->lchild=NULL;
     t->rchild=NULL;
      t->tag=1;
      t->data.operand=ch[i]-'0'; //converting to integer
      s.push(t);
    }
    else if(ch[i]=='+' || ch[i]=='-' || ch[i]=='*' || ch[i]=='/')
    { t->tag=2;
      second=s.top();s.pop();
      first=s.top();s.pop();
      t->data.operato=ch[i];
      t->lchild=first;
      t->rchild=second;
      s.push(t);

    }

}
t=s.top();
cout<<eval_exptree(t);

 return 0;



}
