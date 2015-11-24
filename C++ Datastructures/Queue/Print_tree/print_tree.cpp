#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;

class treestructure
{char root,child[100],ch,printstore[100];
int level;
 queue<char> store;
    public:
   void readTree();
   void printTree();
};
int main()
{
    treestructure t;
    t.readTree();
    return 0;
}
void treestructure::readTree()
{ int k=1,i=0;
cout<<"how many levels u want to give for a tree :";
    cin>>level;
    cout<<"Enter root(parent) :";
    cin>>root;
    store.push(root);
   store.push('$');


    while(!store.empty() && k<=level)
    {
       while(store.front()!='$')
        {
        cout<<"press . to stop entering the children\nEnter children for "<<store.front()<<"  :  ";


             printstore[i++]=store.front();
            store.pop();

            while(ch!='.')
            {
            cin>>ch;
            if(ch!='.')
                store.push(ch);

            }
                ch='\0';//dot should not present in ch

        }
      if(store.front()=='$')
       { store.push('$');
           store.pop();
           k++;
           printstore[i++]='\n';

        }



    }
    printstore[i]='\0';
    printTree();
}
void treestructure::printTree()
{ for(int k=0;printstore[k]!='\0';k++)
  cout<<printstore[k];

}


