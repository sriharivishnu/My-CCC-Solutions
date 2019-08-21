//Solution by Srihari Vishnu
// CCC 2009 S4 : Shop and Ship
// Dijkstra's with Priority Queue to find cheapest costs

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
  int x,cost;
};
struct City {
  int n;
  int pencil = -1;
  vector<Edge> connected;
};
struct Node {
  int c,dist;
  Node() {};
  Node(int city, int d) {c = city; dist = d;};
  bool operator<(const Node &s) const {
    return dist > s.dist;
  }
};

City cities[5001];
int best[5001];
int n, t, k, x, y, w, d;
Edge e, e2;
Node curr;
priority_queue<Node> pq;

int main() {
  scanf("%d%d",&n, &t);
  for (int i = 1; i < n+1; i++) {
    City c;
    c.n = i;
    cities[i] = c;
    best[i] = 999999999;
  }
  while (t--) {
    scanf("%d%d%d",&x,&y,&w);
    e.x = y, e.cost = w;
    cities[x].connected.push_back(e);
    e2.x = x, e2.cost = w;
    cities[y].connected.push_back(e2);
  }
  scanf("%d",&k);
  while (k--) {
    scanf("%d%d",&x,&w);
    cities[x].pencil = w;
  }
  scanf("%d", &d);
  pq.push(Node(d,0));
  best[d] = 0;
  while (!pq.empty()) {
    curr = pq.top();
    pq.pop();
    for (Edge e : cities[curr.c].connected) {
      if (curr.dist + e.cost < best[e.x]) {
        best[e.x] = curr.dist + e.cost;
        pq.push(Node(e.x,best[e.x]));
      }
    }
  }
  int b = 999999999;
  for (int i =1; i < n+1; i++) {
    if (best[i]+cities[i].pencil < b && cities[i].pencil != -1) {
      b = best[i]+cities[i].pencil;
    }
  }
  printf("%d\n",b);
  
}
