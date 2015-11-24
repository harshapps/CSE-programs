#include<iostream>
using namespace std;

struct bstnode
{
    bstnode *lchild;
    int data;
    bstnode *rchild;
};

class tstack
{int topval;
 bstnode *element[50];
 int size;
 public:
 tstack (){topval=-1;size=50;}  //constructor
 void push(bstnode *t);
 void pop();
  bstnode *top();
  bool empty()
  {if(topval==-1)
    return 1;
    else
    return 0;
  }
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

void inorder_traversal(bstnode *t)    //lchild,parent ,rchild 
{tstack store;

 do
 {    while(t!=NULL)
       {store.push(t);
       t=t->lchild;
       }
        if(!store.empty())
        { t=store.top();cout<<store.top()->data<<"  ";  store.pop();
           t=t->rchild;
        }

  }while(t!=NULL || !store.empty());
}
void preorder_traversal(bstnode *t)    //parent ,lchildchild ,rchild child
{tstack store;
 do
 {    while(t!=NULL)
       {store.push(t);
         cout<<t->data<<"  ";
       t=t->lchild;
       }
        if(!store.empty())
        { t=store.top();store.pop();
         t=t->rchild;
        }

  }while(t!=NULL || !store.empty());
}
void postorder_traversal(bstnode *t)    //lchild ,rchild,parent
{tstack store;bstnode *prev;
 do
    {
        while (t!=NULL)
        {
        store.push(t);
            t=t->lchild;
        }
        if(!store.empty())
        {
            while(t==NULL && !store.empty())
            {
                t=store.top();
                if(t->rchild!=NULL)
                {
                    if(t->rchild == prev)
                    {
                        cout << t->data  <<  "  ";
                        store.pop();
                        prev = t;
                        t = NULL;
                    }
                    else
                        t = t->rchild;
                }
                else
                {
                    cout << t->data<<  "  ";
                    store.pop();
                    prev = t;
                    t= NULL;
                }
            }
        }
    }while(!store.empty());
}



void print_tree(bstnode *t)
{
    if(t!=NULL)
    {
        cout<<t->data<<"  ";
        print_tree(t->lchild);
        print_tree(t->rchild);
    }

}


int main()
{   int el;
    bstnode *t;

    t=NULL;
   do
    {
    cout<<"press 0 to stop entering data\nEnter the integer in to tree :";
    cin>>el;
    if(el!=0)
    filltree(t,el);
    }while(el!=0);

    cout<<"\ninorder traversal  :";postorder_traversal(t);

}

void tstack::push(bstnode *t)
 {if(topval<size-1)
    element[++topval]=t;
    else
    cout<<"stack is full";
 }
 void tstack::pop()
 {if(topval>-1)
  topval--;
  else
  cout<<"Stack is empty";
  }
bstnode* tstack::top()
{if(topval>-1)
 return element[topval];
  else
  cout<<"stack is empty";
}
