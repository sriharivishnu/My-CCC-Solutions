//Solution by Srihari Vishnu
//CCC 2014 J2

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
  int x, a, b;
  string s;
  cin >> x >> s;

  a = count(s.begin(), s.end(), *"A");
  b = count(s.begin(), s.end(), *"B");

  if (a == b) {
    cout << "Tie";
  }
  else if (a > b) {
    cout << "A";
  }
  else {
    cout << "B";
  }
}
