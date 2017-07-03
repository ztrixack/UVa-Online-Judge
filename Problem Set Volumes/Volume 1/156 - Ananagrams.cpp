//============================================================================
// Name        : 156 - Ananagrams.cpp
// Author      : ztrixack
// Copyright   : MIT
// Description : 156 Ananagrams in C++, Ansi-style
// Run Time    : 0.008 seconds
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define FRI(i, a, b) for(i = a; i < b; ++i)

int main() {
	int i, j;
	bool check[1005] = {0};
	string iter;
	vector<string> word, wsort;
	set<string> res;
	for (i = 0; cin >> iter && iter != "#"; ++i) {
		word.push_back(iter);
		transform(iter.begin(), iter.end(), iter.begin(), ::tolower);
		sort(iter.begin(), iter.end());
		FRI(j, 0, (int)wsort.size()) {
			if (iter == wsort[j]) check[i] = check[j] = true;
		}
		wsort.push_back(iter);
	}
	FRI(i, 0, (int)word.size()) {
		if (!check[i]) res.insert(word[i]);
	}
	for (__typeof((res).begin()) word=(res).begin();word!=(res).end();word++) cout << *word << endl;
	return 0;
}
