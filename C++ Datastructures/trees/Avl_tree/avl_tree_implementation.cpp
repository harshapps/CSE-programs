#include<iostream>
using namespace std;
#include<windows.h>
HANDLE dev;  //for colours
struct avlnode
{
    avlnode *lchild,*rchild;
    int data;
    int height;
    avlnode (){height=-1;}
};
void insert(avlnode *&t, int el);
int maximum(avlnode *t);
int minimum(avlnode *t);
int height_bal(avlnode *t);

void rotatefromleft_towards(avlnode *&k1);
void rotatefromright_towards(avlnode *&k1);
void doublerotate_toleftright(avlnode *&k1);
void doublerotate_torightleft(avlnode *&k1);
int findmax(int a,int b)
{
    return a>b ? a: b;
}
void print_tree(avlnode *t)
{
    if(t!=NULL)
    { print_tree(t->lchild);
     cout<<t->data<<"  ";
    print_tree(t->rchild);
    }
}
int main()
{dev= GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(dev,9);
    int el;
    avlnode *t;
    t=NULL;
   do
    {
    cout<<"press 0 to stop entering data\nEnter the integer in to tree :";
    cin>>el;
    if(el!=0)
    insert(t,el);
    }while(el!=0);

    print_tree(t);
    cout<<"\nmaximum element is :"<<maximum(t);
     cout<<"\nminimum element is :"<<minimum(t);
     cout<<"height of tree is :"<<t->height;

}
void insert(avlnode *&t, int el)
{
    if(t==NULL)
    {t=new avlnode;
     t->lchild=NULL;
     t->rchild=NULL;
     t->data=el;
     t->height=-1;
    }
    else if(el < t->data)
    {insert(t->lchild,el);
      if(height_bal(t->lchild)-height_bal(t->rchild)==2)  //avl node imbalanced
           if(el < t->lchild->data)
           rotatefromleft_towards(t);
           else
           doublerotate_toleftright(t);
    }
    else if(el > t->data)
    { insert(t->rchild,el);
        if(height_bal(t->rchild)-height_bal(t->lchild)==2)
            if(el> t->rchild->data)
              rotatefromright_towards(t);
            else
            doublerotate_torightleft(t);
    }
    t->height=findmax(height_bal(t->lchild),height_bal(t->rchild))+1;



}

int height_bal(avlnode *t)
{
    return t==NULL ? -1 : t->height;
}
void rotatefromleft_towards(avlnode *&k1)
{// tree unbalanced at k1  and k2 left child of k1.  k2 would become the root node after rotation
    avlnode *k2;
    k2=k1->lchild;
    k1->lchild=k2->rchild;
    k2->rchild=k1;
    k1->height=findmax(height_bal(k1->lchild),height_bal(k1->rchild))+1;
    k2->height=findmax(height_bal(k2->lchild),k1->height)+1;
    k1=k2;
}
void rotatefromright_towards(avlnode *&k1)
{ avlnode *k2;
  k2=k1->rchild;
  k1->rchild=k2->lchild;
  k2->lchild=k1;
  k1->height=findmax(height_bal(k1->lchild),height_bal(k1->rchild))+1;
  k2->height=findmax(height_bal(k2->rchild),k1->height)+1;
  k1=k2;

}
void doublerotate_toleftright(avlnode *&k1)
{ rotatefromright_towards(k1->lchild);
    rotatefromleft_towards(k1);
}
void doublerotate_torightleft(avlnode *&k1)
{ rotatefromleft_towards(k1->rchild);
  rotatefromright_towards(k1);

}

int maximum(avlnode *t)
{  if(t->rchild==NULL)
     return t->data;
     else
    maximum(t->rchild);
}

int minimum(avlnode *t)
{ if(t->lchild==NULL)
   return t->data;
   else
    minimum(t->lchild);

}
