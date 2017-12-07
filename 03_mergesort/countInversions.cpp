#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long countInversions( int[], int, int);
long countSplitInversions( int[], int, int, int);

int main() {

	int d; 
	cin>>d;
	
	for ( int i = 0; i < d; i++ ) {

		int n; 
		cin >> n;

		int arr[n];

		for ( int j = 0; j < n; j++ )
			cin>>arr[j];

		long result = countInversions(arr, 0, n-1);
	
		for ( int j = 0; j < n; j++ )
			cout<<arr[j]<<" ";
		
		cout<< "\nResult: " <<result << endl;
	}
		
	return 0;
}

long countInversions( int arr[], int low, int high) {

	if ( low >= high) 
		return 0;
	
	else {
	
		int middle = low  + (high - low)/2;
		
		long result = countInversions( arr, low, middle);
		result += countInversions(arr, middle+1, high);

		result+= countSplitInversions ( arr, low, middle, high);
		return result;
	}

}

long countSplitInversions( int arr[], int low, int middle, int high) {

	long count = 0;
	
	//Create tempororary array to store sorted values
	//Have index for start of left and right subparts
	int tempArray[high - low + 1];
	int k = 0, i = low, j = middle + 1;

	//while index i is lower than ends of both left and right subarrays
	while ( i <= middle && j <= high) {

		if ( arr[i] <= arr[j] )
			tempArray[k++] = arr[i++];

		else {
			tempArray[k++] = arr[j++];
			count += middle - i + 1;		
		}
	}	

	while ( i <= middle )
		tempArray[k++] = arr[i++];

	while ( j <= high )
		tempArray[k++] = arr[j++];

	for ( int i = low; i <= high; i++ ) 
		arr[i] = tempArray[ i - low ];

	return count;
}
