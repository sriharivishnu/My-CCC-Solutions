//Solution by Srihari Vishnu
//CCC 2007 S5 : Bowling for Numbers
//2D Dynamic programming

#include <iostream>
using namespace std;

int a0, n, k, w, pins[30001], sums[30001];
int dp[501][30001];
int main() {
  scanf("%d", &a0);
  while (a0--) {
    scanf("%d%d%d", &n, &k, &w);
    for (int i = 0; i < n; i++) {
      scanf("%d", &pins[i]);
    }
    sums[0] = pins[0];
    for (int i = 1; i < n; i++) {
      if (i < w) {
        sums[i] = pins[i] + sums[i-1];
      }
      else {
        sums[i] = sums[i-1] + pins[i] - pins[i-w];
      }
    }
    for (int i = 0; i < k+1; i++) {
      for (int j = 0; j < n; j++) {
        if(i==0) {dp[0][j] = 0;}
        else {
          if (j<w) {
            dp[i][j] = sums[j];
          }
          else {
            dp[i][j] = max(sums[j] + dp[i-1][j-w], dp[i][j-1]);
          }
        }
      }
    }
    printf("%d\n",dp[k][n-1]);
  }
}
