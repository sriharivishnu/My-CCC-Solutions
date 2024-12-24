//Solution by Srihari Vishnu
//CCC 2015 J1

#include <iostream>
#include <algorithm>

using namespace std;
int main() {
  int m, d;
  scanf("%d%d", &m, &d);

  if (m < 2 || (m == 2 && d < 18)) {
    printf("Before");
  }
  else if (m == 2 && d == 18) {
    printf("Special");
  }
  else {
    printf("After");
  }
}
