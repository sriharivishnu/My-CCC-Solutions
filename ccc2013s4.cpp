//Solution by Srihari Vishnu
// C++ Solution to CCC 2013 S4 : Who is Taller?
//Standard BFS

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool BFS(int start, int end, int n, bool visited[], vector<int> adjList[]) {
  queue<int> que;
  bool inque[n+1];
  fill(inque, inque+n+1, false);
  int c;
  que.push(start);
  visited[start] = true;
  inque[start] = true;
  
  while (!que.empty()) {
    c = que.front();
    que.pop();
    inque[c] = false;
    vector<int> :: iterator it;
    int i = 0;
    for (it = adjList[c].begin(); it != adjList[c].end(); it++, i++) {
      if (*it == end) {
        return true;
      } else {
        if (!visited[*it]) {
          visited[*it] = true;
          if (!inque[*it]) {
            que.push(*it);
            inque[*it] = true;
          }
        }
      }
    }
  }
  return false;
}
int main() {
  int n,m;
  int u,v;
  cin >> n >> m;
  bool visited[n+1];
  vector<int> adjList[n+1];
  fill(visited, visited+n+1, false);
  for (int i=0; i<m; i++) {
    cin >> u >> v;
    adjList[u].push_back(v);
  }
  int p,q;
  cin >> p >> q;
  if (BFS(p,q,n,visited, adjList)) {
    cout << "yes";
  }
  else if (BFS(q,p,n,visited, adjList)){
    cout << "no";
  }
  else {
    cout << "unknown";
  }
}
