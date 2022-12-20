// morgageproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// David Xie 11/7/2020 Make a program that calculates how long it takes to make a payment
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;


int main()
{
	ofstream input; //file reference
	string plan; //inputfile
	int	years; // values user enters to be computed
	double	prin; // values user enters to be computed
	double	term; // values user enters to be computed

	cout << "Enter name of file for the output: "; 
	cin >> plan;
	input.open(plan);

	if (input.fail()) { //checks to see if input works
		cout << "failed";
	}

	cout << "Please enter the principal: ";
	cin >> prin; 

	cout << "Please enter the APR (i.e., 3.5 for 3.5%): ";
	cin >> term;
	double apr = term / 100; //changes the percent to decimal

	cout << "Please enter the number of years: ";
	cin >> years;

	int	n = years * 12;	// number of periods
	double	r = apr / 12;	// periodic interest rate
	
	double	pay = prin * r / (1 - pow(1 + r, -n)); //output for payment

	input << "Principle: " << prin << "\n" << endl;
	input << "Yearly rate: " << apr << "\n" << endl;
	input << "Terms: " << years << "\n" << endl;
	input << "Your payment is: " << pay << endl;

	input.setf(ios::fixed);		// googled this but it fixed point output
	input.precision(2);		// two places after the decimal

	
	double	balance = prin;
	double	ti = 0; // values user enters to be computed
	double	tp = 0; // values user enters to be computed

	input << "Months" << "\t" << "Balance" << "\t" << " Interest" << "\t" << "Principle" << "\n"; //output
	for (int i = 1; i <= n; i++) //for loop to repeatedly run until balance is 0
	{
		double	ti2 = balance * r;
		double	tp2 = pay - ti2;
		ti += ti2;
		tp += tp2;

		balance -= (pay - ti2);

		
		input <<setw(3) << i << ": " << setw(10) << balance << setw(10) << ti2 << setw(10) << tp2 << endl; //output
	}

	input << "Borrowing " << prin << " a total of " << ti + tp << " payments were made and the total interest paid was " << ti << endl; //output
	input.close();
	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
