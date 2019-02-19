// Solution by Srihari Vishnu
// Starting from bottom and building up
// Noticing the value at each node is the sum of all the nodes
// it leads to
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> hill[9999];
int counters[9999];
int n;
void init() {
  for (int i= 0; i <= n; i++) {
    counters[i] = 0;
  }
}
int main() {
  cin >> n;
  int x,y;
  cin >> x >> y;
  while (x != 0 && y != 0) {
    hill[y].push_back(x);
    cin >> x >> y;
  }
  init ();

  //Start Search
  counters[n] = 1;
  for (int i = n; i>0; i--) {
    for (int j=0; j < hill[i].size(); j++) {
      counters[hill[i][j]] += counters[i];
    }
  }
  
  cout << counters[1];

}
