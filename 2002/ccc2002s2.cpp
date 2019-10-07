//Solution by Srihari Vishnu
//CCC 2002 S2 : Fraction Action

#include <iostream>
using namespace std;
int num, den;

int GCF(int x, int y) {
  for (int i = x; i > 1; i--) {
    if (x%i == 0 && y%i == 0) {
      return i;
    }
  }
  return 1;
}
int main() {
  scanf("%d%d", &num, &den);
  if (num/den != 0) {
    printf("%d ", num/den);
  }
  int a = GCF(num % den, den);
  if (num % den != 0) {
    printf("%d/%d", (num % den)/a, den/a);
  }

}
