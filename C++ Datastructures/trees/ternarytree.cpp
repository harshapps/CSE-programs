#include<iostream>
using namespace std;
 struct ternarynode
 {ternarynode *child[3];
 int data[2];
 };

 void insert(ternarynode *&t,int el)
 {if(t==NULL)
   {t=new ternarynode;
     t->child[0]=t->child[1]=t->child[2]=NULL;
     if(t->data[0])
     {  if(el> t->data[0])
          t->data[1]=el;
        else
        {t->data[1]=t->data[0];t->data[0]=el; }

     }
     else t->data[0]=el;

   }

 else if((el<t->data[0]))
    insert(t->child[0],el);

 else if(el>t->data[0]  &&  el<t->data[0])
    insert(t->child[1],el);

 else if((el>t->data[1]))
    insert(t->child[2],el);
 }


 void print(ternarynode *t)
 {if(t!=NULL)
  {print(t->child[0]);
   cout<<t->data[0]<<"  ";
   print(t->child[1]);
   cout<<t->data[1];
   print(t->child[2]);
   }
}

int main()
{ternarynode *t=NULL;
 int el;
 cout<<"To stop entering elements press -1 \n";
 do
 {cout<<"Enter element :";
  cin>>el;
  if(el!=-1)
   insert(t,el);
}while(el!=-1);

print(t);
return 0;
 }


