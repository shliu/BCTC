#include <iostream>
using namespace std;
/*
  Steven Liu
  CS115-J0E1
  Fall, 2010
  Extra Credit #3

  This program will count the amount of "special numbers" between
  000000 - 999999.  "Special number" is defined as a number where all
  digits in the number are unique.
*/

int main(){
	int counter = 0;	//accumulator - counts # special numbers

	//create a six digit odometer
	for (int a = 0; a < 10; a++)
	  for (int b = 0; b < 10; b++)
	    for (int c = 0; c < 10; c++)
	      for (int d = 0; d < 10; d++)
	        for (int e = 0; e < 10; e++)
	          for (int f = 0; f < 10; f++)
			if ( (a != b) && (a != c) && (a != d) && (a != e) &&
				(a != f) && (b != c) && (b != d) && (b != e) &&
				(b != f) && (c != d) && (c != e) && (c != f) &&
				(d != e) && (d != f) && (e != f) ) 
				counter++;
			else
				;	
	cout << "There are " << counter 
		<< " special numbers between 000000 and 999999." << endl;
	}



