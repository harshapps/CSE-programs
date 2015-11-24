#include<iostream>
using namespace std;
struct additionalinfo
{
    int street;

};
struct student
{int roll;
char name[30];
additionalinfo address;//note thsi line
};

int main()
{
student *s[5];
for(int i=0;i<5;i++)  //taking input
{  s[i]=new(student);
cout<<"Enter student  "<<i+1<<"   roll , name ,street:";
cin>>s[i]->roll>>s[i]->name;
cin>>s[i]->address.street;
}

for(int i=0;i<5;i++)   //output
cout<<endl<<s[i]->roll<<" "<<s[i]->name<<" "<<(s[i]->address).street;
return 0;

}
