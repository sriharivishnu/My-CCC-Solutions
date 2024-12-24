//Solution by Srihari Vishnu
//CCC 2014 J1

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int a,b,c;
  scanf("%d%d%d", &a, &b, &c);
  if (a+b+c == 180) {
    if (a == b && b == c) {
      printf("Equilateral");
    }
    else if (a != b && b != c && a != c) {
      printf("Scalene");
    }
    else {
      printf("Isosceles");
    }
  }
  else {
    printf("Error");
  }

}
