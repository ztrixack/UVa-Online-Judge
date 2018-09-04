//============================================================================
// Name        : 394 - Mapmaker.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 394 - Mapmaker in C++, Ansi-style
// Run Time    : 0.000 seconds
//============================================================================

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define FRI(i, a, b)  for(i = a; i < (int)b; ++i)
#define FRD(i, a, b)  for(i = b - 1; i > a; --i)

int main() {
  int i, j;
  int n, r, b;
  int d[100], ld[100], ud[100];
  int c[100][100];
  vector<string> names;
  
  char name[10];
  int addr, index, x;

  cin >> n >> r;
  FRI(i, 0, n) {
    cin >> name >> b >> x >> d[i];

    FRI(j, 0, d[i]) {
      cin >> ld[j + 1] >> ud[j + 1];
    }
    
    names.push_back(name);
    c[i][d[i]] = x;
    c[i][0] = b - (c[i][d[i]] * ld[d[i]]);

    FRD(j, 0, d[i]) {
      c[i][j] = c[i][j + 1] * (ud[j + 1] - ld[j + 1] + 1);
      c[i][0] -= c[i][j] * ld[j];
    }
  }

  FRI(i, 0, r) {
    cin >> name >> x;
    index = distance(names.begin(), find(names.begin(), names.end(), name));
    addr = c[index][0] + c[index][1] * x;

    cout << name << "[" << x;
    FRI(j, 1, d[index]) {
      cin >> x;
      addr += c[index][j + 1] * x;
      cout << ", " << x;
    }

    cout << "] = " << addr << endl;
  }

  return 0;
}
