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

	return 0;
}

