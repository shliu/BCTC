#include <iostream>
using namespace std;
/*
  Steven Liu
  CS115-J0E1
  Fall, 2010
  Extra Credit #1

  This program will 
	1) gather wage and hours worked amounts from user
  	2) calculate weekly pay, including any overtime pay received
  	3) return to the user his final earnings for this week
*/


int calcpay(int hoursworked, int wage);


int main(){
	//variable declariation and definition
	int earning;		//total earning this week
	int hoursworked;	//total hours worked this week
	int wage;		//hourly wage

	//get hours worked and wage amount from user
	cout << "Enter # hours worked this week: ";
	cin >> hoursworked;
	cout << "Enter wage: ";
	cin >> wage;

	//calculate earnings for this week
	earning = calcpay(hoursworked, wage);

	//display total earnings this week
	cout << "You earned $" << earning << endl;
	}


int calcpay(int hoursworked, int wage){
	int earning;		//total earning this week

	//calculate earnings for this week
	if (hoursworked <= 40)
		//earning if NO overtime
		earning = wage * hoursworked;
	else
		//earning if YES overtime
		//if wage is odd number, earnings will be REDUCED by $.5
		earning = (wage * 40) + ((hoursworked - 40) * wage * 1.5);
	
	//throw earnings back to main()
	return earning;
	}
