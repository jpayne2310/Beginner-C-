/*
Programming Assignment 4
James Payne
SE 114.01

Purpose: To Help the Payroll Department calculate the pay for assigned employees. This 
program will ask the user to enter the name of the employee, hours worked, hourly rate 
of pay, and number of exemptions they are claiming. The program will then calculate net 
pay and display results.

Variable Dictionary

Variable Name				Type		Represents
employee_name				string		name of employee
exemption_rate				double		exemption rate
federal_tax_rate			double		federal tax rate
federal_withholding_tax		double		federal withholding Tax
gross_pay					double		gross pay
hourly_rate_of_pay			double		hourly rate of pay
hours_worked				double		hours worked
net_pay						double		net pay
number_of_exemptions		integer		number of exemptions

*/

#include <iostream>
#include <string>

using namespace std;

string employee_name;															//variables declared
double exemption_rate, federal_tax_rate, federal_withholding_tax, gross_pay,
	hourly_rate_of_pay, hours_worked, net_pay;
int number_of_exemptions;

void settings ();																//functions declard
void print_headings ();
void get_input_data ();
void calculations ();
void output_results ();


int main ()
{

	settings ();																//functions set in 
	print_headings ();															//order of operations
	get_input_data ();
	calculations ();
	output_results ();

	system("pause");															//program set to end
	return 0;																	//once functions complete

}

void settings ()
{
	exemption_rate = 53.5;														//rates assigned value
	federal_tax_rate = .16;

}

void print_headings ()
{
	cout << "					ABC Company" << endl;							//output headings
	cout << "				Employee Payroll Calculator" << endl;
	cout << endl;
	cout << "Please enter:" << endl << endl << endl;

}
void get_input_data ()
{
	cout << "	Employee Name:============>";									//receive and store user
	cin >> employee_name;														//entered data
	cout << "	Number of Exemptions======>";
	cin >> number_of_exemptions;
	cout << "	Hourly Rate of Pay========>";
	cin >> hourly_rate_of_pay;
	cout << "	Hours Worked==============>";
	cin >> hours_worked;
	cout << endl <<endl;
}
void calculations ()
{

	gross_pay = hourly_rate_of_pay * hours_worked;								//process data for output
	federal_withholding_tax = federal_tax_rate *								//requirements
		(gross_pay-(number_of_exemptions*exemption_rate));
	net_pay = gross_pay - federal_withholding_tax;

}
void output_results ()
{
	cout << "Gross Pay:		   " << gross_pay << endl;							//output data results
	cout << "Federal Withholding Tax:   " << federal_withholding_tax << endl;
	cout << "Net Pay:	       	   " << net_pay << endl << endl;
	cout << "End of Report for " <<employee_name << endl <<endl;

}