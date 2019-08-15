//Solution by Srihari Vishnu

#include <iostream>
using namespace std;
int main() {
  int c, r;
  int x, y;
  int a, b;
  cin >> c >> r;
  x = 0;
  y = 0;
  cin >> a >> b;
  while (a != 0 or b != 0) {
    x = min(max(a+x, 0),c);
    y = min(max(b+y,0), r);
    cout << x << " " << y << endl;
    cin >> a >> b;
  }
}
