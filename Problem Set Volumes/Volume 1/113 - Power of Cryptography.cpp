//============================================================================
// Name        : 113 - Power of Cryptography.cpp
// Author      : ztrixack
// Copyright   : MIT
// Description : 113 Power of Cryptography in C++, Ansi-style
// Run Time    : 0.016 seconds
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
	double n, p, k;
	while (cin >> n >> p) {
		k = pow(p, 1.0/n);
		printf ("%0.lf\n", k);
	}
	return 0;
}
