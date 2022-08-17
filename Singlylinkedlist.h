#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	int IndexNo;
	string Name;
	int Marks1;
	int Marks2;
	int Marks3;
	int Marks4;
	int Marks5;
	string Grade;
	Node* next;
};

Node* head = new Node();

// Check Function to check that if
// Record Already Exist or Not
bool check(int x)
{
	// Base Case
	if (head == NULL)
		return false;

	Node* t = new Node;
	t = head;

	// Traverse the Linked List
	while (t != NULL) {
		if (t->IndexNo == x)
			return true;
		t = t->next;
	}

	return false;
}

// Function to insert the record
void Insert_Record(int Index, string Name,
	int Marks1, int Marks2, int Marks3, int Marks4, int Marks5)
{
	// if Record Already Exist
	if (check(Index)) {
		cout << "Student with this "
			<< "record Already Exists\n";
		return;
	}

	// Create new Node to Insert Record
	Node* t = new Node();
	t->IndexNo = Index;
	t->Name = Name;
	//t->Dept = Dept;
	t->Marks1 = Marks1;
	t->Marks2 = Marks2;
	t->Marks3 = Marks3;
	t->Marks4 = Marks4;
	t->Marks5 = Marks5;
	t->next = NULL;


	// Insert at Begin
	if (head == NULL
		|| (head->IndexNo >= t->IndexNo)) {
		t->next = head;
		head = t;
	}

	// Insert at middle or End
	else {
		Node* c = head;
		while (c->next != NULL
			&& c->next->IndexNo < t->IndexNo) {
			c = c->next;
		}
		t->next = c->next;
		c->next = t;
	}

	cout << "\nRecord Inserted "
		<< "Successfully\n";
}

// Function to search record for any
// students Record with Index number
void Search_Record(int Index)
{
	// if head is NULL
	if (head == NULL) {
		cout << "\nNo such Record Available\n" << endl;
		return;
	}

	// Otherwise
	else {
		Node* p = head;
		while (p) { //While P is not NULL
			if (p->IndexNo == Index) {
				cout << "\tIndex Number :"
					<< p->IndexNo << endl;
				cout << "\tName : "
					<< p->Name << endl;
				cout << "\t\tEE3301 Marks : "
					<< p->Marks1 << endl;
				cout << "\t\tEE3302 Marks : "
					<< p->Marks2 << endl;
				cout << "\t\tEE3203 Marks : "
					<< p->Marks3 << endl;
				cout << "\t\tEE3304 Marks : "
					<< p->Marks4 << endl;
				cout << "\t\tEE3305 Marks : "
					<< p->Marks5 << endl;
				return;
			}
			p = p->next;
		}

		if (p == NULL)
			cout << "\nNo such Record "
			<< "Available\n";
	}
	cout << " " << endl;
}

// Function to delete record students
// record with given roll number
// if it exist
int Delete_Record(int Index)
{
	Node* t = head;
	Node* p = NULL;

	// Deletion at Begin
	if (t != NULL
		&& t->IndexNo == Index) {
		head = t->next;
		delete t;

		cout << "\nRecord Deleted "
			<< "Successfully\n";
		return 0;
	}

	// Deletion Other than Begin
	while (t != NULL && t->IndexNo != Index) {
		p = t;
		t = t->next;
	}
	if (t == NULL) {
		cout << "\nRecord does not Exist\n";
		return -1;
		p->next = t->next;

		delete t;
		cout << "\nRecord Deleted "
			<< "Successfully\n";

		return 0;
	}
}

// Function to display the Student's
// Record
void Show_Record()
{
	Node* p = head;
	if (p == NULL) {
		cout << "No Record "
			<< "Available\n";
	}
	else {
		cout << "\n\tIndex\tName\tEE3301"
			<< "\t\tEE3302\t\tEE3203\t\tEE3304\t\tEE3305\t\tGPA\n\n";

		// Until p is not NULL
		//int *arr3;
		//arr3 = new int[5];

		int credit[5] = { 3,3,2,3,3 };


		while (p != NULL) {
			int arr[5] = { p->Marks1,p->Marks2,p->Marks3,p->Marks4,p->Marks5 };
			double sum = 0;
			cout << "\t" << p->IndexNo << " \t"
				<< p->Name << "\t";
			for (int i = 0; i < 5; i++)
			{
				int Marks;
				Marks = arr[i];
				double x;


				if (0 > Marks || Marks > 100) {
					p->Grade = "Invalid Marks";
				}
				else if (Marks >= 85) {
					p->Grade = "A+";
					x = 4.0;
				}
				else if (Marks >= 75) {
					p->Grade = "A";
					x = 4.0;
				}
				else if (Marks >= 70) {
					p->Grade = "A-";
					x = 3.7;
				}
				else if (Marks >= 65) {
					p->Grade = "B+";
					x = 3.3;
				}
				else if (Marks >= 60) {
					p->Grade = 'B';
					x = 3.0;
				}
				else if (Marks >= 55) {
					p->Grade = "B-";
					x = 2.7;
				}
				else if (Marks >= 50) {
					p->Grade = "C+";
					x = 2.3;
				}
				else if (Marks >= 45) {
					p->Grade = "C";
					x = 2.0;
				}
				else if (Marks >= 40) {
					p->Grade = "C-";
					x = 1.7;
				}
				else {
					p->Grade = "E";
					x = 0.0;
				}

				sum += (x * credit[i]);
				cout << p->Grade << "\t\t";

			}

			double GPA = sum / double(14);
			cout << GPA << endl;

			p = p->next;

		}
	}
}
