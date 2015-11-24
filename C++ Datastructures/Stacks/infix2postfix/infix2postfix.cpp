#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>

using namespace std;

class Infix2postfix
{char infix[50];
 char postfix[50];


public:
    void readData()
    {
        cout<<"Enter infix epression";
        cin.getline(infix,50);
    }
    int priorityOf(char sym)
    {
        switch(sym)
        {
        case '*':
        case '/':return 2; break;
        case '+':
        case '-':return 1; break;
        case '(':return 0;break;
        default: cout<<"Unknown symbol  "<<sym;exit(1);
        }
    }

    void infix2Postfix()
    { stack<char> s;

    int i,p=0;char c;
     for(i=0;infix[i]!='\0';i++)
     {
         while(infix[i]==' ' || infix[i]=='\t') i++;

        if(isalpha(infix[i])|| isdigit(infix[i]))   postfix[p++]=infix[i];
        else if(infix[i]=='(')  s.push(infix[i]);
        else if(infix[i]==')')
        {    if(s.empty())
              {
                  cout<<"There is no ( corresponding to ) in infix expression";exit(1);
              }
            while(s.top()!= '(' )
            {
                postfix[p++]=s.top();
                s.pop();
            }
            s.pop();

        }
        else if (infix[i]=='*' ||infix[i]=='/' ||infix[i]=='+' ||infix[i]=='-' )
        {    if(s.empty()) s.push(infix[i]);
              else if(priorityOf(infix[i])>priorityOf(s.top()))
            s.push(infix[i]);
            else
                {
                     while(priorityOf(s.top())>=priorityOf(infix[i]))
                    {
                    postfix[p++]=s.top();
                    s.pop();

                    if(s.empty()) break;

                    }
                     s.push(infix[i]);
                }
        }

    }
    while(!s.empty())
    { postfix[p++]=s.top();
    s.pop();

    }
cout<<"\nEquivalent postfix expresion  : ";
     for(int k=0;k<p;k++)
        cout<<postfix[k]<<" ";
    }
};
int main()
{Infix2postfix e;
e.readData();
e.infix2Postfix();
return 0;
}
