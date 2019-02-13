//Solution by Srihari Vishnu
//Very Straightforward brute force
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int testcases,n,x,max;
  vector<int> a,b;
  cin >> testcases;
  for (int a0 = 0; a0<testcases; a0++) {
    cin >> n;
    max = 0;
    for (int i = 0; i<n; i++) {
      cin >> x;
      a.push_back(x);
    }
    for (int i=0; i<n; i++) {
      cin >> x;
      b.push_back(x);
    }
    for (int i = 0; i<n; i++) {
      for (int j = i; j<n; j++) {
        if (a[i]<=b[j]) {
          if (j-i > max) {
            max = j-i;
          }
        }
      }
    }
    cout << "The maximum distance is " << max <<endl;
    a.clear();
    b.clear();
  }
  

}
