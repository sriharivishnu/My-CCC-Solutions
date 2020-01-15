//Solution by: Srihari Vishnu
//CCC 2010 S1
//Bunch of if statements
#include <iostream>
#include <string>
using namespace std;
int calc(int r, int s, int d) {
  return 2*r + 3*s + d;
}
int main() {
  int n, r, s, d;
  string name, best1, best2;
  int score1 = -1, score2 = -1;
  cin >> n;
  while (n--) {
    cin >> name >> r >> s >> d;
    int value = calc(r,s,d);
    if (value>score1) {
      score2 = score1;
      best2 = best1;
      score1= calc(r,s,d);
      best1 = name;
    }
    else if (value == score1) {
      if (name < best1) {
        best2 = best1;
        best1 = name;
        score2 = score1;
      }
      else {
        best2 = name;
        score2 = value;
      }
    }
    else if (value > score2 && value < score1) {
      score2 = value;
      best2 = name;
    }
  }
  cout << best1 << endl << best2;
}
