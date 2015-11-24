#include<iostream>
#include<queue>
using namespace std;
class evaluatepostfix
{  char exp[50];
    queue<int> result;
    public:
    void eval_postfix();

};



int main()
{
    evaluatepostfix e;
    e.eval_postfix();
}

void evaluatepostfix::eval_postfix()
    {int temp,first,second;int c=0;
       cout<<"Enter the postfix expression ";
       cin.getline(exp,50);
        for(int i=0;exp[i]!='\0';i++)
        { if(exp[i]>='0'  && exp[i]<='9')
          {              result.push(int(exp[i]-'0')); //for converting char to integer Ascii value of 0 is 48
                            ++c;
          }
          else if(exp[i]=='*'||exp[i]=='/'||exp[i]=='+'||exp[i]=='-')
          { if(c==2)
            {first=result.front();
            result.pop();
            second=result.front();
            result.pop();
            }
            else if(c==3)
            { temp=result.front(); result.push(temp);result.pop();
            first=result.front();
            result.pop();
            second=result.front();
            result.pop();
            }


            switch(exp[i])
            {
                case '*':result.push(first*second);break;
                case '/': result.push(first/second);break;
                case '+': result.push(first+second);break;
                case '-': result.push(first-second);break;
                default:cout<<"unknown symbol";
            }
            c=1;
          }

        }
        cout<<"After evaluating postfix exp ,result is : "<<result.front();
    }
