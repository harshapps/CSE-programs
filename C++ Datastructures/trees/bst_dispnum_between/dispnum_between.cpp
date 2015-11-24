#include<iostream>
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
        t->data=el;
        t->lchild='\0';
        t->rchild='\0';
        return;
     }
     else if(el <= t->data)
        filltree(t->lchild,el);
        else
        filltree(t->rchild,el);
}

void dispnumbetween_tree(bstnode *t,int k1 ,int k2)
{
    if(t!=NULL)
    {   if(t->data >=k1  &&   t->data <= k2)
        cout<<t->data<<"  ";
      dispnumbetween_tree(t->lchild,k1,k2);
      dispnumbetween_tree(t->rchild,k1,k2);
    }
}


int main()
{   int el;
    bstnode *t;
    t=NULL;
   do
    {
    cout<<"press -0 to stop entering data\nEnter the integer in to tree \n";
    cin>>el;
    if(el!=0)
    filltree(t,el);
    }while(el!=0);
int k1,k2;

    cout<<"display range of numbers between k1 and k2 ...enter k1 and k2  :";
    cin>>k1;
    cout<<" and  ";
    cin>>k2;
    dispnumbetween_tree(t,k1,k2);
    return 0;

}
