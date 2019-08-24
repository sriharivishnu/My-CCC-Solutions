//Solution by Srihari Vishnu
//CCC 2007 J4 : Anagram Checker

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string removeSpaces(string str) 
{ 
  str.erase(remove(str.begin(), str.end(), ' '), str.end());
  return str;
} 
int main() {
  string s1, s2;
  int last1 = 0, last2 = 0;
  getline(cin, s1);
  getline(cin, s2);
  bool b = true;

  s1 = removeSpaces(s1);
  s2 = removeSpaces(s2);
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  if (s1.length() != s2.length()) {
    b = false;
  }
  else {
    for (int i = 0; i < s1.length(); i++) {
      if (s1[i] != s2[i]) {
        b = false;
        break;
      }
    }
  }
  
  if (b) {
    cout << "Is an anagram." << endl;
  }
  else {
    cout << "Is not an anagram." << endl;
  }

}
