//Solution by Srihari Vishnu
//CCC 2017 J2

#include <iostream>
using namespace std;

int shift(int n, int k) {
  if (k == 0) return n;
  else return n + shift(n*10, k-1);
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  printf("%d", shift(n,k));
}
