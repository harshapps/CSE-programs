#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node *next;
};
int main ()
{
    int d,n;
    node *l,*k;
    node *l1;
    node *l2;
    node *s;
    node *t,*p;
    l1=new(node);
    s=l1;

    cout<<"enter data in to first linked list:";
    cin>>d;
    l1->data=d;
while(d!=-1)
    {
        cout<<"enter next element if u want to continue or press -1:";
        cin>>d;
       if(d!=-1)
       {t=new(node);
        t->data=d;
        l1->next=t;
        l1=t;

       }
    }
    l1->next='\0';

    l2=k=l1;

    cout<<"enter data in to second linked list:";
    cin>>n;
    l2->data=n;

while(n!=-1)
    {cout<<"enter next element if u want to continue or press -1:";
        cin>>n;
        if(n!=-1)
        {t=new(node);
        t->data=n;
        l2->next=t;
        l2=t;
        }

    }
    l2->next='\0';
    l2=k;
    l1=s;
    l=new (node);
    p=l;
       l=l1;int count=0;
       while(l2!='\0')
       { while(l1!='\0')
           {
               if(l1->data==l2->data)
               {cout<<l1->data<<"  ";
                   count++;
                   l1=l1->next;
                   l2=l2->next;
                  l->next=l1;

               }
               else
                {cout<<l1->data<<"   ";
               l1=l1->next;}
           }
           if(count==0)
           {
            l->next=l2;
           }
           l2=l2->next;
            cout<<l2->data<<" ";
            l=l2;
       }

    return 0;
    }
