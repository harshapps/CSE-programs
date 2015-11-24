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

void inorder_traversal(bstnode *t)    //leftchild ,parent ,right child
{if(t!=NULL)
 {inorder_traversal(t->lchild);
  cout<<t->data<<"  ";
  inorder_traversal(t->rchild);
 }
}
void preorder_traversal(bstnode *t)    //parent ,leftchild ,right child
{if(t!=NULL)
 { cout<<t->data<<"  ";
  preorder_traversal(t->lchild);
  preorder_traversal(t->rchild);


 }
}
void postorder_traversal(bstnode *t)    //leftchild ,right child,parent
{if(t!=NULL)
 {postorder_traversal(t->lchild);
  postorder_traversal(t->rchild);
  cout<<t->data<<"  ";
 }
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

    cout<<"\ninorder traversal  :";inorder_traversal(t);
    cout<<"\npreorder traversal  :";preorder_traversal(t);
    cout<<"\npost order traversal  :";postorder_traversal(t);
}

