//============================================================================
// Name        : 10921 - Find the Telephone.cpp
// Author      : ztrixack
// Copyright   : MIT
// Description : 10921 Find the Telephone in C++, Ansi-style
// Run Time    : 0.008 seconds
//============================================================================

#include <iostream>
using namespace std;
#define FRI(i, a, b) for(i = a; i < b; ++i)

char map[] = {'2', '2', '2', '3', '3', '3', '4', '4', '4',
		'5', '5', '5', '6', '6', '6', '7', '7', '7', '7',
		'8', '8', '8', '9', '9', '9', '9'};

int main() {
	int i, length;
	string text;
	while (getline (cin, text)) {
		length = text.length();
		FRI(i, 0, length) {
			if (text.at(i) >= 'A' && text.at(i) <= 'Z')
				text.replace(i, 1, 1, map[text.at(i) - 'A']);
		}
		cout << text << endl;
	}
	return 0;
}
