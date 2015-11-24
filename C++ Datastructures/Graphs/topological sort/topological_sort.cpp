#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<fstream>
int n;
using namespace std;
int find_leastindegree(int indegree[])
{ int index;
 for(int i=0;i<n;i++)
 {if(indegree[i]==0)
      index=i;
 }
	return index;
}
void topological_sort(int *graph[],int indegree[])
{int index;
 for(int i=0;i<n;i++)
  {index=find_leastindegree(indegree); //zero indegree
 	cout<<index+1<<"  ";
 	indegree[index]=1000;cout<<"indeg  ";
  for(int w=0;w<n;w++)
    {cout<<indegree[w]<<"  ";
	if(graph[index][w]!=0)
   	   indegree[w]--;
    }
    cout<<endl;
   }
}

int main()
{ cout<<"Enter the number of vertices..";
  cin>>n;
int **graph=new int*[n],indegree[n];
ifstream inp("adj_matrix.txt");
 for( int i=0;i<n;i++)
	indegree[i]=0;
 for( int i=0;i<n;i++)
	{graph[i]=new int[n];
	for(int j=0;j<n;j++)
	    { inp>>graph[i][j];
	      if(graph[i][j]!=0)
	        indegree[j]++;
	     cout<<setw(4)<<graph[i][j];
	    }
	    cout<<endl;
	}
	cout<<"in";
 for( int i=0;i<n;i++)
   cout<<indegree[i]<<"  ";	
   cout<<endl;
topological_sort(graph,indegree);
	
}


