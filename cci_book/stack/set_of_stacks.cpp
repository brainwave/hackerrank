#include <iostream>
#include <vector>
#include <algorithm>

#define THRESHOLD 3

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

	void clear() {
		//clear stack by removing reference to the top node
		top = NULL;
	}
};

class setOfStacks{
	
	int count = 0;
	vector<Stack> setOfStacks;
	Stack bufferStack;

public:
	void push(int newData) {

		if (count + 1 >= THRESHOLD)
			cout<<"\nNext entry to new stack\n";
	
		if (++count >= THRESHOLD) {

			bufferStack.push(newData);
			setOfStacks.push_back(bufferStack);
			bufferStack.clear();
			count = 0; } 
		else
			bufferStack.push(newData);
	}

	void pop() {

		if (!bufferStack.isEmpty()) {
			bufferStack.pop();

		}
		else if (!setOfStacks.empty()){

			bufferStack = setOfStacks.back();
			setOfStacks.pop_back();
			bufferStack.pop();

		}

	}

	void popAt(int index) {

		if (index == setOfStacks.size()) 
			bufferStack.pop();
		else 
		{
			cout<<"\nPopping "<<setOfStacks.at(index).get()<<endl;
			(setOfStacks.at(index)).pop();
		}
	}

	int get() {

		if (!bufferStack.isEmpty()) 
			return	bufferStack.get();

		else if (!setOfStacks.empty())
			return (setOfStacks.back()).get();
		
	}

	bool isEmpty() {
		return bufferStack.isEmpty() && setOfStacks.empty(); 
	}

};


int main() {
	setOfStacks stack;

	int numElements, input;
	cout<<"\nNumber of elements to be pushed into stack: ";
	cin>>numElements;

	for ( int i = 0; i < numElements; i++ ){
		cin>>input;
		stack.push(input);	
	}

	stack.popAt(0);

	cout<<"\nStack: ";

	while( !stack.isEmpty() ) {
		cout<<stack.get()<<" ";
		stack.pop();
	}

	return 0;
}

