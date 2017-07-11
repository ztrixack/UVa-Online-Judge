//============================================================================
// Name        : 291 - The House Of Santa Claus.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 278 The House Of Santa Claus in C++, Ansi-style
// Run Time    : 0.008 seconds
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define FRI(i, a, b) for (i = a; i < b; ++i)

int mem[] = { 1, 2, 3, 1, 5, 3, 4, 5, 2 };

int main() {
	int i, x, y;
	bool ma;
	do {
		bool direct[5][5] = { {0, 1, 1, 0, 1}, {0, 0, 1, 0, 1}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 0} };
		ma = true;
		FRI (i, 0, 8) {
			x = min(mem[i] - 1, mem[i + 1] - 1);
			y = max(mem[i] - 1, mem[i + 1] - 1);
			if (!(direct[x][y]) || direct[y][x]) {
				ma = false;
				break;
			}
			direct[y][x] = true;
		}
		if (ma) {
			FRI(i, 0, 9) cout << mem[i];
			cout << endl;
		}
		next_permutation(mem, mem + 9);
	} while (mem[0] == 1);
	return 0;
}
