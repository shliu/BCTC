#include <iostream>
#undef NULL
const int NULL = 0;
using namespace std;


//*******************************global section*******************************
typedef char element;		//datatype of "element"
const element SENTINEL = -1;	//value of element that ends user input


//reads single type checked element
element read_element();


//listnode class
	//each listnode consists of 2 sides:
	//1) one side, called "data" holds a single element
	//2) the other side, called "next" holds the address to the 
	//next listnode
class listnode {
	public:
		element data;		//holds actual data
		listnode * next;	//holds address to next listnode
	};
	
	
//Linked List class
	//a valid linked list is defined as:
		//1) "head" points to the first listnode
		//2) followed by a series of listnodes
		//3) last listnode pointing to NULL
		//4) "tail" points to last listnode
	//when the list is empty (but also valid):
		//1) "head" points to NULL
		//2) "tail" is undefined
class LList {
	private:
		listnode * head;		//points to the first listnode
		listnode * tail;		//points to the last listnode
	public:
		//constructor/destructor:
		LList();	//constructor - auto called upon N.O. birth
		~LList();	//destructor - auto called before N.O. death
		//methods:
		void Clean();
		void Print();
		void ReadForward();
		void ReadBackward();
		void InsertTail(element val);
		void InsertHead(element val);
		element DeleteHead();
		element DeleteTail();	//extra credit
		void Steal(LList & Victim);
		void Append(LList & Donor);
		void Duplicate(LList & Source);
		void Reverse();
		void ReserveInPlace();	//extra credit
		bool IsFull();
		bool IsEmpty();
	};
	
	
class LStack {
	private:
		LList Employee;
	public:
		LStack();
		~LStack();
		void Push(element thing);
		element Pop();		
		bool IsFull();
		bool IsEmpty();
	};
	

class LQueue {
	private:
		LList Employee;
	public:
		LQueue();
		~LQueue();
		void Enqueue(element thing);
		element Dequeue();		
		bool IsFull();
		bool IsEmpty();
	};
	

//---------------------------End global section-------------------------------

//*****************************MAIN FUNCTION*****************************





//**main function**
int main(){
	LStack myStack;
	
	char user_input;
	
	cin >> user_input;
	while (user_input != '!') {
		myStack.Push(user_input);
		cin >> user_input;
		}
	
	while (!myStack.IsEmpty())
		cout << myStack.Pop() << ", ";
	
	cout << endl << endl;
	}
	
	
	
//---------------------------END MAIN FUNCTION-------------------------------
	
//*****************************global functions*****************************
	
	
//type checks input to see if it matches "element"
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
	
	
//---------------------------End global functions-----------------------------
	
//************************LList constructor/destructor************************


//constructor
LList::LList(){
	//pre: none
	//post: the N.O. LList is empty

	head = NULL;
	}
	

//destructor
LList::~LList(){
	//pre: the N.O. LList is valid
	//post: the N.O. LList is empty

	Clean();
	}
	

//-------------------End LList constructor/destructor------------------------

//*****************************LList methods*********************************
	
	
bool LList::IsFull() {
	return false;
	}
	
	
bool LList::IsEmpty() {
	return (head == NULL);
	}
	
	
//cleans the LList of all nodes
void LList::Clean(){
	//pre: N.O. is valid
	//post: N.O. is now empty and all of its former listnodes have
		//had their memory returned to the system memory pool
		
	listnode * temp;		//points listnode to be deleted
	
	//we point "head" at the next listnode, maintaining a valid LList
	//while "temp" points to the listnode we want to delete
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
		}
	}
	

//prints out the entire LList	
void LList::Print(){
	//pre: N.O. is valid
	//post: N.O. is unchanged, and the element it contains
		//have been displayed
		
	//LCV - begins at head then traverses entire LList
	listnode * temp;		
	
	temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;	//pointer increment
		}
	cout << endl;
	}
	
	
//reads in data, and puts new data at the END of linked list
void LList::ReadForward(){
	//pre: N.O. is valid
	//post: N.O. is valid, containing elements entered by user
		//in forward order
		
	Clean();		//removes any existing listnodes in linked list
	
	element userval;	//input/LCV - stores user element input
	listnode * temp;	//keeps track of new listnode
	
	cout << "Enter elements, " << SENTINEL << " to stop: ";
	userval = read_element();
	while (userval != SENTINEL){
		temp = new listnode;
		temp->data = userval;
		temp->next = NULL;
		if (head == NULL)	//first time
			head = temp;
		else //not first time
			tail->next = temp;
		tail = temp;
		userval = read_element();
		}
	}
	
	
//reads in data, and puts new data at the FRONT of linked list
void LList::ReadBackward(){
	//pre: N.O. is valid
	//post: N.O. is valid, containing elements entered by user
		//in backward order
		
	Clean();		//removes any existing listnodes in linked list
	
	element userval;	//input/LCV - stores user element input
	listnode * temp;	//keeps track of new listnode
	
	cout << "Enter elements, " << SENTINEL << " to stop: ";
	userval = read_element();
	while (userval != SENTINEL){
		temp = new listnode;
		temp->data = userval;
		temp->next = head;
		if (head == NULL)	//first time
			tail = temp;
		else //not first time
			;
		head = temp;
		userval = read_element();
		}
	}
	
	
//inserts one listnode containing element val, at the END of list
void LList::InsertTail(element val){
	//pre: N.O. is valid, and element "val" is valid
	//post: N.O. is unchanged, except it now has an addition
		//listnode at its tail-end containing element val
		
	listnode * temp;		//points to new listnode
	
	temp = new listnode;
	temp->data = val;
	temp->next = NULL;
	if (head == NULL) //empty list
		head = temp;
	else //not empty list
		tail->next = temp;
	tail = temp;
	}
	
	
//inserts one listnode containing element val, at the FRONT of list
void LList::InsertHead(element val){
	//pre: N.O. is valid, and element "val" is valid
	//post: N.O. is unchanged, except it now has an addition
		//listnode at its head-end containing element val
		
	listnode * temp;		//points to new listnode
	
	temp = new listnode;
	temp->data = val;
	temp->next = head;
	if (head == NULL) //empty list
		tail = temp;
	else //not empty list
		;
	head = temp;
	}
	
	
//removes first listnode in the list and returns the element in listnode
element LList::DeleteHead(){
	//pre: N.O. is valid and non-empty
	//post: N.O. is unchanged, except the listnode at the head-end
		//has been removed, its memory returned to the system pool,
		//called heap, and its element returned to the caller
		
	element val;		//holds element in listnode to be deleted
	listnode * temp;	//points to the listnode to be deleted
	
	temp = head;
	head = head->next;
	val = temp->data;
	delete temp;
	return val;
	}
	
	
//removes last listnode in the list and returns the element in the listnode
element LList::DeleteTail() {	//extra credit
	//pre: N.O. is valid and non-empty
	//post: N.O. is unchanged, except the listnode at the tail-end
		//has been removed, its memory returned to the system pool,
		//called heap, and its element returned to the caller
		
	element val;		//holds element in listnode to be deleted
	listnode * temp;	//points to the listnode to be deleted
	
	temp = head;
	while (temp->next != tail)
		temp = temp->next;
	//by the end of above loop we know:
		//"temp" is now pointing to the second to last listnode
	
	val = tail->data;
	delete tail;
	tail = temp;
	tail->next = NULL;
	return val;
	}
	
	
//takes over "Victim"'s listnodes after throwing away N.O.'s listnodes
void LList::Steal(LList & Victim) {
	//pre: N.O. is valid, the LList Victim is valid
	//post: N.O. has returned all of its memory to system pool (heap)
		//and now contains the listnodes originally on the 
		//Victim LList.  The Victim LList is empty
		
	Clean();	//N.O.'s Clean() method - removes all self listnodes

	//if the visiting/local object's class names are the same as N.O.'s, 
		//all co-members of the visiting/local object are visible 
		//to N.O. (including private co-members)
	head = Victim.head;		
	tail = Victim.tail;		
	Victim.head = NULL;
	}
	
	
//adds "Donor"'s listnodes to N.O.'s existing listnodes
void LList::Append(LList & Donor) {
	//pre: N.O. is valid, the LList Donor is valid
	//post: N.O. has all listnodes originally belonging to itself
		//and Donor.  Donor object is empty
		
	if (head != NULL) //N.O. is not empty
		tail->next = Donor.head;
	else //N.O. is empty
		head = Donor.head;
		
	if (Donor.head != NULL) //Donor is not empty
		tail = Donor.tail;
	else //Donor is empty
		;
	}
	
	
//makes N.O. an exact copy of "Source"
void LList::Duplicate(LList & Source) {
	//pre: N.O. is valid, the LList Source is valid
	//post: LList Source is valid.  N.O. will be an exact
		//listnode for listnode copy of Source
		
	Clean();	//removes any existing listnodes in linked list
	
	listnode * temp;
	temp = Source.head;
	while (temp != NULL) {
		InsertTail(temp->data);		//N.O.'s InsertTail() method
		temp = temp->next;
		}
	}
	
	
//reverses the listnodes in the N.O. LList
void LList::Reverse() {
	//pre: the N.O. is valid
	//post: the N.O. is unchanged, except elements in its listnodes
		//are now in reverse order
		
	LList Helper;		//local LList objct. temp. holds N.O. contents
	
	while (head != NULL)
		Helper.InsertHead(DeleteHead());
	//by the end of above loop we'll know:
		//Helper LList will contain contents of N.O.'s listnodes in
		//reverse order
		
	//N.O. now takes over Helper's listnodes
	Steal(Helper);	
	}
	
	
	
	

//reverses the listnodes in the N.O. LList - cannot use extra memory space
void LList::ReserveInPlace() {	//extra credit
	//pre: the N.O. is valid
	//post: the N.O. is unchanged, except elements in its listnodes
		//are now in reverse order
		
	if ((head != NULL) && (head->next != NULL)) {
		//since we're inside of the if statement,
			//there MUST be at least 2 listnodes in the LList
			
		listnode * prev;		//points to previous listnode
		listnode * curr;		//points to current listnode
		listnode * succ;		//points to succeeding listnode
		
		prev = head;
		curr = head->next;
		succ = curr->next;
		
		//since there are at least 2 listnodes, we have to reverse
			//listnodes (loop body) at least once - dowhile loop 
		//we're done when:
			//prev == tail OR curr == NULL, only need to pick one
			//becase we increment both prev and curr every loop
		do {
			curr->next = prev;	//reverse listnode
			
			//pointer increments:
			prev = curr;
			curr = succ;
			if (succ != NULL)
				succ = succ->next;
			else
				;
			} while (prev != tail);
		//by end of the above loop we know:
			//directions of all listnodes have been reversed
			//but the two ends of the listnodes aren't clear
		//however, we know that:
			//1) head is currently pointing to new tail
			//2) tail is currently pointing to new head
			//3) prev is also pointing to new head
		
		tail = head;
		tail->next = NULL;
		head = prev;		
		}
	else
		cout << endl << "LList has less than 2 listnodes "
			<< "and is therefore already ordered." << endl;
	}
	
	
//---------------------------End LList methods------------------------------

//*****************************LStack methods*********************************
LStack::LStack(){
	}
	
LStack::~LStack(){
	}
	
void LStack::Push(element thing){
	Employee.InsertHead(thing);
	}
	
element LStack::Pop(){
	return Employee.DeleteHead();
	}
	
bool LStack::IsFull(){
	return Employee.IsFull();
	}

bool LStack::IsEmpty(){
	return Employee.IsEmpty();
	}
	
//---------------------------End LStack methods------------------------------
	
//*****************************LQueue methods*********************************
LQueue::LQueue(){
	}
	
LQueue::~LQueue(){
	}
	
void LQueue::Enqueue(element thing){
	Employee.InsertTail(thing);
	}
	
element LQueue::Dequeue(){
	return Employee.DeleteHead();
	}
	
bool LQueue::IsFull(){
	return Employee.IsFull();
	}

bool LQueue::IsEmpty(){
	return Employee.IsEmpty();
	}
	
//---------------------------End LQueue methods------------------------------

	
	
	
	
	
	
	
	
	
	
	
