#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long countInversions(int[], int);
long mergeSort ( int[], int, int);
long merge( int[], int[],int, int);

int main() {

	int d; 
	cin>>d;
	
	for ( int i = 0; i < d; i++ ) {

		int n; 
		cin >> n;

		int arr[n];

		for ( int j = 0; j < n; j++ )
			cin>>arr[j];

		long result = countInversions(arr, n-1);
		
		cout<< result << endl;
		

	}
		
	return 0;
}

long countInversions( int arr[], int high) {

	
	if ( high > 0) 
		
		long result = mergeSort( arr, 0, high);

}

long mergeSort( int arr[], int low, int high) {
	
	if ( high > low ) {
	
		int middle = ( low + high )/2; 
		long cntInv1 = mergeSort ( arr, low, middle);
		long cntInv2 = mergeSort ( arr, middle+1, high); 

		return ( cntInv1 + cntInv2 + merge(  

	}
	
}
