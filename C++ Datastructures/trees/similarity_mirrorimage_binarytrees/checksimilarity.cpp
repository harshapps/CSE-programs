#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
struct bstnode
{
    bstnode *lchild;
    int data;
    bstnode *rchild;
};
void filltree(bstnode *&t,int el)
{     if(t==NULL)
     {  t=new bstnode;
        t->data=el;        t->lchild='\0';
        t->rchild='\0';
        return;
     }
     else if(el <= t->data)
        filltree(t->lchild,el);
        else
        filltree(t->rchild,el);
}
bool checksimilarity(bstnode *t1,bstnode *t2)
{
    if(t1!=NULL  && t2!=NULL)
    {
        if(t1->data == t2->data)
        {
            checksimilarity(t1->lchild ,t2->lchild );
            checksimilarity(t1->rchild ,t2->rchild );
           return 1;
        }
        else
        return 0;

    }
}


int main()
{   int el;
    bstnode *t1,*t2;
    t1=NULL;
    cout<<"Enter the data in to the tree 1 :\n";
   do
    {
    cout<<"press -0 to stop entering data\nEnter the integer in to tree :";
    cin>>el;
    if(el!=0)
    filltree(t1,el);
    }while(el!=0);

   t2=NULL;
    cout<<"Enter the data in to the tree 2 :\n";
   do
    {
    cout<<"press -0 to stop entering data\nEnter the integer in to tree :";
    cin>>el;
    if(el!=0)
    filltree(t2,el);
    }while(el!=0);

  if( checksimilarity(t1,t2))
    cout<<"Both are similar ";
    else
        cout<<"both are not similar ";
}

