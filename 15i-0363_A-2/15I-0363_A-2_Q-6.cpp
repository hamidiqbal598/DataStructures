//------------------------
//Name: Hamid Iqbal and Talha Shafique
//Roll NO: i15-0363 and f15-8103
//Section: A (DS-Summer)
//Assignment-2 Question-6
//------------------------

#pragma once

#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

struct passenger
{
	char name[20];
	int waiting; // how many minutes the person has been waiting
	struct passenger *next;
};

struct train {
	int id; // id number of the train
	int pos; // position on track in km
	struct train *next; // a pointer to the next train
};



struct passenger* make_passenger(char *Pr_name);
void insert_passenger_after(struct passenger *Pr, struct passenger *new_Pr);
int num_passengers(struct passenger *first_Pr);
void print_passenger(struct passenger *Pr);
void print_passenger_list(struct passenger *first_Pr);
void remove_first_passenger(struct passenger **Pr);
void clear_passenger_list(struct passenger **first_Pr);
void increment_passenger_list(struct passenger *first_Pr);
double average_passenger_list(struct passenger *first_Pr);

int contains_train_id(struct train *first_Tr, int value);
struct train* make_train(int iden, int position);
void prepend_train(struct train **first_Tr, struct train *new_Tr);
void print_train(struct train *Tr);
void print_trains(struct train *first_Tr);
int can_advance(struct train *current_Tr, int passengers_on_platform);
void advance_train(struct train *current_Tr, int passengers_on_platform);
int num_trains(struct train *first_Tr);
double avg_train_dist(struct train *first_Tr);
void remove_train_after(struct train *Tr);
void clear_all_trains(struct train **first_Tr);
struct train* get_last_train(struct train *first_Tr);
int train_at_position(struct train *first_Tr, int pos);

struct passenger* make_passenger(char *Pr_name)
{
	passenger *Temp = new passenger;
	strcpy_s(Temp->name, Pr_name);
	Temp->waiting = 0;
	Temp->next = NULL;
	return Temp;
}
int num_passengers(struct passenger *first_Pr)
{
	int count = 0;
	while (first_Pr != NULL)
	{
		first_Pr = first_Pr->next;
		count++;
	}
	return count;
}
void print_passenger(struct passenger *Pr)
{
	if (Pr == NULL)
	{
		cout << "Error Bcz it is NULL" << endl;
	}
	else
	{
		cout << Pr->waiting << "   " << Pr->name << endl;
	}
}
void print_passenger_list(struct passenger *first_Pr) 
{
	if (first_Pr == NULL)
	{
		cout << "Error Bcz List is Empty" << endl;
	}
	while (first_Pr != NULL)
	{
		cout << "Waiting time : " << first_Pr->waiting <<" Names : "<<first_Pr->name<< endl;
		first_Pr = first_Pr->next;
	}
}
void insert_passenger_after(struct passenger *Pr, struct passenger *new_Pr) 
{
	if (Pr == NULL || new_Pr == NULL)
	{
		cout << "Error Bcz one of them is NULL " << endl;
	}
	else
	{
		new_Pr->next = Pr->next;
		Pr->next = new_Pr;
		
	}
}
void remove_first_passenger(struct passenger **Pr) 
{
	if (Pr == NULL)
	{
		cout << "Error Bcz one of them is NULL " << endl;
	}
	else
	{

	}
}
//
//void clear_passenger_list(struct passenger **first_Pr) {
//}
//
void increment_passenger_list(struct passenger *first_Pr) 
{
	if (first_Pr == NULL)
	{
		cout << "Error Bcz one of them is NULL " << endl;
	}
	else
	{
		while (first_Pr != NULL)
		{
			first_Pr->waiting = first_Pr->waiting + 1;
			first_Pr = first_Pr->next;
		}
	}
}
double average_passenger_list(struct passenger *first_Pr) 
{
	if (first_Pr == NULL)
	{
		cout << "Error Bcz one of them is NULL " << endl;
		return -1;
	}
	else
	{
		int sum = 0;
		int count = 0;
		while (first_Pr != NULL)
		{
			first_Pr->waiting = first_Pr->waiting + sum;
			first_Pr = first_Pr->next;
			count += 1;
		}
		sum = sum / count;
	}
}
//
//int contains_train_id(struct train *first_Tr, int value) {
//}
//
//struct train* make_train(int iden, int position) {
//}
//void prepend_train(struct train **first_Tr, struct train *new_Tr) {
//}
//
//void print_train(struct train *Tr) {
//	// This method is provided to students.
//	// Prints a single train, and what it points to (if it points to another train)
//	cout << "\nTrain # " << Tr->id << " at " << Tr->pos;
//	if (Tr->next)
//	{
//		cout << "\ --->Next Train # is " << Tr->next->id << " at " << Tr->next->pos;
//	}
//	cout << "\n";
//}
//void print_trains(struct train *first_Tr) {
//}
//
//int can_advance(struct train *current_Tr, int passengers_on_platform) {
//}
//void advance_train(struct train *current_Tr, int passengers_on_platform) {
//}
//int num_trains(struct train *first_Tr) {
//}
//double avg_train_dist(struct train *first_Tr) {
//}/*
//	else
//		return 0;*/
////}
//void remove_train_after(struct train *Tr) {
//}
//void clear_all_trains(struct train **first_Tr) {
//}
//
//struct train* get_last_train(struct train *first_Tr) {}
//
//int train_at_position(struct train *first_Tr, int pos)
//{
//	// Returns 1 iff there exists a train at position pos (given to students)
//	// PRE: none
//	// POST: none
//	struct train *curr = first_Tr;
//	int contains_pos = 0;
//	while (curr)
//	{
//		if (curr->pos == pos)
//		{
//			return 1;
//		}
//		curr = curr->next;
//	}
//	return contains_pos;
//}