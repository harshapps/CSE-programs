#include <iostream>
using namespace std;
struct registration;
struct student
{
	int snum;
	registration *down;
	student *right;
};
struct course
{
	int cnum;
	registration *right;
	course *down;
};
struct registration
{ registration *next_reg;
	int tag1;
	union
	{registration *next_creg;
	student *studbeg_pos;
	} studnt;
	int tag2;
	union
	{registration *next_sreg;
	course *coursbeg_pos;
	} co;
};


int main()
{ int num_s,num_c,k;
    cout<<"Enter the number of students :";
    cin>>num_s;
    cout<<"Enter the number of courses  : ";
    cin>>num_c;
    student *s=new student,*s_beg=s;
    course *c=new course,*c_beg=c;

    registration *reg_point,*horiz_traversal;
      for(k=i;k<=num_c;k++)
      {s->snum=k;
       s->down=NULL;
       s->right=new student;
      }
    for(k=1;k<=num_c;k++)
      { c->cnum=k;
        c->right=NULL;
        c->down=new course;
      }
for(int i=0;i<num_s;i++)
{
    cout<<"press -1 to stop entering the courses\nEnter the courses the student "<<i+1<<" want to register :";

    int flag=0;
  s->down=reg_point;
   while(cours!=-1)
    {cin>>cours;
            if(cours!=-1)
            { // if(flag==1)
                //reg_point->next_reg=new registration;
                while(c.cnum!=cours)
                c=c->down;
                if(c->right==NULL)
                   { c->right=new registration;
                      studnt.next_creg=c->right;
                      reg_point=studnt.next_creg;

                   }
                else
                {while(horiz_traversal!=NULL)
                horiz_traversal=horiz_traversal->nextc;

                reg_point->studnt.next_sreg=new(registration);
                }
            }
            c=c_beg;
   }
   reg_point->studbeg_pos=s_beg;
   s=s->right;

}
