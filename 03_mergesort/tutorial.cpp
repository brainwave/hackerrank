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

	while ( array.size() > 0 ) {
	
		int output = array.back();
		array.pop_back();
		cout<<output<<" ";
	}


	return 0;
}

void merge( 

void mergeSort( vector<int> &array, int low, int high) {

	int middle = (low + high) / 2;
	
	if ( high > low ) //element is not one element
	{

		mergeSort ( array, low, middle );
		mergeSort ( array, middle+1, high);

	}

}
