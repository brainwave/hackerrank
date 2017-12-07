#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeSort( vector<int> &array, int l, int r);

int main() {

	int input, n;
	vector<int> array;

	cin>>n;

	for ( int i = 0; i < n; i++ ) {
		cin >> input;
		array.push_back(input);
	}

	mergeSort( array, 0, n-1 );

	//Prints in reverse order

	while ( array.size() > 0 ) {
	
		int output = array.back();
		array.pop_back();
		cout<<output<<" ";
	}


	return 0;
}

void merge( vector<int> &array, int low, int middle, int high) {


	int n1 = middle - low + 1; //size of smaller sub-array
	int n2 = high - middle; 

	int L[n1], R[n2];

	int i, j, k;

	//Copy sorted data into temp arrays
	for ( i = 0; i < n1; i++ )
		L[i] = array[low+i];
	for ( j = 0; j < n2; j++ )
		R[j] = array[middle+1+j];

	//Merge temp arrays back into the main array
	i = 0; j = 0; k = low;//Reset counters
	
	while ( i < n1 and j < n2 ) {

		if ( L[i] <= R[j] ) 
			array[k] = L[i++];

		else
			array[k] = R[j++];

		k++;
	}

	while ( i< n1 )
		array[k++] = L[i++];

	while ( j < n2 )
		array[k++] = R[j++];

}

void mergeSort( vector<int> &array, int low, int high) {

	int middle = (low + high) / 2;
	
	if ( high > low ) //element is not one element
	{

		mergeSort ( array, low, middle );
		mergeSort ( array, middle+1, high);

	}

	merge ( array, low, middle, high );

}
