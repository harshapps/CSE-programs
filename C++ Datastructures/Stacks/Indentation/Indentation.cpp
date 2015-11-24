#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
class Indentation
{ char store[500000];
  int numofchar;
    public:
         void readFile(ifstream &inp);
         void indentData();
         void printSpace(int &s);
};
int main()
{Indentation f;
ifstream f1("file2.txt");
f.readFile(f1);
f.indentData();
return 0;
}


 void Indentation::readFile(ifstream &inp)
    {int i;
    inp.unsetf(ios::skipws); //include white space in read
        for(i=0;!inp.eof();i++)
        inp>>store[i];
        numofchar=i-1;
    }
    void Indentation::printSpace(int &s)
    {
        for(int k=0;k<s;k++) cout<<"   ";
    }
void Indentation::indentData()
{ stack<char> symbol;

        stack<int> symbolspacegap;
    int cntsymbolgap=0,s=0,k;
    for(int i=0;i<numofchar;i++)
    {  cntsymbolgap++;
        switch(store[i])
          {case '#' :{ for(;store[i]!='>';i++)
                        cout<<store[i];
                        cout<<">\n";
                        break;
                     }
           case '\n':  printSpace(s);cntsymbolgap=0;break;
           case ';' :  cout<<store[i]<<endl; printSpace(s);break;
           case '{' :{ cout<<endl;
                    printSpace(s);
                    cout<<store[i]<<endl;
                     printSpace(s);
                    symbol.push(store[i]);
                    symbolspacegap.push(s);s++;
                    break;
                     }
            case '}':{cout<<endl;
                  printSpace(symbolspacegap.top());
                  cout<<store[i]<<endl;
                  symbol.pop();symbolspacegap.pop();
                  break;
                  }
          case '(' :{  for(;store[i]!=')';i++)
                            cout<<store[i];cout<<")";break;
                    }

         default:{cout<<store[i];}
        }
    }

}
