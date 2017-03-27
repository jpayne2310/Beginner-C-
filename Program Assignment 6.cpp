/*
Program Assignment 6
James Payne
SE 114.01

Purpose: This program will help the sales department of ACME.COM determine the pricing pf products sold
to their customers.  The program will display the customer's name, product they are inquiring
about, and the cost of the product up to an order quantity of fifteen pieces.

Variable Dictionary:

Variable Name					Type				Represents
company_name					string				customer company name
item_counter					integer				item counter
item_purchase_cost				double				cost of items to be purchased
max_amount_of_products			integer				the maximum amount of products for inquiry
price_of_product				doulbe				price of product
product_inquiry_name			string				product inquired about
response_y_n					char				'Y' for yes "N" for no
sales_tax_rate					double				rate of sales tax
total_price						double				total price
total_sales_tax					double				amount of sales tax for product inquiry

*/

#include <iostream>
#include <string>
using namespace std;

char response_y_n;															//declared variables
double sales_tax_rate, item_purchase_cost, price_of_product, total_price, total_sales_tax;
int item_counter, max_amount_of_products;
string company_name, product_inquiry_name;

void setup ();																//declared functions
void get_input_data ();
void headings ();
void processing ();
void output_results ();

int main ()
{

	cout << "ACME Sales Chart Creator" << endl;
	cout << "Would you like to prepare a Sales Chart? Y or N:";				//check if program
	cin >> response_y_n;													//is to be run
	response_y_n = toupper(response_y_n);

	while (response_y_n !='Y' && response_y_n !='N')						//validate response
	{
		cout << "Incorrect response." << endl;
		cout << "Enter 'Y' for Yes or 'N' for No:";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}

	while (response_y_n == 'Y')
	{
		setup ();
		get_input_data ();													//functions set in
		headings ();														//order of operations
		output_results ();

		cout << "Would you like to prepare another chart? (Y/N)" << endl;	//check if program is
		cout << "Press <ENTER> to continue";								//to be run again
		cin >> response_y_n;
	response_y_n = toupper(response_y_n);
	}
		while (response_y_n !='Y' && response_y_n !='N')					//validate response
		{
			cout << "Incorrect response." << endl;
			cout << "Enter 'Y' for Yes or 'N' for No:";
			cin >> response_y_n;
			response_y_n = toupper(response_y_n);
		}

system("pause");															//end program if chosen
return 0;																	//not to be run again
}

void setup ()
	{
		max_amount_of_products = 15;										//changeable values set
		sales_tax_rate = .07;

		cout.setf(ios::fixed, ios::floatfield);
		cout.setf(ios::showpoint);
		cout.precision(2);

	}

void get_input_data ()
	{
		system("cls");
		cout << "Please enter:" << endl;									//receive and assign
		cout << "	Name of Company: ";										//user entered data
		cin >> company_name;
		cout << "	Name of Product: ";
		cin >> product_inquiry_name;
		cout << "	Price of Product: ";
		cin >> price_of_product;
	}

void headings ()
	{
		system("cls");
		cout << "			 PRICE QUOTATION" << endl;						//output headings
		cout << "		     PREPARED FOR: " << company_name << endl;
		cout << "		     PRODUCT NAME: " << product_inquiry_name << endl;
		cout << endl << endl;
		cout <<"Number of Items		Cost		Tax		Total Price" << endl << endl;
	}

void output_results ()														//loop until max amount
	{																		//of products reached
		for (item_counter=1; item_counter <= max_amount_of_products; item_counter = item_counter + 1)
		{
			cout <<	"	" << item_counter;
			processing ();													//call processing
 			cout << "		" << item_purchase_cost;						//for changeing 
			cout << "		" << total_sales_tax;							//variable output
			cout << "		" << total_price << endl;
		}
		cout << endl;
	}

void processing ()
	{
		item_purchase_cost = price_of_product * item_counter;					//process variables
		total_sales_tax = item_purchase_cost * sales_tax_rate;				//for chart output
		total_price = item_purchase_cost + total_sales_tax;
	}