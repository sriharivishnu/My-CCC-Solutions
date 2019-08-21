//Solution by Srihari Vishnu
//CCC 2015 S2 : Jerseys

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char s;
string sizes = "SML";
int jerseys[1000001], j, a, x;
int main() {
  scanf("%d%d", &j, &a);
  for (int i = 1; i < j+1; i++) {
    scanf(" %c", &s);
    jerseys[i] = sizes.find(s);
  }
  int ans = 0;
  while (a--) {
    scanf(" %c%d", &s, &x);
    if (jerseys[x] >= int(sizes.find(s))) {
      jerseys[x] = -1;
      ans++;
    }
  }
  printf("%d", ans);

}
