#include <bits/stdc++.h>

using namespace std;

long countSplitInversions( int arr[], int leftLower, int middle, int rightUpper) {
    long result = 0;
    
    int numLeft = middle - leftLower + 1;
    int numRight = rightUpper - middle;
    
    int tempArray[numLeft + numRight], i = 0, k = 0;
    
    while ( i <= numLeft && i <= numRight) {
        
        if ( arr[i] <= arr [ middle + i + 1 ])
            tempArray[k++] = arr[i++];
        else {
            tempArray[k++] = arr[ middle + i + 1 ];        
            result += middle - i + 1;
        }
    }
    
    while ( i < numLeft )
        tempArray[k++] = arr[i++];
    while ( i < numRight )
        tempArray[k++] = arr[i++];
    
    arr = tempArray;
    
    return result;
    
}

long countInversions(int arr[], int leftLower, int rightUpper ) {
    
    if ( rightUpper <= leftLower )
        return 0; //Done when array size <= 1
    
    else {
        
        int middle = leftLower + (rightUpper - leftLower) /2;
        long result = countInversions ( arr, leftLower, middle);
        result += countInversions ( arr, middle+1, rightUpper);
        result += countSplitInversions( arr, leftLower, middle, rightUpper);
        
        return result;
    }
    
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int arr[n];
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
       // long result = countInversions(arr, 0, n-1 );
        cout << result << endl;
    }
    return 0;
}

