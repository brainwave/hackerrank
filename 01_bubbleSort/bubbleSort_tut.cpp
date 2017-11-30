#include <iostream>
#include <vector>

using namespace std;

void bubbleSort( vector<int>&); 
void printArray( vector<int> );
void swap(int &a, int&b) {

	int temp = a;
	a = b;
	b = temp;

}

int main() {

	int arraySize, input;
	vector<int> arr;

	cout<<"Enter number of elements, followed by list of elements: ";
	cin>>arraySize;
	
	for ( int cnt = 0; cnt < arraySize && cin>>input; cnt++ ) 
		arr.push_back(input);	
	
	bubbleSort(arr);
	printArray(arr);

	return 0;
}

void bubbleSort( vector<int>& array) {
	//code to sort the array in place	
	bool isSorted = false;
	int lastUnsorted = array.size() - 1;

	while ( !isSorted ) {
	
		isSorted = true;
		for ( int i = 0; i < lastUnsorted; i++ ) {
		
			if ( array[i] > array[ i+1 ]) {
				swap( array[i], array[i+1] );
				isSorted = false;

			}
		}
		lastUnsorted--;
	}
	

}

void printArray( vector<int> arr) {
	
	for ( auto& it :arr )
		cout<< it <<"\t";

	cout<<"\n";
}

