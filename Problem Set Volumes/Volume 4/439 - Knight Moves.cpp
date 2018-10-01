//============================================================================
// Name        : 439 - Knight Moves.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 439 - Knight Moves in C++, Ansi-style
// Run Time    : 0.000 seconds
//============================================================================

#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

#define FRI(i, a, b)      for(i = a; i <= b; ++i)

struct Position {
  int x;
  int y;
  int move;

  Position(int a_x, int a_y, int a_move) : x(a_x), y(a_y), move(a_move) {}
};

int main() {
  int i, j, x, y, nx, ny;
  int count;
  string from, to;
  queue<Position> q; 

  while (cin >> from >> to) {
    bool board[8][8] = {{false}};
    q = queue<Position>();

    x = from[0] - 'a';
    y = from[1] - '1';
    board[x][y] = true;
    q.push(Position(x, y, 0));
    x = to[0] - 'a';
    y = to[1] - '1';

    while (!q.empty()) {
      Position pos = q.front();
      q.pop();

      if (pos.x == x && pos.y == y) {
        count = pos.move;
        break;
      }

      FRI (i, -2, 2) {
        FRI (j, -2, 2) {
          if (abs(i) == abs(j) || i == 0 || j == 0) continue;
          nx = pos.x + i;
          ny = pos.y + j;

          if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
            if (nx == x && ny == y) {
              count = pos.move + 1;
              goto answer;
            } else if (!board[nx][ny]) {
              board[nx][ny] = true;
              q.push(Position(nx, ny, pos.move + 1));
            }
          }
        }
      }
    }

answer:
    cout << "To get from " + from + " to " + to + " takes " << count << " knight moves." << endl;
  }
  return 0;
}
