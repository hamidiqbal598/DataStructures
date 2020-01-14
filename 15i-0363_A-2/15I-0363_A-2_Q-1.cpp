//------------------------
//Name: Hamid Iqbal and Talha Shafique
//Roll NO: i15-0363 and f15-8103
//Section: A (DS-Summer)
//Assignment-2 Question-1
//------------------------

#include<iostream>
using namespace std;

struct X_Node
{
	int data;
	X_Node *next;
};
X_Node *X_Head = NULL;
struct Y_Node
{
	int data;
	Y_Node *next;
};
Y_Node *Y_Head = NULL;

struct Z_Node
{
	int data;
	Z_Node *next;
};
Z_Node *Z_Head = NULL;

void Add_Node_X(int d)
{
	X_Node *temp = new X_Node;
	temp->data = d;
	temp->next = NULL;
	if (X_Head == NULL)
	{
		X_Head = temp;
		X_Head->next = NULL;
	}
	else
	{
		X_Node *temp1 = X_Head;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	cout << temp->data<<" ";
}
void Add_Node_Y(int d)
{
	Y_Node *temp = new Y_Node;
	temp->data = d;
	temp->next = NULL;
	if (Y_Head == NULL)
	{
		Y_Head = temp;
		Y_Head->next = NULL;
	}
	else
	{
		Y_Node *temp1 = Y_Head;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	cout << temp->data << " ";
}
void Add_Node_Z(int d)
{
	Z_Node *temp = new Z_Node;
	temp->data = d;
	temp->next = NULL;
	if (Z_Head == NULL)
	{
		Z_Head = temp;
		Z_Head->next = NULL;
	}
	else
	{
		Z_Node *temp1 = Z_Head;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
}

void Traverse()
{
	Z_Node *temp = Z_Head;
	while (temp != NULL)
	{
		cout << temp->data << "   ";
		temp = temp->next;
	}
	cout << endl;
}
void Merge_Z()
{
	X_Node *X = X_Head;
	Y_Node *Y = Y_Head;
	int a = 0;
	while (X != NULL || Y != NULL)
	{
		if (a == 0)
		{
			if (X == NULL)
			{
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
			if (Y == NULL)
			{
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

	int Arr1[7] = { 6,7,8,9,0,33,45 };
	cout << "Linked List X is : " << endl;
	cout << "List : ";
	for (int i = 0; i < 7; i++)
	{
		Add_Node_X(Arr1[i]);
	}
	cout << endl;
	int Arr[9] = {1,2,3,4,5,5,6,7,9};
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