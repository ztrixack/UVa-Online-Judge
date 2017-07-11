//============================================================================
// Name        : 299 - Train Swapping.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 299 Train Swapping in C++, Ansi-style
// Run Time    : 0.012 seconds
//============================================================================

#include <iostream>
using namespace std;
#define FRI(i, a, b) for(i = a; i < b; ++i)
#define FRD(i, a, b) for(i = a; i > b; --i)

int main() {
	int i, j, n, m, ans;
	int num[55];
	cin >> n;
	while (n--) {
		ans = 0;
		cin >> m;
		FRI(i, 0, m) {
			cin >> num[i];
			FRD(j, i, 0) {
				if (num[j] < num[j - 1]) {
					num[j] ^= num[j - 1] ^= num[j] ^= num[j - 1];
					ans++;
				} else break;
			}
		}
		cout << "Optimal train swapping takes " << ans << " swaps." << endl;
	}
	return 0;
}
