#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<fstream>
int c=1;
using namespace std;
int n;
struct graph
{int *numbering;
 bool *visited;
 int *low;
 int *parent; 	
 int **vertex;
  graph()
  {numbering = new int [n];
  visited=new bool [n];
   low= new int [n];
   parent=new int [n];
   vertex= new int *[n];
   for(int i=0;i<n;i++)
     {  vertex[i]=new int [n]; visited[i]=0;          	
     }
   }
	 
};
int minimum(int x,int y)
{ return x>y ? y : x;	
}

void find_articulation_points(graph *g,int s)
{   g->visited[s]=1;
	g->numbering[s]=g->low[s]=c++;
	for(int w=0;w<n;w++)
	{ if(g->vertex[s][w]!=0) //connected
	   { 
	    if(g->visited[w]==0)   //forward edge
	    	{g->parent[w]=s;	     		
			find_articulation_points(g,w);
				if(g->numbering[s] <= g->low[w] && s!=0)
		 			cout<<g->numbering[s]<<"  is a articulation point \n ";
	     g->low[s]=minimum(g->low[s],g->low[w]) ; 
	       }
	       else
	       { if(g->numbering[s] > g->numbering[w] && g->parent[w] !=s)  //back edge
	    	   {	g->low[s]=minimum(g->low[s],g->numbering[w]);	    	 	
	    	   }
	       }
	 }
   }
	
}
int main()
{
 cout<<"Enter the number of vertices  :";
 cin>>n; 
 graph *g=new graph;
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
ifstream inp("adj_matrix.txt");
 for( int i=0;i<n;i++)
	{for(int j=0;j<n;j++)
	    { inp>>g->vertex[i][j];
	     cout<<setw(4)<<g->vertex[i][j];
	    }
	    cout<<endl;
	}
find_articulation_points(g,0);
}



 
	
	

