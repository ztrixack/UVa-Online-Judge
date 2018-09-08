//============================================================================
// Name        : 423 - MPI Maelstrom.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 423 - MPI Maelstrom in C++, Ansi-style
// Run Time    : 0.000 seconds
//============================================================================

#include <iostream>
#include <string>

using namespace std;

#define FRI(i, a, b)      for(i = a; i < b; ++i)
#define INF               100000

int main() {
  int i, j, k;
  int n, m;
  int min, to, answer;
  int a[105][105] = {0};
  int pos[105] = {0};

  cin >> n;
  FRI(i, 0, n) {
    FRI(j, 0, i) {
      cin >> m;
      if (cin.good()) {
        a[i][j] = m;
        a[j][i] = m;
      } else {
        a[i][j] = INF;
        a[j][i] = INF;
        cin.clear();
        cin.ignore();
      }
    }
    a[i][i] = INF;
    pos[i] = INF;
  }

  pos[0] = 0;
  answer = 0;
  FRI(i, 1, n) {
    min = INF;
    FRI(j, 0, n) {
      if (pos[j] == INF) continue; 

      FRI(k, 0, n) {
        if (pos[k] < INF) continue;

        if (a[j][k] < min) {
          min = a[j][k];
          to = k;
        }
      }
    }

    FRI(j, 0, n) {
      if (pos[j] == INF) continue; 

      FRI(k, 0, n) {
        if (a[j][k] == INF || a[j][k] == 0) continue;
        a[j][k] -= min;
        a[k][j] -= min;
        if (a[j][k] < 0) {
          a[j][k] = 0;
          a[k][j] = 0;
        }
      }
    }

    pos[to] = min;
    answer += min;
  }

  cout << answer << endl;

  return 0;
}
