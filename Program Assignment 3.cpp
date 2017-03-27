/*
Program Assignment 3
James Payne
SE 114.01

Purpose : To help sales personnel determine the amount to charge customers for items purchased.  The 
program will ask the user to enter the number of items purchased, the price of the item, and the sales
tax rate. Finally, the program will display the cost of the items, sales tax, and the total amount due.

Variable Dictionary

Variable Name			Type		Represents
cost_of_items			double		total cost of items
number_of_item			integer 	number of item
price_per_item			double		price per item
sales_tax				double		total sale tax
sales_tax_rate			double		sales tax rate
total_amount_due		double		total amount due

*/

#include <iostream>
using namespace std;

double cost_of_items, price_per_item, sales_tax, sales_tax_rate, total_amount_due;
int number_of_item;

int main()
{
	system ("cls");
	cout << endl;
	cout << "Please enter:" << endl;
	cout << endl << endl;
	cout << "	Number of items purchased:========>";
	cin >> number_of_item;
	cout << "	Price per item====================>";
	cin >> price_per_item;
	cout << "	Sales Tax Rate====================>";
	cin >> sales_tax_rate;
	cout << endl << endl << endl;

	cost_of_items = price_per_item * number_of_item;
	sales_tax = (sales_tax_rate * .01) * cost_of_items;
	total_amount_due = cost_of_items+sales_tax;

	cout << "Cost of items:	      ";
	cout << cost_of_items << endl;
	cout << "Sales Tax:	      ";
	cout << sales_tax << endl;
	cout << "Total Amount Due:    $";
	cout << total_amount_due << endl;
	cout << endl << endl;
	system ("pause");
	return 0;
}
