#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
using namespace std;
int n,count=0;//dft undirected
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
int list[100],temp_list[50];
void splice(graph *g,int list[],int &l_size,int &insert_at,int temp_list[],int &t_size)
{ for(int j=l_size;j>insert_at;j--)
     list[j+t_size-1]=list[j];
   for(int j=0;j<t_size;j++)
     list[j+insert_at]=temp_list[j]; 
   
   l_size+=t_size;  
   t_size=0;
}
int firstnonzero_degreevertex(graph *g,int list[],int &l_size)
{ int flag=0,i; 

for( i=0;i<l_size;i++)
    {
   for(int j=0;j<n;j++)
     { if(g->vertex[list[i]][j]!=0)
            { flag=1;
           		break;
            }
     }
     if(flag==1) break;
    }

  return flag==1 ? i : -1;
}
 int t_size=1,l_size=0;
void euler_path(graph *g,int v,int insert_at)
{   
int flag=0; 
	for(int w=0;w<n;w++)
	{ 
	 if(g->vertex[v][w]!=0 )   //connected 
	   { 
	   temp_list[t_size++]=w; 	 
	   flag=1;
	   g->vertex[v][w]=0;
	   g->vertex[w][v]=0;
	    euler_path(g,w,insert_at);      		
       } 
	}
if(flag==0)	
	{	cout<<"\ntemp list.....";
	for(int i=0;i<t_size;i++)
       cout<<temp_list[i]+1<<"  ";
       cout<<endl;
	splice(g,list,l_size,insert_at,temp_list,t_size);  
	cout<<"after splice...";
for(int i=0;i<l_size;i++)
       cout<<list[i]+1<<"  ";
       cout<<endl;
	  
	 int insert_at=firstnonzero_degreevertex(g,list,l_size) ;
		cout<<"ins .."<<insert_at<<endl;;
    if(insert_at!=-1)
     	{ 
          temp_list[t_size++]=list[insert_at];
		  euler_path(g,list[insert_at],insert_at);       	 
     	}
     }
}

int main()
{ifstream inp;string file;
cout<<"Enter the filename :";
cin>>file;
inp.open(file.c_str());
if(inp.fail())
{cout<<"file doesnot exist ";
exit(1);
}
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
list[0]=temp_list[0]=4;
 euler_path(g,4,0);
  	cout<<"\n\neuler path  \n\n";
  for(int i=0;i<l_size;i++)
       cout<<list[i]+1<<"  ";
       cout<<endl;   
}

    
  
	

