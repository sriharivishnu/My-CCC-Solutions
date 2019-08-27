//Solution by Srihari Vishnu
//CCC 2017 : J3

#include <iostream>
using namespace std;

int a,b,c,d,t;

int main() {
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &t);
  int dist = abs(a-c) + abs(b-d);
  if (((dist % 2) == (t % 2)) && (dist <= t)) {
    printf("Y");
  }
  else {
    printf("N");
  }
}
