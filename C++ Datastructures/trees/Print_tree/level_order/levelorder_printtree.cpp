#include<iostream>
#include<queue>
using namespace std;
struct btnode
{
    btnode *lchild;
    int data;
    btnode *rchild;
};
void filltree(btnode *&t,int el)
{     if(t==NULL)
     {  t=new btnode;
        t->data=el;
        t->lchild='\0';
        t->rchild='\0';
        return;
     }
     else if(el < t->data)
        filltree(t->lchild,el);
        else
        filltree(t->rchild,el);
}

void print_levelwise(btnode *t)
{ btnode *r=new btnode;
   r->data='$';
    queue<btnode *> q;
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

int height(btnode  *t)
{ int a,b;
	if(t==NULL)
	  return -1;  
	else
	{a=height(t->lchild);
	 b=height(t->rchild);
	 return a > b ? a+1 : b +1 ;
		
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
{   int el;
    btnode *t;
    t=NULL;
     cout<<"press -1 to stop entering data\n";
   do
    {
    cout<<"\nEnter the integer in to tree :";
    cin>>el;
    if(el!=-1)
    filltree(t,el);
    }while(el!=-1 );
   
    int h=height(t);
    cout<<"height of tree......"<<h<<endl;
for(int i=1;i<=h+1;i++)
  {rec_level_print(t,i);
  cout<<endl;
  } 
//rec_level_print(t,1);
}
