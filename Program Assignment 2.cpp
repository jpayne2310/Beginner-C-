/*
Program Assignment 2
James Payne
SE 114.01

Purpose:  To calculate mileage expenses for the company sales force. The program will ask the user to enter the beginning and ending mileage submitted by sales people.  It will then calculate and display the mileage exspense.

Variable Dictionary

Varible Name			Type			Repersents
beginning_mileage		intreger		beginning mileage
cost_per_mile			double			cost per mile
ending_mileage			intreger		ending mileage
mileage_expense			double			mileage expense
miles_traveled			intreger		miles traveled
salesman_name			string			name of salesman

*/

#include <iostream>
#include <string>
using namespace std;

int beginning_mileage, ending_mileage, miles_traveled;
double cost_per_mile, mileage_expense;
string salesman_name;

int main()
{
	system ("cls");
	cout << endl;
	cout << "Please enter:" << endl;
	cout << endl;
	cout << endl;
	cout << "	Salesman name:==================>";
	cin >> salesman_name;
	cout << "	Beginning Mileage===============>";
	cin >> beginning_mileage;
	cout << "	Ending Mileage==================>";
	cin >> ending_mileage;

	miles_traveled = ending_mileage-beginning_mileage;
	cost_per_mile = .42;
	mileage_expense = miles_traveled*cost_per_mile;

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Salesman ";
	cout << salesman_name;
	cout << " traveled " << miles_traveled;
	cout << " miles and will be reimbursed $" << mileage_expense;
	cout << endl;
	cout << endl;
	system ("pause");
	return 0;
}
