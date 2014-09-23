#include <iostream>
using namespace std;


/*
  Steven Liu
  CS215-J001
  Spring, 2011
  Homework 1
  
  Program description:
  This program will ask for and take 2 integers from the user and tells user
  whether the two given integers are "relatively prime" numbers
*/



//secondary function prototype
int GetIntBetween(int min, int max);
int GetInt();
int CountCommonFactors(int first, int second);
int WhichSmaller(int first, int second);
void DisplayOutput(int first, int second, int commonfactors);




int main(){
	//variable declariation and definition
	int first;			//input - first user integer input
	int second;			//input - second user integer input
	int commonfactors;		//calculated - # common factors
	
	//get first integer
	cout << "Enter a first whole number between 1 and 1000: ";
	first = GetIntBetween(1, 1000);
	
	//get second integer
	cout << "Enter a second whole number between 1 and 1000: ";
	second = GetIntBetween(1, 1000);
	
	//count # of common factors between first and second
	commonfactors = CountCommonFactors(first, second);
	
	//display output to user
	DisplayOutput(first, second, commonfactors);
	}
	

	
	
	
//gets an integers from the user between "min" and "max"
int GetIntBetween(int min, int max){
	//variable dec+def
	int num;	//input - user integer input between 1 and 1000
	
	//range checking - integer must be between min and max
	num = GetInt();
	while (num < min || num > max){
		cout << "Bad input; Number must be between " << min
			<< " and " << max << "; Try again: ";
		num = GetInt();
		}
	
	return num;
	}
	

	
	
//gets an integer from the user
int GetInt(){
	//variable dec+def
	int num;	//input - user integer input
	
	//type checking - user must enter an integer
	cin >> num;
	while (!cin.good()){
		cout << "Bad input; Integer input required; Try again: ";
		cin.clear();
		cin.ignore(80, '\n');
		cin >> num;
		}

	return num;
	}
	
	

	
//count # of common factors that are greater than 1 between the two given ints
int CountCommonFactors(int first, int second){
	//variable dec+def
	int commonfactors;	//calculated - counts # of common factors
	int smaller;		//calculated - the smaller of the two inputs
	
	smaller = WhichSmaller(first, second);
	
	//find # common factors > 1 between the two integers
	commonfactors = 0;
	for (int i = 2; i <= smaller; i++)
		if (first % i == 0 && second % i == 0)
			commonfactors++;
	
	return commonfactors;	
	}
	
	
	
	
//finds and returns the smaller of the two passed args
int WhichSmaller(int first, int second){
	//variable dec+def
	int smaller;	//calculated - the smaller of the two inputs
	
	//finds the smaller of the two values
	if (first < second)
		smaller = first;
	else
		smaller = second;
	
	return smaller;
	}
	
	
	
	
//display output to the user
void DisplayOutput(int first, int second, int commonfactors){
	cout << endl << first << " and " << second << " share " 
		<< commonfactors << " common factors greaters than 1" << endl;
	
	cout << first << " and " << second;
	if (commonfactors == 0)
		cout << " ARE";
	else
		cout << " are NOT";
	cout << " relatively prime" << endl;
	}
	
	
	
	

	
	

	
	
	
	
	
	
	
	
	
