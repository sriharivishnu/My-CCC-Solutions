//Solution by Srihari Vishnu
// CCC 2004 S1 : Fix

#include <iostream>
#include <string>
using namespace std;
bool ff(string x, string y) {
  if (x.length() >= y.length()) {
    if (x.find(y) == 0) return false;
    else if (x.rfind(y) == int(x.length()) - int(y.length())) return false;
  }
  return true;
}
int main() {
  int n;
  string a,b,c, ans;
  cin >> n;
  while (n--) {
    cin >> a >> b >> c;
    if (ff(a,b) && ff(b,c) && ff(c,a) && ff(b,a) && ff(c,b) && ff(a,c)) {
      cout << "Yes"<< endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}
