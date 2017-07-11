//============================================================================
// Name        : 260 - Il Gioco dell'X.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 260 Il Gioco dell'X in C++, Ansi-style
// Run Time    : 0.020 seconds
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <map>
using namespace std;

#define FRI(i, a, b)      for(i = a; i < b; ++i)
#define FRD(i, a, b)      for(i = a; i > b; --i)

int main() {
  int i, j, k;
  int n, game = 0;
  stack< pair<int, int> > path;
  pair<int, int> current;
  bool blackWin;
  int di[] = {-1, -1, 0, 0, 1, 1};
  int dj[] = {-1, 0, -1, 1, 0, 1};

  while (cin >> n, n != 0) {
    bool check[n][n];
    string row[n];

    path = stack< pair<int, int> >();
    memset(check, false, sizeof(check));
    blackWin = false;

    FRI(i, 0, n) {
      cin >> row[i];
    }

    FRI(j, 0, n) {
      if (row[0][j] == 'b') {
        check[0][j] = true;
        path.push(make_pair(0, j));
      }
    }

    while(!path.empty()) {
      current = path.top();
      path.pop();

      if (current.first == n-1) {
        blackWin = true;
        break;
      }

      FRI (k, 0, 6) {
        i = current.first + di[k];
        j = current.second + dj[k];

        if (i >= 0 && i < n && j >= 0 && j < n && row[i][j] == 'b' && !check[i][j]) {
          check[i][j] = true;
          path.push(make_pair(i, j));
        }
      }
    }

    if (blackWin) {
      cout << ++game << " B" << endl;
    } else {
      cout << ++game << " W" << endl;
    }
  }
  return 0;
}
