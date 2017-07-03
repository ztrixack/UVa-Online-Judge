//============================================================================
// Name        : 146 - ID Codes.cpp
// Author      : ztrixack
// Copyright   : MIT
// Description : 146 ID Codes in C++, Ansi-style
// Run Time    : 0.008 seconds
//============================================================================

#include <iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
int main() {
	char text[100];
	while (gets(text) && (text[0] != '#')) {
		if (next_permutation(text, text + strlen(text))) {
			cout << text << endl;
		} else {
			cout << "No Successor" << endl;
		}
	}
	return 0;
}
