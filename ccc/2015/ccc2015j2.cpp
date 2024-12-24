//Solution by Srihari Vishnu
//CCC 2015 J2

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int count(string s, string c) {
  int count = 0;
  for (int i=0;i<s.length()-3;i++) {
    if ((s[i] == c[0]) && (s[i+1] == c[1]) && (s[i+2] == c[2])) {
      count++;
    }
  }
  return count;
}
int main() {
  int h, s;
  string input;
  getline(cin, input);

  h = count(input, ":-)");
  s = count(input, ":-(");

  if (h == 0 && s == 0) {
    printf("none");
  }
  else if (h > s) {
    printf("happy");
  }
  else if (h < s) {
    printf("sad");
  }
  else {
    printf("unsure");
  }
  
}
