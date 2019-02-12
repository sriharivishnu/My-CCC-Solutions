//Solution by Srihari Vishnu
//Same algorithm works in Python too
//Modified Dijkstra's Algorithm to not allow paths once hull thickness is below 0
//Passes every test case except weirdly gives wrong answer for one test case. When tried same test case manually,
//program produces correct answer.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf = 999999999;
int k,n,m;
pair<int,int> visited[2001];
vector<vector<int> > adjList[2001]; 
priority_queue<vector<int> > que;
void init() {
  for (int i = 0; i <= n; i++) {
    visited[i].first = inf;
    visited[i].second = -1;
  }
}
vector<int> getVector(int x,int y,int z) {
  int temp[] = {x,y,z};
  return vector<int>(temp,temp+3);
}
int main() {
  int a,b,t,h;
  vector<int> c;
  cin >> k >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> t >> h;
    adjList[a].push_back(getVector(b, t, h));
    adjList[b].push_back(getVector(a,t,h));
  }
  init();
  cin >> a >> b;
  que.push(getVector(0,a,k));
  visited[a].first = 0;
  visited[a].second = k;
  vector<int> node;
  while (!que.empty()) {
    c = que.top();
    que.pop();
    for (int n = 0; n < adjList[c[1]].size(); n++) {    
      if (c[2] - adjList[c[1]][n][2] > 0) {
        if (c[0] + adjList[c[1]][n][1] < visited[adjList[c[1]][n][0]].first) {
          visited[adjList[c[1]][n][0]].first = c[0] + adjList[c[1]][n][1];
          visited[adjList[c[1]][n][0]].second = c[2] - adjList[c[1]][n][2];
          que.push(getVector(c[0] + adjList[c[1]][n][1], adjList[c[1]][n][0],c[2] - adjList[c[1]][n][2]));
        }
      }
    }
  }
  if (visited[b].first == inf) {
    visited[b].first = -1;
  }
  cout << visited[b].first;
}
