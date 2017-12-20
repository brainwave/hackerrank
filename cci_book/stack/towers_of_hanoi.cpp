#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void move ( stack<int>& source, stack<int>& dest ) {
	//Move a single disc from source to dest
	cout<<"\nMoving "<<source.top();

	int temp = source.top();
	source.pop();
	dest.push(temp);

}

void printStack ( string s, stack<int> buffer ) {

	cout<<endl<<s<<": ";

	while ( !buffer.empty() ) {
		cout<<buffer.top()<<" ";
		buffer.pop();
	}
}


void towerOfHanoi ( int n, stack<int>& source, stack<int>& dest, stack<int>& aux) {

	if ( n == 1)
		move(source, dest);

	else {

		towerOfHanoi ( n-1, source, aux, dest);

		move(source, dest);

		towerOfHanoi ( n-1, aux, dest, source);

	}
}
int main() {

	stack<int> source, dest, aux, buffer;

	int numDisks;

	cout<<"\nEnter number of discs: ";
	cin>>numDisks;

	for ( int i = numDisks; i > 0; i-- ) 
		source.push(i);

	printStack("Source", source);
	printStack("Dest", dest);
	printStack("Aux", aux);
	cout<<endl;

	towerOfHanoi ( numDisks, source, dest, aux );

	cout<<endl;
	printStack("Source", source);
	printStack("Dest", dest);
	printStack("Aux", aux);
		
	return 0;
}

