#include <iostream>

using namespace std;

class stack{
public:
    int el[50];
    int top = -1;
    void push(int e);
    int pop();
    bool isEmpty();

};

void stack::push(int e){
    el[++top] = e;
    cout<<e<<" pushed "<<endl;
}

int stack::pop(){
    cout<<el[top]<<" pop "<<endl;
   return el[top--];
}

bool stack::isEmpty(){
    if( top == -1)
        return true;
    else
        return false;

}

int main()
{ //Ascii values of * 42 , + 43 ,- 45 ,/ 47

    stack s;
    char a[50];
    int b[50] , i=0 ,sum;
    cout<<"enter :";
    cin>>a;

    while( a[i] != '\0'){
        b[i] = int( a[i] ) - 48;
      //  cout<<b[i]<<endl;
        i++;
    }
    int j=0;
    while (j<i){
        if( b[j] == -6)  // -6  mult
            {
            sum = s.pop() * b[++j];
            s.push(sum);
            j++;
            }
        else{
            s.push(b[j]);
            j++;
           }

    }
    int z,n;
    while ( s.top !=0 ){
         z = s.pop();
         cout<<endl<<"z = "<<z<<endl;
         if(s.pop() == -3 ){
            sum = z - s.pop();
            s.push(-sum);
            cout<<endl<<" sum ="<<sum<<endl;;
         }

         else{

           n=s.pop();
           cout<<endl<<" n = "<<n<<endl;
           sum = z + n;
           s.push(sum);
           cout<<endl<<n<<endl<<"yipee"<<sum;
         }
    }
    cout<<endl<<"ANSWER: "<<s.pop();
    return 0;
}
