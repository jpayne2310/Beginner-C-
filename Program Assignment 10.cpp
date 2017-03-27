/*
Programming Assignment 10
James Payne
SE 114.01

Purpose: This program will prepare a stock report that will track commissions based on transactions from
brokerage salesmen.  All commissions for purchases and sells of stocks from the New York Stock Exchange, 
the American Stock Exchange, and all over counter transactions will be calculated and displayed in a 
summary for the individual salesman.  Once all the salemen transactions have been entered a full
summary of all transactions will be displayed.

Variable Dictionary:

Variable Name						Type			Represents
american_stock_exchange				character		transaction location
amount_of_commission				double			amount of commission
amount_of_tranaction				double			dollar amount of transaction
ase_purchase_commission_rate		double			purchase commission rate for american stock exchange
counter_purchase_commission_rate	double			purchase commission rate for counter transactions
exchange_location					character		N for NYSE, A for AMST, or O for over counter trans
first_name							string			first name of salesman
first_run							character		program initiator
increment_amount					integer			amount to increment by
last_name							string			last name of salesnam
new_york_stock_exchange				character		transaction location
nyse_purchase_commission_rate		double			purchase commission rate for new york stock exchange
nyse_sales_commission_rate			double			sales commission rate for new york stock exchange
purchase							character		transaction type
response_y_n						character		Y for yes, N for no
sale								character		transaction type
salemen_transaction_type			string			salesmen transaction type
total_commission_all_salesmen		double			total dollar amount for all commissions
total_salesmen_procesed				integer			number of salesmen processed
total_transactions_amount			double			total dollar amount of all transactions
transaction_type					character		is the transaction a purchase or a sale
universal_sale_commission_rate		double			universal sales commission rate

*/

#include <iostream>
#include <string>
using namespace std;

char american_stock_exchange, exchange_location, first_run = 'Y',		//declared variables
	new_york_stock_exchange, purchase, response_y_n, sale, transaction_type;
double amount_of_tranaction, amount_of_commission, ase_purchase_commission_rate,
	counter_purchase_commission_rate, nyse_purchase_commission_rate, nyse_sales_commission_rate, 
	total_commission_all_salesmen, total_transactions_amount, universal_sale_commission_rate;
int increment_amount, total_salesmen_procesed;
string first_name, last_name, salemen_transaction_type;

void setup ();															//declared functions
void input ();
void process_results ();
void output_totals ();

int main ()
{
	cout << "Would you like to create a stock report? Y or N: ";		//check to see if to run
	cin >> response_y_n;
	response_y_n = toupper(response_y_n);

	while (response_y_n != 'Y' && response_y_n != 'N')					//validate response
	{
		cout << "Incorrect response." << endl;
		cout << "Enter a Y for Yes or a N for No: ";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}

	while (response_y_n == 'Y')											//initiate main while loop
	{
		if (first_run == 'Y')
		{
			setup ();													//call setup
			first_run = 'N';
		}

		input ();														//call input
		process_results ();												//call process_results
		
		cout <<"Would you like to process another salesmen? Y or N: ";	//check to see if to run again
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}

	if (first_run == 'N')
		{
			output_totals ();											//call output_totals
		}
	system ("pause");
	return 0;															//end program
}

void setup ()
{
	american_stock_exchange = 'A';										//variable beginning values set
	ase_purchase_commission_rate = .035;								//changing variables values set
	counter_purchase_commission_rate =.03;
	increment_amount = 1;
	new_york_stock_exchange = 'N';
	nyse_purchase_commission_rate = .045;
	nyse_sales_commission_rate = .025;
	purchase = 'P';
	sale = 'S';
	total_commission_all_salesmen = 0;
	total_salesmen_procesed = 0;
	total_transactions_amount = 0;
	universal_sale_commission_rate = .02;

	cout.setf(ios::fixed, ios::floatfield);								//format for output
	cout.setf(ios::showpoint);
	cout.precision(2);

}

void input ()
{
	system("cls");														//get and assign user input
	cout << "Please enter the following information about the salesmen:" << endl << endl;
	cout << "	First Name: ";
	cin >> first_name;
	cout << "	Last Name:  ";
	cin >> last_name;
	cout << "	Transaction Amount: ";
	cin >> amount_of_tranaction;
	cout << "	Transaction Type (P for Purchase or S for Sale) : ";
	cin >> transaction_type;
	transaction_type = toupper(transaction_type);
	while (transaction_type != 'P' && transaction_type != 'S')			//validate transaction_type
	{
		cout << "	Incorrect Response." << endl;
		cout << "	Transaction Type must be 'P' for Purchase or 'S' for Sale." << endl;
		cout << "	Please re-enter Transaction Type: ";
		cin >> transaction_type;
		transaction_type = toupper(transaction_type);
	}
	cout << "	Exchange Location (N for NYSE, A for AMSE, or O for Over counter): ";
	cin >> exchange_location;
	exchange_location = toupper(exchange_location);
	while (exchange_location != 'N' && exchange_location != 'A' &&		//validate exchange_location
		exchange_location != 'O')
	{
		cout << "	Incorrect Response." << endl;
		cout << "	Exchange Location must be 'N' for NYSE, 'A' for AMSE, " << endl;
		cout << "	or 'O' for over counter." << endl;
		cout << "	Please re-enter Exchange Location: ";
		cin >> exchange_location;
		exchange_location = toupper(exchange_location);
	}
}

void process_results ()
{
	total_salesmen_procesed = total_salesmen_procesed +					//calculations for output_totals
		increment_amount;
	total_transactions_amount = total_transactions_amount + amount_of_tranaction;
	if (transaction_type == purchase)									//transaction_type processed
	{
		salemen_transaction_type = "purchase";							//calculations for purchase
		if (exchange_location == new_york_stock_exchange)				//exchange location determined
		{
			amount_of_commission = amount_of_tranaction * nyse_purchase_commission_rate;
		}
		else
		{
		if (exchange_location == american_stock_exchange)
		{
			amount_of_commission = amount_of_tranaction * ase_purchase_commission_rate;
		}
		else
		{
			amount_of_commission = amount_of_tranaction * counter_purchase_commission_rate;
		}
		}
	}
	if (transaction_type == sale)
	{
		salemen_transaction_type = "sale";								//calculation for sale
		if (exchange_location == new_york_stock_exchange)				//exchange location determined
		{
			amount_of_commission = amount_of_tranaction * nyse_sales_commission_rate;
		}
		else
		{
		amount_of_commission = amount_of_tranaction * universal_sale_commission_rate;
		}
	}
	total_commission_all_salesmen = total_commission_all_salesmen +		//calculation for output_totals
		amount_of_commission;
	system ("cls");														//print salesmen summary
	cout << first_name << " " << last_name << " has earned " << amount_of_commission 
		<< " in commissions on " << amount_of_tranaction << " " 
		<< salemen_transaction_type << " transactions." << endl;
}

void output_totals ()
{
	system("cls");														//print final summary
	cout << "Total salesmen processed		" << total_salesmen_procesed << endl;
	cout << "Total transactions for all salesmen	" << total_transactions_amount << endl;
	cout << "Total commission for all salesmen	" << total_commission_all_salesmen << endl;
}