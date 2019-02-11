#include <iostream>
#include <string>
#include <stdio.h>
#include<algorithm>
using namespace std;
void findPattern(string str, int ones, int zeroes) {
  if (ones == 0 && zeroes == 0) {
    cout << str << endl;
    return;
  }
  string temp = str;
  if (ones > 0) {
    findPattern(str.append("1"),ones-1,zeroes);
  }
  if (zeroes > 0) {
    findPattern(temp.append("0"),ones,zeroes-1);
  }
}
int main() {
  int a;
  int n,k;
  cin >> a;
  for (int i =0; i<a; i++) {
    cin >> n >> k;
    findPattern("", k, n-k);
  }
  return 0;
}
