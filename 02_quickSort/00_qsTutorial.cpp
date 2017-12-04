//Partitioned with last element as pivot
//
#include <vector>
#include <iostream>

using namespace std;

// A utility function to swap two elements
void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}


int partition( vector<int>& arr, int low, int high) {

	int pivot = arr[high];
	int i = low-1;

	for ( int j = low; j < high; j++ ) {
	
		if ( arr[j] <= pivot ) {
			
			i++;
			swap( arr[i], arr[j] );

		}
	
	}

	swap( arr[i+1], arr[high] );
	return i+1;

}

void quickSort( vector<int>& arr, int low, int high) {
	
	//as long as array size is more than one, partition and sort

	if ( low < high ) {

		int p = partition(  arr, low, high);

		quickSort( arr, low, p-1 ); 
		
		quickSort ( arr, p+1, high);
	
	}

}


 ;
int main() {
    
    int n, input, count=0;
    cin >> n;

    vector<int> arr(n);

    while ( count < n ) {
	    cin>>input;
	    arr[count++] = input;
    }

    count = 0;

    quickSort( arr, 0, n-1);

    while ( count < n )
	    cout<<arr[count++];

   return 0;
}
