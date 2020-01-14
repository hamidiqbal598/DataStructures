//-------------------------------------
//Name: Hamid Iqbal and Talha Shafique
//Roll NO: i15-0363 and f15-8103
//Section: A (DS-Summer)
//Assignment-5  Hash Table Assignment
//-------------------------------------


#include<iostream>
#include<string>
#include<fstream>
#include<math.h>
#include<cmath>
#define PI 3.141592
using namespace std;

struct AdjListNode
{
	int zip_code;
	double longitude;
	double lattitude;
	AdjListNode* next;
};
struct AdjList
{
	AdjListNode *head = NULL;
	AdjListNode *tail = NULL;
};
AdjList *add_edge(AdjList *arr, int src, int zip, double longitude, double lattitude)
{
	AdjListNode *node = new AdjListNode;
	node->zip_code = zip;
	node->longitude = longitude;
	node->lattitude = lattitude;

	node->next = NULL;
	if (arr[src].head == NULL)
	{
		arr[src].head = arr[src].tail = node;
	}
	else
	{
		arr[src].tail->next = node;
		arr[src].tail = arr[src].tail->next;
	}
	return arr;
}

void display(AdjList *arr, int size)
{
	AdjListNode *temp;
	for (int i = 0; i < size; i++)
	{
		cout <<"For "<< i << " Vertice adjacency list is : " << endl;
		temp = arr[i].head;
		while (temp != NULL)
		{
			cout << " [" << temp->zip_code << "]  {" << temp->longitude << "} [" << temp->lattitude << "] " << endl;
			temp = temp->next;
		}
		cout << endl;
		temp = NULL;
	}
}
int Heap_function(int src)
{
	src = src % 10;
	return src;
}
void fileing(AdjList *arr)
{
	ifstream in;
	in.open("zipcodes-assignment5.CSV");
	string str, temp;
	int j = 0;
	while(!in.eof())
	{
		in >> str;   //501,40.81,53.89
		int len = str.length();
		j = 0;
		while (str[j] != ',')
		{
			temp = temp + str[j];
			j++;
		}
		int zip = stoi(temp);

		j++;
		temp = "";
		while (str[j] != ',')
		{
			temp = temp + str[j];
			j++;
		}
		double longitude = stod(temp);

		temp = "";
		j++;
		while (j != len)
		{
			temp = temp + str[j];
			j++;
		}
		double lattitude = stod(temp);
		temp = "";

		int src = Heap_function(zip);
		add_edge(arr, src, zip, longitude, lattitude);
	}
}
void New_Entry(AdjList *arr)
{
	AdjListNode *node = new AdjListNode;
	cout << "Entry Zip code for new entry : ";
	cin >> node->zip_code;
	cout << "Entry longitude for new entry : ";
	cin>>node->longitude;
	cout << "Entry lattitude for new entry : ";
	cin >> node->lattitude;
	int src = Heap_function(node->zip_code);
	add_edge(arr, src, node->zip_code, node->longitude, node->lattitude);
	
	ofstream out;
	out.open("zipcodes-assignment5.CSV" , ios::app);
	string s1, s2, s3, s4;
	s1 = to_string(node->zip_code);
	s2 = to_string(node->longitude);
	s3 = to_string(node->lattitude);
	s4 = s1 + "," + s2 + "," + s3;
	out << s4 << endl;
}
void Get_Values(AdjList *arr,int size)
{
	int code;
	cout << "Enter Zip-code value for search : " << endl;;
	cout << "Enter : ";
	cin >> code;

	AdjListNode *temp;
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		temp = arr[i].head;
		while (temp != NULL)
		{
			if (temp->zip_code == code)
			{
				cout << " ---: Value is Found :----" << endl;
				cout << " Details are :  [" << temp->zip_code << "]  {" << temp->longitude << "} [" << temp->lattitude << "] " << endl;
				i = size;
				flag = true;
			}
			temp = temp->next;
		}
		temp = NULL;
	}
	if (flag == false)
	{
		cout << " ---: Ooops Data is not Found :----" << endl;
	}
}
void Avg_Length(AdjList *arr, int size)
{
	int *array = new int[size];
	AdjListNode *temp;
	int loop;
	for (int i = 0; i < size; i++)
	{
		loop = 0;
		temp = arr[i].head;
		while (temp != NULL)
		{
			loop++;
			temp = temp->next;
		}
		array[i] = loop;
		temp = NULL;
	}
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		cout << "Length of Hast Table at position " << i << " is : " << array[i] << endl;
		sum = sum + array[i];
	}
	cout << "sum is : " << sum << endl;
	int avg = sum / size;
	cout << "Average length of Hash Table is : " << avg << endl;
}
void Alpha_Length(AdjList *arr, int size)
{
	double *array = new double[size];
	AdjListNode *temp;
	int loop;
	for (int i = 0; i < size; i++)
	{
		loop = 0;
		temp = arr[i].head;
		while (temp != NULL)
		{
			loop++;
			temp = temp->next;
		}
		array[i] = loop;
		temp = NULL;
	}
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + array[i];
	}
	cout << "Sum is (n): " << sum << endl;
	cout << "Size is (m) : " << size << endl;
	double avg = sum / (size*1.0);
	cout << "Alpha value of Hash Table is : " << avg << endl;
}
void Distance(AdjList *arr, int size)
{

	int ch;
	int R = 0;
	cout << "1) For Distance in Kilometers : " << endl;
	cout << "2) For Distance in Miles : " << endl;
	do
	{
		cout << "Enter : ";
		cin >> ch;
	} while (ch != 1 && ch != 2);
	if (ch == 1)
	{
		R = 6373;
	}
	else if (ch == 2)
	{
		R = 3961;
	}

	int ch1;
	cout << "1) For Input Points of Longitude and Lattitude : " << endl;
	cout << "2) For Taking Points From Hash Table : " << endl;
	do
	{
		cout << "Enter : ";
		cin >> ch1;
	} while (ch1 != 1 && ch1 != 2);
	double Long1, Long2, Lat1, Lat2;
	if (ch1 == 1)
	{
		cout << "Enter Longitude for Point 1 : ";
		cin >> Long1;
		cout << "Enter Lattitude for Point 1 : ";
		cin >> Long2;
		cout << "Enter Longitude for Point 2 : ";
		cin >> Lat1;
		cout << "Enter Lattitude for Point 2 : ";
		cin >> Lat2;
	}
	else if (ch1 == 2)
	{
		int zip1, zip2;
		double Arr[2];
		cout << "Enter Zip-code for Search Longitude and Lattitude value from Hash Table : " << endl;
		cout << "Enter Zip-code for point 1 : " << endl;
		bool flag = false;
		do
		{
			cout << "Enter : ";
			cin >> zip1;
			AdjListNode *temp;
			for (int i = 0; i < size; i++)
			{
				temp = arr[i].head;
				while (temp != NULL)
				{
					if (temp->zip_code == zip1)
					{
						Long1 = temp->longitude;
						Lat1 = temp->lattitude;
						i = size;
						cout << Long1 << "  " << Lat1 << endl;
						flag = true;
					}
					temp = temp->next;
				}
				temp = NULL;
			}
		} while (!flag);

		flag = false;
		cout << "Enter Zip-code for point 2 : " << endl;
		do
		{
			cout << "Enter : ";
			cin >> zip2;
			AdjListNode *temp;
			for (int i = 0; i < size; i++)
			{
				temp = arr[i].head;
				while (temp != NULL)
				{
					if (temp->zip_code == zip2)
					{
						Long2 = temp->longitude;
						Lat2 = temp->lattitude;
						cout << Long2 << "  " << Lat2 << endl;
						i = size;
						flag = true;
					}
					temp = temp->next;
				}
				temp = NULL;
			}
		} while (!flag);
	}

	double D = 0.0;
	D = R * 2 * asin(sqrt(pow((sin(((Lat2 - Lat1) / 2)*PI / 180)), 2) + cos(Lat1*PI / 180) * cos(Lat2*PI / 180) *  pow(sin(((Long2 - Long1) / 2) *PI / 180), 2)) * 180 / PI);
	cout << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;;
	cout << "Distance Caluclated is : ";
	cout << D;
	if (ch == 1)
	{
		cout << " Kilometer " << endl;
	}
	else
	{
		cout << " Miles" << endl;
	}
	cout <<endl<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}
int main()
{
	int size = 10;
	AdjList *Arr = new AdjList[size];

	int choice;
	bool flag = false;
	cout << "---------------------------------------------------------------" << endl;
	cout << "---------------Enter To Hash Table Assignment------------------" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << endl;
	do
	{
		cout << endl;
		cout << "-----------------------------------------" << endl;
		cout << "1) New Entry in the table : " << endl;
		cout << "2) Get longitude and lattitude values : " << endl;
		cout << "3) Read CSV file and Enter them in Hast Table : " << endl;
		cout << "4) Press to view the Hash Table : " << endl;
		cout << "5) Print out the load Factor Alpha(@) : " << endl;
		cout << "6) Print out the average length of Linked list : " << endl;
		cout << "7) Distance calculated using Haversine Formula : " << endl;
		cout << "8) For Exit ;( : " << endl;
		cout << "-----------------------------------------" << endl << endl;;
		do
		{
			cout << "Enter : ";
			cin >> choice;
		} while (choice < 1 || choice > 8);
		cout << endl;
		if (choice == 1)
		{
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			New_Entry(Arr);
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		else if (choice == 2)
		{
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			Get_Values(Arr, size);
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		else if (choice == 3)
		{
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << endl << " File is Reading.........(Just wait a minute..)" << endl;
			fileing(Arr);
			cout << endl << " File is Readed :)  (Press 4 to view Hash Table)" << endl;
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		else if (choice == 4)
		{
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << endl << "Display of Hash Table is : " << endl;
			display(Arr, size);
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		else if (choice == 5)
		{
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << endl;
			Alpha_Length(Arr, size);
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		else if (choice == 6)
		{
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << endl;
			Avg_Length(Arr, size);
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		else if (choice == 7)
		{
			Distance(Arr, size);
		}
		else if (choice == 8)
		{
			flag = true;
			cout << endl << "  --: GOOD BYE :---" << endl;
		}
	} while (!flag);

	
	system("pause>NULL");
	return 0;
}