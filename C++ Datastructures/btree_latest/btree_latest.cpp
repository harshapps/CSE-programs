#include<iostream>
#include<cstring>
using namespace std;
int d;
struct bdnode   //b-tree of degree d
{
    int count;
    int *key;
    bdnode **ptr,*pptr;   // ptr child   pptr parent
    bdnode()
    { key=new int[2*d+1];
		ptr=new bdnode*[2*d+2];
        for(int i=0;i<2*d+1;i++)
            key[i]=-1;
         for(int i=0;i<2*d+2;i++)
          ptr[i]=NULL;
         pptr=NULL;
        count=0;
    }
};
bdnode *root;
void print_level(bdnode *t,int h);
void insert(bdnode *&t,int el);
void resolve_overflow_nodesplit(bdnode *&t);
void sort_updatepointers(bdnode *&t,int flag);
void print_l(bdnode *&t);
void print(bdnode *t);
void del(bdnode *&t,int el);

int main()
{  int num=0;
cout<<"Enter degee of binary tree........";
cin>>d;

 while(num!=-1)
 {  cout<<"Enter next number : ";
     cin>>num;
     if(num !=-1)
     insert(root,num);
 }
for(int k=1;k<=3;k++)
{print_level(root,k);
cout<<endl;
}
cout<<endl;

 return 0;
}
void overflow(bdnode *&t)
{if(t->count > 2*d)
   {bdnode *par=t->pptr;
     resolve_overflow_nodesplit(t);
      if(par)
	  overflow(par);
   }
}

void sort(bdnode *&t);
void insert(bdnode *&t,int el)
{   if(t==NULL)
    {t=new bdnode();
	  t->key[t->count++]=el;
	}
	else if(t->ptr[0]==NULL) //leaf
	{    t->key[t->count++]=el;
    	sort(t);
		overflow(t);
	}
	else
	{int i;
	for(i=0;i<t->count;i++)
	   if( el< t->key[i])
	       break;
	insert(t->ptr[i],el);
	}
}

void resolve_overflow_nodesplit(bdnode *&t)  //splitting of node
{
 if(t->count >2*d)
  { int k;
    bdnode *par=t->pptr,*left=new bdnode (),*right =new bdnode();
    for(k=0;k<=d;k++)
     {  if(k!=d)
          left->key[left->count++]=t->key[k];
          left->ptr[k]=t->ptr[k];
          if(left->ptr[k])
          left->ptr[k]->pptr=left;
     }

    for(k=d+1;k<=2*d+1;k++)
    {    if(k!=2*d+1)
		      right->key[right->count++]=t->key[k];
              right->ptr[k-d-1]=t->ptr[k];
            if(right->ptr[k-d-1])
			right->ptr[k-d-1]->pptr=right;
    }



    if(par==NULL)             //if leaf node has no parent create a node
    {par= new bdnode();
      par->key[par->count++]=t->key[d];
      par->ptr[0]=left;par->ptr[1]=right;
        left->pptr=par;right->pptr=par;
       		root=par;
    }
    else
    { int pos,j;
	    for( pos=0;pos<=par->count;pos++)
        {if(par->ptr[pos]->key[0]==t->key[0])
          break;
        }
		
        for(j=par->count;j!=pos;j--)
         {par->key[j]=par->key[j-1];
		  par->ptr[j+1]=par->ptr[j];
         }

        par->key[j]=t->key[d];
		par->ptr[j]=left;
		par->ptr[j+1]=right;
		left->pptr=par;	right->pptr=par;
		par->count++;
    }
  }
}
 void sort(bdnode *&t)
{int k;
for(int i=0;i<t->count;i++)
for(int j=0;j<t->count;j++)
if(t->key[i]<t->key[j])
{k=t->key[j];
t->key[j]=t->key[i];
t->key[i]=k;}}
 void print(bdnode *t)
{int j;
    if(t!=NULL)
    { for(j=0;j<2*d+1;j++)
      {
       print(t->ptr[j]);
cout<<t->key[j]<<"  "     ;
       }
    print(t->ptr[j]);
    }
}
void print_l(bdnode *&t)
{if(t!=NULL)
{for(int i=0;i<t->count;i++)
cout<<t->key[i]<<" ";
cout<<endl;
for(int i=0;i<t->count+1;i++)
{print(t->ptr[i]);}}}

void del(bdnode *&t,int el)
{int prev=0;
  if(t!=NULL)
  {for(int i=0;i<t->count;i++)
   {  if(t->key[i]==el)
   		{cout<<"data found: ";
   		   //cases
   		   if(t->ptr[0]==NULL )
   		    { if(t->count> d)
   		        {t->key[i]=-1;
   		         t->count--;
				}
				else //underflow
				{
				t->key[i]=t->pptr->key[prev];
				 t=t->pptr;
				  t->key[prev]=t->ptr[prev+1]->key[0];
				  t=t->ptr[prev+1];
				  t->key[0]=2000;
				  sort(t);
				  t->count--;
				}
				
			}
   		    
   		}
        else
        {prev=i;
		del(t->ptr[i],el);
        }
        
   }
 }

}
void print_level(bdnode *t,int h)
{if(h==1)
for(int i=0;i<t->count;i++)
     cout<<t->key[i]<<"   ";
  else
     {for(int j=0;j<=t->count;j++)
        print_level(t->ptr[j],h-1);
     }
   
}
