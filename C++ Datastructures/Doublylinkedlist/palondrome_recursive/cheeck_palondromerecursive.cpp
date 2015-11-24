#include<iostream>
using namespace std;
struct dnode
{
	dnode *left;
	char data;
	dnode *right;
};


void inputdata(dnode *&l,dnode *&D1,dnode *&D2)
{ dnode *temp;
 l=new dnode;
 D1=l;
 l->left='\0';
 cout<<"Enter data ........press ; to stop entering  : \n";
  cin>>l->data;
 l->right='\0';
  do {

    temp=new dnode;
    cin>> temp->data;
    if(temp->data!=';')
      {
       temp->right='\0';
       l->right=temp;
       l->right->left=l;
       l=temp;
      }
    } while(temp->data!=';');
D2=l;
l=D1;
}
bool chk_palondrome_rec(dnode *D1, dnode *D2)
{   if(D1==D2)
        return 1;
    if(D1->data==D2->data)
    {
     chk_palondrome_rec(D1->right,D2->left);

    }

    else
        return 0;

}

int main()
{
    dnode *lst,*D1,*D2;
    inputdata(lst,D1,D2);
    if(chk_palondrome_rec(D1,D2))
        cout<<"palondrome ";
        else
        cout<<"Not palondrome ";

}
