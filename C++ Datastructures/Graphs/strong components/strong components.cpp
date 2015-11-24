#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int n,count=0;//dft directed
struct graph
{ 	int **vertex;
    int *numbering;
    bool *visited;
	graph()
	{  numbering=new int [n];
		visited=new bool[n];
	 vertex=new int *[n];
	 for(int i=0;i<n;i++)
	 {vertex[i]=new int[n];
	  visited[i]=0; 
	 }		
	 }	
};
void reverse_directions(graph *&g)
{ for(int i=0;i<n;i++)
    {
    for(int j=i;j<n;j++)
       { swap(g->vertex[i][j],g->vertex[j][i]);  
	    }
     }   
}
void reset_visited(graph *g)
{for(int i=0;i<n;i++)
   g->visited[i]=0;
}
void strong_components(graph *g,int v,int tag)
{ if(tag==1)
     cout<<v+1<<",";
	g->visited[v]=1;
	for(int w=0;w<n;w++)
	{ if(g->vertex[v][w]!=0 && g->visited[w]==0)   //connected and not visited
	   {strong_components(g,w,tag);  	
       } 
	}
   if(tag==0)
   {	g->numbering[v]=++count;
	   			cout<<v+1<<"  number  "<<g->numbering[v]<<endl;
   } 			
}
int calc_maxnum_vertex(graph *g)
{int maxi=-1,index;
 for(int i=0;i<n;i++)
   if(g->numbering[i]>maxi)
      {maxi=g->numbering[i];
       index=i;
      } ;
g->numbering[index]=-1;
 return index;
	
}
int main()
{ifstream inp("strong_graph.txt");
cout<<"Enter number of vertices.......";
cin>>n;
graph *g=new graph;
 for( int i=0;i<n;i++)
	{for(int j=0;j<n;j++)
	    { inp>>g->vertex[i][j];
	     cout<<setw(4)<<g->vertex[i][j];
	    }
	    cout<<endl;
	}
for(int i=0;i<n;i++)	
     {
     if(g->visited[i]==0)
  			strong_components(g,i,0);
  	 }

    reverse_directions(g);
reset_visited(g);
cout<<"strong components............";
for(int i=0;i<n;i++)
{ int indx=calc_maxnum_vertex(g);
  if(g->visited[indx]==0)
  {cout<<"{  ";
      strong_components(g,indx,1);
    cout<<"} \n";
  }
  	
}

    
  
	
}
