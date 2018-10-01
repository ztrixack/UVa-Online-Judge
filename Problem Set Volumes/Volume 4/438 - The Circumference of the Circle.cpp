//============================================================================
// Name        : 438 - The Circumference of the Circle.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 438 - The Circumference of the Circle in C++, Ansi-style
// Run Time    : 0.000 seconds
// Reference   : https://www.quora.com/Given-3-points-in-the-Cartesian-plane-how-can-you-find-the-coordinates-of-the-center-of-the-circle-that-intersects-all-three-points-if-there-exists-such-a-circle
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define FRI(i, a, b)      for(i = a; i < b; ++i)
#define PI                3.141592653589793

int main() {
  int i, j;
  double r, u, v, w, p, q;
  double a, b, c, d, e, f; 

  while (cin >> a >> b >> c >> d >> e >> f) {
    r = 0;
    u = (a * a + b * b - c * c - d * d) / 2;
    v = (a * a + b * b - e * e - f * f) / 2;
    w = (a - c) * (b - f) - (a - e) * (b - d);
    p = (u * (b - f) - v * (b - d)) / w;
    q = (v * (a - c) - u * (a - e)) / w;
    r = (a - p) * (a - p) + (b - q) * (b - q);

    cout << setprecision(2) << fixed << 2 * PI * sqrt((float)r) << endl;
  }

  return 0;
}
