//============================================================================
// Name        : 256 - Quirksome Squares.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 256 Quirksome Squares in C++, Ansi-style
// Run Time    : 0.008 seconds
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;
#define FRI(i, a, b) for(i = a; i < b; ++i)
#define MAX 1<<16

int main() {
	int i, num;
	int digit, lim, table[MAX];
	FRI(i, 0, MAX) table[i] = i * i;
	while (cin >> digit) {
		lim = (int)pow(10.0, digit/2);
		FRI(i, 0, lim) {
			num = table[i]/lim + table[i]%lim;
			if (table[i] == num * num) {
				cout.width(digit);
				cout.fill('0');
				cout << table[i] << endl;
			}
		}
	}
	return 0;
}
