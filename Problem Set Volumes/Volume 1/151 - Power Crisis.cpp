//============================================================================
// Name        : 151 - Power Crisis.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 151 Power Crisis in C++, Ansi-style
// Run Time    : 0.008 seconds
//============================================================================

#include <iostream>
//#include <algorithm>
//#include <list>
using namespace std;
//#define FRI(i, a, b) for(i = a; i < b; ++i)

int main() {
	int n;
	int ans[100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 1, 18, 10, 11, 7, 17, 11, 15,
			29, 5, 21, 13, 26, 14, 11, 23, 22, 9,
			73, 17, 42, 7, 98, 15, 61, 22, 84, 24,
			30, 9, 38, 15, 54, 27, 9, 61, 38, 22,
			19, 178, 38, 53, 79, 68, 166, 20, 9, 22,
			7, 21, 72, 133, 41, 10, 82, 92, 64, 129,
			86, 73, 67, 19, 66, 115, 52, 24, 22, 176,
			10, 57, 137, 239, 41, 70, 60, 116, 81, 79,
			55, 102, 49, 5, 22, 54, 52, 113, 15};
	//int i, n, m;
	//list<int> list;
	while (cin >> n && n != 0) {
		cout << ans[n] << endl;
	/*	m = 0;
		do {
			list.clear();
			FRI (i, 0, n) list.push_back(i);
			while (list.size() > 1) {
				list.pop_front();
				FRI (i, 0, m) {
					list.push_back(list.front());
					list.pop_front();
				}
			}
			m++;
		} while(list.front() != 12);
		cout << m << endl;*/
	}
	return 0;
}
