#include<ioststrem>
using namespace std;

class queue
{
	int size;
	int elts[50];
	int front;
	int rear;
	public:
		queue();
		int isqfull();
		queue(int a);
		int isqempty();
		void enqueue(int b);
		int delqueue();
		void input();
		void display();
};
queue :: queue()
{
	size=50;
	front=-1;
	rear=-1;
}
queue :: queue(int a)
{
	size=a;
	front=-1;
	rear=-1;
}
void queue :: enqueue (int b)
{
	if(isqfull())
	cout<<"Q is full";
	else
	{
		rear=(rear+1)%size;
		elts[rear]=b;
		if(front==-1)
		front ++;
	}
}
int queue :: delqueue()
{
	if(isqempty())
	return NULL;
	else
	{
		int c=elts[front];
		if(front==rear)
		front=rear=-1;
		else
		front=((front+1)%size);
		return c;
	}
}
int queue :: isqfull()
{
	if(((rear+1)%size)==front)
	return 1;
	else return 0;
}
int queue :: isqempty()
{
	if(front==-1)
	return 1;
	else return 0;
}

