//Solution by Srihari Vishnu
//CCC 2013 J4

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int t,c, chores[101], ans = 0;
  scanf("%d%d", &t, &c);
  
  for (int i = 0; i < c; i++) {
    cin >> chores[i];
  }

  sort(chores, chores+c);
  
  while ((ans < c) && (t>=0)) {
    t-=chores[ans++];
  }
  if (t < 0) {
    ans-=1;
  }
  cout << ans;
}
