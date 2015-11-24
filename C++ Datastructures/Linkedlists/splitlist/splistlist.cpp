#include<iostream>
using namespace std;
union slist
{
    int num;
    char c;
};
 struct node
 {
    slist data;
    node *next;

 };

node *inputdata(node *l,int tag[]);
void printlist(node *l,int tag[]);
void addatend(node *l,int el);

int main()
{node *lst;
int tag[20];
printlist(inputdata(lst,tag),tag);


return 0;


}

node * inputdata(node *l,int tag[])
{ node *s,*temp;
 l=new node;
s=l;
int choice;

cout<<"press 1 for integer ,2 for char and -1 to stop entering: ";
cin>>choice;
cout<<"Enter element  :";
 if(choice==1)
    cin>>l->data.num;
else if (choice==2)
    cin>>l->data.c;
  else
    cout<<"Invalid choice.....Reenter \n";

int i=0;

l->data.num=0;
l->data.c='d';
   do
    {
    temp=new node;
     temp->next='\0';
     l->next=temp;
     l=temp;cout<<"press 1 for integer ,2 for char and -1 to stop entering: ";
cin>>choice;
cout<<"Enter element  :";
     if(choice==1)
   {cin>>temp->data.num;
   tag[i++]=choice;
   }
    else if (choice==2)
   {
       cin>>temp->data.c;tag[i++]=choice;
   }

    } while(choice!=-1);

 l->next='\0';
return s;
}




void printlist(node *l,int tag[])
{int i=0;
while(l!='\0')
       { if(tag[i++]==1)
       cout<<l->data.num<<"   ";
       else
         cout<<l->data.c<<"   ";
       l=l->next;
       }
}




