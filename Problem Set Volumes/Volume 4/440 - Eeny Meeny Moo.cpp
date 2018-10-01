//============================================================================
// Name        : 440 - Eeny Meeny Moo.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 440 - Eeny Meeny Moo in C++, Ansi-style
// Run Time    : 0.150 seconds
// 
//============================================================================

#include <iostream>

using namespace std;

#define FRI(i, a, b)      for(i = a; i < b; ++i)

int main() {
  int i, j, k;
  int n, count, head, prev, last;
  int link[200], m[200];

  FRI (i, 3, 151) {
    last = 0;
    count = 2;

    while (last != 2) {
      prev = i;
      head = 2;
      link[i] = 2;
      FRI (j, 2, i) link[j] = j + 1;
      FRI (j, 1, i) {
        FRI (k, 1, count) {
          prev = head;
          head = link[head];
        }
        last = head;
        link[prev] = link[head];
        head = link[head];
      }
      count++;
    };
    m[i] = count - 1;
  }

  while (cin >> n, n != 0) {
    cout << m[n] << endl;
  }

  return 0;
}
