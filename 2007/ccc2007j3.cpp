//Solution by Srihari Vishnu
//CCC 2007 J3 : Deal or No Deal Calculator

#include <iostream>
using namespace std;
int main() {
  int n,x,s, deal = 0;
  int cases[10] = {100 , 500, 1000, 5000,10000,25000,  50000, 100000, 500000, 1000000};
  for (int i = 0; i<10; i++) {s+=cases[i];}
  int c = 10;
  cin >> n;
  while (n--) {
    cin >> x;
    s -= cases[x-1];
    c-=1;
  }
  double avg = s/c;
  cin >> deal;
  if (deal > avg) {
    cout << "deal";
  }
  else {
    cout << "no deal";
  }

}
