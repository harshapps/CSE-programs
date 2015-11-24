#include<iostream>
#include<cmath>
#include<iomanip>
#include<queue>
using namespace std;
struct btnode
{
    btnode *lchild;
    char data;
    btnode *rchild;
};
void printspaces(int level)
{
    for(int k=0;k<pow(2,level-1);k++)
        cout<<"    ";
}
void printsymspaces(int level)
{
    for(int k=0;k<pow(2,level-1);k++)
        cout<<"  ";
}


void insertdata(btnode *&t,char el)
{queue<char> store;
char printstore[100],ch;
int i=0,level=0;
     if(t==NULL)
     {  t=new btnode;
        t->data=el;
        t->lchild='\0';
        t->rchild='\0';
        return;
     }
     store.push(t->data);
     store.push('$');

     while(!store.empty())
      {
       while(store.front()!='$')
        {
         printstore[i++]=store.front();
             cout<<"Enter left child for  " <<store.front()<<" : ";
             cin>>ch;
             if(ch!='.')
                {store.push(ch);

                }
             cout<<"Enter right child for  " <<store.front()<<" : ";
             cin>>ch;
             if(ch!='.')
                {store.push(ch);
                }
                  store.pop();

                ch='\0';//dot should not present in ch for next iteration

        }
      if(store.front()=='$')
       { store.push('$');
           store.pop();
                 if(store.front()=='$')
            store.pop();
       level++;
           printstore[i++]='\n';

        }
    }

    int k=0,maxline=1;
    for( k=0;printstore[k]!='\0';k++)
  cout<<printstore[k];
//printing grpahically
cout<<endl<<endl;

printspaces(level--);
for(k=0;printstore[k]!='\0';k++)
{ if(printstore[k]=='\n')
    {cout<<printstore[k++];
    printspaces(level);
    for(int i=0;i<maxline;i++)
    {//cout<<"/      \\";
	printsymspaces(level+1);}
    cout<<endl;
    maxline++;
      printspaces(level--);}
    cout<<printstore[k];printspaces(level+2);

}



}






int main()
{
    btnode *t;
    t=new btnode;
    cout<<"Enter root node (parent)  :";
    cin>>t->data;
    t->lchild='\0';
    t->rchild='\0';

     insertdata(t,t->data);




}
