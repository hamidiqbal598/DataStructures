//------------------------
//Name: Hamid Iqbal and Talha Shafique
//Roll NO: i15-0363 and f15-8103
//Section: A (DS-Summer)
//Assignment-2 Question-4
//------------------------

#include<iostream>
using namespace std;

struct X_Node
{
	int Coeffiecent;
	int Power;
	X_Node *next;
};
X_Node *X_Head = NULL;
X_Node *X_Tail = NULL;

void Traverse()
{
	X_Node *temp = X_Head;
	while (temp != NULL)
	{
		cout << temp->Coeffiecent << " " << temp->Power << " : ";
		temp = temp->next;
	}
	cout << endl;
}
void Add_Node_X(int co,int po)
{
	X_Node *temp = new X_Node;
	temp->Coeffiecent = co;
	temp->Power = po;
	temp->next = NULL;
	if (X_Head == NULL)
	{
		X_Head = temp;
		X_Tail = temp;
	}
	else
	{
		bool flag = false;
		X_Node *temp1 = X_Head;
		X_Node *temp2 = X_Head;
		temp2 = temp2->next;
		while (temp1->next != NULL && flag == false)
		{
			if (temp->Power < X_Tail->Power && flag == false)
			{
				X_Tail->next = temp;
				flag = true;
				X_Tail = temp;
			}
			else if (temp->Power > temp2->Power && temp->Power < temp1->Power && flag == false)
			{
				temp1->next = temp;
				temp->next = temp2;
				flag = true;
			}
			else if (temp->Power == temp1->Power && flag == false)
			{
				temp1->Coeffiecent = temp1->Coeffiecent + temp->Coeffiecent;
				flag = true;
			}
			temp1 = temp1->next;
			if (temp2 != NULL)
			{
				temp2 = temp2->next;
			}
		}
		if (flag == false)
		{
			temp->next = X_Head;
			X_Head = temp;
		}
	}
}
int main()
{

	int Arr1[7] = { 9,8,7,6,9,11,13};   //for coeeficents
	int Arr2[7] = { 1,3,0,5,2,4,8 };   // for power
	cout << "Linked List X is : " << endl;
	cout << "List : ";
	for (int i = 0; i < 7; i++)
	{
		//making link list
		Add_Node_X(Arr1[i],Arr2[i]);
	}
	cout << endl;
	cout << "Linked List is : " << endl;
	Traverse();
	system("pause>NULL");
	return 0;
}