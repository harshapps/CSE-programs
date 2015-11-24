#include<iostream>
#include<cstring>
using namespace std;
int d,flag=0;
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
void print_level(bdnode *t,int h)
{if(h==1)
for(int i=0;i<t->count;i++)
     cout<<t->key[i]<<"   ";
  else
     {for(int j=0;j<=t->count;j++)
        print_level(t->ptr[j],h-1);
     }
   
}
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


void insert(bdnode *&t,int el);
void resolve_overflow_nodesplit(bdnode *&t);
void sort_updatepointers(bdnode *&t,int flag);
void print_l(bdnode *&t)
{if(t!=NULL)
{for(int i=0;i<t->count;i++)
cout<<t->key[i]<<" ";
cout<<endl;
for(int i=0;i<t->count+1;i++)
{print_l(t->ptr[i]);}}}



int main()
{  int num; bdnode *t;
cout<<"Enter degee of binary tree........";
cin>>d;
    t= new bdnode;
         cout<<"Enter number : ";
         cin>>num;
    t->key[t->count++]=num;
 while(num!=-1)
 {  cout<<"Enter next number : ";
     cin>>num;
     if(num !=-1)
     insert(t,num);
 }
 //cout<<endl;cout<<t->ptr[0]->key[0]<<"  "<<t->ptr[1]->key[0];
for(int k=1;k<=3;k++)
{print_level(t,k);
cout<<endl;
}
cout<<endl;
//for(int m=0;m<1;m++)
//    levelwise_add_nodenum(t,m);
 return 0;
}
void insert(bdnode *&t,int el)
{ if(t->ptr[0]==NULL)  //leaf node
  {   t->key[t->count++]=el;
    sort_updatepointers(t,0);
      if(t->count == 2*d+1)  //overflow
          resolve_overflow_nodesplit(t);
 }
else   //go upto the leaf node
{
    if(el < t->key[0])
       {   insert(t->ptr[0],el);
           // t=t->ptr[0];
       }
    else
    for(int j=0;j<2*d;j++)
     {
        if(t->key[j+1]==-1  && el > t->key[j] )
        {
        insert(t->ptr[j+1],el);
        break;
        }
        else if(el > t->key[j] && el < t->key[j+1])
        {insert(t->ptr[j+1],el); }
        else if (el > t->key[2*d-1] && t->key[2*d-1]!=-1)
       {insert(t->ptr[2*d],el);   break;
       }
     }
}
}
void resolve_overflow_nodesplit(bdnode *&t)  //splitting of node
{      int k;static int flag=0;
    bdnode *par=t->pptr,*left=new bdnode(),*temp =new bdnode();
    for(k=0;k<=d;k++)
     {  if(k!=d)
          left->key[left->count++]=t->key[k];
          left->ptr[k]=t->ptr[k];
          if( left->ptr[k])
          left->ptr[k]->pptr=left;
     }
    for(k=d+1,temp->count=0;k<2*d+1;k++,temp->count++)
           {temp->key[temp->count]=t->key[k];
            temp->ptr[temp->count]=t->ptr[k];                     
          }
    temp->ptr[temp->count]=t->ptr[k];
          int store=t->key[d];
    
    if(t->pptr==NULL)             //if leaf node has no parent create a node
        { par= new bdnode();
          par->key[par->count++]=t->key[d];
          t->pptr=par;
          t->pptr->ptr[0]=t;
        }
        else
        {par->key[par->count++]=t->key[d];
         par->ptr[t->count]=temp;
         sort_updatepointers(par,1);
         
         
        	
        }
      
                cout<<"\nnew split node linked to the pptr and it contains.....";
                for(int n=0;n<temp->count;n++)
                     cout<<temp->key[n]<<"  ";cout<<endl;
   if(t->count==2*d+1) //again overflow
        {  cout<<"parent overflow";flag=1;
         resolve_overflow_nodesplit(t);
         
         }
}
void sort_updatepointers(bdnode *&t,int flag)
{ for(int i=0;i<t->count;i++)
    {  for(int j=i+1;j<t->count;j++)
        { if(t->key[i] > t->key[j])
               {swap(t->key[i],t->key[j]);
                if(flag==1)
                swap(t->ptr[i+1],t->ptr[j+1]);
               }
        }if(flag!=1)    cout<<t->key[i]<<"  ";
    }    cout<<endl;
}
