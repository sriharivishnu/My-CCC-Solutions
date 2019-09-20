//Solution by Srihari Vishnu
//CCC 2018 J1 : Telemarketer or not?

#include <iostream>
using namespace std;
int main() {
  int x,y,w,z;
  scanf("%d%d%d%d", &x, &y, &w, &z);
  if (x >= 8 && z >= 8 && y == w) {
    printf("ignore");
  }
  else {
    printf("answer");
  }
}
