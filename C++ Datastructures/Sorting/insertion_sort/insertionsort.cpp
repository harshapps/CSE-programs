#include<iostream>
using namespace std;
void rec_insertion_sort(node *&l,node *temp);
//insertionsort in linked list
int main()
{
}

void rec_insertion_sort(node *&l,node *temp)
 {  
    if(l!=NULL)
     {   if(strcmp(temp->data,l->data)==-1) //Adding temp  to the beginning
         {temp->next=l; 
		  l=temp;	                
         }
        else if(strcmp(temp->data,l->data)==1)  
        {   if(l->next!=NULL)
		     {  if( strcmp(temp->data,l->next->data)==-1 )
		     	{ temp->next=l->next; //Adding temp to the middle
           		 l->next=temp;
           		 
		     	}
		     	else
		     	rec_insertion_sort(l->next,temp);
		    }
		    else
		    l->next=temp; //temp added to the end		     	
        }
    }
    
 }
