//============================================================================
// Name        : 10071 - Back To High School Physics.cpp
// Author      : ztrixack
// Copyright   : MIT
// Description : 10071 Back To High School Physics in C++, Ansi-style
// Run Time    : 0.120 seconds
//============================================================================

#include <iostream>
using namespace std;

int main () {
	long long int v, t;
	while(cin >> v >> t) {
		v *= t << 1;
		cout << v << endl;
	}

}
