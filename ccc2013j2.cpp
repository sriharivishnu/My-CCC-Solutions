//Solution by Srihari Vishnu
//CCC 2013 J2
#include <iostream>
#include <string>
using namespace std;
int main() {
  string x;
  bool b = true;
  cin >> x;
  string reversible = "IOSHZXN";
  for (char c : x) {
    if (reversible.find(c) == string::npos) {
      b = false;
      break;
    }
  }
  if (b) {
    cout << "YES";
  }
  else {
    cout << "NO";
  }

}
