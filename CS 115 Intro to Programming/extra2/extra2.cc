#include <iostream>
using namespace std;
/*
  Steven Liu
  CS115-J0E1
  Fall, 2010
  Extra Credit #2

  This program will count how many days it will take for an exponentially
  growing daily wage, starting at 1 cent, to surpass a high intial
  salary offering.
*/


const float OFFER = 5260348205.00;	//global var used to easily change
					//the OFFER we want to compare to
int main(){
	int numday;		//accumulator - days until totalpay > OFFER
	float daypay;		//accumulator - the day's pay
	float totalpay;		//LCV - total earnings

	numday = 0;
	daypay = 0.01;
	totalpay = 0.0;

	//find out how long it takes (in days) for an exponential pay,
	//starting at $0.01 to surpass an initial offering, called OFFER 
	while (totalpay < OFFER){
		numday++;
		totalpay += daypay;	
		daypay *= 2.0;
		}

	cout << "It took " << numday << " days to earn $" << totalpay << endl
		<< "Your initial offering was $" << OFFER << endl;
	}
