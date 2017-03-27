/*
Programming Assignment 9
James Payne
SE 114.01

Purpose: To process traffic violations for the Providence Police Department.  The program will use inputted 
information to put together a traffic citation report for people that have been issued a moving or 
nonmoving traffic violation.  Individual summaries will be generated with the name of the offender and the
amount they have been assessed.  There will also be a check for previous violations with penalties added 
for habitual offenders.  Once all records have been entered a summary totaling all citations will be
display for review.

Variable Dictionary:

Variable Name							Type				Represents
fine_assessed							double				amount of fine assessed
first_name								string				first name of violator
first_run								character			program initiator
increment_amount						integer				amount to increment by
last_name								string				last name of violator
maximum_previous_violations				integer				maximum amount of previous violations allowed
moving_violation_fine					double				declared fine amount
non-moving_violation_fine				double				declared fine amount
non_penalty_rate						integer				rate for non-penalty
penalty_assessed						double				penalty assessed
penalty_rate							double				amount of penalty
pervious_violations						integer				number of previous violations
response_y_n							character			Y for yes N for no
total_amount_assessed					double				total dollar amount assessed
total_citation							double				total dollar amount of individual citation
total_fines_assessed					double				total dollar amount of assessed fines
total_moving_violations_processed		integer				total number of moving violations processed
total_non_moving_violations_processed	integer				total number of non-moving violations processed
total_penalties_assessed				double				total dollar amount of assessed penalties
total_tickets_processed					integer				total number of tickets processed
violation_type							character			violation defined

*/

#include <iostream>
#include <string>
using namespace std;

char first_run = 'Y', response_y_n, violation_type;								//declared variables
double fine_assessed, moving_violation_fine, non_moving_violation_fine, penalty_assessed, penalty_rate, 
	total_amount_assessed, total_citation, total_fines_assessed, total_penalties_assessed;
int incerment_amount, maximum_previous_violations, non_penalty_rate, previous_violations, 
	total_moving_violations_processed, total_non_moving_violations_processed, total_tickets_processed;
string first_name, last_name;

void setup ();																	//declared functions
void input ();
void process_results ();
void output_totals ();

int main ()
{
	cout << "Traffic Citation Report." << endl;									//check to see if
	cout << "Is this the application you would like to run? Y or N: ";			//application is to be ran
	cin >> response_y_n;
	response_y_n = toupper(response_y_n);

	while (response_y_n != 'Y' && response_y_n != 'N')							//validate response
	{
		cout << "Incorrect response." << endl;
		cout << "Enter a 'Y' for Yes or a 'N' for No: ";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}

	while (response_y_n == 'Y')													//initiate main while loop
	{
		if (first_run == 'Y')													//check first_run
		{
			setup ();
			first_run = 'N';
		}

		input ();																//call input
		process_results ();														//call process_results

		cout << "Would you like to enter another record? Y or N: ";				//check to see if another
		cin >> response_y_n;													//record is to be entered
		response_y_n = toupper(response_y_n);
	}

	if (first_run == 'N')
	{
		output_totals ();														//call output_totals
	}
system ("pause");
return 0;																		//end
}
void setup ()
{
	incerment_amount = 1;
	moving_violation_fine = 200;												//values for changing 
	non_moving_violation_fine = 100;											//variables and starting
	non_penalty_rate = 0;														//totals set
	penalty_assessed = 0;
	penalty_rate = 50;
	maximum_previous_violations = 3;
	total_amount_assessed = 0;
	total_fines_assessed = 0;
	total_moving_violations_processed = 0;
	total_non_moving_violations_processed = 0;
	total_penalties_assessed = 0;
	total_tickets_processed = 0;

	cout.setf(ios::fixed, ios::floatfield);										//format for output set
	cout.setf(ios::showpoint);
	cout.precision(2);

}
void input ()
{
	system("cls");
	cout << "Please enter the following information for the citation record:" << endl;
	cout << "Last Name: ";														//get and assign user input
	cin >> last_name;
	cout << "First Name: ";
	cin >> first_name;
	cout << "Enter 'M' for Moving Violation or 'N' for Non-moving violation: ";	
	cin >> violation_type;
	violation_type = toupper(violation_type);

	while (violation_type != 'M' && violation_type != 'N')						//validate response
	{
		cout << "Incorrect response." << endl;
		cout << "Enter 'M' for Moving Violation or 'N' for Non-moving violation: ";
		cin >> violation_type;
		violation_type = toupper(violation_type);
	}
	cout << "Number of previous violations: ";
	cin >> previous_violations;

}
void process_results ()
{
	total_tickets_processed = total_tickets_processed + incerment_amount;	//tracking number of tickets
	if (violation_type == 'M')												//determine violation amount
	{
		total_moving_violations_processed = total_moving_violations_processed + incerment_amount;
		fine_assessed = moving_violation_fine;

	}
	else
	{
		total_non_moving_violations_processed = total_non_moving_violations_processed + incerment_amount;
		fine_assessed = non_moving_violation_fine;
	}
	total_fines_assessed = total_fines_assessed + fine_assessed;			//total amount of fines

	if (previous_violations <= maximum_previous_violations)					//previous violations checked
	{
		penalty_assessed = non_penalty_rate;
	}
	else
	{
		penalty_assessed = penalty_rate;
		total_penalties_assessed = total_penalties_assessed + penalty_assessed;	//total amount of penalties
	}
	total_citation = fine_assessed + penalty_assessed;
	total_amount_assessed = total_amount_assessed + total_citation;				//total amount assessed
	cout << first_name << " " << last_name << " has been assessed a " << fine_assessed << " fine and " 
		<< penalty_assessed << " penalty." << endl;								//individual record printed
	cout << "Total due " << total_citation << endl;
}
void output_totals ()
{
	system("cls");																//totals printed for 
	cout << "Total tickets processed " << total_tickets_processed << endl;		//citation report
	cout << "Total moving violations processed " << total_moving_violations_processed << endl;
	cout << "Total non-moving violations processed " << total_non_moving_violations_processed << endl;
	cout << "Total Fines assessed " << total_fines_assessed << endl;
	cout << "Total penalties assessed " << total_penalties_assessed << endl;
	cout << "Total amount assessed " << total_amount_assessed << endl;
}