//============================================================================
// Name        : 167 - The Sultan's Successors.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 167 The Sultan's Successors in C++, Ansi-style
// Run Time    : 0.000 seconds
//============================================================================

#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define SQUARE		8

int main() {
	int n, sum, ans;
	bool next;
	int score[SQUARE][SQUARE];

	cin >> n;
	while (n--) {
		int permutations[] = {0, 1, 2, 3, 4, 5, 6, 7};
		for (int i = 0; i < SQUARE; ++i) {
			for (int j = 0; j < SQUARE; ++j) {
				cin >> score[i][j];
			}
		}
		ans = 0;
		do {
			next = false;
			for (int i = 0; i < SQUARE; ++i) {
				for (int j = i + 1; j < SQUARE; ++j) {
					int offset = j - i;
					if (permutations[i] + offset == permutations[j] || permutations[i] - offset == permutations[j]) {
						next = true;
						i = j = SQUARE;
					}
				}
			}

			if (next) {
				continue;
			}

			sum = 0;
			for (int i = 0; i < SQUARE; ++i) {
				sum += score[i][permutations[i]];
			}
			if (sum > ans) {
				ans = sum;
			}
		} while ( next_permutation(permutations, permutations + SQUARE) );
		cout << setw(5) << ans << endl;
	}
	return 0;
}
