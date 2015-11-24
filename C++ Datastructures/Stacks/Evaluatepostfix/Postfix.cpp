#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;
class Postfix
{    char exp[50];
public:
    int char2integer(char x)
    {
        return(x-'0');  //he character encodings for digits in AscII are all in order from 48 (for '0') to 57 (for '9').
    }
    void inputdata()
    { cout<<"Enter postfix expression\n";
     cin.getline(exp,50);
    }
    void evaluatepostfix()
    {  stack<int> store;
        int j=0,num,first,second,result;



        for(;exp[j]!='\0';j++)
        {while( exp[j]==' ' || exp[j]=='\t') j++;

            if(exp[j]>='0'  && exp[j]<='9')
            {
                num =char2integer(exp[j]);
                store.push(num);
            }
            else
            {
                first=store.top();store.pop();
                second=store.top();store.pop();
                switch(exp[j])
                {
                case '*' :result=second * first; store.push(result);break;
                case '/' :result=second / first; store.push(result);break;
                case '+' :result=second + first; store.push(result);break;
                case '-' :result=second - first; store.push(result);break;
                default :cout<<"unknown operator \n";exit(1);
                }

           }

       }
       cout<<"After evaluating postfix expression, result is :"<<store.top();
    }
};
int main()
{Postfix ex;
ex.inputdata();
ex.evaluatepostfix();
return 0;
}



