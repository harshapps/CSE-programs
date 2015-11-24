#include<iostream>
using namespace std;
//treap= bst + heap and not complete binary tree as like heap
struct treapnode
{ treapnode *lchild,*rchild;
    char key;        //binary tree in terms of key
   int priority;  //heap in terms of priority

};
void rotate_towardsright(treapnode *&t,char k,int prior);
void rotate_towardsleft(treapnode *&t,char k,int prior);
void insert(treapnode *&t,char k, int prior);
void print_treap(treapnode *t);
int main()
{
    int num,prior;
    char ch,key;
    treapnode *t;
    t=NULL;
     cout<<"press ; to stop entering data\n";
   do
    {
    cout<<" Enter character ,number in to treap tree :";
    cin>>ch>>num;
          if(ch!=';')
          {key=ch;
           prior=num;
          insert(t,key,prior);
           }

    }while(ch!=';');

    print_treap(t);

}


void insert(treapnode *&t,char k, int prior)
{
    if(t==NULL)
    { t= new treapnode;
      t->lchild=t->rchild=NULL;
      t->key=k; t->priority=prior;
    }
   else if(k<t->key)
   { insert(t->lchild,k,prior);
        if(prior < t->priority)
            rotate_towardsright(t,t->key,t->priority);   }
   else if(k > t->key)
   {insert(t->rchild,k,prior);
        if(prior < t->priority)
           rotate_towardsleft(t,t->key,t->priority);
   }
}

void rotate_towardsright(treapnode *&t,char k,int prior)
{
    treapnode *k2;
    k2=t->lchild;
    t->lchild=k2->rchild;
    k2->rchild=t;
    t=k2;
}
void rotate_towardsleft(treapnode *&t,char k,int prior)
{
    treapnode *k2;
    k2=t->rchild;
    t->rchild=k2->lchild;
    k2->lchild=t;
    t=k2;
}
void print_treap(treapnode *t)
{
    if(t!=NULL)
    { print_treap(t->lchild);
     cout<<t->key<<"  "<<t->priority<<endl;
    print_treap(t->rchild);
    }
}
