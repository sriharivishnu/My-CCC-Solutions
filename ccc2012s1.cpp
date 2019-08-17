//Solution by Srihari Vishnu
// CCC 2012 S1 : Don't Pass Me the Ball!
//Simple math. Use combinatorial formula and then simplify to get ((n-1)*(n-2)*(n-3))/6

#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << ((n-1)*(n-2)*(n-3))/6;
}
