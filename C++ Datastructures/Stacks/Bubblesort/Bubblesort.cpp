#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;
class bubblesort
{ stack<int> store;
  stack<int> sorted;
  public:
        void bsort();
};

 void bubblesort::bsort()
 { int i=0,top_elmnt,el,size;
 cout<<"enter the num of elements u want to enter ";cin>>size;
    cout<<"Enter the elements ";
     for(i=0;i<size;i++)
    { cin>>el;
    store.push(el);
    }
cout<<"Elements in sorted order \n";
i=0;
  while(i<size)
  {
    while(!store.empty())
    { top_elmnt=store.top();store.pop();
        if(store.empty())
       {
        sorted.push(top_elmnt);
        break;
       }

       if(top_elmnt > store.top())
             {sorted.push(store.top());
             store.pop();
             store.push(top_elmnt);

             }
        else
        {
            sorted.push(top_elmnt);
        }
       if(i==size-1) cout<<sorted.top()<<"  ";
    }

     while(!sorted.empty())
    {
      store.push(sorted.top());
      sorted.pop();
    }

    i++;
  }


 }
 int main()
 {
bubblesort sortasc;
sortasc.bsort();
 }
