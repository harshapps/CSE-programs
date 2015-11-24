#include <iostream>
#include<cstdlib>
using namespace std;
struct entity
{
    int a;
    char b;
};
class stack
{ public:
    entity ar[100];
    int top=-1;
    void push(entity);
    entity pop();
};
void  stack ::push(entity e)
{
    top=top+1;
    ar[top]=e;
}
entity stack :: pop()
{
    return ar[top--];
}
int main()
{ stack s;
char c;
while(c!='\n')
{entity ey;
    cin.get(c);
    if(int(c)>=48&&int(c)<=57)
    {
        ey.b=c;
        ey.a=int(c)-48;
        s.push(ey);
    }
    else
        {
            if(c=='-')
            {ey.b='-';
                while(s.top!=0)
            {
              if(s.ar[s.top-1].b=='+')
              {
                int  u=s.pop().a;
                  s.pop();
                 int t =s.pop().a;
                 entity pit;
                 pit.a=u+t;
                 s.push(pit);
            }
           else if(s.ar[s.top-1].b=='*')
              {
                int  u=s.pop().a;
                  s.pop();
                 int t =s.pop().a;
                 entity pit;
                 pit.a=u*t;
                 s.push(pit);
            }
           else if(s.ar[s.top-1].b=='/')
              {
                int  u=s.pop().a;
                  s.pop();
                 int t =s.pop().a;
                 entity pit;
                 pit.a=t/u;
                 s.push(pit);
            }
            }
            s.push(ey);
            }
           else if(c=='+')
                 {ey.b='+';
                while(s.top!=0)
            {
                if(s.ar[s.top-1].b=='-')
                break;
              if(s.ar[s.top-1].b=='*')
              {
                int  u=s.pop().a;
                  s.pop();
                 int t =s.pop().a;
                 entity pit;
                 pit.a=u*t;
                 s.push(pit);
            }
           else if(s.ar[s.top-1].b=='/')
              {
                int  u=s.pop().a;
                  s.pop();
                 int t =s.pop().a;
                 entity pit;
                 pit.a=t/u;
                 s.push(pit);
            }
            }
            s.push(ey);
            }
            else if(c=='*')
                 {ey.b='*';
                while(s.top!=0)
            {
                if(s.ar[s.top-1].b=='-')
                break;
              if(s.ar[s.top-1].b=='+')
              break;
           else if(s.ar[s.top-1].b=='/')
              {
                int  u=s.pop().a;
                  s.pop();
                 int t =s.pop().a;
                 entity pit;
                 pit.a=t/u;
                 s.push(pit);
            }
            }
            s.push(ey);
            }
           else if(c=='/')
            {
                ey.b='/';
                s.push(ey);
            }
        }
}
int oner=s.pop().a;
char doer=s.pop().b;
int twer= s.pop().a;
if(doer=='+')
    cout<<oner +twer;
else if(doer=='-')
    cout<<twer-oner;
    else if(doer=='*')
    cout<<twer*oner;
    else if(doer=='/')
    cout<<twer/oner;
    return 0;
}
