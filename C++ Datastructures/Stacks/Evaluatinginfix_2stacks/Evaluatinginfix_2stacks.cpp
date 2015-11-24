#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>

using namespace std;

class Evaluateinfix2s
{char infix[50];
 stack<char> operatorsym;
 stack<int>  operand;
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
   void poptop2numandcompute(char sym)
   { int first,second,result;
        first=operand.top();operand.pop();
        second=operand.top();operand.pop();
                switch(sym)
                {
                case '*' :result=second * first; operand.push(result);break;
                case '/' :result=second / first; operand.push(result);break;
                case '+' :result=second + first; operand.push(result);break;
                case '-' :result=second - first; operand.push(result);break;
                default :cout<<"unknown operator \n";exit(1);
                }


   }

    void Evaluateinfix()
    {

    int i,p=0,num;char c;
     for(i=0;infix[i]!='\0';i++)
     {
         while(infix[i]==' ' || infix[i]=='\t') i++;

        if(isdigit(infix[i]))
        {num=infix[i]-'0';
        operand.push(num);
        }
        else if(infix[i]=='(')  operatorsym.push(infix[i]);
        else if(infix[i]==')')
        {    if(operatorsym.empty())
              {
                  cout<<"There is no ( corresponding to ) in infix expression";exit(1);
              }
            while(operatorsym.top()!= '(' )
            { poptop2numandcompute(operatorsym.top());
                operatorsym.pop();
            }
            operatorsym.pop();

        }
        else if (infix[i]=='*' ||infix[i]=='/' ||infix[i]=='+' ||infix[i]=='-' )
        {    if(operatorsym.empty()) operatorsym.push(infix[i]);
              else if(priorityOf(infix[i])>priorityOf(operatorsym.top()))
            operatorsym.push(infix[i]);
            else
                {
                    while(priorityOf(operatorsym.top())>=priorityOf(infix[i]))
                    {poptop2numandcompute(operatorsym.top());
                      operatorsym.pop();

                    if(operatorsym.empty()) break;

                    }
                     operatorsym.push(infix[i]);
                }
        }

    }
    while(!operatorsym.empty())
    { poptop2numandcompute(operatorsym.top());
    operatorsym.pop();

    }
cout<<"\nEvaluating  infixexpresion  : "<<operand.top();

    }
};
int main()
{ Evaluateinfix2s e;
e.readData();
e.Evaluateinfix();
return 0;
}
