#include<iostream>
#include<cmath>
#include<iomanip>
#include<queue>
using namespace std;
struct btnode
{
    btnode *lchild;
    char data;
    btnode *rchild;
    btnode *parent;
};
void printspaces(int level)
{
    for(int k=0;k<pow(2,level-1);k++)
        cout<<"    ";
}
void printsymspaces(int level)
{
    for(int k=0;k<pow(2,level-1);k++)
        cout<<"  ";
}


void insert_levelorder(btnode *&t,int el)
{ 
btnode *par=t;
if(el!=-1)
    {
		if(t==NULL)
    	{
      		t=new btnode;
      		t->lchild=t->rchild=NULL;
      		t->data=el;
      		t->parent=par;
  		}
  	else
    {  cout<<"Enter left child for "<<t->parent->data<<"  :  ";cin>>el;
        insert_levelorder(t->lchild,el);
        cout<<"\t\t\tEnter right child for "<<t->parent->data<<"  :  ";cin>>el;
     insert_levelorder(t->rchild,el);

    }
}

}
void rec_level_print(btnode *t,int h)
{
    if(h==1)
        cout<<t->data<<"  ";
    else
        {rec_level_print(t->lchild,h-1);
        rec_level_print(t->rchild,h-1);
        }

}


int main()
{
    btnode *t;
    t=new btnode;
    cout<<"Enter root node (parent)  :";
    cin>>t->data;
    t->lchild='\0';
    t->rchild='\0';

     insert_levelorder(t,t->data);
     cout<<endl;
/*
for(int i=1;i<3;i++)
{
    rec_level_print(t,i);cout<<endl;
}
*/


}
