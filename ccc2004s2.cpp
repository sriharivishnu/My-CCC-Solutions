#Solution by Srihari Vishnu
#CCC 2004 S2 : TopYodeller
#Only need to find worst rank of contestants who win.

#include <iostream>
#include <algorithm>
using namespace std;

int n,k,s, contest[101][101] = {0};

int findWorstRank(int c) {
  int worst = -1;
  for (int i = 0; i < k; i++) {
    int r = 1;
    for (int j = 0; j < n; j++) {
      if (contest[i][j] > contest[i][c]) {
        r++;
      }
    }
    worst = max(r,worst);
  }
  return worst;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    for (int c = 0; c < n; c++) {
      cin >> s;
      if (i > 0) contest[i][c] += contest[i-1][c] + s;
      else contest[i][c] = s;
    }
  }
  int* largest = max_element(contest[k-1], contest[k-1]+n);

  for (int i = 0; i < n; i++) {
    if (*largest == contest[k-1][i]) {
      cout << "Yodeller " << i+1 << " is the TopYodeller: score " << *largest << ", worst rank " << findWorstRank(i) << endl;
    }
  }
}
