//============================================================================
// Name        : 10300 - Ecological Premium.cpp
// Author      : ztrixack
// Copyright   : MIT
// Description : 10300 Ecological Premium in C++, Ansi-style
// Run Time    : 0.008 seconds
//============================================================================

#include <iostream>
using namespace std;

int main () {
	int n, f, x, y, z, sum;
	cin >> n;
	for (int i = 0; i < n; i++) {
		sum = 0;
		cin >> f;
		for (int j = 0; j < f; j++) {
			cin >> x >> y >> z;
			y = x * z;
			sum += y;
		}
		cout << sum << endl;
	}
}
