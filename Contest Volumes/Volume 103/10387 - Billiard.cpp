//============================================================================
// Name        : 10387 - Billiard.cpp
// Author      : ztrixack
// Copyright   : MIT
// Description : 10387 Billiard in C++, Ansi-style
// Run Time    : 0.008 seconds
//============================================================================

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int a, b, s, m, n;
	double dis, angle;
	cout.precision(2);
	cout.setf(ios::fixed);
	while (true) {
		cin >> a >> b >> s >> m >> n;
		if (!a && !b && !s && !m && !n) break;
		dis = hypot(b * n, a * m);
		angle = fabs((double)atan2((double)b * n, a * m) * 180 / M_PI);
		if(angle > 90)
			angle = 180 - angle;
		dis /= s;
		cout << angle << " " << dis << endl;
	}
}
