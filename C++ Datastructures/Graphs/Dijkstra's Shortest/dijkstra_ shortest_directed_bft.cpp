#include<iostream>
#include<climits>
using namespace std;
int n;
struct dijkstra
{	bool visited;
	
	int distance;
	int via;
dijkstra()
	{distance=INT_MAX;
	visited=0;
	}
};

int main()
{ cout<<"Enter number of vertices....";
 cin>>n;
	dijkstra **d;
	d= new dijkstra*[n];
	for(int i=0;i<n;i++)
	  d[i]=new dijkstra[n];
	  int adj,weight;

  for(int j=0;j<n;j++)
    { cout<<"Enter adjacent vertices for "<<j+1<<" seperated by spaces :";
     cin>>adj;
     if(adj!=-1)
     cin>>weight;
     while(adj!=-1)
     {d[j][adj-1]=weight;
     cin>>adj;
     if(adj!=-1)
     cin>>weight;
     }    
    }
for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  cout<<d[i][j]<<"  ";
	
	
	
	
}

