#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
float levels;int j=0;
//based on the concept of complete binary tree
struct btnode
{int data;
 btnode *lchild,*rchild;
};
btnode *calc(btnode *&t)
{btnode *a,*b;
    if(t->lchild!=NULL)
    {
      a=calc(t->lchild);
      b=calc(t->rchild);
       t->data= a->data < b->data ? a->data: b->data;
    }
    return t;
}
void clear_min(btnode *&t,int root)
{ if(t!=NULL)
    {if(t->data==root)
         t->data=1000;
         clear_min(t->lchild,root);
         clear_min(t->rchild,root);
         }
}
void construct_complete_btree(btnode *&t,vector<int> el,int h,int level)
{static int i=0;
   if(t==NULL)
     {
     t=new btnode;
     t->lchild=t->rchild=NULL;
     if(h==1 && level==levels &&  i <=levels)
        t->data=el[i++];
    else
      t->data=1000;

     }
    else
    {construct_complete_btree(t->lchild,el,h-1,level);
     construct_complete_btree(t->rchild,el,h-1,level);
    }

}
void tournament_sort(btnode *&t)
{ static int c=0;
 if(c<j)
 {calc(t);
 cout<<t->data<<"  ";
 clear_min(t,t->data);
  c++;
 tournament_sort(t);

 }

}
void level_print(btnode *t,int h)
{if(t!=NULL)
    if(h==1)
        cout<<t->data<<"  ";
    else
        {level_print(t->lchild,h-1);
        level_print(t->rchild,h-1);
        }
}
int main()
{int el,i;
vector<int> num;
 btnode *t=NULL;
while(el!=-1)
{
    cout<<"Enter number ";
    cin>>el;
    if(el!=-1)
        num.push_back(el);
    j++;
}
j--;
levels=log2(j);
if((int)levels==levels)
 levels+=1;
 else
 levels= int(levels+2);

for(i=1;i<=levels;i++)
construct_complete_btree(t,num,i,i);
tournament_sort(t);


for(int m=1;m<=levels;m++)
{cout<<endl;level_print(t,m);}

}




