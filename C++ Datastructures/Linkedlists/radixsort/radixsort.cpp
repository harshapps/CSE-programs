#include<iostream>
#include<cmath>
using namespace std;
struct node
{int data;
 node *next;
};
void inputdata(node *&l,node *&lst_start);
void printlist(node *l);
int main()
{node *lst,*lst_start,*bucket[10],*bucket_start[10],*temp;

int j,n,rem;
 inputdata(lst,lst_start);



 for(int k=0;k<2;k++)
 { for( j=0;j<10;j++)      //creating memory for buckets
    {    bucket[j]=new node;
        bucket_start[j]=bucket[j];
    }
      while(lst->next!='\0')   //filling buckets
      {
       rem=(lst->data/pow(10,k));
       rem%=10;
        temp=new node;
        temp->data=lst->data;
        bucket[rem]->data=temp->data;
        temp->next='\0';
        bucket[rem]->next=temp;
        bucket[rem]=temp;
        lst=lst->next;
       }

      for( j=0;j<10;j++)
      {   bucket[j]->next='\0';
          bucket[j]=bucket_start[j];
      }
        lst=lst_start;
      for(j=0;j<10;j++)   //Refilling list
      {
          while(bucket[j]->next!='\0')
          {
              lst->data=bucket[j]->data;
              if(k==1) cout<<lst->data<<" ";
              lst=lst->next;
              bucket[j]=bucket[j]->next;

          }
      }


   lst=lst_start;
 }


}
void inputdata(node *&l,node *&lst_start )
{ node *temp;
 l=new node;
lst_start=l;

cout<<"Enter element.press -1 to stop entering  : \n";


do {

    temp=new node;
    cin>> temp->data;
    if(temp->data!=-1)
      {l->data=temp->data;
       temp->next='\0';
       l->next=temp;
       l=temp;

     }
    } while(temp->data!=-1);
l->next='\0';
l=lst_start;
}
void printlist(node *l)
{
while(l->next!='\0')
       {
       cout<<l->data<<"   ";
       l=l->next;
       }
}

