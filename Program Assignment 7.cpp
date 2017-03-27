/*
Programming Assignment 7
James Payne
SE 114.01

Purpose: To calculate hourly, weekly, monthly, and yearly salaries of an employee.

Variable Dictionary:

Variable Name						Type			Represents
beginning_pay_rate					double			beginning rate of pay
ending_pay_rate						double			ending rate of pay
hourly_pay_rate						double			hourly pay rate
hours_pre_week						integer			amount of hours worked per week
incremental_rate					double			amount of raise
maximum_ending_pay_rate				integer			maximum ending pay rate
maximum_incremental_rate			double			maximum increment rate
minimum_beginning_pay_rate			integer			minimum beginning rate of pay
minimum_incremental_rate			double			minimum increment rate
monthly_salary						double			monthly salary
months_in_a_year					integer			number of months in a year
response_y_n						char			'Y' for yes 'N' for no
weekly_salary						double			weekly salary
weeks_in_a_year						integer			number of weeks in a year
yearly_salary						double			yearly salary

*/

#include <iostream>
using namespace std;

char response_y_n;														//declared variables
double beginning_pay_rate, ending_pay_rate, hourly_pay_rate, incremental_rate, 
	maximum_incremental_rate, minimum_incremental_rate, monthly_salary, weekly_salary, 
	yearly_salary;
int hours_per_week, maximum_ending_pay_rate, minimum_beginning_pay_rate, 
	months_in_a_year, weeks_in_a_year;

void setup ();															//declared functions
void heading ();
void input ();
void output ();
void processing ();

int main ()
{
	cout  << "Would you like to prepare a Sales Chart? Y or N: ";		//check if program
	cin >> response_y_n;												//is to be ran
	response_y_n = toupper(response_y_n);
	
	while (response_y_n != 'Y' && response_y_n != 'N')					//validate response
	{
		cout << "Incorrect response." << endl;
		cout << "Enter 'Y' for Yes or 'N' for No: ";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}

	while (response_y_n == 'Y')
	{																	//functions set in
		setup ();														//order of operations
		input ();
		heading ();
		output ();
		
		cout << "Would you like to prepare another chart? (Y/N)"		//check if program is
			<< endl;													//to be ran again
		cout << "Press <ENTER> to continue.";
		cin >>  response_y_n;
		response_y_n = toupper(response_y_n);
	}

	while (response_y_n != 'Y' && response_y_n != 'N')					//validate response
	{
		cout << "Incorrect response." << endl;
		cout << "Enter 'Y' for Yes or 'N' for No: ";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}

	system ("pause");													//end program if chosen
	return 0;															//not to be ran again
}
	void setup ()
	{
		hours_per_week = 40;											//changable values set
		maximum_ending_pay_rate = 50;
		maximum_incremental_rate = 5.00;
		minimum_beginning_pay_rate = 0;
		minimum_incremental_rate = 1.00;
		months_in_a_year = 12;
		weeks_in_a_year = 52;

		cout.setf(ios::fixed, ios::floatfield);							//output format set
		cout.setf(ios::showpoint);
		cout.precision(2);
	}

	void input ()
	{
		system ("cls");
		cout << "Beginning Rate of Pay: ";								//receive and assign
		cin >> beginning_pay_rate;										//user entered data
		while (beginning_pay_rate <= 0)
		{																//validate response
			cout << "Beginning Rate of Pay needs to be greater than zero." << endl;
			cout << "Please re-enter Beginning Rate of Pay: ";
			cin >> beginning_pay_rate;
		}
		cout << "Ending Rate of Pay: ";
		cin >> ending_pay_rate;											//validate response
		
		while (ending_pay_rate <= beginning_pay_rate || ending_pay_rate > maximum_ending_pay_rate)
		{
			cout << "Ending Rate of Pay must be greater than Beginning Rate of Pay, but less than "
				 << maximum_ending_pay_rate << "." << endl;
			cout << "Please re-enter Ending Rate of Pay: ";
			cin >> ending_pay_rate;
		}
		
		cout << "Increment to the Beginning Pay Rate: ";
		cin >> incremental_rate;										//validate response
		
		while (incremental_rate < minimum_incremental_rate || incremental_rate > maximum_incremental_rate)
		{
			cout << "Increment to the Beginning Pay Rate must be between " << minimum_incremental_rate
				 << " and " << maximum_incremental_rate << "." << endl;
			cout << "Please re-enter Increment to the Beginning Pay Rate: ";
			cin >> incremental_rate;
		}

	}

	void heading ()														//print heading
	{
		system ("cls");
		cout << "					PAYROLL CHART" << endl << endl << endl;
		cout <<"		       Hourly	     Weekly	Monthly	    Yearly" << endl << endl;
	}

	void output ()
	{																	//loop until ending
		for (hourly_pay_rate = beginning_pay_rate; hourly_pay_rate <=	//pay rate is reached
			ending_pay_rate; hourly_pay_rate = hourly_pay_rate + incremental_rate)
		{
			cout << "			 " << hourly_pay_rate;
			processing ();												//call processing

			cout << "	     " << weekly_salary;						//output processing
			cout << "	" << monthly_salary;							//results
			cout << "	    " << yearly_salary << endl;
		}
		cout << endl << endl << endl;
	}

	void processing ()
	{
		weekly_salary = hourly_pay_rate * hours_per_week;				//process variables
		yearly_salary = weekly_salary * weeks_in_a_year;				//for chart results
		monthly_salary = yearly_salary / months_in_a_year;
	}