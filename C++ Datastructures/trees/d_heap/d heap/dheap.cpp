#include<iostream>
#include<vector>
using namespace std;
int d;
struct dheap_node
{ int data;
  dheap_node **child;
  dheap_node *pptr;
   dheap_node()
   {child=new dheap_node*[d];
    for(int i=0;i<d;i++) 
     child[i]=NULL;  	
   }	
};
int c=0;

void min_heapify(dheap_node *t)
{if(t->pptr!=NULL)
 {
 	if(t->data < t->pptr->data)
 	  swap(t->data,t->pptr->data);
 	min_heapify(t->pptr);
 }
	
}
void insert(dheap_node *&t,dheap_node *p,vector<int> num)
{
	if(t==NULL)
	{t=new dheap_node;
	 if(p!=NULL)
	      cout<<"present parent "<<p->data<<"child.."<<num[c]<<endl;
	 t->pptr=p;
	 t->data=num[c++];
	}
	else if(c<num.size())
	{for(int i=0;i<d;i++)
	  { //cout<<"ins....."<<i<<" chil\n";
	  insert(t->child[i],t,num);
	  	 min_heapify(t->child[i]);  
	  }
	}	
}
int maxi=-1;
int height(dheap_node *t)
{ int a;
	if(t==NULL)
	  return -1;
	  
	else
	{ for(int i=0;i<d;i++)
	  {a=height(t->child[i]);
	   if(a > maxi)
	    maxi=a;
	  }
	 	 return maxi+1;
	}
}

void print(dheap_node *t,int h)
{ if(h==1)
   { if(t!=NULL)
   cout<<t->data<<"  ";  
   }
   else
   {for(int i=0;i<d;i++)
    print(t->child[i],h-1);
   }
	
}
int main()
{ vector<int> num;
int el;d=3;
dheap_node *t=NULL;
cout<<"Enter  number : ";
cin>>el;
  while(el!=-1)
  {num.push_back(el);
  cout<<"Enter next  number : ";
  cin>>el;
  }
  for(int i=0;i<num.size();i++)
   insert(t,NULL,num);
   cout<<endl;
   int h=height(t);
   
   cout<<"height......"<<h<<endl;
for(int i=1;i<h;i++)
  { print(t,i);	cout<<endl;
  }

}
