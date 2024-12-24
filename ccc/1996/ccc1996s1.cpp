#include <iostream>
#include<math.h>
using namespace std;
int main() {
  int t,n, sum;
  cin >> t;
  for (int a0 = 0; a0 < t; a0++) {
    cin >> n;
    sum = 1;
    for (int j = 2; j < sqrt(n); j++) {
      if (n % j == 0) {
        sum += j;
        sum += (int) (n/j);
      }
    }
    if (sum < n) {
      cout << n << " is a deficient number." << endl;
    }
    else if (sum == n) {
      cout << n << " is a perfect number." << endl;
    }
    else {
      cout << n << " is an abundant number." << endl;
    }
  }
  return 0;
}
