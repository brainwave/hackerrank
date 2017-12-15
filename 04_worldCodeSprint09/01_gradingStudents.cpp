#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, input;
	cin>>n;

	vector<int> arr;
	arr.reserve(n);

	for ( int i =0; i < n; i++) {

		cin>>input;
		
		if ( input >= 38 && (( 5*(input/5+1) - input ) < 3))
			input = 5*(input/5+1);

		arr.push_back(input);
	}

	for ( auto it = arr.begin(); it != arr.end(); it++)
		cout<<*it<<endl;


	return 0;
}


