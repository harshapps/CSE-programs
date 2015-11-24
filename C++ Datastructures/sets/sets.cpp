#include<iostream>
#include<cstdlib>
using namespace std;
int *s,n;
class set
{ public:
	int data[30];
	
	
	int find(int x);
	int find_and_compress(int x);
	void union_(int x,int y);
	void union_byheight(int x,int y);
	set()
	{s=new int[n];
	for(int i=0;i<n;i++)
	   s[i]=-1;
	}
};

int main()
{cout<<"Enter the size of set :";
  cin>>n;
  set a;
  a.union_(4,5);
    for(int i=0;i<n;i++)
    cout<<s[i]<<"   ";
  
}
void set::union_(int x,int y)
{s[y]=x;
}
void set::union_byheight(int x,int y)
{
	if(abs(s[x]) <abs(s[y]))   //checking height which in -ve so absolute func is used
	       s[x]=y;
	  else
	  { if(s[x]==s[y])  
	      { 
	      	s[x]--;					// x root
	      	s[y]=x;
	      }	 
	 }
}

int set::find(int x)
{if(s[x]<0)
    return x;
 else
 return find(s[x]);
	
}
int set::find_and_compress(int x)
{if(s[x]<0)
    return x;
 else
 {
  s[x]= find_and_compress(s[x]);
 return s[x];
 }
	
}


