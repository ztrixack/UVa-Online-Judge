//============================================================================
// Name        : 272 - TEX Quotes.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 272 TEX Quotes in C++, Ansi-style
// Run Time    : 0.020 seconds
//============================================================================

#include <iostream>
using namespace std;
#define FRI(i, a, b) for(i = a; i < b; ++i)

int main() {
	int iter;
	bool isf = true;
	string text;
	while (getline(cin, text)) {
		while (true) {
			iter = text.find('"', 0);
			if (iter < 0) break;
			if (text[iter] == '"') {
				if (isf) {
					text.replace(iter, 1, "``");
				} else {
					text.replace(iter, 1, "''");
				}
				isf = !isf;
			}
		}
		cout << text << endl;
	}
	return 0;
}
