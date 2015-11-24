#include<iostream>
using namespace std;

struct node
{
    int coef;
    int exp;
    node *next;
};

void inputdata(node *&l)
{ node *s,*temp;
 l=new node;
s=l;
cout<<"Enter elements.press 0 to stop entering \n";
cout<<"\nEnter coefficient : ";
cin>>l->coef;
cout<<"for exponent : ";
cin>>l->exp;
l->next='\0';


  do{
    temp=new node;
    cout<<"Enter coefficient : ";
    cin>>temp->coef;

    if(temp->coef!=0)
      { cout<<"for exponent : ";
        cin>>temp->exp;

             temp->next='\0';
             l->next=temp;
             l=temp;


      }
    } while(temp->coef!=0);

l=s;
}


void printlist(node *l)
{
while(l!='\0')
       {
       cout<<l->coef<<"y^"<<l->exp <<" + ";
       l=l->next;
       }
}
void addend(node *P,int c,int k)
{
	node *T;
	T=new(node);
	while(P->next!=NULL)
		P=P->next;
	T->coef=c;
	T->exp=k;
	T->next=NULL;
	P->next=T;
}
void display(node *P)
{
	while(P->next!=NULL)
	{
		cout<<P->coef<<"x^"<<P->exp<<" + ";
		P=P->next;
	}
	cout<<P->coef<<"x^"<<P->exp<<endl;
}
void sort(node *P3,node *S3,int count)
{
	int tmp1,tmp2;
	for(int i=0;i<count;i++)
	{
		P3=S3;
		for(int j=1;j<count;j++)
		{
			if(P3->exp < P3->next->exp)
			{
				tmp1=P3->exp;
				P3->exp=P3->next->exp;
				P3->next->exp=tmp1;
				tmp2=P3->coef;
				P3->coef=P3->next->coef;
				P3->next->coef=tmp2;
			}
			P3=P3->next;
		}
	}
}

void add(node *P1,node *P2)
{
	node *P3;
	node *S3;
	node *S2;
	int count=0;
	S2=P2;
	P3=new(node);
	S3=P3;
	P3->coef=P1->coef;
	P3->exp=P1->exp;
	P3->next=NULL;
	P1=P1->next;
	while(P1!=NULL)
	{
		addend(P3,P1->coef,P1->exp);
		P1=P1->next;
	}
	while(P2!=NULL)
	{
		P3=S3;
		while(P3!=NULL)
		{
			if(P2->exp==P3->exp)
			{
				P3->coef=P3->coef+P2->coef;
				break;
			}
			else
				P3=P3->next;
		}
		if(P3==NULL)
		{
			P3=S3;
			addend(P3,P2->coef,P2->exp);
		}
		P2=P2->next;
	}
	P3=S3;
	while(P3!=NULL)
	{
		count++;
		P3=P3->next;
	}
	P3=S3;
	sort(P3,S3,count);
	cout<<"addition of the two polynomials is ";
	display(P3);
}


void subtract(node *P1,node *P2)
{
	node *P3;
	node *S3;
	node *S2;
	int count=0;
	S2=P2;
	P3=new(node);
	S3=P3;
	P3->coef=P1->coef;
	P3->exp=P1->exp;
	P3->next=NULL;
	P1=P1->next;
	while(P1!=NULL)
	{
		addend(P3,P1->coef,P1->exp);
		P1=P1->next;
	}
	while(P2!=NULL)
	{
		P3=S3;
		while(P3!=NULL)
		{
			if(P2->exp==P3->exp)
			{
				P3->coef=P3->coef-P2->coef;
				break;
			}
			else
				P3=P3->next;
		}
		if(P3==NULL)
		{
			P3=S3;
			addend(P3,-P2->coef,P2->exp);
		}
		P2=P2->next;
	}
	P3=S3;
	while(P3!=NULL)
	{
		count++;
		P3=P3->next;
	}
	P3=S3;
	sort(P3,S3,count);
	cout<<"Subtraction of the two polynomials is ";
	display(P3);
}

void multiply(node *num1, node *num2)
{node *start2=num2,*result,*result_start;
 result=new node;
 result_start=result;
 result->coef= num1->coef * num2 -> coef;
 result->exp= num1->exp + num2->exp ;
 num2=num2->next;
 int tag=0;
    for(;num1!='\0';num1=num1->next)
     {
         for(num2=(tag==1)?start2:num2;num2!='\0'; num2=num2->next)
            { result->next=new node;
            result->next->next='\0';
            result=result->next;
            result->coef= num1->coef * num2 -> coef;
            result->exp= num1->exp + num2->exp ;
            tag=1;
         }
     }
cout<<endl;
result=result_start;
printlist(result);
}



int main()
{node *num1,*num2;
cout<<"Enter plynomial 1 :\n";
inputdata(num1);
cout<<"Enter plynomial 2 :\n";
inputdata(num2);
printlist(num1);
cout<<endl;
printlist(num2);
cout<<"\n";
multiply(num1,num2);



}
