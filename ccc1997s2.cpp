//Solution by Srihari Vishnu
#include <iostream>
#include<math.h>
#include<vector>
bool indifferences[32001];
using namespace std;
int main() {
  int a0;
  cin >> a0;
  for (int j = 0; j<a0; j++) {
    int n;
    vector<int> differences;
    vector<int> sums;
    cin >> n;
    differences.push_back(n-1);
    sums.push_back(n+1);
    for (int i = 2; i<=(sqrt(n)); i++) {
      if (n % i == 0) {
        differences.push_back((n/i)-i);
        sums.push_back(n/i+i);
      }
    }
    for (int i = 0; i<differences.size(); i++) {
      indifferences[differences[i]] = true;
    }
    bool answer = false;
    for (int i = 0; i<sums.size(); i++) {
      if (indifferences[sums[i]]) {
        answer = true;
        break;
      }
    }
    if (!answer) {
      cout << n << " is not nasty" << endl;
    } else {
      cout << n << " is nasty" << endl;
    }
    fill(indifferences,indifferences+32001,false);
  }


  
}
