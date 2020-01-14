//------------------------
//Name: Hamid Iqbal and Talha Shafique
//Roll NO: i15-0363 and f15-8103
//Section: A (DS-Summer)
//Assignment-2 Question-5
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
struct Y_Node
{
	int Coeffiecent;
	int Power;
	Y_Node *next;
};
Y_Node *Y_Head = NULL;
Y_Node *Y_Tail = NULL;
struct Z_Node
{
	int Coeffiecent;
	int Power;
	Z_Node *next;
};
Z_Node *Z_Head = NULL;
Z_Node *Z_Tail = NULL;

void Traverse_X()
{
	X_Node *temp = X_Head;
	while (temp != NULL)
	{
		cout << temp->Coeffiecent << "x^" << temp->Power << " + ";
		temp = temp->next;
	}
	cout << endl;
}
void Traverse_Y()
{
	Y_Node *temp = Y_Head;
	while (temp != NULL)
	{
		cout << temp->Coeffiecent << "x^" << temp->Power << " + ";
		temp = temp->next;
	}
	cout << endl;
}
void Traverse_Z()
{
	Z_Node *temp = Z_Head;
	while (temp->next != NULL)
	{
		if (temp->Coeffiecent != 0)
		{
			cout << "( " << temp->Coeffiecent << "x^" << temp->Power << " ) + ";
		}
		else
		{
			cout << "( ""x^" << temp->Power << " ) + ";
		}

		temp = temp->next;
	}
	cout << "( " << temp->Coeffiecent << "x^" << temp->Power << " ) ";
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
void Add_Node_Y(int co, int po)
{
	Y_Node *temp = new Y_Node;
	temp->Coeffiecent = co;
	temp->Power = po;
	temp->next = NULL;
	if (Y_Head == NULL)
	{
		Y_Head = temp;
		Y_Tail = temp;
	}
	else
	{
		bool flag = false;
		Y_Node *temp1 = Y_Head;
		Y_Node *temp2 = Y_Head;
		temp2 = temp2->next;
		while (temp1->next != NULL && flag == false)
		{
			if (temp->Power < Y_Tail->Power && flag == false)
			{
				Y_Tail->next = temp;
				flag = true;
				Y_Tail = temp;
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
			temp->next = Y_Head;
			Y_Head = temp;
		}
	}
}
void Add_Node_Z(int co, int po, int check)
{
	Z_Node *temp = new Z_Node;
	temp->Coeffiecent = co;
	temp->Power = po;
	temp->next = NULL;
	if (Z_Head == NULL)
	{
		Z_Head = temp;
		Z_Tail = temp;
	}
	else
	{
		bool flag = false;
		Z_Node *temp1 = Z_Head;
		Z_Node *temp2 = Z_Head;
		temp2 = temp2->next;
		while (temp1 != NULL && flag == false)
		{
			if (temp->Power == temp1->Power && flag == false)
			{
				if (check == 1)
				{
					temp1->Coeffiecent = temp1->Coeffiecent + temp->Coeffiecent;
				}
				else if (check == 2)
				{
					temp1->Coeffiecent = temp1->Coeffiecent - temp->Coeffiecent;
				}
				else
				{
					temp1->Coeffiecent = temp1->Coeffiecent * temp->Coeffiecent;
				}
				flag = true;
			}
			else if (temp->Power < Z_Tail->Power && flag == false)
			{
				Z_Tail->next = temp;
				flag = true;
				Z_Tail = temp;
			}
			else if (temp->Power > temp2->Power && temp->Power < temp1->Power && flag == false)
			{
				temp1->next = temp;
				temp->next = temp2;
				flag = true;
			}
			if (temp2 != NULL)
			{
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
		}
		if (flag == false)
		{
			temp->next = Z_Head;
			Z_Head = temp;
		}
	}
}
void Mathematical_Operations(int check)
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
				Add_Node_Z(X->Coeffiecent,X->Power,check);
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
				Add_Node_Z(Y->Coeffiecent, Y->Power, check);
				Y = Y->next;
				a = 0;
			}
		}
	}
}
int main()
{

	int Arr1[7] = { 9,8,7,6,9,11,13};   //for coeeficents
	int Arr2[7] = { 1,3,0,5,2,4,8 };   // for power
	for (int i = 0; i < 7; i++)
	{
		//making link list
		Add_Node_X(Arr1[i],Arr2[i]);
	}
	cout << endl;
	cout << "Linked List X is : " << endl;
	Traverse_X();

	int Arr3[7] = { 89,8,17,6,19,10,13 };   //for coeeficents
	int Arr4[7] = { 6,5,1,5,4,3,8 };   // for power
	for (int i = 0; i < 7; i++)
	{
		//making link list
		Add_Node_Y(Arr3[i], Arr4[i]);
	}
	cout << endl;
	cout << "Linked List Y is : " << endl;
	Traverse_Y();


	int n;
	cout << endl;
	cout << "Enter 1) Addition : " << endl;
	cout << "Enter 2) Subtraction : " << endl;
	cout << "Enter 3) Multiplication : " << endl;
	do
	{
		cout << "Enter : ";
		cin >> n;
	} while (n != 1 && n != 2 && n != 3);
	Mathematical_Operations(n);
	Traverse_Z();

	system("pause>NULL");
	return 0;
}