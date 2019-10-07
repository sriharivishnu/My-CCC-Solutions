//Solution by Srihari Vishnu
//CCC 2016 J3 : Hidden Palindrome
//Numbering is as follows for possible centre of palindrome
//positions:
//b|a|n|a|n|a
//012345678910
//O(N^2) solution

#include <iostream>
#include <string>
using namespace std;
string s;
int best = 0, cnt = 0;

int main() {
  cin >> s;
  for (int i = 0; i < 2*s.size() -1; i++) {
    cnt = 0;
    if (i % 2 == 0) {
      cnt = 1;
    }
    for (int j = cnt; i/2 -j >= 0 && i/2 +j + !cnt < s.size(); j++) {
      if (i %2 == 0 && s[i/2 - j] == s[i/2 +j]) cnt+=2;
      else if (i % 2 == 1 && s[i/2-j] == s[i/2 +j + 1]) cnt += 2;
      else break;
    }
    best = max(cnt, best);
  }
  cout << best;
}
