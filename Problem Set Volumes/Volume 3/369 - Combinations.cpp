//============================================================================
// Name        : 369 - Combinations.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 369 Combinations in C++, Ansi-style
// Run Time    : 0.000 seconds
//============================================================================

#include <iostream>

using namespace std;

int main() {
  int i, j;
  int n, m;
  long long int c;

  while (cin >> n >> m, n != 0 && m != 0) {
    c = 1;
    for (i = m + 1, j = 1; i <= n; ++i, ++j) {
      c = c * i / j;
    }

    printf("%d things taken %d at a time is %lld exactly.\n", n, m, c);
  }

  return 0;
}
