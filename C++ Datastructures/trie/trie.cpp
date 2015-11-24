#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct trie;
string dummyfile[20];
union uni
{
    trie* tr[29];
    int fptr;
};

struct trie
{
    trie *parent;
    int f;
    uni u;
};

string getdata(int x)
{
    return dummyfile[x];
}
void print(trie *T)
{
    if(T==NULL)return;
    if(T->f==0)
        cout<<getdata(T->u.fptr)<<endl;
    else if(T->f==1)
    {
        for(int i=0;i<26;i++)
            if(T->u.tr[i]!=NULL)
            {
                cout<<"yes for "<<i;
                print(T->u.tr[i]);
            }
    }

}

void initiate(trie *&T)
{
    T->f=NULL;
    T->u.fptr=NULL;
    for(int i=0;i<27;i++)
        T->u.tr[i]=NULL;
}
void add(int level,trie*& T,string x,int fptr)
{

    if(T==NULL)
    {
        T=new trie;
        initiate(T);
        T->f=0;
        T->u.fptr=fptr;
    }

    else if(T->f==1)
    {
        add(level+1,T->u.tr[(int)x.at(level)-65],x,fptr);
    }

    else if(T->f==0)
    {
        int k1=T->u.fptr,k2=fptr,c;
        initiate(T);
        T->f=1;
        string temp=getdata(k1),x1,x2;
        if(temp.length()>=x.length()){x1=temp;x2=x;}
        else{x1=x;x2=temp;c=k2;k2=k1;k1=c;}
        if(x2.length()-1==level && x2.length()!=x1.length())
        {
            T->u.tr[26]=new trie;
            initiate(T->u.tr[26]);
            T->u.tr[26]->f=0;
            T->u.tr[26]->u.fptr=k2;
        }
        else add(level+1,T->u.tr[(int)x2.at(level)-65],x2,k2);
        add(level+1,T->u.tr[(int)x1.at(level)-65],x1,k1);
    }
}

int height(trie *T)
{
    if(T==NULL || T->f==0)return -1;
    int d,c=-2;
    for(int i=0;i<=26;i++)
    {
        if(T->u.tr[i]!=NULL)
        {
        d=height(T->u.tr[i]);
        if(d>c)c=d;
        }
    }
    return c+1;
}

/*void printchar(trie *T,trie *P)
{   int i;
    if(P==NULL)return;
    if(P->parent==NULL)
    {
        for(i=0;i<27;i++)
            if(P->u.tr[i]==T)
                break;
            cout<<char(i+65);
            return;
    }
    printchar(T->parent,P->parent);
    for(i=0;i<27;i++)
            if(P->u.tr[i]==T)
                break;
            cout<<char(i+65);
}*/

void pri(trie *T,int level,int ll)
{
    if(T==NULL)return;
    if(level==0)
    {   int flag=1;
        for(int i=0;i<27;i++)
            if(T->u.tr[i]!=NULL)
            {
                if(i==26)cout<<"(-)";
                else
                {
                    if(T->u.tr[i]->f==0)
                    {flag=0;
                    cout<<"(";
                    string kk=getdata(T->u.tr[i]->u.fptr);
                    for(int iz=0;iz<ll;iz++)cout<<kk.at(iz);
                    cout<<char(i+65)<<") ";
                    cout<<"->"<<getdata(T->u.tr[i]->u.fptr)<<" ";
                    }
                    else cout<<"("<<char(i+65)<<") ";
                }
                if(T->u.tr[i]->f==0 && flag)
                    cout<<"->"<<getdata(T->u.tr[i]->u.fptr)<<" ";
            }
    }
    else{
        for(int i=0;i<=26;i++)
            if(T->u.tr[i]!=NULL && T->u.tr[i]->f==1)
                pri(T->u.tr[i],level-1,ll);
    }
}

void looper(trie *T)
{
    int x=height(T);
    for(int i=0;i<=x;i++)
    {
        pri(T,i,i);
        cout<<"\n\n";
    }
}

void settrie(trie *T,int i)
{
    if(T==NULL)return;
    if(i)T->parent=NULL;
    else for(i=0;i<27;i++)
            if(T->u.tr[i]!=NULL)
            {
                T->u.tr[i]->parent=T;
                settrie(T->u.tr[i],0);
            }
}



int main()
{
    trie *T=NULL;
    string x;
    cin>>x;
    int i=0;
    ofstream fout;
    fout.open("data.txt");
    while(x!="$")
    {
        fout<<x<<" ";
        dummyfile[i]=x;
        add(0,T,x,i);
        looper(T);
        i++;
        cin>>x;
    }
    looper(T);
    cout << "Hello world!" << endl;
    return 0;
}
