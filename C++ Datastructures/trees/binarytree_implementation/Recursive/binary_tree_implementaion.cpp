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

bool searchBT(bstnode *t ,int el)
{ if(t!=NULL)
   {  if(el==t->data)
        return 1; //element found
    else if (el<t->data)
        searchBT(t->lchild,el);
    else if (el> t->data)
        searchBT(t->rchild,el);
    }
    else
        return 0; //element not found
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

void print_leafnodes(bstnode *&t)
{  if (t!=NULL)
     {if(t->lchild ==NULL && t->rchild ==NULL)
    cout<<t->data<<"  ";
    print_leafnodes(t->lchild);
    print_leafnodes(t->rchild);

     }
     else return;


}
void print_nonleafnodes(bstnode *t)
{ if (t!=NULL)
     {if(t->lchild !=NULL || t->rchild !=NULL)
        cout<<t->data<<"  ";
    print_leafnodes(t->lchild);
    print_leafnodes(t->rchild);
    }



if(t->lchild !=NULL || t->rchild !=NULL)
        cout<<t->data<<"  ";
    print_leafnodes(t->lchild);
    print_leafnodes(t->rchild);
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

int height(bstnode  *t)
{ int a,b;
	if(t==NULL)
	  return -1;  
	else
	{a=height(t->lchild);
	 b=height(t->rchild);
	 return a > b ? a+1 : b +1 ;
		
	}
}
void del_node_recursive(bstnode *&t,int el)
{ if(t==NULL)
    return;
    if (el<t->data)
        del_node_recursive(t->lchild,el);
    else if (el> t->data)
        del_node_recursive(t->rchild,el);

    else if(t->lchild!=NULL && t->rchild!=NULL)
           { t->data=minimum(t->rchild);
             del_node_recursive(t->rchild,t->data);
           }
    else
    { bstnode *temp=t;
        if(t->lchild !=NULL) t=t->lchild; else t=t->rchild;
        delete temp;
    }

}
void rec_level_print(bstnode *t,int h)
{
    if(h==1 && t!=NULL)
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
     cout<<"press -1 to stop entering data.Enter integer...";
     cin>>el;
  while(el!=-1)
   {filltree(t,el);
    cout<<" \nEnter the next integer in to tree :";
     cin>>el;
   
    
    }

  if( searchBT(t,5))
     cout<<"Element found";
  else
    cout<<"Element not found";

   cout<<"\nThe maximum element is :"<< maximum(t)<<endl;
    cout<<"\nThe minimum element is :"<< minimum(t)<<endl;
 // cout<<"Which element u want to delete :";
 // cin>>el;
 del_node_recursive(t,el);

  // print_tree(t);
   cout<<endl;
   int h=height(t);
   cout<<"height of tree......"<<h<<endl;
   for(int i=1;i<=h+1;i++)
   {rec_level_print(t,i);cout<<endl;}
}
