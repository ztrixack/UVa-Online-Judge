//============================================================================
// Name        : 437 - The Tower of Babylon.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 437 - The Tower of Babylon in C++, Ansi-style
// Run Time    : 0.000 seconds
//============================================================================

#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>

using namespace std;

#define FRI(i, a, b)      for(i = a; i < b; ++i)

struct block_t {
  int x;
  int y;
  int z;

  bool operator <(const block_t& b) const {
    return x < b.x || (!(b.x < x) && y < b.y) || (!(b.x < x) && !(b.y < y) && z < b.z);
  }
};

int main() {
  int i, j, k, l;
  int length, high, highest;
  int cases = 0;
  int n;
  int dimension[3];
  set<block_t> blocks;
  set<block_t>::iterator itBase;
  set<block_t>::iterator itPush;

  while (cin >> n, n != 0) {
    highest = 0;
    FRI (i, 0, n) {
      FRI(j, 0, 3) {
        cin >> dimension[j];
      }
      sort(dimension, dimension+3);
      do {
        block_t block;
        block.x = dimension[0];
        block.y = dimension[1];
        block.z = dimension[2];
        blocks.insert(block);
      } while (next_permutation(dimension, dimension+3));
    }

    int high[blocks.size()] = {0};
    i = 0;

    for (itBase = blocks.begin(); itBase != blocks.end(); ++itBase) {
      block_t base = *itBase;
      high[i] = base.z;
      j = 0;

      for (itPush = blocks.begin(); itPush != itBase; ++itPush) {
        block_t push = *itPush;
        if (push.x < base.x && push.y < base.y) {
          high[i] = max(high[i], high[j] + base.z);
        }
        j++;
      }
      highest = max(highest, high[i]);
      i++;
    }

    cout << "Case " << ++cases << ": maximum height = " << highest << endl;
    blocks.clear();
  }

  return 0;
}
