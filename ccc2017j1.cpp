//Solution by Srihari Vishnu
//CCC 2017 J1

#include <iostream>
using namespace std;
int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  if (x > 0 && y > 0) {
    printf("1");
  }
  else if (x < 0 && y > 0) {
    printf("2");
  }
  else if (x < 0 && y < 0) {
    printf("3");
  }
  else {
    printf("4");
  }
}
