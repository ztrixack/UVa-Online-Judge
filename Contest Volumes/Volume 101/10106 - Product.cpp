//============================================================================
// Name        : 10106 - Product.cpp
// Author      : ztrixack
// Copyright   : MIT
// Description : 10106 Product in C++, Ansi-style
// Run Time    : 0.008 seconds
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main () {
	string snumx, snumy, tmp;
	int lx, ly, c = 0;
	int nx[255] = {0}, ny[255] = {0}, ans[550] = {0};
	while (cin >> snumx >> snumy) {
		lx = snumx.length();
		ly = snumy.length();
		for (int i = 0; i < lx; i++) nx[lx - (i + 1)] = snumx[i] - 48;
		for (int i = 0; i < ly; i++) ny[ly - (i + 1)] = snumy[i] - 48;
		for (int i = 0; i < ly; i++) {
			for (int j = 0; j < lx; j++) {
				c = i + j;
				ans[c] += nx[j] * ny[i];
				while (ans[c] / 10 != 0) {
					ans[c + 1] += ans[c] / 10;
					ans[c] %= 10;
					c++;
				}
			}
		}

		if (snumx == "0" || snumy == "0") c = 0;
		for (int i = c; i >= 0; i--) {
			cout << ans[i];
			ans[i] = 0;
		}
		cout << endl;
	}
}
