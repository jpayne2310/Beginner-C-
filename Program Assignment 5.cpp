/*
Program Assignment 5
James Payne
SE 114.01

Purpose: To help airline dispatchers produce a weight and balance report for specific flights.
The program will ask for the airline name, flight number, number of passengers, and the weight
of the fuel on board.  All the information will be processed and a report will be generated 
with the results.

Variable Dictionary:

Variable Name					Type			Represents
airline_name					string			name of airline
average_weight_per_Passenger	integer			average weight per passenger
flight_number					string			flight number
gross_takeoff_weight			double			gross takeoff weight
max_amount_of_passengers		integer			maximum amount of passengers
max_fuel_weight					double			maximum fuel weight
number_of_passengers			integer			number of passengers
response_y_n					character		response of y or n	
weight_of_fuel					double			weight of fuel in pounds

*/

#include <iostream>
#include <string>
using namespace std;

char response_y_n;																	//variable types
double gross_takeoff_weight, max_fuel_weight, weight_of_fuel;						//declared
int average_weight_per_passenger, max_amount_of_passengers, number_of_passengers;
string airline_name, flight_number;

void setup ();																		//functions declared
void display_heading ();
void get_input_data ();
void processing ();
void output_results ();

int main ()
{
	setup ();

	cout << "Airline Flight Dispatcher Weight and Balance Calculator." << endl;		//check if program
	cout << "Would you like to run this program?" << endl;							//is to be run
	cout << "Enter 'Y' for Yes or 'N' for No:";
	cin >> response_y_n;
	response_y_n = toupper(response_y_n);
	while (response_y_n !='Y' && response_y_n !='N')								//validate response
	{
		cout << "Incorrect response." << endl;
		cout << "Enter 'Y' for Yes or 'N' for No:";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}

	while (response_y_n == 'Y')
	{
		display_heading ();															//functions set in
		get_input_data ();															//order of operations
		processing ();
		output_results ();

		cout << "Do you want to enter another report?" << endl;						//check if program is
		cout << "Enter 'Y' for Yes or 'N' for No:";									//to be run again
		cin >> response_y_n;
	response_y_n = toupper(response_y_n);
	}
	while (response_y_n !='Y' && response_y_n !='N')								//validate response
	{
		cout << "Incorrect response." << endl;
		cout << "Enter 'Y' for Yes or 'N' for No:";
		cin >> response_y_n;
		response_y_n = toupper(response_y_n);
	}

	system("pause");																//end program if chosen
	return 0;																		//not to be run again
	}
	
	void setup ()
	{
		average_weight_per_passenger = 150;											//changeable values set
		max_amount_of_passengers = 250;
		max_fuel_weight = 200000;

	}
	void display_heading ()															//output headings
	{
		system ("cls");
		cout << "			    Airline Flight Dispatcher" << endl;
		cout << "			  Weight and Balance Calculator" << endl << endl;
		cout << "Please enter:" << endl << endl << endl;
	}
	void get_input_data ()															//receive and assign
	{																				//user entered data
		cout << "	Airline name:===========>";
		cin >> airline_name;
		cout << "	Flight Number===========>";
		cin >> flight_number;
		cout << "	Number of passengers====>";
		cin >> number_of_passengers;
		while (number_of_passengers < 0 || number_of_passengers > max_amount_of_passengers)
	{
			cout << "	Number of passengers cannot exceed more than ";				//input not to exceed
			cout << max_amount_of_passengers << "." << endl;						//max passenger limit
			cout << "	Please re-enter the number of passengers:";
			cin >>  number_of_passengers;
	}
		cout << "	Weight of fuel==========>";
		cin >> weight_of_fuel;
		while (weight_of_fuel < 1 || weight_of_fuel > max_fuel_weight)
	{
			cout << "	Maximum Fuel Weight cannot be 0 or exceed ";				//input not to exceed
			cout << max_fuel_weight  << "." << endl;								//max fuel weight limit
			cout << "	Please re-enter fuel weight: ";
			cin >> weight_of_fuel;
	}
		cout << endl << endl << endl;
	}
	void processing ()															//process data for
	{																				//output requirements
		gross_takeoff_weight = (number_of_passengers*average_weight_per_passenger) + weight_of_fuel;
	}
	void output_results ()															//output data results
	{
		cout << "Gross Takeoff weight:	" << gross_takeoff_weight << endl << endl << endl << endl;
		cout << "End of Weight and Balance report for " << airline_name << " Flight " << flight_number;
		cout << endl << endl << endl;
	}