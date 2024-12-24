//Solution by Srihari Vishnu
//CCC 2006 S2 : Attack of the CipherTexts

#include <iostream>
#include <string>
#include <map>
using namespace std;

string plain, coded, tofind, ans = "";
map<char, char> coding;
int main() {
  getline(cin, plain);
  getline(cin, coded);
  getline(cin, tofind);

  for (int i = 0; i < plain.size(); i++) {
    coding[coded[i]] = plain[i];
  }
  for (int i = 0; i < tofind.size(); i++) {
    if (coding.find(tofind[i]) == coding.end()) {
      cout << '.';
    }
    else {
      cout << coding[tofind[i]];
    }
  }
  cout << endl;
}
