/*GROUP MINI PROJECT
GROUP NO:25
PROJECT : UNIVERSITY SEMESTER EXAM RESULTS MANAGEMENT SYSTEM
DATE    : 06/07/2022
*/

#include <iostream>
#include"Singlylinkedlist.h"
using namespace std;

	// Driver code
int main()
{
	cout << "\n\t\t\t *------------------------------------------------------*" << endl;
	cout << "\n\t\t\t |  UNIVERSITY SEMESTER EXAM RESULTS MANAGEMENT SYSTEM  |" << endl;
	cout << "\n\t\t\t | DEPARTMENT OF ELECTRICAL AND INFORMATION ENGINEERING |" << endl;
	cout << "\n\t\t\t *------------------------------------------------------*\n" << endl;

	cout << " \nModules : " << endl;
	cout << " \tEE 3301-Analog Electronics" << endl;
	cout << " \tEE 3302-Data Structures and Algorithms" << endl;
	cout << " \tEE 3203-Electrical and Electronic Measurements" << endl;
	cout << " \tEE 3304-Power Systems I" << endl;
	cout << " \tEE 3305-Signals and Systems\n" << endl;

	cout << "\n -------------------------------------------------------------------------\n" << endl;

	head = NULL;
	string Name;
	int Index, Marks1,Marks2,Marks3,Marks4,Marks5;


	// Menu-driven program
	while (true) {
		
		cout << " \nPress : " << endl;
		cout << " \t1: Create a New Record" << endl;
		cout << " \t2: Delete a Student Record" << endl;
		cout << " \t3: Search a Student Record" << endl;
		cout << " \t4: View all Students Record" << endl;
		cout << " \t5: Exit from System" << endl;
		cout << " \nEnter your Choice : ";
		int Choice;

		// Enter Choice
		cin >> Choice;
		if (Choice == 1) {
			cout << "\n\tEnter Name of Student         : ";
			cin >> Name;
			cout << "\tEnter Index Number of Student : ";
			cin >> Index;
			cout << "\tEnter EE3301 marks            : ";
			cin >> Marks1;
			cout << "\tEnter EE3302 marks            : ";
			cin >> Marks2;
			cout << "\tEnter EE3203 marks            : ";
			cin >> Marks3;
			cout << "\tEnter EE3304 marks            : ";
			cin >> Marks4;
			cout << "\tEnter EE3305 marks            : ";
			cin >> Marks5;
			
			 
			Insert_Record(Index, Name, Marks1, Marks2, Marks3, Marks4, Marks5);
		}
		else if (Choice == 2) {
			cout << "\nEnter Index Number of Student whose "
				"record is to be deleted : ";
			cin >> Index;
			Delete_Record(Index);
		}
		else if (Choice == 3) {
			cout << "\nEnter Index Number of Student whose "
				"record you want to Search : ";
			cin >> Index;
			Search_Record(Index);
		}
		else if (Choice == 4) {
			Show_Record();
		}
		else if (Choice == 5) {
			exit(0);
		}
		else {
			cout << "\nInvalid Choice "
				<< "Try Again\n";
		}
	}
	return 0;
}
