#include <iostream>
using namespace std;

//Can also use "int" type to return true/false
bool user_says_yes();

int main(){
	//Ask user question
	cout << "Do you enjoy cake? Y/N: ";

	//Output based on user response
	if (user_says_yes())
		cout << "You enjoy cake!" << endl;
	else
		cout << "You hate cake!" << endl;	
	}


//Checks user input to ensure correct type/data has been inputted
//Returns bool "true" if user says yes, bool "false" if user says no
bool user_says_yes(){
	char userinput;		//input - response to y/n question
	cin >> userinput;
	
	//Input validation
	while (!((userinput == 'Y') || (userinput == 'y') ||
		(userinput == 'N') || (userinput == 'n'))){	
		cout << "Bad input; "
			<< "Type Y/y for Yes, N/n for No; "
			<< "Please try again: "; 
		cin >> userinput;
		}

	//return result
	if ((userinput == 'Y') || (userinput == 'y'))
		return true;	//ANY NUMBER other than '0' also means true
	else
		return false;	//'0' also means same as "false"
	}
