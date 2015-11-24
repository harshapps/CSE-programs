#include<iostream>
#include<stack>
using  namespace std;
class Balancingsymbols
{ public:
    bool checkIfBalanced(char exp[]);

};

int main()
{  Balancingsymbols one;
  const int siz=100;
  char exp[siz];
  cout << "Enter a mathematical expression. U can use  (), {}, [] : ";
  cin.getline(exp,siz);
  if(one.checkIfBalanced(exp))
    cout<<"Balanced expression.....\n";
  else
    cout<<"Unbalanced expression....\n";
    return 0;
}

 bool Balancingsymbols::checkIfBalanced(char exp[])
    {  stack<char> balancest;
        for(int j=0;exp[j]!='\0';j++)
        {
            if(exp[j]=='(' || exp[j]=='{' || exp[j]=='[' )
                balancest.push(exp[j]);
            else if(exp[j]==')')
            {
                if(balancest.empty() || balancest.top()!='(') return 0;
                else balancest.pop();
            }
            else if(exp[j]=='}')
            {
                if(balancest.empty() || balancest.top()!='{')  return 0;
                else balancest.pop();
            }
             else if(exp[j]==']')
            {
                if(balancest.empty() || balancest.top()!='[')  return 0;
                else balancest.pop();
            }
        }
        if(balancest.empty())
            return 1;    //expression balanced
        else
            return 0;    //not balance



    }
