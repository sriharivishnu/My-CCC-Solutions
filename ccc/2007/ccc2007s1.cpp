// Solution by Srihari Vishnu

#include <iostream>
using namespace std;
int main() {
  int n;
  int year, month, day;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> year >> month >> day;
    if (year < 1989) {
      cout << "Yes" << endl;
    }
    else if ( year == 1989) {
      if (month <2) {
        cout << "Yes" << endl;
      }
      else if (month == 2) {
        if (day <= 27) {
          cout << "Yes" << endl;
        }
        else {
          cout << "No" << endl;
        }
      } 
      else {
        cout << "No" << endl;
      }
    }
    else {
      cout << "No" << endl;
    }
  }

}
