//============================================================================
// Name        : 341 - Non-Stop Travel.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 341 Non-Stop Travel in C++, Ansi-style
// Run Time    : 0.000 seconds
//============================================================================

#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

#define MAX           1000000
#define FRI(i, a, b)  for(i = a; i < (int)b; ++i)

int main() {
  int i, j, k, l;
  int n, m, cases = 0;
  int start, end;
  stack<int> store;
  char numstr[21];

  while (cin >> n, n != 0) {
    ++n;
    int delay[n][n];
    int minimal[n];
    string answer[n];

    store = stack<int>();
    fill(minimal, minimal + n, MAX);
    memset(delay, -1, sizeof(delay));

    FRI(i, 1, n) {
      cin >> m;
      FRI(j, 0, m) {
        cin >> k >> l;
        delay[i][k] = l;
      }
    }

    cin >> start >> end;
    sprintf(numstr, "%d", start);
    answer[start] = numstr;
    minimal[start] = 0;
    store.push(start);

    while (!store.empty()) {
      start = store.top();
      store.pop();

      FRI (i, 1, n) {
        if (delay[start][i] != -1 && start != i) {
          if (minimal[i] > minimal[start] + delay[start][i]) {
            sprintf(numstr, "%d", i);
            minimal[i] = minimal[start] + delay[start][i];
            answer[i] = answer[start] + " " + numstr;
            if (i != end) {
              store.push(i);
            }
          }
        }
      }
    }
    cout << "Case " << ++cases << ": Path = " << answer[end] << "; " << minimal[end] <<" second delay" << endl;
  }

  return 0;
}
