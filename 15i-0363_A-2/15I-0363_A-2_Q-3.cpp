//------------------------
//Name: Hamid Iqbal and Talha Shafique
//Roll NO: i15-0363 and f15-8103
//Section: A (DS-Summer)
//Assignment-2 Question-3
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
void Reverse()
{
	X_Node *temp = X_Head;
	X_Node *rev = X_Head;
	X_Node *iterator = X_Head;
	iterator = iterator->next;
	int c = 0;
	while (iterator!=X_Head)
	{
		c++;
		rev = iterator;
		iterator = iterator->next;
		rev->next = temp;
		temp = rev;
	}
	X_Head->next = X_Tail;
	cout << endl;
}
void Traverse()
{
	X_Node *temp = X_Tail;
	while (temp != X_Head)
	{
		cout << temp->data << "   ";
		temp = temp->next;
	}
	cout << X_Head->data << "   ";
	cout << endl;
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

	cout << "Reverse of Linked List are : " << endl;
	Reverse();
	Traverse();

	system("pause>NULL");
	return 0;
}