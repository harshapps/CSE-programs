#include<iostream>
#include<queue>
using namespace std;
class bubblesortq
{ queue<int> store;
public:

   void bsort_q();
};

int main()
{
  bubblesortq q;
  q.bsort_q();
}

void bubblesortq::bsort_q()
{int i,num,frontelm,el,j=0;
    cout<<"number of elements u want to enter :";cin>>num;
cout<<"start entering elements :\n";
for(i=0;i<num;i++)
   {  cin>>el;
    store.push(el);
   }
  i=0;
  cout<<"Elements in sorted order\n";
     frontelm=store.front();store.pop();
while(i<num)
{j=0;

    while(j<num)
    {
      if(frontelm>store.front())
       {
        store.push(frontelm);
        frontelm=store.front();
        store.pop();
        }
      else
      {store.push(store.front());
      store.pop();
      }
   if(j==num-1) cout<<frontelm<<"    ";
    j++;

    }  frontelm=store.front(); store.pop();


i++;
}

}
