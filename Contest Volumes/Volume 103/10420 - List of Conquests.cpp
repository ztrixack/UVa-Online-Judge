//============================================================================
// Name        : 10420 - List of Conquests.cpp
// Author      : ztrixack
// Copyright   : MIT
// Description : 10420 List of Conquests in C++, Ansi-style
// Run Time    : 0.016 seconds
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct cty {
	string locale;
	int num;
}cty[2001];

int compare (const void *a, const void *b) {
	if ((*(struct cty*)a).locale > (*(struct cty*)b).locale)
		return 1;
	else if ((*(struct cty*)a).locale < (*(struct cty*)b).locale)
		return -1;
	else
		return 0;
}

int main () {
	int number, m;
	int n = 0;
	bool no;
	string nation, tmp;
	cin >> number;
	getline(cin, tmp);
	for (int i = 0; i < number; i++) {
		nation.clear();
		tmp.clear();
		no = true;
		getline(cin, tmp);
		m = tmp.find(' ');
		nation.append(tmp, 0, m + 1);
		for (int j = 0; j < n; j++) {
			if (cty[j].locale == nation) {
				cty[j].num++;
				no = false;
				break;
			}
		}
		if (no) {
			cty[n].locale = nation;
			cty[n].num++;
			n++;
		}
	}
	qsort (cty, n, sizeof(struct cty), compare);
	for (int i = 0; i < n; i++)
		cout << cty[i].locale << cty[i].num << endl;
}
