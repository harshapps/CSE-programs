#include<iostream>
using namespace std;
int n=0;
int m;
void DFT(int *G[],char V[],char c,int visited[],int i,int number[])
{
	visited[i]=1;
		
		for(int k=0;k<n;k++)
		{
			if(G[i][k]==1)
			{
				if(visited[k]==0)
					DFT(G,V,V[k],visited,k,number);
			}
		}
		m++;
		number[i]=m;
}
void strongComponent(int *G[],char V[],char c,int visited[],int i)
{
	visited[i]=1;
	cout<<c<<" ";
		for(int k=0;k<n;k++)
		{
			if(G[i][k]==1)
			{
				if(visited[k]==0)
					strongComponent(G,V,V[k],visited,k);
			}
		}
}
void calMax(int number[],int& p)
{
	int max;
	max=number[0];
	
	for(int i=1;i<n;i++)
	{
		if(max < number[i])
			max=number[i];
	}
	
	for(p=0;p<n;p++)
	{
		if(max==number[p])
			break;
	}
	number[p]=0;
}
void reverse(int *G[])
{
	int **G1=new int* [n];
	for(int i=0;i<n;i++)
		G1[i]=new int[n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			G1[i][j]=G[j][i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			G[i][j]=G1[i][j];
	}
}
int main()
{
	int i,j,k;
	char c;
	cout<<"enter the number of vertices ";
	cin>>n;
	char *V=new char[n];
	int *visited=new int[n];
	int *number=new int[n];
	
	int **G=new int* [n];
	for(i=0;i<n;i++)
		G[i]=new int[n];
		
	cout<<"enter the vertices ";
	for(i=0;i<n;i++)
		cin>>V[i];
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			G[i][j]=0;	
			
	for(i=0;i<n;i++)
		visited[i]=0;

	
	for(i=0;i<n;i++)
	{
		cout<<"enter the adjacent vertices of "<<V[i]<<" ";
		for(j=0;j<n;j++)
		{
			cin>>c;
			if(c=='.')
				break;
			else
			{
				for(k=0;k<n;k++)
				{
					if(c==V[k])
						G[i][k]=1;
				}			
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		cout<<"vertex "<<V[i]<<" is adjacent to ";
		for(j=0;j<n;j++)
		{
			if(G[i][j]==1)
				cout<<V[j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
			DFT(G,V,V[i],visited,i,number);
	}
				
//	for(int i=0;i<n;i++)
//		cout<<number[i]<<" ";
		
	for(i=0;i<n;i++)
		visited[i]=0;
		
	int p;
	reverse(G);

	for(int i=0;i<n;i++)
	{
		calMax(number,p);
		if(visited[p]==0)
		{
			strongComponent(G,V,V[p],visited,p);
			cout<<endl;
		}
	} 
	
}
