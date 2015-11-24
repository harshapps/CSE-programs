#include<iostream>
#include<cmath>
#include"doublylinkedlist_implementation.h"
using namespace std;

int main()
{
    dnode *num1,*num2;
    cout<<"Enter number 1 :";
    inputdata(num1);
    cout<<"Enter number 2 :";
    inputdata(num2);
    int n1,n2;

    cout<<endl;
    int result,carrydigit=0,sum=0,i=1;
    while(num1 !='\0' || num2!='\0' )
    { if(num1!='\0')
        n1=num1->data-'0';  //converting char to interger
        else n1=0;
        if (num2!='\0')
        n2=num2->data-'0';
        else n2=0;
        if(n1 + n2 + carrydigit >=9 )
        { result= (n1 + n2 + carrydigit)%10;

          carrydigit=(n1 + n2 + carrydigit)/10;

        }
       else
        {
            result=n1 + n2 + carrydigit;
             carrydigit=0;

        }

    sum=sum + result*i;
    i=i*10 ;
     if(num1!='\0')
     num1=num1->left;
      if (num2!='\0')
      num2=num2->left;

   }
    sum=sum + carrydigit*i ;
 cout<<endl<<sum;

}




