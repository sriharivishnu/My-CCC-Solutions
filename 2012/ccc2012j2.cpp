//Solution by Srihari Vishnu
//CCC 2012 J2
#include <iostream>
using namespace std;

int main() {
  int w,x,y,z;
  scanf("%d%d%d%d", &w, &x, &y, &z);
  if (w < x && x < y && y < z) {
    printf("Fish Rising");
  }
  else if (w == x && x == y && y == z) {
    printf("Fish At Constant Depth");
  }
  else if (w > x && x > y && y >z) {
    printf("Fish Diving");
  }
  else {
    printf("No Fish");
  }
  
  
}
