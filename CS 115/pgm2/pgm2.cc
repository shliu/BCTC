#include <iostream>
using namespace std;

/*
  Steven Liu
  CS115-J0E1
  Fall, 2010
  Program 2

  1)Program description:
	This shipping cost calculation program will ask the user for a desired 
	delivery method as well as the weight of material to be shipped then 
 	will display the total cost of shipping back to the user.
  2)Precondition:
	i.	User will enter the method of shipping, called shiptype, which 
		will be one of the following four characters: 'e', 'E', 't',
		 or 'T'.
	ii.	User will enter the amount of material to be shipped (in 
		pounds), called amount, which will be a whole number between 1 
		and 100.
  3)Postcondition:
	i.	Program will display shipping type and the amount of weight 
		the user asked to be shipped, following the same boundaries in 
		the precondition.
	ii.	Program will display the dollar amount of the final cost, 
		called costdollar, which will be a whole number between 
		0 and 179.
	iii.	Program will display the cent amount of the final cost, called 
		costcent, which will be a whole number between 0 and 99.
	iv.	Total cost implied by choosing the most expensive shipping type
		and the maximum allowable weight does not exceed 179 dollars 
		and 69 cents (less than or equivalent to $179.69).
*/



//secondary function prototypes
char get_delivery_service();
int get_package_weight();
int compute_delivery_cost(char shiptype, int amount);
void report_delivery_cost(char shiptype, int amount, int totaljustcents);


int main(){
	//variable declariation and definition
	char shiptype;		//input - user specified shipping method	
	int amount;		//input - user specified shipping amount in lb.
	int totaljustcents;	//calculated - total cost of shipping in cents
	
	//display header
	cout << "Fly-By-Night Delivery Program, version 1.0" << endl 
		<< "(c) Steven Liu, 2010" << endl << endl;

	//get delivery type from user
	shiptype = get_delivery_service();

	//get package amount from user
	amount = get_package_weight();

	//calculate cost
	totaljustcents = compute_delivery_cost(shiptype, amount);

	cout << endl;
	
	//display total cost back to user
	report_delivery_cost(shiptype, amount, totaljustcents);
	
	//display footer
	cout << endl << endl 
		<< "Finishing Fly-By-Night Delivery Program, version 1.0" 
		<< endl; 
	}



//Get delivery service type from user
//default shipping type is "overnight" if input is out of range
char get_delivery_service(){
	//variable dec+def
	char shiptype;		//input - one character user input

	//asking for and getting input from user
	cout << "Enter the desired delivery service, E(conomy), T(wo-day),"
		<< " or O(vernight): ";
	cin >> shiptype;	

	//input validation - input must be E, e, T, or t
	if ((shiptype == 'E') || (shiptype == 'e'))
		shiptype = 'e';
	else if ((shiptype == 'T') || (shiptype == 't'))
		shiptype = 't';
	else
		;

	return shiptype;
	}
	



//Get package weight from user
//will set shipping amount to 100 (default) if input is outside range
int get_package_weight(){
	//variable dec+def
	int amount;		//input - whole number weight in pound

	//asking for and getting input from user
	cout << "Enter the weight of the package in pounds: ";
	cin >> amount;

	//input validation - input must be between 1 - 100 inclusive
	//or else default of 100 is selected
	if ((amount < 1) || (amount > 100))
		amount = 100;
	else
		;

	return amount;
	}




//Calculate the cost of delivery
int compute_delivery_cost(char shiptype, int amount){
	//variable dec+def
	int totaljustcents;		//calculated - total cost of shipping

	//calculate costs based on deliver type
	if (shiptype == 'e')
		totaljustcents = amount * 87;
	else if (shiptype == 't')
		totaljustcents = amount * 153;
	else if (amount <= 3)
		totaljustcents = 800;
	else
		totaljustcents = ((amount - 3) * 177) + 800;

	return totaljustcents;
	}



//Display results on the screen
void report_delivery_cost(char shiptype, int amount, int totaljustcents){
	//variable dec+def
	int costdollar;		//calculated - dollar portion of cost
	int costcent;		//calculated - cent portion of cost

	//split total into dollars and cents
	costdollar = totaljustcents / 100;
	costcent = totaljustcents % 100;
	
	cout << "Your " << amount << " pound package for ";

	//display ship type based on user choice
	if (shiptype == 'e')
		cout << "Economy";
	else if (shiptype == 't')
		cout << "Two-Day";
	else
		cout << "Overnight";

	cout << " delivery will cost ";

	//display dollar portion of cost, handle pluration of word "dollar"
	if (costdollar == 1)
		cout << "1 dollar and ";
	else if (costdollar > 1)
		cout << costdollar << " dollars and ";
	else
		;

	//display cent portion of cost, handle pluration of word "cent"
	if (costcent == 1)
		cout << "1 cent.";
	else
		cout << costcent << " cents.";
	}



