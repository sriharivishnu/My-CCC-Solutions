//Solution by Srihari Vishnu
//CCC 2014 J3

#include <iostream>
#include <algorithm>

using namespace std;
int main() {
  int n, x, y;
  int s1 = 100, s2 = 100;
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &x, &y);
    if (x > y) {
      s2 -= x;
    }
    else if (x < y) {
      s1 -= y;
    }
  }
  printf("%d\n%d", s1, s2);
}
