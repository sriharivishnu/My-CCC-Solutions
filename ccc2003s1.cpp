//Solution by Srihari Vishnu
//Simple Implementation

//3 snakes (from 54 to 19, from 90 to 48 and from 99 to 77)
//3 ladders (from 9 to 34, from 40 to 64 and from 67 to 86)

#include <iostream>
using namespace std;
int main() {
  int steps;
  int pos = 1;
  bool win = false;
  bool quit = false;
  while (!quit && !win) {
    cin >> steps;
    if (steps == 0) {
      quit = true;
    }
    else {
      if (pos + steps < 101) {
        pos += steps;
      }
      if (pos == 100) {
        win = true;
        pos = 100;
      } else if (pos==54){
        pos = 19;
      }
      else if (pos==90){
        pos = 48;
      }
      else if (pos==99){
        pos = 77;
      }
      else if (pos==9){
        pos = 34;
      }
      else if (pos==40){
        pos = 64;
      }
      else if (pos==67){
        pos = 86;
      }
      cout << "You are now on square " << min(pos,100) << endl;
    }
    if (quit) {
      cout << "You Quit!" << endl;
    }
    else if (win) {
      cout << "You Win!" << endl;
    }
  }

}
