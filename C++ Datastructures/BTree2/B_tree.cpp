#include<iostream>
#include<cstring>
using namespace std;
int d,flag=0;
struct bdnode   //b-tree of degree d
{
    int count;
    int *key;
    bdnode **ptr,*pptr;   // ptr child   pptr parent
    bdnode(int d)
    { key=new int[2*d];
		ptr=new bdnode*[2*d+1];
        for(int i=0;i<2*d;i++)
            key[i]=-1;
         for(int i=0;i<2*d+1;i++)
          ptr[i]=NULL;
         pptr=NULL;
        count=0;
    }
};
void print(bdnode *t)
{int j;
    if(t!=NULL)
    { for(j=0;j<2*d;j++)
       { print(t->ptr[j]);
        cout<<t->key[j]<<"  ";
       }
        print(t->ptr[j]);
    }
}
void levelwise_add_nodenum(bdnode *&t,int h)
{int i;static int c=0;
  if(t!=NULL)
  {for(i=0;i<h;i++)
   { if(h==1)

    cout<<t->key[i]<<"   ";
    else
    {levelwise_add_nodenum(t->ptr[i],h-1);

    }
   levelwise_add_nodenum(t->ptr[i],h-1);
 }
  }
}

void insert(bdnode *&t,int el,int d);
void resolve_overflow(bdnode *&t,int arr[],int el,int d,int flag);
void sort(int a[],int size);
void sort_updatepointers(bdnode *&t);


int main()
{   bdnode *t;int num,d;
cout<<"Enter degee of binary tree........";
cin>>d;
    t= new bdnode(d);
         cout<<"Enter number : ";
         cin>>num;
    t->key[t->count++]=num;
 while(num!=-1)
 {  cout<<"Enter next number : ";
     cin>>num;
     if(num !=-1)
     insert(t,num,d);
 }
 cout<<endl;
print(t);
cout<<endl;
for(int m=0;m<1;m++)
    levelwise_add_nodenum(t,m);
 return 0;
}
void insert(bdnode *&t,int el,int d)
{  int arr[2*d+1],m;
 if(t->ptr[0]==NULL)  //leaf node
 {  if(t->count < 2*d)
     {t->key[t->count++]=el;
      sort(t->key,t->count);
     }
     else //overflow
     {    for( m=0;m<2*d;m++)
        arr[m]=t->key[m];
           arr[m]=el;
           sort(arr,2*d+1);
         resolve_overflow(t,arr,el,d,flag);
     }
}
else   //go upto the leaf node
{
    if(el < t->key[0])
       {
           insert(t->ptr[0],el,d);
            // t=t->ptr[0];
       }
    else
    for(int j=0;j<2*d;j++)
     {
        if(t->key[j+1]==-1  && el > t->key[j] )
        {
        insert(t->ptr[j+1],el,d);
        break;
        }
        else if(el > t->key[j] && el < t->key[j+1])
        {insert(t->ptr[j+1],el,d); }
        else if (el > t->key[2*d-1] && t->key[2*d-1]!=-1)
       {insert(t->ptr[2*d],el,d);   break;
       }
     }
}
}
void resolve_overflow(bdnode *&t,int arr[],int el,int d ,int flag)  //splitting of node
{    t->count=0;
    for(int i=0;i<d;i++,t->count++)
    {
        t->key[i]=arr[i];
    }
    for(int i=d;i<2*d;i++)
    {
        t->key[i]=-1;
    }
    bdnode *temp =new bdnode(d),*s=t;
    int k,i=1;
    //cases for the different position of key in the array made from overflow
     //transfering the data from overflow tree node to temp node

if(t->ptr[0]!=NULL)
{

    if(el==arr[0])
     { k=d,temp->count=0;flag=1;}
     if(el>arr[0] && el < arr[d])
     { k=d,temp->count=0;flag=2;}
     else if(el==arr[d])
     {k=d+1,temp->count=1;flag=3;}
      else if(el>arr[d] && el <arr[2*d])
     {k=d+1,temp->count=1;flag=4;}
     else if(el==arr[2*d])
     {k=d+1,temp->count=0;flag=5;cout<<"dev";}

         for(;k<2*d+1;k++,temp->count++)
         {    temp->ptr[temp->count]=t->ptr[k];
           if((flag==5 && k!=2*d )||flag==1 || flag ==2 || flag==3 || flag==4)
                t->ptr[k]=NULL;
            temp->ptr[temp->count]->pptr=temp;
            temp->key[temp->count]=arr[k];

         }

}
else           //leaf node
{ for(k=d+1,temp->count=0;k<2*d+1;k++,temp->count++)
           temp->key[temp->count]=arr[k];

}
        bdnode *store=temp;
    if(t->pptr==NULL)             //if leaf node has no parent create a node
        { t->pptr= new bdnode(d);
            t->pptr->ptr[0]=t;
            t->pptr->pptr=NULL;
        }
            t=t->pptr;
        temp->pptr=t;
        if(t->count <2*d)
        { cout<<"\n ....data inserting in parent node";
            t->key[t->count++]=arr[d];
            //update_pointers
        if(t->count-1!=0)
             {t->ptr[t->count]=temp; sort_updatepointers(t);}
           else
            { t->ptr[0]=s;
            t->ptr[0]->pptr=t;
           t->ptr[1]=temp;
             t->ptr[1]->pptr=t;
            }


                  sort(t->key,t->count);
                cout<<"\nnew split node linked to the pptr and it contains.....";
                for(int n=0;n<temp->count;n++)
                     cout<<temp->key[n]<<"  ";cout<<endl;

          }
        else  //again overflow
        {int b=arr[d];bdnode *g;
        int a=0;cout<<"parent overflow";
             for(a=0;a<2*d;a++)
            arr[a]=t->key[a];
            arr[a]=b;
             sort(arr,2*d+1);
             cout<<"flag"<<flag;
            resolve_overflow(t,arr,b,d,flag);
            if(flag==1 || flag==2)
            {t->ptr[0]->ptr[t->count]=temp;t->ptr[0]->ptr[t->count]->pptr=t->ptr[0];}
            else if(flag==3)
            { t->ptr[t->count]->ptr[0]=temp;temp->pptr=t->ptr[t->count]->ptr[0];}
           else if(flag==4 || flag==5)
           { g=t->ptr[t->count]; cout<<"g "<<g->count;t->ptr[t->count]->ptr[g->count]=temp;temp->pptr=t->ptr[t->count]->ptr[g->count];
           }

         }
}
void sort(int arr[],int size)
{    for(int i=0;i<size;i++)
    {        for(int j=i;j<size;j++)
        { if(arr[i] > arr [j])
               swap(arr[i],arr[j]);
        }
    }
    for(int k=0;k<size;k++) cout<<arr[k]<<"  ";
       cout<<endl;
}
void sort_updatepointers(bdnode *&t)
{ for(int i=0;i<t->count;i++)
    {  for(int j=i+1;j<t->count;j++)
        { if(t->key[i] > t->key[j])
               {swap(t->key[i],t->key[j]);
                swap(t->ptr[i+1],t->ptr[j+1]);
               }
        }
    }
}
