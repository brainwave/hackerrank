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

//	cout<<"Enter number of elements, followed by list of elements: ";
	cin>>arraySize;
	
	for ( int cnt = 0; cnt < arraySize && cin>>input; cnt++ ) 
		arr.push_back(input);	
	
	bubbleSort(arr);
//	printArray(arr);

	return 0;
}

void bubbleSort( vector<int>& a) {
	

	int n = a.size();
	int totalSwaps = 0;

	for (int i = 0; i < n; i++) {
	    // Track number of elements swapped during a single array traversal
	    int numberOfSwaps = 0;
    
    		for (int j = 0; j < n - 1; j++) {
       		 // Swap adjacent elements if they are in decreasing order
       		 if (a[j] > a[j + 1]) {
          		  swap(a[j], a[j + 1]);
           		 numberOfSwaps++;
        	 }
    		}
    
    	// If no elements were swapped during a traversal, array is sorted
   	 if (numberOfSwaps == 0) {
	 	cout<<"Array is sorted in "<<totalSwaps<<" swaps.";
		cout<<"\nFirst Element: "<<a[0];
		cout<<"\nLast Element: "<<a[a.size()-1];
		cout<<"\n";
       		 break;
   	 }

	 else {
		 totalSwaps += numberOfSwaps;
	 }

	}

}

void printArray( vector<int> arr) {
	
	for ( auto& it :arr )
		cout<< it <<"\t";

	cout<<"\n";
}

