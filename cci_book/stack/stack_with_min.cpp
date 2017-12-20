//Stack implementation that can return min element in O(1) time.
//
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

class Stack {
	
	Node* top=NULL;
	Node* min = NULL;

public:

	void push(int newData) {
		
	
		Node* temp = new Node(newData); 				//Create a new node with incoming data
		temp->next = top;						//link it to existing topmost data

		if ( (top == NULL) || (min->nodeData > temp->nodeData) ) 	//If min node needs updating, copy current node pointer to it
	 		min = temp;

		top = temp;							//Make "top" point to the newly created and linked node

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

	//Function to retrieve minimum element in O(1) time
	Node getMin() {
		return *min;
	}


};

int main() {
	Stack stack;

	int numElements, input;
	cout<<"\nNumber of elements to be pushed into stack: ";
	cin>>numElements;

	for ( int i = 0; i < numElements; i++ ){
		cin>>input;
		stack.push(input);	
	}

	cout<<"\nStack: ";

	while( !stack.isEmpty() ) {
		cout<<stack.get()<<" ";
		stack.pop();
	}

	Node minNode = stack.getMin();

	cout<<"\nMinimum entered value is: "<<minNode.nodeData<<endl;

	return 0;
}

