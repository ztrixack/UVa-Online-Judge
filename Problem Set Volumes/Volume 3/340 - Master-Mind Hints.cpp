//============================================================================
// Name        : 340 - Master-Mind Hints.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 340 Master-Mind Hints in C++, Ansi-style
// Run Time    : 0.000 seconds
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

#define FRI(i, a, b) for(i = a; i < (int)b; ++i)

int main() {
  int i;
  int n, game = 0;
  int sum, strong, weak;

  while (cin >> n, n != 0) {
    bool mark[n];
    int secret[n];
    int guess[n];
    int basket[10];
    int cloner[10];

    memset(basket, false, sizeof(basket));

    FRI(i, 0, n) {
      cin >> secret[i];
      basket[secret[i]]++;
    }

    cout << "Game " << ++game << ":" << endl;
    while (true) {
      sum = strong = weak = 0;
      memset(mark, false, sizeof(mark));

      FRI(i, 0, n) {
        cin >> guess[i];
        sum |= guess[i];
      }

      if (sum == 0) {
        break;
      }

      FRI(i, 1, 10) {
        cloner[i] = basket[i];
      }

      // strong
      FRI(i, 0, n) {
        if (secret[i] == guess[i]) {
          mark[i] = true;
          cloner[secret[i]]--;
          strong++;
        }
      }

      // weak
      FRI(i, 0, n) {
        if (!mark[i] && cloner[guess[i]]) {
          cloner[guess[i]]--;
          weak++;
        }
      }

      cout << "    (" << strong << "," << weak << ")" << endl;
    }

  }
  return 0;
}
