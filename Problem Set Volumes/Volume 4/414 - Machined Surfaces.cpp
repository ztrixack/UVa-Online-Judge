//============================================================================
// Name        : 414 - Machined Surfaces.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 414 - Machined Surfaces in C++, Ansi-style
// Run Time    : 0.000 seconds
//============================================================================

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define FRI(i, a, b)  for(i = a; i < (int)b; ++i)

int main() {
  int i;
  int n, min, answer;
  int blank[15];
  string line;

  while (cin >> n, n != 0) {
    getline(cin, line);
    min = 25;
    FRI(i, 0, n) {
      getline(cin, line);
      blank[i] = count(line.begin(), line.end(), ' ');
      if (min > blank[i]) min = blank[i];
    }

    answer = 0;
    FRI(i, 0, n) {
      blank[i] -= min;
      answer += blank[i];
    }

    cout << answer << endl;
  }
  return 0;
}
