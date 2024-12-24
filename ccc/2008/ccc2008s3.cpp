//Solution by Srihari Vishnu
//CCC 2008 S3 : Maze

#include <iostream>
#include <string>
#include <vector>

#include <bits/stdc++.h>
using namespace std;

int r, c, ans;
int visited[21][21] = {0};
string grid[21];

void flood(int x, int y, int depth) {

  if (x > -1 && x < r && y > -1 && y < c && (depth < visited[x][y] || visited[x][y] == -1) && grid[x][y] != '*') {
    visited[x][y] = depth;
    if (x == r-1 && y == c-1) {
      return;
    }
    if (grid[x][y] == '-' || grid[x][y] == '+') {
      flood(x, y-1, depth + 1);
      flood(x, y+1, depth + 1);
    }
    if (grid[x][y] == '|' || grid[x][y] == '+') {
      flood(x+1, y, depth+1);
      flood(x-1, y, depth+1);
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    ans = -1;
    memset(visited, -1, sizeof(visited));
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
      cin >> grid[i];
    }
    flood(0,0,1);
    cout << visited[r-1][c-1] << endl;
  }
  
}
