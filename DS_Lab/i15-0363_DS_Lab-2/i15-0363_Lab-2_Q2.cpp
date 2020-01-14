//------------------------
//Name: Hamid Iqbal
//Roll NO: i15-0363
//Section: A (DS-Summer)
//DS - Lab - 2 Question - 2
//------------------------


#include<conio.h>
#include<iostream>
using namespace std;
class intqueue
{
private:
	int *queuearray;
	int queuesize;
	int front;
	int rear;
	int numitems;
public:
	intqueue(int);
	~intqueue(void);
	void enqueue(int);
	int dequeue(void);
	int isempty(void);
	int isfull(void);
	void clear(void);
};
intqueue::intqueue(int s)
{
	queuearray = new int[s];
	queuesize = s;
	front = -1;
	rear = -1;
	numitems = 0;
}
intqueue::~intqueue(void)
{
	delete[] queuearray;
}
void intqueue::enqueue(int num)
{
	if (isfull())
		cout << "The queue is full." << endl;
	else
	{
		rear = (rear + 1) % queuesize;
		queuearray[rear] = num;
		numitems++;
	}
}
int intqueue::dequeue(void)
{
	if (isempty())
		cout << "The queue is empty";
	else
	{
		front = (front + 1) % queuesize;
		queuearray[front];
		numitems--;
	}
	return queuearray[front];
}
int intqueue::isempty()
{
	if (numitems == 0)
		return 1;
	else
		return 0;
}
int intqueue::isfull()
{
	if (numitems<queuesize)
		return 0;
	else
		return 1;
}
void intqueue::clear(void)
{
	front = -1;
	rear = -1;
	numitems = 0;
}
void Reversing(int size,intqueue queue)
{
	intqueue rev_queue(size);
	int iterator = size;
	while (iterator > 0)
	{
		iterator--;
		int value;
		int j = iterator;
		for (int z = 0; z < j; z++)
		{
			value = queue.dequeue();
			queue.enqueue(value);
		}
		value = queue.dequeue();
		rev_queue.enqueue(value);
	}
		cout<<endl<<endl;
		cout<<"Now Queue is in Reverse Direction : "<<endl;
		for (int i = 0; i < size; i++)
		{
			int value = rev_queue.dequeue();
			cout << value << "   ";
		}
		cout << endl;
}
int main()
{
	int size = 7;
	intqueue iqueue(size);
	int data;
	cout << "Enqueuing 7 items......." << endl;
	for (int x = 1; x <= 7; x++)
	{
		cout << "Enter Element " << x << " :";
		cin >> data;
		iqueue.enqueue(data);
	}
	cout << endl;

	Reversing(size,iqueue);

	system("pause>NULL");
	return 0;
}