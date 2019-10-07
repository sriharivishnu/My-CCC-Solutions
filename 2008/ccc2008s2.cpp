//Solution by Srihari Vishnu
//CCC 2008 S2 : Pennies in the Ring

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int r, count, y = 0;
  scanf("%d", &r);
  while (r != 0) {
    count = 0;
    for (int x = 0; x <= r; x++) {
      y = sqrt(r*r-x*x);
      count += int(y);
    }
    printf("%d\n", count*4 + 1);
    scanf("%d", &r);
  }
  
}
