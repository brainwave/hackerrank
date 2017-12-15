#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	string s;
	cin >> s;
	
	int n, input;
	cin >> n;

	int arr[26] = {0};

	for ( char&c : s ) 
		arr[ (int)c - 97 ] ++;

	//Function to test if the array is updated as expected - comment out later
	//for ( int& a: arr )
	//		cout<<a<<endl;

	for ( int i = 0; i < n; i++ ){
		cin >> input;

		for ( int i = 0; i < 26; i ++) {
					
		}

	}

	return 0;
}

