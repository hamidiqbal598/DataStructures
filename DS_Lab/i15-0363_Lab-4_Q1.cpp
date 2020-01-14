#include<iostream>
using namespace std;

struct AdjListNode
{
	int data;
	AdjListNode* next;
};
struct AdjList
{
	AdjListNode *head = NULL;
	AdjListNode *tail = NULL;
};
int hash_function_WOS(int src,int size)
{
	src = src % size;
	return src;
}
void LinearProbingWOS(AdjList *arr, int size)
{
	int array[] = { 1,2,3,4,5,14,12,13,0,11,6};
	for (int i = 0; i < 11; i++)
	{
		AdjListNode *node = new AdjListNode;
		node->data = array[i];
		node->next = NULL;
		int src = hash_function_WOS(array[i], size);
		if (arr[src].head == NULL)
		{
			arr[src].head = arr[src].tail = node;
		}
		else
		{
			int k = src;
			k++;
			while (arr[k].head != NULL && k != src)
			{
				if (k < size)
				{
					k = k + 1;
				}
				else
				{
					k = 0;
				}
			}
			if (k == src)
			{
				cout << "Array is Full " << endl;
			}
			else
			{
				arr[k].head = arr[k].tail = node;
			}
		}
	}
}
int hash_function_WS(int src, int size, int con)
{
	src = ( src + con ) % size;
	return src;
}
void LinearProbingWS(AdjList *arr, int size)
{
	int array[] = { 1,2,3,4,5,14,12,13,0,11,6 };
	for (int i = 0; i < 10; i++)
	{
		AdjListNode *node = new AdjListNode;
		node->data = array[i];
		node->next = NULL;
		int src = hash_function_WOS(array[i], size);
		bool flag = false;
		do
		{
			if (arr[src].head == NULL)
			{
				arr[src].head = arr[src].tail = node;
				flag = true;
			}
			else
			{
				int con;
				cout << "For " << i << " ";
				cout << "Enter constant Factor : ";
				cin >> con;
				src = hash_function_WS(array[i], size, con);
			}
		} while (!flag);
	}
}
void display(AdjList *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i].head->data << endl;
	}
}
void Chaining(AdjList *arr, int size)
{
	int array[] = { 1,2,3,4,5,14,12,13,0,11,6};
	for (int i = 0; i < 11; i++)
	{
		AdjListNode *node = new AdjListNode;
		node->data = array[i];
		node->next = NULL;
		int src = hash_function_WOS(array[i], size);
		if (arr[src].head == NULL)
		{
			arr[src].head = arr[src].tail = node;
		}
		else
		{
			arr[src].tail->next = node;
			arr[src].tail = arr[src].tail->next;
		}
	}
}
void display_Chain(AdjList *arr, int size)
{
	AdjListNode *temp;
	for (int i = 0; i < size; i++)
	{
		cout << i << " virtce adjacency list" << endl;
		temp = arr[i].head;
		while (temp != NULL)
		{
			cout << " [" << temp->data <<"] "<< endl;
			temp = temp->next;
		}
		cout << endl;
		temp = NULL;
	}
}
int hash_function_Quad(int src, int size, int val, bool flag)
{
	if (flag == true)
	{
		src = (src + (val*val)) % size;
	}
	else
	{
		src = abs(src - (val*val)) % size;
	}
	return src;
}
void QuadraticProbing(AdjList *arr, int size)
{
	int array[] = { 1,2,3,4,5,14,12,13,0,11,6 };
	for (int i = 0; i < 10; i++)
	{
		AdjListNode *node = new AdjListNode;
		node->data = array[i];
		node->next = NULL;
		int a = 0;
		int src = hash_function_WOS(array[i], size);
		bool flag = false;
		bool flag1;
		int c = 1;
		do
		{
			if (arr[src].head == NULL)
			{
				arr[src].head = arr[src].tail = node;
				flag = true;
			}
			else
			{
				if (a == 0)
				{
					flag1 = true;
					a = 1;
				}
				else
				{
					flag1 = false;
					a = 0;
					c++;
				}
				cout << "For " << i << " i = " << c << " with flag : " << flag1 << endl;
				src = hash_function_Quad(array[i], size, c, flag1);
			}
		} while (!flag);
	}
}
int main()
{
	int n;
	cout << "Enter 1 for Hashing without skipping : " << endl;
	cout << "Enter 2 for Hashing with skipping : " << endl;
	cout << "Enter 3 for Hashing with Chaining : " << endl;
	cout << "Enter 4 for Hashing with Quadratic : " << endl;
	do
	{
		cout << "Enter : ";
		cin >> n;
	} while (n < 1 || n>4);

	int size;
	cout << "Enter size of Hash : ";
	cin >> size;
	AdjList *Arr = new AdjList[size];

	if (n == 1)
	{
		LinearProbingWOS(Arr, size);
		display(Arr, size);
	}
	else if (n == 2)
	{
		LinearProbingWS(Arr, size);
		display(Arr, size);
	}
	else if (n == 3)
	{
		Chaining(Arr, size);
		display_Chain(Arr, size);
	}
	else
	{
		QuadraticProbing(Arr, size);
		display(Arr, size);
	}

	system("pause");
	return 0;
}