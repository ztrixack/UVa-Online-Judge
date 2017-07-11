//============================================================================
// Name        : 102 - Ecological Bin Packing.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 102 Ecological Bin Packing in C++, Ansi-style
// Run Time    : 0.120 seconds
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>

using namespace std;

int main() {
	int sum, min, ip, ians;
	int bottle[3][3];
	string str[] = {
			"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"
	};
	while (cin >> min) {
		int permu[] = {0, 1, 2};
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (i == j && j == 0) {
					bottle[i][j] = min;
				} else {
					cin >> bottle[i][j];
				}
			}
			swap (bottle[i][1], bottle[i][2]);
		}
		min = 2147483647;
		ians = ip = 0;
		do {
			sum = 0;
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					if (j != permu[i]) {
						sum += bottle[i][j];
					}
				}
			}
			if (min > sum) {
				min = sum;
				ians = ip;
			}
			ip++;
		} while (next_permutation(permu, permu + 3));
		cout << str[ians] << ' ' << min << endl;
	}
	return 0;
}
