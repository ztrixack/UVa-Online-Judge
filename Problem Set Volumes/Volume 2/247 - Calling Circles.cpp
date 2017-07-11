//============================================================================
// Name        : 247 - Calling Circles.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 247 Calling Circles in C++, Ansi-style
// Run Time    : 0.020 seconds
//============================================================================

#include <iostream>
#include <cstring>
#include <map>
using namespace std;

#define FRI(i, a, b)      for(i = a; i < b; ++i)

int main() {
  int i, j, k, a, b;
  int n, m, cases = 0;
  int index;
  map<string, int> caller;
  string call1, call2;

  while (cin >> n >> m, n != 0 || m != 0) {
    bool check[n][n];
    bool used[n];
    string name[n];

    index = 0;
    caller.clear();
    memset(check, 0, sizeof(check));
    memset(used, 0, sizeof(used));

    while (m--) {
      cin >> call1 >> call2;
      FRI(i, 0, n) {
        a = caller[call1];
        b = caller[call2];
        if (!a) {
          name[index++] = call1;
          a = caller[call1] = index;
        }
        if (!b) {
          name[index++] = call2;
          b = caller[call2] = index;
        }

        check[i][i] = check[a - 1][b - 1] = true;
      }
    }

    FRI(k, 0, n) {
      FRI(i, 0, n) {
        FRI(j, 0, n) {
          if(check[i][k] && check[k][j]) {
              check[i][j] = true;
          }
        }
      }
    }

    if (cases) cout << endl;
    cout << "Calling circles for data set " << ++cases << ":" << endl;

    FRI(i, 0, n) {
      if(!used[i]) {
        bool next = false;
        FRI(j, 0, n) {
          if((!used[j]) && check[i][j] && check[j][i]) {
            if(next) cout << ", ";
            cout << name[j];
            next = used[i] = used[j] = true;
          }
        }
        cout << endl;
      }
    }
  }

  return 0;
}
