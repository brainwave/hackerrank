#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 =  high - mid;

    //define tempArray to be size of the passed array
    int temp[ high - low + 1 ], i = low, k = 0, j = mid+1;

    while ( i <= mid && j <= high ) {
    
	    if ( a[i] <= a[j] ) //Compare next elem. between subarrays
		    temp[k++] = a[i++];
	    else
		    temp[k++] = a[j++];
    }

    while ( i <= mid )
	    temp[k++] = a[i++];
    while ( j <= high )
	    temp[k++] = a[j++];

    for ( i = low; i <= high; i++ )
	    a[i] = temp [i-low];
    

}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m =  ( l + r )/2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

int main() {

        int n;

        cin >> n;

        int arr[n];

        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
       mergeSort(arr, 0, n-1 );

        for(int arr_i = 0; arr_i < n; arr_i++){
           cout << arr[arr_i] <<" ";
        }

	cout<<endl;

    return 0;
}

