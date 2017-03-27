/*
Programming Assignment 8
James Payne
SE 114.01

Purpose: Credit report generator - program will generate a credit report of customer accounts based on user
inputted information. The generator will check customers spending to make sure they haven't exceeded the 
maximum credit limit, display account balance, and remaining credit available.  Once all customer 
information has been entered, the program will display a total summary of all processed accounts combine.

Variable Dictionary:

Variable Name							Type			Represents
available_credit_all_customers			double			total available credit for all customers
credit_maximum							double			maximum credit available for accounts
customer_account_balance				double			customer account balance
customer_account_number					integer			customer account number
customer_available_credit				double			customer available credit
customer_first_name						string			customer first names
customer_last_name						string			customer last name
customer_purchases						double			customer purchases
customer_new_account_balance			double			customer new account balance
exceeded_credit_limit					double			amount customer exceeded credit limit
first_run								character		program initionator
response_y_n							character		Y for yes N for no
total_balance_due_all_customers			double			total balance due from all customers
total_customers_processed				integer			total number of customers processed
total_purchases_all_customers			double			total amount of customer purchases

*/

#include <iostream>
#include <string>
using namespace std;

char first_run = 'Y', response_y_n;												//declared variables
double available_credit_all_customers, credit_maximum, customer_account_balance, 
	customer_available_credit, customer_new_account_balance, customer_purchases, 
	exceeded_credit_limit, total_balance_due_all_customers, 
	total_purchases_all_customers;
int customer_account_number, total_customers_processed;
string customer_first_name, customer_last_name;

void setup ();																	//declared functions
void input ();
void process_results ();
void output_totals ();

int main ()
{

	cout << "Would you like to generate a Credit Report? Y or N: ";				//check if program
	cin >> response_y_n;														//is to be ran
	response_y_n = toupper(response_y_n);

	while (response_y_n != 'Y' && response_y_n != 'N')							//validate response
	{
		cout << "Incorrect response." << endl;
		cout << "Enter a 'Y' for Yes or 'N' for No: ";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}

	while (response_y_n == 'Y')													//initiate credit
																				//report
	{
		if (first_run == 'Y')
		{
			setup ();															//call setup
			first_run = 'N';
		}

		input ();																//call input
		process_results ();														//call process results

		cout << "Would you like to enter another customer account? Y or N: ";	//check for another
		cin >> response_y_n;													//customer account
		response_y_n = toupper(response_y_n);
	}

	if (first_run == 'N')
	{
		output_totals ();														//call output_totals
	}
system ("pause");
return 0;
}

void setup ()
{
	customer_new_account_balance = 0;											//starting values set
	total_customers_processed = 0;
	total_balance_due_all_customers = 0;
	total_purchases_all_customers = 0;
	available_credit_all_customers = 0;
	credit_maximum = 1500.00;

	cout.setf(ios::fixed, ios::floatfield);										//output format set
	cout.setf(ios::showpoint);
	cout.precision(2);

}

void input ()
{
	system("cls");																//receive and assign
	cout << "Please enter the following information:" << endl;					//user enter data
	cout << "	Customer Account Number: ";
	cin >> customer_account_number;
	cout << "	Customer's Last Name: ";
	cin >> customer_last_name;
	cout << "	Customer's First Name: ";
	cin >> customer_first_name;
	cout << "	Customer's Account Balance: ";
	cin >> customer_account_balance;
	cout << "	Amount of Customer's Purchases: ";
	cin >> customer_purchases;

}
void process_results ()
{
	total_customers_processed = total_customers_processed + 1;					//calculate summary
	total_balance_due_all_customers = total_balance_due_all_customers			//totals
		+ (customer_account_balance + customer_purchases);
	total_purchases_all_customers = total_purchases_all_customers + customer_purchases;

	customer_new_account_balance = customer_account_balance + customer_purchases;

	system("cls");
	cout << "The following credit report is prepared for "
		<< customer_first_name << " " << customer_last_name << "."
		<< endl << endl;

	if (customer_new_account_balance <= credit_maximum)							//check credit use
	{
		customer_available_credit = credit_maximum - customer_new_account_balance;
		available_credit_all_customers = available_credit_all_customers + customer_available_credit;

		cout << "You have " << customer_available_credit << " of available credit in account " 
			<< customer_account_number << "." << endl;
	}
	else
	{
		exceeded_credit_limit = customer_new_account_balance - credit_maximum;

		cout << "You have exceeded your credit limit by " << exceeded_credit_limit 
			<< " in account " << customer_account_number << "." << endl;
	}
}

void output_totals ()
{
	system("cls");																//output summary
	cout << "Total number of customers processed "								//totals
		<< total_customers_processed << endl;
	cout << "Total balance due for all customers is " 
		<< total_balance_due_all_customers << endl;
	cout << "Total purchases for all customers is " 
		<< total_purchases_all_customers << endl;
	cout << "Total available credit for all customers is " 
		<< available_credit_all_customers << endl;
}
