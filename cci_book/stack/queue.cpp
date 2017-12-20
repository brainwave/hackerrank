#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {

	int nodeData;
	Node* next = NULL;

	Node(int newData){
		nodeData = newData;
	}

};

class Queue{

	//Null initialize pointers to front and back
	Node* front = NULL;
	Node* back = NULL;

public:

	void enQ ( int newData ) {
		
		if ( front ) {			//If its not the first element in the queue
		
		back->next = new Node(newData); //Add incoming data to a new node at the end
		back = back->next;		//Point back to newly added node

		}

		else {
			back = new Node(newData); //create the first node
			front = back;		//Make front same as back
		}

	}

	Node deQ ( ) {

		Node* node = front;

		if ( front == back ) {

			front = NULL;
			back = NULL;
		}

		else 
			front = front->next;
	

		return *node;
	}

	bool isEmpty() {
	
		if (front)
			return false;

		return true;
	}

};

class Stack {
	
	Node* top=NULL;

public:

	void push(int newData) {

		Node* temp = new Node(newData); 	//Create a new node with incoming data
		temp->next = top;			//link it to existing topmost data
		top = temp;				//Make "top" point to the newly created and linked node

	}

	void pop() {
		if (top) 
			top = top->next;
		
	}
	
	int get() {
		return top->nodeData;	
	}

	bool isEmpty() {
		if (top)
			return false;

		return true;
	}


};

int main() {

	Queue q;

	int numElements, input;
	cout<<"\nNumber of elements to be queued: ";
	cin>>numElements;

	
	for ( int i = 0; i < numElements; i++ ){
		cin>>input;
		q.enQ(input);	
	}

	cout<<"\nQueue: ";

	while( !q.isEmpty() ) 
		cout<<q.deQ().nodeData<<" ";

	return 0;
}

