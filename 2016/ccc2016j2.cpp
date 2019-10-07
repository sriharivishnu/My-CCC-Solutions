//Solution by Srihari Vishnu
//CCC 2016 J2 : Magic Squares
#include <iostream>
using namespace std;
int sums[8], s, t;
int main() {
  for (int i = 0; i < 4; i++) {
    s = 0;
    for (int j = 0; j < 4; j++) {
      cin >> t;
      sums[j] += t;
      s+= t;
    }
    sums[i+4] += s;
  }
  int a = sums[0];
  bool b = true;
  for (int i = 0; i < 8; i++) {
    if (sums[i] != a) {
      b= false;
      break;
    }
  }
  if (b) {
    cout << "magic" << endl;
  }
  else {cout << "not magic" << endl;}
}
