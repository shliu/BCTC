#include <iostream>
using namespace std;
/*
  Steven Liu
  CS115-J0E1
  Fall, 2010
  Program 1

  1)Program description:
	This program will request a set of numbers representing the quantity 
	(in gallons, quarts, and pints) of different colored paint (red, 
	green, yellow, and blue) sold by the user.  The program will then 
	redisplay the various types of paint sold, the sum of the amount of 
	paint sold, and the total cost of the paint sold - including any unit 
	specific discounts given.  
  2)Precondition:
	i.	User will enter number of gallons of red paint desired, called 
		redgallons, which is a whole number between 0 and 100.
	ii.	User will enter number of quarts of red paint desired, called 
		redquarts, which is a whole number between 0 and 100.
	iii.	User will enter number of pints of red paint desired, called 
		redpints, which is a whole number between 0 and 100.
	iv.	User will enter number of gallons of green paint desired, 
		called greengallons, which is a whole number between 0 and 100.
	v.	User will enter number of quarts of green paint desired, 
		called greenquarts, which is a whole number between 0 and 100.
	vi.	User will enter number of pints of green paint desired, called 
		greenpints, which is a whole number between 0 and 100.
	vii.	User will enter number of gallons of yellow paint desired, 
		called yellowgallons, which is a whole number between 0 and 100.
	viii.	User will enter number of quarts of yellow paint desired, 
		called yellowquarts, which is a whole number between 0 and 100.
	ix.	User will enter number of pints of yellow paint desired, 
		called yellowpints, which is a whole number between 0 and 100.
	x.	User will enter number of gallons of blue paint desired, 
		called bluegallons, which is a whole number between 0 and 100.
	xi.	User will enter number of quarts of blue paint desired, called 
		bluequarts, which is a whole number between 0 and 100.
	xii.	User will enter number of pints of blue paint desired, called 
		bluepints, which is a whole number between 0 and 100.
	xiii.	Total amount of paint sold implied by the above preconditions 
		does not exceed 400 gallons, 400 quarts, and 400 pints (must 
		be less than or equal to 550 gallons of paint total).
  3)Postcondition:
	i.	Program will redisplay the gallons, quarts, and pints of red 
		paint sold.  Following the same boundaries of the preconditions.
	ii.	Program will redisplay the gallons, quarts, and pints of green 
		paint sold.  Following the same boundaries of the preconditions.
	iii.	Program will redisplay the gallons, quarts, and pints of yellow
		paint sold. Following the same boundaries of the preconditions.
	iv.	Program will redisplay the gallons, quarts, and pints of blue 
		paint sold. Following the same boundaries of the preconditions.
	v.	Display the sum of all paint sold separated into gallons 
		(called totalgallons, a whole number between 0-550), quarts 
		(called totalquarts, a whole number between 0-3), and pints 
		(called totalquarts, a whole number between 0-1).
	vi.	Display the total cost of the paint sold in dollars, called 
		finalcost, which is a whole number between 0-9350.  
*/

int main(){

	//Variable declariation and definition
	int redgallons;		//user input: # gallons of red paint
	int redquarts;		//user input: # quarts of red paint
	int redpints;		//user input: # pints of red paint
	int greengallons;	//user input: # gallons of green paint
	int greenquarts;	//user input: # quarts of green paint
	int greenpints;;	//user input: # pints of green paint
	int yellowgallons;	//user input: # gallons of yellow paint
	int yellowquarts;	//user input: # quarts of yellow paint
	int yellowpints;	//user input: # pints of yellow paint
	int bluegallons;	//user input: # gallons of blue paint
	int bluequarts;		//user input: # quarts of blue paint
	int bluepints;		//user input: # pints of blue paint
	int justpints;		//calc: total amount of paint sold in pints
	int quartspints;	//calc: paint left over after removing gallons
	int totalgallons;	//calc: gallon value of total paint sold
	int totalquarts;	//calc: quart value of total paint sold
	int totalpints;		//calc: pint value of total paint sold
	int finalcost;		//calc: cost of total paint sold with discounts


	//Get amount of individual paint desired from the user
	cout << endl << "Acme Paint Pricing Program, version 1.0" << endl
		<< "(c) Steven Liu, 2010" << endl << endl;
	cout << "Enter the number of gallon containers of red paint sold:    ";
	cin >> redgallons;
	cout << "Enter the number of quart containers of red paint sold:     ";
	cin >> redquarts;
	cout << "Enter the number of pint containers of red paint sold:      ";
	cin >> redpints;
	cout << endl;
	cout << "Enter the number of gallon containers of green paint sold:  ";
	cin >> greengallons;
	cout << "Enter the number of quart containers of green paint sold:   ";
	cin >> greenquarts;
	cout << "Enter the number of pint containers of green paint sold:    ";
	cin >> greenpints;
	cout << endl;
	cout << "Enter the number of gallon containers of yellow paint sold: ";
	cin >> yellowgallons;
	cout << "Enter the number of quart containers of yellow paint sold:  ";
	cin >> yellowquarts;
	cout << "Enter the number of pint containers of yellow paint sold:   ";
	cin >> yellowpints;
	cout << endl;
	cout << "Enter the number of gallon containers of blue paint sold:   ";
	cin >> bluegallons;
	cout << "Enter the number of quart containers of blue paint sold:    ";
	cin >> bluequarts;
	cout << "Enter the number of pint containers of blue paint sold:     ";
	cin >> bluepints;
	cout << endl;


	//Calculate the total amount of paint sold and its final cost
	justpints = (redgallons * 8) + (greengallons * 8) + (yellowgallons * 8)
		+ (bluegallons * 8) + (redquarts * 2) + (greenquarts * 2)
		+ (yellowquarts * 2) + (bluequarts * 2) + redpints
		+ greenpints + yellowpints + bluepints;
	totalgallons = justpints / 8;
	quartspints = justpints % 8;
	totalquarts = quartspints / 2;
	totalpints = quartspints % 2;
	finalcost = (totalgallons * 17) + (totalquarts * 9) + (totalpints * 5);


	//Display the total paint sold and the final cost
	cout << "Amount of red paint sold:    " << redgallons << " gallon(s), "
		<< redquarts << " quart(s), " << redpints << " and pint(s)"
		<< endl;
	cout << "Amount of green paint sold:  " << greengallons
	 	<< " gallon(s), " << greenquarts << " quart(s), "
		<< greenpints << " and pint(s)" << endl;
	cout << "Amount of yellow paint sold: " << yellowgallons
		<< " gallon(s), " << yellowquarts << " quart(s), "
		<< yellowpints << " and pint(s)" << endl;
	cout << "Amount of blue paint sold:   " << bluegallons << " gallon(s), "
		<< bluequarts << " quart(s), " << bluepints << " and pint(s)"
		<< endl << endl;
	cout << "Total amount of paint sold: " << totalgallons << " gallon(s), "
		<< totalquarts << " quart(s), " << totalpints << " and pint(s)"
		<< endl << endl;
	cout << "Total cost:   $" << finalcost << endl << endl;
	cout << "Finishing Acme Paint Pricing Program, version 1.0" << endl
		<< endl;

	}


















