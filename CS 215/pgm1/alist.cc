#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
	Steven Liu
	CS215-J001
	Spring, 2011
	Program 1

1. Program description:
	This program will display and prompt the user to choose from eight
	different options.  Two of these options will allow the user to 
	generate a list, three options will sort the list, two options will 
	search through the list, and the final option will exit the program.
2. Precondition:
	i.	User will enter the main menu option, called menu_option, which
		will be a whole number between 0 and 8.
	ii.	When the user chooses to reset the list using user input, the 
		user will enter each element into the element called 
		element_input.
	iii.	When the user chooses to reset the list using randomly 
		generated elements, the user will enter the size of the list, 
		a whole number called list_size.  The user will also limit 
		the range of the possible randomly generated elements by giving 
		the lower limit, a whole number called range_low, and the upper 
		limit, a whole number called range_high.
	iv.	When the user chooses to search the list, the user will provide 
		the target to search far, a valid element called search_target.
3. Postcondition:
	i.	If the user chooses to reset the list, the program will 
		create a new list from either user input or by randomly 
		generating the elements in the list, then will display the 
		contents of the list.  The program will also display a 
		warning that the newly reset list is not known to be ordered.
	ii.	If the user chooses to sort the list, the program will first 
		sort the list, then display the theoretical number of 
		comparisons and movements made by the sort, then the actual 
		number of comparisons and movements made by the program during 
		the sort.  The program will then display contents of the list 
		and will report that the list is now known to be ordered.
	iii.	If the user chooses to search through the list, 
		the program will display whether the search target was 
		found/not found.  The program will only attempt binary search
		if the list is known to be ordered.  If the target was on the 
		list, the program will report the position of the first 
		location the target was found.  Finally the program will 
		display the number of comparisons made during the search.
	iv.	If the user chooses to quit, the program will exit.
*/


//global section:
const int MLS = 50;		//size of array
typedef int element;		//datatype of "element"
const element SENTINEL = -1;	//"element value" that ends user input



//global function prototypes:
element read_element();
int read_int();
void display_menu();
//array list class prototype:
class AList {
	private:
		element items[MLS];
		int size;
		bool list_ordered;
		//-I/O:
		void Print();
		void Read();
		void GenRandList(int list_size, int range_high, int range_low);
		void Swap(element first, element second);
		//-Sorts:
		void BubbleSort(int & comps, int & moves);
		void InsertionSort(int & comps, int & moves);
		void SelectionSort(int & comps, int & moves);
		//-Searches:
		void LinearSearch(element target, bool & found, int & position,
			int & comps);
		void BinarySearch(element target, bool & found, int & position,
			int & comps);
		//-Stats:
		int CalcQuad();
		int CalcLog();
	public:
		void FirstLoad();
		void Run_Print();
		void Run_Read();
		void Run_GenRandList();
		void Run_BubbleSort();
		void Run_InsertionSort();
		void Run_SelectionSort();
		void Run_LinearSearch();
		void Run_BinarySearch();
	};
	

	
//****main function****
int main() {
	cout << "Sort and Search Demo Program, version 1.0" << endl
		<< "(c) 2011, (Steven Liu)" << endl << endl;
	
	srand(int(time(0)));	//seed the random number generator
	
	AList myAList;		//create object
	myAList.FirstLoad();	//prepares object for use
	int menu_option;	//input - user menu choice
	//loop menu
	do {
		myAList.Run_Print();
		display_menu();
		menu_option = read_int();

		switch (menu_option) {
			case 1:
				myAList.Run_Read();
				break;
			case 2:
				myAList.Run_GenRandList();
				break;
			case 3:
				myAList.Run_BubbleSort();
				break;
			case 4:
				myAList.Run_InsertionSort();
				break;
			case 5:
				myAList.Run_SelectionSort();
				break;
			case 6:
				myAList.Run_LinearSearch();
				break;
			case 7:
				myAList.Run_BinarySearch();
				break;
			case 8:
				cout << endl << "Quitting Sort and Search "
					<< "Demo Program, version 1.0" << endl;
				break;
			default:
				cout << endl << "Invalid choice; Please choose"
					<< "between menu options 1-8" << endl 
					<< endl;
				break;
			}
		} while (menu_option != 8);
	}
	

	
	
	
//------------------------------Global Functions------------------------------
	



//type checks input to see if it matches "element"
//if element is int, will also make certain 
//range is between -2147483648 and 2147483648  
element read_element() {
	//variable dec+def
	element user_input;	//input - user input
	
	//type checking
	cin >> user_input;
	while (!cin.good()){
		cout << "Bad input datatype; Try again: ";
		cin.clear();
		cin.ignore(80, '\n');
		cin >> user_input;
		}

	return user_input;
	}
	
	

	
	
//type checks input to ensure it is an integer
int read_int() {
	//variable dec+def
	int user_input;		//input - user input
	
	//type checking
	cin >> user_input;
	while (!cin.good()){
		cout << "Response must be a whole number, try again: ";
		cin.clear();
		cin.ignore(80, '\n');
		cin >> user_input;
		}

	return user_input;
	}
	
	
	
	
	
	
//displays the main menu to the user
void display_menu() {
	cout << "Actions:" << endl
		<< "   1.  Reset the current list from the keyboard" << endl
		<< "   2.  Reset the current list using "
		<< "randomly generated elements" << endl
		<< "   3.  Perform Bubble Sort on the current list" << endl
		<< "   4.  Perform Insertion Sort on the current list" << endl
		<< "   5.  Perform Selection Sort on the current list" << endl
		<< "   6.  Perform Linear Search on the current list" << endl
		<< "   7.  Perform Binary Search on the current list" << endl
		<< "   8.  Quit the program" << endl << endl
		<< "Choose an action: ";
	}

	
	
	

//*****************************End Global Functions*************************
	
//-----------------------------I/O Methods----------------------------------




//prints the entire contents of the list
void AList::Print() {
	//Pre: the Native Object AList is valid
	//Post: the Native Object AList is unchanged, and its elements are
		//displayed
	for (int i = 0; i < size; i++)
		cout << items[i] << " ";
	}


	
	
	
	

//fills the list with a series of user element inputs
void AList::Read() {
	//Pre: none
	//Post: the Native Object AList is valid
	element userval;	//input - user input of a single element
	size = 0;		//LCV - size of array, items[]
	
	//Read data from user
	cout << "Enter a series of elements, " << SENTINEL 
		<< " to stop: ";
	userval = read_element();
	while ((size < MLS) && (userval != SENTINEL)) {
		items[size] = userval;
		size++;
		if (size >= MLS)
			cout << "The array is full, exiting." << endl;
		else
			userval = read_element();
		}
	
	//List is not known to be ordered after input
	list_ordered = false;
	}
	
	


	
	
	
	
//fills the list with a series of randomly generated elements
void AList::GenRandList(int list_size, int range_high, int range_low) {
	//Pre: none
	//Post: the Native Object AList is valid
	size = 0;	//LCV - size of array, items[]
	
	//create list with randomly generated values
	while (size < list_size) {
		items[size] = (rand() % (range_high - range_low + 1)) 
			+ range_low;
		size++;
		}
		
	//List is not known to be ordered after input
	list_ordered = false;
}




	
	

	
//swaps the elements in the position specified
void AList::Swap(element first, element second) {	
	//Pre: the Native Object AList is valid
	//Post: the Native Object Alist is unchanged, except elements
		//in position [first] and [second] has swapped places
	element temp;
	temp = items[first];
	items[first] = items[second];
	items[second] = temp;
	}
	
	


	

//**********************************End I/O********************************
	
//-------------------------------Sorts----------------------------------------




//sorts the list using bubble sort
void AList::BubbleSort(int & comps, int & moves) {
	//Pre: the Native Object AList is valid
	//Post: the Native Object AList is unchanged, except its elements
		//are in ascending order
	comps = 0;		//Accumulator - counts # comparisons
	moves = 0;		//Accumulator - counts # moves
	
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - 1 - i; j++) {
			comps++;
			if (items[j] > items[j+1]) {
				moves += 3;
				Swap(j, j+1);
				}
			else
				;
			}
	
	//List is known to be ordered after sorting
	list_ordered = true;
	}

	
	
	
	
	
//sorts the list using insertion sort
void AList::InsertionSort(int & comps, int & moves) {
	//Pre: the Native Object AList is valid
	//Post: the Native Object AList is unchanged, except its elements
		//are in ascending order
	int j;		//LCV - keeps track of current element position
	bool done;	//LCV - when elements to its left are sorted, true	
	comps = 0;	//Accumulator - counts # comparisons
	moves = 0;	//Accumulator - counts # moves
		
	for (int i = 1; i < size; i++) {
		j = i;
		done = false;
		while ( (j >= 1) && (!done) ) {
			comps++;
			if (items[j] < items[j-1]) {
				moves += 3;
				Swap (j, j-1);
				j--;
				}
			else
				done = true;
			}
		}	
	
	//List is known to be ordered after sorting
	list_ordered = true;
	}

	
	
	
	
	

//sorts the list using selection sort
void AList::SelectionSort(int & comps, int & moves) {
	//Pre: the Native Object AList is valid
	//Post: the Native Object AList is unchanged, except its elements
		//are in ascending order
	int maxpos;		//LCV - location of highest value
	comps = 0;		//Accumulator - counts # comparisons
	moves = 0;		//Accumulator - counts # moves
	
	for (int i = size - 1; i > 0; i--) {
		maxpos = 0;
		for (int j = 1; j <= i; j++) {
			comps++;
			if (items[j] > items[maxpos])
				maxpos = j;
			else
				;
			}
		moves += 3;
		Swap(maxpos, i);
		}
	
	//List is known to be ordered after sorting
	list_ordered = true;
	}

	
	
	

//**********************************End Sorts********************************
	
//--------------------------------Searches-----------------------------------




//searches the list for the specified target, using linear search
void AList::LinearSearch(element target, bool & found, int & position,
	int & comps) {
	//Pre: the Native Object AList is valid and target is a valid element
	//Post: 1) if target exist on the Native Object Alist, 
		//found will be true and position will be a location of the
		//target on N.O. AList
		// 2) otherwise, target will be false and position will be
		// undefined (make no promises)
	found = false;		//LCV - target not found at first
	position = 0;		//LCV - position of current position
	comps = 0;		//Accumulator - counts # comparisons
	
	while ( (!found) && (position < size) ) {
		comps++;
		if (items[position] == target)
			found = true;
		else
			position++;
		}
	}




		
	
	
	
//searches the list for the specified target, using binary search
void AList::BinarySearch(element target, bool & found, int & position,
	int & comps) {
	//Pre: the Native Object Alist is valid AND in ascending order and
		//target is a valid element
	//Post: 1) if target exist on the Native Object Alist, 
		//found will be true and position will be a location of the
		//target on N.O. AList
		// 2) otherwise, target will be false and position will be
		// undefined (make no promises)
	int low;	//LCV - lowest position of "interesting" part of list
	int high;	//LCV - highest position of "interesting" part of list
	int mid;	//LCV - middle position of "interesting" part of list
	found = false;	//LCV - target not found at first
	comps = 0;	//Accumulator - counts # comparisons
	low = 0;
	high = size - 1;

	while ( (!found) && (low <= high) ) {
		mid = (low + high) / 2;
		comps++;
		if (target == items[mid]) {
			found = true;
			position = mid;
			}
		else if (target < items[mid]) {
			comps++;
			high = mid - 1;
			}
		else {//target > items[mid] 
			comps++;
			low = mid + 1;
			}
		}
	}

	
	
	
	
	
//**********************************End Searches****************************
	
//--------------------------------Stats-----------------------------------



//calculates the theoretical computations/moves required for quadratic sorts
int AList::CalcQuad() {
	int result;	//result of theoretical quadratic comp/move
	
	result = (size * size / 2) - (size / 2);
	
	return result;
	}
	
	
	
	
	
	
//calculates the theoretical computations required for logarithmic searches
int AList::CalcLog() {
	int remain;	//LCV - size of list; size of list as it's halved
	int counter;	//Accumulator - counts # times list is halved
	
	remain = size;
	counter = 0;
	while (remain > 0) {
		remain /= 2;
		counter++;
		}
	
	return counter;	
	}
	
	
	
	
//**********************************End Stats********************************
	
//-------------------------------Public Methods-------------------------------



//should be called right after the creation of the object
//sets the N.O. AList to be a valid empty list
void AList::FirstLoad() {
	//Pre: the N.O. AList cannot be valid
	//Post: the N.O. AList is valid (specifically, AList is empty)
	size = 0;
	list_ordered = true;
	}
	
	
	
	
//runs Print()
void AList::Run_Print() {
	cout << "Current list:  ";
	
	//display contents of list
	if (size > 0)
		Print();
	else //size <= 0
		cout << "(empty) ";
	
	if (list_ordered == true)
		cout << "(KNOWN to be ordered)" << endl << endl;
	else //list_ordered == false
		cout << "(NOT KNOWN to be ordered)" << endl << endl;
	}

	
	

	
	

//runs Read(), display output
void AList::Run_Read() {
	cout << endl << "Resetting the current list from the keyboard."
		<< endl << endl;
	
	Read();
		
	cout << endl << "Finished resetting, " << size 
		<< " elements entered." << endl << endl;
	}
	

	
	
	
	
	
	
//runs GenRandList(), display output
void AList::Run_GenRandList() {
	int list_size;		//input - desired list size
	int range_high;		//input - desired upper limit
	int range_low;		//input - desired lower limit
	
	cout << endl << "Resetting the current list "
		<< "using randomly generated elements." << endl << endl;
		
	//get desired list size
	cout << "Enter the desired number of elements (0 to " << MLS << "): ";
	list_size = read_int();
	while ((list_size > MLS) || (list_size < 0)) {
		cout << "Response must be between 0 and " << MLS
			<< ", try again: ";
		list_size = read_int();
		}
		
	//get desired lower limit
	cout << "Enter the lower limit of the range: ";
	range_low = read_int();
	
	//get desired upper limit
	cout << "Enter the upper limit of the range: ";
	range_high = read_int();
	while (range_high < range_low) {
		cout << "Must be a value higher than " << range_low
			<< ", try again: ";
		range_high = read_int();
		}

	GenRandList(list_size, range_high, range_low);
	
	//display confirmation
	cout << endl << "Finished resetting, " << size 
		<< " elements between " << range_low 
		<< " and " << range_high
		<< " randomly generated." << endl << endl;
}
	
	
	
	

//runs BubbleSort(), display calculations/moves required for sort
void AList::Run_BubbleSort() {
	int comps;		//Accumulator - counts # comparisons
	int moves;		//Accumulator - counts # moves

	cout << endl << "Performing Bubble Sort on the current list." << endl;	
	
	BubbleSort(comps, moves);
	
	cout << endl << "Theoretical sort statistics:  " << CalcQuad()
		<< " element comparisons, " << 3 * CalcQuad()
		<< " element movements " << endl;
	
	cout << "Actual sort statistics:       " << comps
		<< " element comparisons, " << moves
		<< " element movements " << endl;

	cout << endl <<  "Finishing Bubble Sort." << endl << endl;
	}

	
	
	

//runs InsertionSort(), display calculations/moves required for sort
void AList::Run_InsertionSort() {
	int comps;		//Accumulator - counts # comparisons
	int moves;		//Accumulator - counts # moves

	cout << endl << "Performing Insertion Sort on the current list." 
		<< endl;
	
	InsertionSort(comps, moves);
	
	cout << endl << "Theoretical sort statistics:  " << CalcQuad()
		<< " element comparisons, " << 3 * CalcQuad()
		<< " element movements " << endl;
	
	cout << "Actual sort statistics:       " << comps
		<< " element comparisons, " << moves
		<< " element movements " << endl;

	cout << endl <<  "Finishing Insertion Sort." << endl << endl;
	}




//runs SelectionSort(), display calculations/moves required for sort
void AList::Run_SelectionSort() {
	int comps;		//Accumulator - counts # comparisons
	int moves;		//Accumulator - counts # moves

	cout << endl << "Performing Selection Sort on the current list." 
		<< endl;
	
	SelectionSort(comps, moves);
	
	cout << endl << "Theoretical sort statistics:  " << CalcQuad()
		<< " element comparisons, ";
	
	if (size > 0)
		cout << 3 * (size - 1);
	else
		cout << 0;
	
	cout << " element movements " << endl;
	
	cout << "Actual sort statistics:       " << comps
		<< " element comparisons, " << moves
		<< " element movements " << endl;

	cout << endl <<  "Finishing Selection Sort." << endl << endl;
	}
	
	
	
	
	
	
//runs LinearSearch(), display output, and calculations required for search
void AList::Run_LinearSearch() {
	element target;		//input - element user wants to find
	bool found;		//LCV - target not found at first
	int position;		//LCV - position of current position
	int comps;		//Accumulator - counts # comparisons
	
	cout << endl << "Performing Linear Search on the current list." 
		<< endl << endl;
	
	//get desired target from user
	cout << "Enter a target element to search for: ";
	target = read_element();
	
	LinearSearch(target, found, position, comps);
	
	if (found == true)
		cout << endl << "The target was FOUND on the current list "
			<< "in position " << position << "." << endl;
	else // found == false
		cout << endl << "The target was NOT FOUND on the current list."
			<< endl;
			
	cout << endl << "Theoretical search statistics:  " << size
		<< " element comparisons" << endl;
	
	cout << "Actual search statistics:       " << comps
		<< " element comparisons" << endl;
	
	cout << endl << "Finishing Linear Search." << endl << endl;
	}
	

	

	
	
//runs BinarySearch(), display output, and calculations required for search
void AList::Run_BinarySearch() {
	//only run binary search when the list is known to be ordered
	
	if (list_ordered == true) {
		element target;		//input - element user wants to find
		bool found;		//LCV - target not found at first
		int position;		//LCV - position of current position
		int comps;		//Accumulator - counts # comparisons
				
		cout << endl << "Performing Binary Search on the current list." 
		<< endl << endl;
	
		//get desired target from user
		cout << "Enter a target element to search for: ";
		target = read_element();

		BinarySearch(target, found, position, comps);
			
		if (found == true)
			cout << endl << "The target was FOUND on "
				<< "the current list in position " 
				<< position << "." << endl;
		else // found == false
			cout << endl << "The target was NOT FOUND "
				<< "on the current list." << endl;

		cout << endl << "Theoretical search statistics:  " 
			<< 2 * CalcLog() << " element comparisons" << endl;
		
		cout << "Actual search statistics:       " << comps
			<< " element comparisons" << endl;
		
		cout << endl << "Finishing Binary Search." << endl << endl;
		}
	else //list_ordered == false
		cout << endl << "Sorry, since the current list is not known "
			<< "to be ordered, the Binary Search" << endl 
			<< "cannot be performed at this time.  "
			<< "Please sort the current list first." 
			<< endl << endl;
	}
	
	
//*****************************End Public Methods**************************
