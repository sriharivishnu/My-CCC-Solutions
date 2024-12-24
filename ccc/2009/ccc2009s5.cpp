//Solution by Srihari Vishnu
//CCC 2009 S5 : Wireless
//Using difference arrays!
//Getting y-value from x coordinate of circle formula (x-x1)^2 + (y-y1)^2 = r^2:
// y = +-sqrt(r^2 - (x-x1)^2) +y1

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int m, n, k, x, y, r, b;
int city[30001][1001] = {0};

int main() {
  scanf("%d%d%d", &m, &n, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d%d%d%d", &y, &x, &r, &b);
    for (int s = max(1,x-r); s<= min(m,x+r); s++) {
      int ans1 = max(1, (int) ceil(y - sqrt(r*r - (s-x)*(s-x))));
      int ans2 = min(n,(int)floor(y + sqrt(r*r - (s-x)*(s-x))));
      city[s][ans1] += b;
      city[s][ans2+1] -= b;
    }
  }
  int best = -1, cnt = 0;
  for (int i = 1; i < m+1; i++) {
    int sum = 0;
    for (int j = 1; j < n+1; j++) {
      sum += city[i][j];
      if (sum == best) {
        cnt++;
      }
      if (sum > best) {
        best = sum;
        cnt = 1;
      }
    }
  }
  printf("%d\n%d", best, cnt);

}
