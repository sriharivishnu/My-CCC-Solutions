#include <iostream>
using namespace std;
char s;
int c = 0;
int main() {
  for (int i = 0; i < 6; i++) {
    cin >> s;
    if (s == 'W') {
      c++;
    }
  }
  if (c >=5) {cout << 1;}
  else if (c >=3) {cout << 2;}
  else if (c>=1) {cout << 3;}
  else {cout << -1;}
}
