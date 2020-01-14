//------------------------
//Name: Hamid Iqbal and Talha Shafique
//Roll NO: i15-0363 and f15-8103
//Section: A (DS-Summer)
//Assignment-6 Graph Assignment
//------------------------


#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct node;
struct edge;
struct node
{
	string name;
	node *next;
	edge *EHead;
	edge *ETail;
}*head, *tail;
struct edge
{
	string next_name;
	double length;
	edge *nextEdge;
};
void Add_NewCity(string name) 
{
	node *ptr = new node;
	ptr->name = name;
	ptr->next = NULL;
	ptr->EHead = NULL;
	ptr->ETail = NULL;
	if (head) 
	{
		tail->next = ptr;
		tail = ptr;
	}
	else
	{
		head = ptr;
		tail = head;
	}
}
void Add_EdgeCity(string name, string next_name, double cost)
{
	edge *Edge = new edge;
	Edge->next_name = next_name;
	Edge->nextEdge = NULL;
	Edge->length = cost;

	node *ptr = head;
	while (ptr->name != name)
	{
		ptr = ptr->next;
	}

	if (ptr->EHead) 
	{
		ptr->ETail->nextEdge = Edge;
		ptr->ETail = Edge;
	}
	else 
	{
		ptr->EHead = Edge;
		ptr->ETail = ptr->EHead;
	}
}

void Traverse()
{
	node *ptr = head;
	int k = 1;
	while (ptr != NULL)
	{
		edge *edg = ptr->EHead;
		cout << endl << "======================:::TRAVERSE:::=====================" << endl;
		cout << "Country " << k << " with name is : " << ptr->name << endl;
		k++;
		int i = 1;
		while (edg != NULL)
		{
			cout << "Neighbour country " << i << " is : " << edg->next_name << " with Boarder length : " << edg->length << endl;
			i++;
			edg = edg->nextEdge;
		}
		ptr = ptr->next;
	}
}
void filing()
{
	ifstream out;
	out.open("countries.dat");
	string line, name = "";
	int len, k;
	//for (int i = 0; i<279; i++)
	while(!out.eof())
	{
		getline(out, line);
		//cin.ignore();
		len = line.length();
		k = 0;
		name = "";
		while (k < len && line[k + 1] != '>')
		{
			name = name + line[k];
			k++;
		}
		Add_NewCity(name);
		int j = k + 4;
		while(j < len)
		{
			bool flag = false;
			string next_name = "";
			string dis = "";
			while (line[j] != ';' && j < len)
			{
				if (flag == false && line[j] != ':')
				{
					next_name = next_name + line[j];
				}
				else if (flag == true)
				{
					dis = dis + line[j];
				}
				else
				{
					j++;
					flag = true;
				}
				j++;
			}
			double distance, len = dis.length(), temp = 0;
			string acc_dis="";
			while (temp < len && dis[temp] != ' ')
			{
				if (dis[temp] != ',')
				{
					acc_dis = acc_dis + dis[temp];
				}
				temp++;
			}
			if (acc_dis != "")
			{
				distance = stod(acc_dis);
			}
			else
			{
				distance = 0;
			++}
			j = j + 2;
			Add_EdgeCity(name,next_name, distance);
		}
	}
}

void Add_Country_Neighbour()
{
	int choice;
	cout << endl;
	cout << "For Addition of City or its Neighbour ::-" << endl;
	cout << "1) For Adding city : " << endl;
	cout << "2) For Adding Neighbour : " << endl;
	do
	{
		cout << "Enter : ";
		cin >> choice;
		cin.ignore();
	} while (choice != 1 && choice != 2);
	string name;
	if (choice == 1)
	{
		cout << "Enter city name : ";
		getline(cin, name);
		Add_NewCity(name);
	}
	else
	{
		string next_name;
		double length;
		cout << "Enter starting city name : ";
		getline(cin, name);
		node *ptr = head;
		while (ptr != NULL && ptr->name != name)
		{
			ptr = ptr->next;
		}
		if (ptr == NULL)
		{
			cout << "You enter Invalid name ;( " << endl;
		}
		else
		{
			cout << "Enter neighbour city name : ";
			getline(cin, next_name);
			cout << "Enter Length between two cities : ";
			cin >> length;
			cin.ignore();
			Add_EdgeCity(name, next_name, length);
		}
	}
}
void Delete_Country_Neighbour()
{
	int choice;
	cout << endl;
	cout << "For Deletion of City or its Neighbour ::-" << endl;
	cout << "1) For Deleting city : " << endl;
	cout << "2) For Deleting Neighbour edge : " << endl;
	do
	{
		cout << "Enter : ";
		cin >> choice;
		cin.ignore();
	} while (choice != 1 && choice != 2);
	string name;
	if (choice == 1)
	{
		cout << "Enter city name : ";
		getline(cin, name);
		node *ptr = head;
		node *temp = head;
		bool flag = true;
		while (ptr != NULL && ptr->name!=name)
		{
			temp = ptr;
			ptr = ptr->next;
		}
		if (ptr == NULL)
		{
			cout << "NOT Found : " << endl;
		}
		if (ptr == head)
		{
			head = head->next;
		}
		else
		{
			temp->next = ptr->next;
		}
		delete ptr;
		choice = 3;
	}
	else
	{
		string next_name;
		cout << "Enter city name : ";
		getline(cin, name);
		cout << "Enter Neighbour city name : ";
		getline(cin, next_name);
		node *ptr = head;
		while (ptr->next != NULL && ptr->name != name)
		{
			ptr = ptr->next;
		}
		if (ptr->name == name)
		{
			edge *ptr1 = ptr->EHead;
			edge *temp1 = ptr->EHead;
			while (ptr1 != NULL && ptr1->next_name != next_name)
			{
				temp1 = ptr1;
				ptr1 = ptr1->nextEdge;
			}
			if (ptr1 == NULL)
			{
			}
			else if (ptr1 == ptr->EHead)
			{
				ptr->EHead = ptr->EHead->nextEdge;
			}
			else
			{
				temp1->nextEdge = ptr1->nextEdge;
			}
			delete ptr1;
		}
		else
		{
			cout << "Not Found Distint City : " << endl;
		}

		//remaining

	}
	if(choice == 3)
	{
		node *ptr = head;
		while (ptr->next != NULL)
		{
			edge *ptr1 = ptr->EHead;
			edge *temp1 = ptr->EHead;
			while (ptr1 != NULL && ptr1->next_name != name)
			{
				temp1 = ptr1;
				ptr1 = ptr1->nextEdge;
			}
			if (ptr1 == NULL)
			{
			}
			else if (ptr1 == ptr->EHead)
			{
				ptr->EHead = ptr->EHead->nextEdge;
			}
			else
			{
				temp1->nextEdge = ptr1->nextEdge;
			}
			delete ptr1;
			ptr = ptr->next;
		}
	}
}

void Shortest_path()
{
	string name,next_name;
	cout << "Enter Starting Location : " << endl;
	cout << "Starting City name : ";
	getline(cin,name);
	cout << "Ending City name : ";
	getline(cin, next_name);
	string names[282];
	node *ptr = head;
	int size = 0, loc_start = 0, loc_end = 0;
	while (ptr != NULL)
	{
		if (ptr->name == name)
		{
			loc_start = size;
		}
		if (ptr->name == next_name)
		{
			loc_end = size;
		}
		names[size] = ptr->name;
		ptr = ptr->next;
		size++;
	}
	size--;
	int **Directive = new int*[size];
	int **Path = new int*[size];
	for (int i = 0; i < size; i++)
	{
		Directive[i] = new int[size];
		Path[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			Directive[i][j] = 10000;
			Path[i][j] = -1;
		}
	}
	node *ptr1 = head;
	int i = 0, j = 0;
	int tt = 0;
	while (ptr1->next != NULL)
	{
		j = 0;
		edge *edg1 = ptr1->EHead;
		while (edg1 != NULL)
		{
			for (int k = 0; k < 279; k++)
			{
				if (i == k)
				{
					Directive[i][k] = 0;
				}
				else if (names[k] == edg1->next_name)
				{
					Directive[i][k] = edg1->length;
					if (tt < edg1->length)
					{
						tt = edg1->length;
					}
				}
			}
			edg1 = edg1->nextEdge;
		}
		i++;
		ptr1 = ptr1->next;
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			for (int k = size - 1; k >= 0; k--)
			{
				if (j != k && i != k)
				{
					if (Directive[j][k] > Directive[i][k] + Directive[j][i])
					{
						Directive[j][k] = Directive[i][k] + Directive[j][i];
						Path[j][k] = i;
					}
				}
			}
		}
	}
	///*for (int i = 0; i < 50; i++)
	//{
	//	cout << "Country name : " << names[i] << endl;
	//	for (int j = 0; j < 50; j++)
	//	{
	//		cout << Directive[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//*/
	//cout << endl << endl;
	//for (int i = 0; i < 50; i++)
	//{
	//	for (int j = 0; j < 50; j++)
	//	{
	//		cout << Path[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	bool fl1 = true;
	cout << "Our Shortest Path is : "<<endl;
	cout << "Path is :- " << names[loc_start] << " -- ";
	do
	{
		if (Path[loc_start][loc_end] == -1)
		{
			fl1 = false;
		}
		else
		{
			int temp = Path[loc_start][loc_end];
			cout << names[temp] << " -- ";;
			loc_start = temp;
		}
	} while (fl1);
	cout << names[loc_end] << endl;;
}
void size_Neighbours()
{
	int size;
	cout << "Size For Comparison Number of Neighbours ::- " << endl;
	cout << "Enter the size : ";
	cin >> size;
	cout << "Countries with " << size << " Neighbours are : " << endl;
	
	node *ptr = head;
	while (ptr != NULL)
	{
		bool flag = false;
		edge *edg = ptr->EHead;
		int i = 0;
		while (edg != NULL)
		{
			i++;
			edg = edg->nextEdge;
		}
		if (i == size)
		{
			cout << endl << "===================:::SIZE EQUALITY:::===================" << endl;
			cout << "Country name is : " << ptr->name << endl;
			edg = ptr->EHead;
			int k = 1;
			while (edg != NULL)
			{
				cout << "Neighbour country " << k << " is : " << edg->next_name << " with Boarder length : " << edg->length << endl;
				k++;
				edg = edg->nextEdge;
			}
		}
		ptr = ptr->next;
	}
}
void Boarder()
{
	int length;
	cout << "Boarder Length Greater Finding ::- " << endl;
	cout << "Enter the borders length : ";
	cin >> length;

	node *ptr = head;
	while (ptr != NULL)
	{
		bool flag = false;
		edge *edg = ptr->EHead;
		while (edg != NULL)
		{
			if (edg->length > length)
			{
				flag = true;
			}
			edg = edg->nextEdge;
		}
		if (flag)
		{
			cout << endl << "==================:::BOARDER LENGTH:::===================" << endl;
			cout <<"Country name is : "<< ptr->name << endl;
			edg = ptr->EHead;
			int i = 0;
			while (edg != NULL)
			{
				cout << "Neighbour country " << i << " is : " << edg->next_name << " with Boarder length : " << edg->length << endl;
				i++;
				edg = edg->nextEdge;
			}
		}
		ptr = ptr->next;
	}
}
int main()
{
	
	filing();  //Most Important thing....!!!!
	int choice;
	bool flag = true;
	do
	{
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "1) Add country/city or neighbors of country/city : " << endl;
		cout << "2_ Delete either the Country or neighbor of a country : " << endl;
		cout << "3) List all countries and bordering countries : " << endl;
		cout << "4) Find shortest path : " << endl;
		cout << "5) List all countries with X neighbors : " << endl;
		cout << "6) Find countries with borders larger than X km : " << endl;
		cout << "7) For Exit ...;( " << endl;
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << endl;
		do
		{
			cout << "Enter : ";
			cin >> choice;
			cin.ignore();
		} while (choice < 1 || choice>7);
		if (choice == 1)
		{
			cout << "----------------------------------------------------------" << endl;
			Add_Country_Neighbour();
			cout << "----------------------------------------------------------" << endl << endl;;
		}
		else if (choice == 2)
		{
			cout << "----------------------------------------------------------" << endl;
			Delete_Country_Neighbour();
			cout << "----------------------------------------------------------" << endl << endl;;
		}
		else if (choice == 3)
		{
			cout << "----------------------------------------------------------" << endl;
			Traverse();
			cout << "----------------------------------------------------------" << endl << endl;;
		}
		else if (choice == 4)
		{
			cout << "----------------------------------------------------------" << endl;
			Shortest_path();
			cout << "----------------------------------------------------------" << endl << endl;;
		}
		else if (choice == 5)
		{
			cout << "----------------------------------------------------------" << endl;
			size_Neighbours();
			cout << "----------------------------------------------------------" << endl << endl;
		}
		else if (choice == 6)
		{
			cout << "----------------------------------------------------------" << endl;
			Boarder();
			cout << "----------------------------------------------------------" << endl << endl;;
		}
		else if (choice == 7)
		{
			cout << "---------------------------------------------" << endl;
			cout << "-----::  GOOD - BYE  ::------" << endl;
			cout << "---------------------------------------------" << endl;
			flag = false;
		}

	} while (flag);

	cout << "" << endl;
		
		
		
	system("pause>NULL");
	return 0;
}