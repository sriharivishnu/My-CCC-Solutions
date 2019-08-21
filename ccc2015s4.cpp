//Solution by Srihari Vishnu
//CCC 2015 S4 : Convex Hull
//Modified Dijkstra's Algorithm to store thickness of all paths

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
  int i, t, h;
  Edge() {};
  Edge(int isle, int time, int hi) {i = isle; t = time; h = hi;}
  bool operator<(const Edge &e) const {
    if (t==e.t) {
      return h < e.h;
    }
    return t > e.t;
  }
};
struct Island {
  vector<Edge> connected;
};

int k, n, m, a, b, t, h, best[2001][201];
Island isles[2001];
priority_queue<Edge> pq;
Edge curr;

using namespace std;
int main() {
  scanf("%d%d%d", &k, &n, &m);
  for (int i = 0 ; i < n+1; i++) {
    isles[i] = Island();
    for (int j = 0; j < 201; j++) {
      best[i][j] = 999999999;
    }
  }
  while (m--) {
    scanf("%d%d%d%d", &a, &b, &t, &h);
    isles[a].connected.push_back(Edge(b,t,h));
    isles[b].connected.push_back(Edge(a,t,h));
  }
  scanf("%d%d", &a, &b);
  pq.push(Edge(a, 0, k));
  best[a][k] = 0;
  while (!pq.empty()) {
    curr = pq.top();
    pq.pop();
    for (Edge e : isles[curr.i].connected) {
      if ((curr.t + e.t < best[e.i][curr.h-e.h]) && curr.h - e.h > 0) {
        best[e.i][curr.h-e.h] = curr.t + e.t;
        pq.push(Edge(e.i, curr.t + e.t, curr.h - e.h));
      }
    }
    if (curr.i == b) {
      break;
    }
  }
  int ans = 999999999;
  for (int i = 0; i < 201; i++) {
    if (best[b][i] < ans) {
      ans = best[b][i];
    }
  }
  if (ans == 999999999) {
    cout << -1;
  } else {
    cout << ans;
  }
}
