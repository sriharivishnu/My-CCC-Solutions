//Solution by Srihari Vishnu
//CCC 2018 J2

#include <iostream>
#include <string>
using namespace std;
int n;
string x,y;
int ans = 0;
int main() {
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    if (x[i] == y[i] && x[i] == 'C') ans++;
  }
  cout << ans;
}
