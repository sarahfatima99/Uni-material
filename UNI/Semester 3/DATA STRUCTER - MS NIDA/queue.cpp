#include<iostream>

using namespace std;

class queue{
	public:
	int front;
	int rear;
	int size;
	int* arr;
	
	queue(int n)
	{
		front=-1;
		rear=-1;
		size=n;
		arr= new int;
	}
	
	bool isfull()
	{
		if(rear==size-1)
		{
			return true;
		}
	}
	
	bool isEmpty()
	{
		if(front==-1)
		{
			return true;
		}
	}
	
	void enqueue(int n)
	{
		if(!this->isfull())
		{
			rear++;
			arr[rear]=n;
			if(front==-1)
			{
				front=0;
			}
		}
	}
	
	void dequeue()
	{
		if(!this->isEmpty())
		{
			if(front==rear)
			{
				front=rear=-1;
			}
			else if(front==size-1)
			{
				front=0;
			}
			else
			{
				front++;
			}
		}
	}
	
	void display()
	{
		if(front==rear)
		{
			cout<<"Queue is empty"<<endl;
		}
		else
		{
			for(int i=front;i<=rear;i++)
			{
				cout<<arr[i]<<" ";
			}
		}
	}
	
	void calculate(queue &st,queue &at){
		for(int i=1;i<3;i++){
		  int x=(st.arr[i-1]+at.arr[i-1]+this->arr[i-1])-at.arr[i];
		  this->enqueue(x);
		}
	}
	
};
int main()
{
	queue at(3),st(3),wt(3);
	
	int n;
	for(int i=0;i<3;i++)
	{ cin>>n;
	st.enqueue(n);
	cin>>n;
	at.enqueue(n);
	}
	at.display();
st.display();
	cout<<endl;
	wt.enqueue(0);
	wt.calculate(st,at);
	
	wt.display();
	
}
