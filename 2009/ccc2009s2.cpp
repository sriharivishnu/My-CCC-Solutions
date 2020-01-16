// Solution by Srihari Vishnu
// CCC 2009 S2 : Lights Going On and Off
// Go through all possible button pushes, deleting duplicates

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int l,r;
string grid[30], s;
string getExclOr(string s1, string s2) {
  string ans = "";
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] != *" ") {
      if (s1[i] == s2[i]) ans += "0";
      else ans += "1";
    }
  }
  return ans;
}
int main() {
  char a;
  cin >> r >> l;
  for (int i = 0; i < r; i++) {
    string s = "";
    for (int j = 0; j < l; j++) {
      cin >> a;
      s += a;
    }
    grid[i] = s;
  }
  vector<string> prev, next;
  prev.push_back(grid[0]);
  for (int i = 1; i < r; i++) {
    next.push_back(grid[i]);
    for (int j = 0; j < prev.size(); j++) {
      string s = getExclOr(grid[i], prev[j]);
      bool f = true;
      for (int m = 0; m < next.size(); m++) {
        if (next[m] == s) {
          f = false;
          break;
        }
      }
      if (f) next.push_back(s);
    }
    prev = next;
    next.clear();
  }
  cout << prev.size();
}
