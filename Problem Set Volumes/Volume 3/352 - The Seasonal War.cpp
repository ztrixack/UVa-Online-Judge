//============================================================================
// Name        : 352 - The Seasonal War.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 352 The Seasonal War in C++, Ansi-style
// Run Time    : 0.000 seconds
//============================================================================

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

#define FRI(i, a, b)  for(i = a; i < (int)b; ++i)

int main() {
  int i, j, k, x, y;
  int n, answer, number = 0;
  stack< pair<int, int> > group;
  pair<int, int> current;
  int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  while (cin >> n) {
    bool image[n][n];
    string row[n];
    answer = 0;

    memset(image, false, sizeof image);

    FRI(i, 0, n) {
      cin >> row[i];
    }

    FRI(i, 0, n) {
      FRI(j, 0, n) {
        if (row[i][j] != '0' && !image[i][j]) {
          image[i][j] = true;

          group = stack< pair<int, int> >();
          group.push(make_pair(i, j));

          while (!group.empty()) {
            current = group.top();
            group.pop();

            FRI (k, 0, 8) {
              x = current.second + dj[k];
              y = current.first + di[k];

              if (x >= 0 && x < n && y >= 0 && y < n && row[y][x] != '0' && !image[y][x]) {
                image[y][x] = true;
                group.push(make_pair(y, x));
              }
            }
          }
          answer++;
        }
      }
    }
    printf("Image number %d contains %d war eagles.\n",++number, answer);
  }

  return 0;
}
