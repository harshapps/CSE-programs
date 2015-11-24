#include<iostream>
using namespace std;
int form_min_heap(int h[]); //return size of the array  ,smallest number has the higest priority
int form_max_heap(int h[]) ; //maximum number has the highest priority
void print_heap(int h[],int siz);
void heap_sort(int h[],int siz);


int main()
{ int numbers[30],s;
  s=form_min_heap(numbers);
  print_heap(numbers,s);

}
int  form_min_heap(int h[])
{  int direction=0,num,temp,i;
    cout<<"Enter number :";
    cin>>num;
    h[0]=num;
     for(i=1;num!=-1;i++,direction++)
       {cout<<"Enter next number :";
           cin>>num;
           if(num==-1)
            break;
           else h[i]=num;
           temp=i;
           if(direction%2==0)
              {while(h[temp]<h[(temp-1)/2] )
                 {swap(h[temp],h[(temp-1)/2]);
                   temp=(temp-1)/2;
                 }

              }
            else
            {
            while(h[temp]<h[(temp-2)/2] )
                { swap(h[temp],h[(temp-2)/2]);
                    temp=(temp-1)/2;


                }
            }
            cout<<"\t";
print_heap(h,i+1);cout<<endl;
       }

return i;
  }

int form_max_heap(int h[])
{

}
void print_heap(int h[],int siz)
{
    for(int i=0;i<siz;i++)
        cout<<h[i]<<"  ";
}

void heap_sort(int h[],int siz)
{

}
