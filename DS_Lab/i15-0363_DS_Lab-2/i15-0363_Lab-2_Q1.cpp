//------------------------
//Name: Hamid Iqbal
//Roll NO: i15-0363
//Section: A (DS-Summer)
//DS - Lab - 2 Question - 1
//------------------------


#include<iostream>
using namespace std;

class intstack
{
	private:
		int *stackarray;
		int stacksize;
	public:
		int top;
		intstack(int);
		void push(int);
		int pop();
		int readtop();
		int isfull(void);
		int isempty(void);
};

intstack::intstack(int size)
{
	cout<<"Initializing stack of size:\t"<<size<<endl;
	stackarray=new int [size];
	stacksize=size;
	top=-1;
}
//push function
void intstack::push(int num)
{
	if (isfull())
		cout<<"Stack is Full"<<endl;
	else
	{
		top++;
		stackarray[top]=num;
		cout<<"Element Entered:\t"<<stackarray[top]<<endl;
	}
}
//pop function
int intstack::pop()
{
	int value=0;
	if(isempty())
		cout<<"Stack is Empty"<<endl;
	else
	{
		//cout<<"Element Removed:\t"<<stackarray[top]<<endl;
		value=stackarray[top];
		top--;	
	}
	return value;
}
//read top element
int intstack::readtop()
{
	if(isempty())
	{
		cout<<"Stack is empty"<<endl;
		return -1;
	}
	else
		return stackarray[top];
}
//checking for full stack
int intstack::isfull(void)
{
	int status;
	if(top==stacksize-1)
		status=1;
	else
		status=0;
	return status;
}
//checking for empty stack
int intstack::isempty()
{
	int status;
	if(top==-1)
		status=1;
	else
		status=0;
	return status;
}


int main()
{
	cout<<"##############################"<<endl<<"Array implementation of stack"<<endl<<"##############################"<<endl<<endl;
	int tempsize;
	cout<<"Enter Stack Size to Initialize (7):\t";
	cin>>tempsize;
	intstack stack(tempsize);
	cout<<endl;
	stack.push(10);
	stack.push(35);
	stack.push(18);
	stack.push(5);
	stack.push(48);
	stack.push(7);
	stack.push(8);
	stack.push(9);

	intstack stack1(tempsize);
	int i=tempsize;
	while(i>0)
	{
		i--;
		int j=i;
		for(int k=0;k<j;k++)
		{
			stack1.push(stack.pop());
		}
		int value=stack.pop();
		for(int k=0;k<j;k++)
		{
			stack.push(stack1.pop());
		}
		stack1.push(value);
	}
	cout<<endl<<endl;
	cout<<"Now Stack is : "<<endl;
	for(int i=0;i<tempsize;i++)
	{
		cout<<stack1.readtop()<<" ";
		stack1.pop();
	}
	cout<<endl;
	system("pause");
	return 0;
}
