//bin sort
#include<iostream>
using namespace std;
struct numlistnode
{   int numdata;
    numlistnode * num_next;
};


struct node
{
char chardata;
numlistnode *number;
node *next;

};
node * inputdata(node *l);
void binsort(node *l);
int main()
{
    node *lst;
    binsort(inputdata(lst));
}
node * inputdata(node *l)
{ node *s,*temp,*storenum; //s start position
 l=new node;
 storenum->number=new numlistnode;
s=l;
int el;
cout<<"Enter element.press -1 to stop entering  : \n";


do
{
    temp=new node;
    cout<<"\nTo stop entering data press . Enter character  : ";
    cin>>temp->chardata;
    if(temp->chardata!='.')
     {l->chardata=temp->chardata;
      cout<<"Enter number  :  ";
       cin>> temp->number->numdata;
       l->number->numdata=temp->number->numdata;

      temp->next='\0';
      l->next=temp;
      l=temp;
    }

} while(temp->chardata!='.');
 l->next='\0';
return s;
}

void binsort(node *l)
{
numlistnode *temp;
node *pos,*Startpos=l;

    while(l->next!='\0')
    {  for(pos=Startpos;pos->next!='\0';pos=pos->next)
        {
            if(l->chardata==pos->chardata)
            {
             temp=new numlistnode;
             temp->numdata=l->next->number->numdata;
             temp->num_next='\0';
             l->number->num_next=temp;
             l->number=temp;
             //Delete the node at pos as the number associated with it is already added to its char data
              pos->next=pos->next->next;

           }
    }

}
}

