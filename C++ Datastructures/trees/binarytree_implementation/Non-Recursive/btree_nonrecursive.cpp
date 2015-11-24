#include<iostream>
#include<queue>
using namespace std;
struct bstnode
{
    bstnode *lchild;
    int data;
    bstnode *rchild;
};
void rec_level_print(bstnode *t,int h);
void insert(bstnode *&t,int el)
{     if(t==NULL)
     {  t=new bstnode;
        t->data=el;
        t->lchild='\0';
        t->rchild='\0';
        return;
     }
     else if(el <t->data)
        insert(t->lchild,el);
        else
        insert(t->rchild,el);
}

int maximum(bstnode *t)
{
    while(t->rchild!=NULL)
        t=t->rchild;
    return t->data;
}


int minimum(bstnode *t)
{
    while(t->lchild!=NULL)
        t=t->lchild;
    return t->data;
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


bstnode* search_return_node(bstnode *t,int el)
{
	if(t!=NULL)
	{
		if(t->data==el)
			return t;
		else if(el <t->data)
			search_return_node(t->lchild,el);
		else
			search_return_node(t->rchild,el);
	}
	else
		return NULL;
}
bstnode* minimum_el_pos(bstnode* t)
{
	if(t->lchild!=NULL)
		minimum_el_pos(t->lchild);
	else
		return t;
}
void del_node(bstnode *t,int el)
{bstnode *replace_el,*s;
    //searching for el
   t= search_return_node(t,el);
   s=t;
  t=minimum_el_pos(t->rchild);
  replace_el=t;
   s->data=t->data;
   delete replace_el;

}

void print_levelwise(bstnode *t)
{ bstnode *r=new bstnode;
   r->data='$';
    queue<bstnode *> q;
    q.push(t);
    q.push(r);

    while(!q.empty())
    { t=q.front();
        cout<<t->data<<"     ";
        q.pop();
        if(t->lchild !=NULL)
            q.push(t->lchild);
        if(t->rchild !=NULL)
        q.push(t->rchild);
        if(q.front()->data=='$')
        { q.pop();
         if(q.empty())
            break;
        q.push(r);
        cout<<endl;

        }
    }

}

void rec_level_print(bstnode *t,int h)
{
    if(h==1)
        cout<<t->data<<"  ";
    else
        {rec_level_print(t->lchild,h-1);
        rec_level_print(t->rchild,h-1);
        }

}


int main()
{   int el;
    bstnode *t;
    t=NULL;
   do
    {
    cout<<"press -0 to stop entering data\nEnter the integer in to tree :";
    cin>>el;
    if(el!=0)
    insert(t,el);
    }while(el!=0);


   print_levelwise(t);
   //cout<<"Enter which element u want to delete :";
   //cin>>el;
   //del_node(t,el);
   cout<<endl;
   for(int i=1;i<=3;i++)
   {rec_level_print(t,i);cout<<endl;}

}
