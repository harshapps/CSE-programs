#include<iostream>
#include<cstdlib>
using namespace std;
struct dnode
{
	dnode *left;
	int data;
	dnode *right;
};


void inputdata(dnode *&l)
{ dnode *s,*temp;
 l=new dnode;
  s=l;
 l->left='\0';
 cout<<"Enter elements.press -1 to stop entering  : \n";
  cin>>l->data;
 l->right='\0';
  do {

    temp=new dnode;
    cin>> temp->data;
    if(temp->data!=-1)
      {
       temp->right='\0';
       l->right=temp;
       l->right->left=l;
       l=temp;
      }
    } while(temp->data!=-1);

l=s;
}
void addbegin(dnode *&lst, int x)
{
	lst->left=new(dnode);
	lst->left->right=lst;
	lst=lst->left;
	lst->data=x;
	lst->left=NULL;
}
void addend(dnode *&lst, int x)
{
	while(lst->right!=NULL)
	lst=lst->right;
	lst->right=new(dnode);
	lst->right->left=lst;
	lst=lst->right;
	lst->data=x;
	lst->right=NULL;
}
void addbefore(dnode *&lst,int y,int x)   // x- element to be added
{
	while(lst->data!=y)
	lst=lst->right;
	dnode *T=new(dnode);
	T->data=x;
	T->right=lst;
	T->left=T->right->left;
	if(T->left!=NULL)   //ig not first element of the list
	T->left->right=T;
	T->right->left=T;
}
void addafter(dnode *&lst,int y,int x)
{
	while(lst->data!=y)
	lst=lst->right;
	dnode *T=new(dnode);
	T->data=x;
	T->left=lst;
	T->right=T->left->right;
	T->left->right=T;
	if(T->right!=NULL)
	T->right->left=T;
}
void del(dnode *&lst,int x)
{
	while(lst->data!=x)
	lst=lst->right;
	dnode *T=lst;
	T->left->right=T->right;
	if(T->right!=NULL)
	T->right->left=T->left;
	T->right=NULL;
	T->left=NULL;

}
void display(dnode *lst)
{
	while(lst !=NULL)
    {cout<<lst->data<<" ";
    lst=lst->right;

    }


}
