//============================================================================
// Name        : 374 - Big Mod.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 374 - Big Mod in C++, Ansi-style
// Run Time    : 0.000 seconds
//============================================================================

#include <iostream>

using namespace std;

int main() {
  int b, p, m, r;
  while (cin >> b >> p >> m) {
    b %= m;
    r = 1;

    while (p) {
      if (p & 1) {
        r = r * b % m;
      }
      b = b * b % m;
      p >>= 1;
    }

    cout << r << endl;
  }

  return 0;
}
