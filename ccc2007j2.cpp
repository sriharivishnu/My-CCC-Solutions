//Solution by Srihari Vishnu
//CCC 2007 J2 : I Speak TXTMSG

#include <map>
#include <iostream>
#include <string>
using namespace std;
int main() {
  string n;
  map<string, string> tt = {{"CU","see you"},{":-)",	"I'm happy"},{":-(",	"I'm unhappy"}, {";-)",	"wink"},{":-P",	"stick out my tongue"}, {"(~.~)",	"sleepy"}, {"TA","totally awesome"}, {"CCC",	"Canadian Computing Competition"}, {"CUZ",	"because"}, {"TY",	"thank-you"}, {"YW",	"you're welcome"}, {"TTYL",	"talk to you later"}};
  cin >> n;
  while (n != "TTYL") {
    if (tt.count(n) == 0) {
      cout << n << endl;
    }
    else {
      cout << tt[n] << endl;
    }
    cin >> n;
  }
  cout << tt[n];
}
