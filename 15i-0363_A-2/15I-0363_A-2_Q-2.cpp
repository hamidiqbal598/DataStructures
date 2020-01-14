//------------------------
//Name: Hamid Iqbal and Talha Shafique
//Roll NO: i15-0363 and f15-8103
//Section: A (DS-Summer)
//Assignment-2 Question-2
//------------------------

#include<iostream>
using namespace std;

struct X_Node
{
	int data;
	X_Node *next;
};
X_Node *X_Head = NULL;
X_Node *X_Tail = NULL;
struct Y_Node
{
	int data;
	Y_Node *next;
};
Y_Node *Y_Head = NULL;
Y_Node *Y_Tail = NULL;
struct Z_Node
{
	int data;
	Z_Node *next;
};
Z_Node *Z_Head = NULL;
Z_Node *Z_Tail = NULL;
void Add_Node_X(int d)
{
	X_Node *temp = new X_Node;
	temp->data = d;
	temp->next = X_Head;
	if (X_Head == NULL)
	{
		X_Head = temp;
		X_Tail = temp;
		X_Head->next = X_Head;
	}
	else
	{
		X_Node *temp1 = X_Head;
		while (temp1 != X_Tail)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
		X_Tail = temp;
	}
	cout << temp->data << " ";
}
void Add_Node_Y(int d)
{
	Y_Node *temp = new Y_Node;
	temp->data = d;
	temp->next = Y_Head;
	if (Y_Head == NULL)
	{
		Y_Head = temp;
		Y_Tail = temp;
		Y_Head->next = Y_Head;
	}
	else
	{
		Y_Node *temp1 = Y_Head;
		while (temp1 != Y_Tail)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
		Y_Tail = temp;
	}
	cout << temp->data << " ";
}
void Add_Node_Z(int d)
{
	Z_Node *temp = new Z_Node;
	temp->data = d;
	temp->next = Z_Head;
	if (Z_Head == NULL)
	{
		Z_Head = temp;
		Z_Tail = temp;
		Z_Head->next = Z_Head;
	}
	else
	{
		Z_Node *temp1 = Z_Head;
		while (temp1 != Z_Tail)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
		Z_Tail = temp;
	}
}
void Traverse()
{
	Z_Node *temp = Z_Head;
	while (temp != Z_Tail)
	{
		cout << temp->data << "   ";
		temp = temp->next;
	}
	cout << Z_Tail->data << "   ";
	cout << endl;
}
void Merge_Z()
{
	X_Node *X = X_Head;
	Y_Node *Y = Y_Head;
	int a = 0;
	int x = 0, y = 0;
	while (X != X_Tail || Y != Y_Tail || x == 0 || y == 0)
	{
		if (a == 0)
		{
			if (X == X_Tail)
			{
				if (x == 0)
				{
					Add_Node_Z(X->data);
					x = 1;
				}
				a = 1;
			}
			else
			{
				Add_Node_Z(X->data);
				X = X->next;
				a = 1;
			}
		}
		else
		{
			if (Y == Y_Tail)
			{
				if (y == 0)
				{
					Add_Node_Z(Y->data);
					y = 1;
				}
				a = 0;
			}
			else
			{
				Add_Node_Z(Y->data);
				Y = Y->next;
				a = 0;
			}
		}
	}

}
int main()
{

	int Arr1[7] = { 1,3,5,7,9,11,13 };
	cout << "Linked List X is : " << endl;
	cout << "List : ";
	for (int i = 0; i < 7; i++)
	{
		Add_Node_X(Arr1[i]);
	}

	cout << endl;
	int Arr[9] = { 2,4,6,8,10,12,14,16,18 };
	cout << "Linked List Y is : " << endl;
	cout << "List : ";
	for (int i = 0; i < 9; i++)
	{
		Add_Node_Y(Arr[i]);
	}
	cout << endl;
	Merge_Z();
	cout << endl;

	cout << "Merge of Two Linked List are : " << endl;
	Traverse();

	system("pause>NULL");
	return 0;
}