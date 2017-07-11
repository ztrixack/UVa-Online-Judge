//============================================================================
// Name        : 278 - Chess.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 278 Chess in C++, Ansi-style
// Run Time    : 0.008 seconds
//============================================================================

/* *** King ***
 * 	o	o	o
 * 	o	K	o
 * 	o	o	o
 */

/* *** Knight ***
 *		o	x	o
 *	o		x		o
 *	x	x	k	x	x
 * 	o		x		o
 * 		o	x	o
 */

/* *** Rook ***
 * 			o
 * 			o
 * 			o
 * 	o	o	r	o	o	o	o	o
 * 			o
 * 			o
 * 			o
 * 			o
 */

/* *** Queen ***
 * 			o			o
 * 	o		o		o
 * 		o	o	o
 * 	o	o	Q	o	o	o	o	o
 * 		o	o	o
 * 	o		o		o
 * 			o			o
 * 			o				o
 */

#include <iostream>
#include <cmath>
using namespace std;
#define FRI(i, a, b) for(i = a; i < b; ++i)

int main() {
	char ch;
	int mc, m, n, ans;
	cin >> mc;
	while(mc--) {
		cin >> ch >> m >> n;
		switch (ch) {
		case 'r':
		case 'Q':
			ans = min(m, n);
			break;
		case 'k':
			ans = (m * n + 1) / 2;
			break;
		case 'K':
			ans = ((m + 1) / 2) * ((n + 1) / 2);
			break;
		}
		cout << ans << endl;
	}
	return 0;
}
