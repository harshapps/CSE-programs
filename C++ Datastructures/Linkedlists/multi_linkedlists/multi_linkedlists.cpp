#include<iostream>
using namespace std;
 struct node
 {
     union list_or_char
     {
         char c;
         node *l;
     };
     int tag;
     list_or_char data;
     node *next;
 };


 int main()
 { node *lst,*level[4];
 char print_store[100];


 int i=-1,j=0;

 int choice;
 do{lst =new node;
    cout<<"press 1. char 2. Another linked list  3.skip to previous list(level)\n 4.stop entering data ";
    cin>>choice;

    switch(choice)
     {
         case 1:lst->tag=1;
         cout<<"Enter data : ";

                cin>>lst->data.c;
                print_store[j++]=lst->data.c;
                print_store[j++]=',';
                lst->next=new node;
                lst->next->next='\0';
                lst=lst->next;

                break;

         case 2:lst->tag=2;
                level[++i]=lst;
                print_store[j++]='(';
               lst->data+.l=new node;
                lst=lst->data.l;

               break;
        case 3:print_store[j++]=')';
             lst=level[--i];


                break;
        case 4:print_store[j]=')';break;

     }
  } while(choice !=4 );
cout<<"(";
  for(int k=0;k<j;k++)
   cout<< print_store[k];

}
