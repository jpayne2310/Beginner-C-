/*
Program Assignment 1
James Payne
SE 114.01

Purpose: To determine the cost of a vaction by car to a variety of locations.  
The program will ask the user to enter the distance to the vaction destination, 
the price of a gallon of gas and the number of miles per gallon used by the vehicle.  
The program will calculate and display the cost 
of using the vehicle for the trip.

Variable Dictionary:

Variable Name			Type			Repersents
cost_of_trip			double			the cost of the trip
distance_traveled		double			the total mile that will be traveled
gallons_used			double			the result of the calculation of mpg * distance traveled
miles_per_gallon		double			miles per gallon
price_per_gallon		double			price per gallon

*/

#include <iostream>
using namespace std;
double cost_of_trip, distance_traveled, gallons_used, miles_per_gallon, price_per_gallon;


	int main()
{
	system ("cls");
	cout << endl;
	cout << "Please enter:" <<endl;
	cout << endl;
	cout << endl;
	cout << "	Distance=====================>";
	cin >> distance_traveled;
	cout << "	Price per gallon=============>";
	cin >> price_per_gallon;
	cout << "	Miles per gallon=============>";
	cin >> miles_per_gallon;
	gallons_used = distance_traveled/miles_per_gallon;
	cost_of_trip = gallons_used*price_per_gallon;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "The cost of using this vehicle for this trip will be=======>" << cost_of_trip;
	cout << endl;
	cout << endl;
	system ("pause");
	return 0;
}
