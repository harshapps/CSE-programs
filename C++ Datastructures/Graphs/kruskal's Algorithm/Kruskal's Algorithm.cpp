#include<iostream>
#include<math.h>
#include<cstdlib>
#include<fstream>
#include<iomanip>
using namespace std;
int n,s[30]; //set, heap ,graph
struct graph
{ 	int **vertex;
	graph()
	{
	 vertex=new int *[n];
	 for(int i=0;i<n;i++)
	 {vertex[i]=new int[n];
	 	    s[i]=-1; 
	 }		
	 }
	 
};

struct heap
{int u,v,weight;
};
void minHeapify(heap a[], int i, int n)    // i- index position
{
    int l = 2*i+1, r = 2*i+2; // l left  r right
    int smallest = i;
    if (l < n && a[l].weight < a[smallest].weight)
    smallest = l;
    if (r < n && a[r].weight < a[smallest].weight)
    smallest = r;
    if (smallest != i)
    {
    swap(a[smallest], a[i]);
    minHeapify(a, smallest, n);

    }
}
void formHeap(heap a[], int n)
{
    for (int i = n / 2; i >= 0; i--)  //n/2 bcoz there is no need to check leaf nodes
    minHeapify(a, i, n);

}
heap del_root_of_heap(heap a[], int &k)
{  
swap(a[0], a[k - 1]);
formHeap(a,k-2);
  return a[k-1];
}
int find_and_compress(int x)
{if(s[x]<0)
    return x;
 else
 {
  s[x]= find_and_compress(s[x]);
 return s[x];
 
 }
 }
void union_byheight(int x,int y)
{	if(abs(s[x]) <abs(s[y]))   //checking height which in -ve so absolute func is used
	       s[x]=y;
	  else
	  { if(s[x]==s[y])  
	      { 
	      	s[x]--;					// x root
	      	s[y]=x;
	      }	 
	 }
}

int main()
{
 cout<<"Enter the number of vertices  :";
 cin>>n;
 graph *g=new graph;
 int weight,v;
 /*
 for(int i=0;i<n;i++)
 { cout<<"Enter the adjacent vertices for  "<<i+1<<"  and the weight seperatd by  spaces \n";
  cin>>v>>weight;
  while(v!=-1)
    {g->vertex[i][v-1]=weight;
     cin>>v;if(v==-1)  break;
	 cin>>weight;    
    }
}*/
ifstream inp("adjmatrix.txt");

 for( int i=0;i<n;i++)
	{for(int j=0;j<n;j++)
	    { inp>>g->vertex[i][j];
	     cout<<setw(4)<<g->vertex[i][j];
	    }
	    cout<<endl;
	}
	
	    
heap h[30];
int k=0;
for(int i=0;i<n;i++)
   for(int j=i;j<n;j++)
   { if(g->vertex[i][j]!=0)  //connected
      {h[k].u=i;h[k].v=j;
       h[k].weight=g->vertex[i][j];
       cout<<"\n"<<h[k].u+1<<"  "<<h[k].v+1<<"  "<<h[k].weight<<"\n";
      	k++;
      }
   }
   
formHeap(h,k);


heap temp;int accepted=0,cost=0;
while(accepted<n)
{temp=del_root_of_heap(h,k);
k--;
cout<<find_and_compress(temp.u)<<"  "<<find_and_compress(temp.v)<<endl;
  if(find_and_compress(temp.u)!=find_and_compress(temp.v))
   {accepted++;
   cost+=temp.weight;
   cout<<"{ "<<temp.u+1<<" ,"<<temp.v+1<<" ,"<<temp.weight<<" }\n ";
   union_byheight(temp.u+1,temp.v+1);   
   	}
}
cout<<"\nMinimum cost :"<<cost;

}

 
	
	

