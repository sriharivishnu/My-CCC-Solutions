//Solution by Srihari Vishnu
//CCC 2011 J2

#include <iostream>
using namespace std;

int h, m;
int ans = -1;

int main() {
  scanf("%d%d", &h, &m);
  for (int i = 1; ans == -1 && i < m+1; i++) {
    if (-6*i*i*i*i + h*i*i*i + 2*i*i + i <= 0) ans = i;
  }
  if (ans == -1) printf("The balloon does not touch ground in the given time.");
  else printf("The balloon first touches ground at hour:\n%d", ans);
}
