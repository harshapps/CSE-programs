#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node * input2setsdata(node *&set1 , node *&set2);
void unionof(node *set1 ,node *set2);
void intersectionof(node *set1 ,node *set2);
int main ()
{
    node *set1,*set2;
    input2setsdata(set1,set2);
    intersectionof(set1,set2);

}

node *input2setsdata(node *&set1 , node *&set2)
{ node *comblst,*comb_start,*temp,*set1_start,*set2_start;
comblst=new node;
comb_start=comblst;
 set1=new node;
 set2=new node;
set1_start=set1;
 set2_start=set2;
int el,c=1;
rep1:
cout<<"Enter elements of set "<<c<<" .press -1 to stop entering  : \n";
   do {
    temp=new node;
    cin>> temp->data;
    if(temp->data!=-1)
      {  if(c==1)
         { set1->data= comblst->data= temp->data;
          temp->next='\0';
          set1->next=comblst->next=temp;
          set1=comblst=temp;
         }
         else
        {set2->data= comblst->data=temp->data;
          temp->next='\0';
          set2->next=comblst->next=temp;
          set2=comblst=temp;

         }

     }
    } while(temp->data!=-1);
    if(++c==1)
    set1->next='\0';
    set1=set1_start;
    if(c==2)
        goto rep1;
set2->next='\0';
 set2=set2_start;
 comblst->next='\0';
return comb_start;


}

void unionof(node *set1 ,node *set2)
{cout<<"Union of 2 sets :\n";
    while(set2->next!='\0')
       { while(set1->next!='\0')
           {
               if(set1->data==set2->data)
               {cout<<set1->data<<"  "; }
               else
                 {cout<<set1->data<<"   "<<set2->data<<"  ";}
                 set1=set1->next;
                   set2=set2->next;
           }

            set2=set2->next;
            cout<<set2->data<<" ";
       }


}

void intersectionof(node *set1 ,node *set2)
{node *start= set2;
    cout<<"Intersection of 2 sets  :\n";
  for(;set1->next!='\0';set1=set1->next)
    {  for(set2=start;set2->next!='\0';set2=set2->next)
         {if(set1->data==set2->data)
               cout<<set1->data<<"  ";

          }
    }


}

void sortlist(node*lst)
{ for(;lst->next!='\0';lst=lst->next)
    for(;lst->next!='\0';lst=lst->next)
}


