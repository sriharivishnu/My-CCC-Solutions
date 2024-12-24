//Solution by Srihari Vishnu
//CCC 2002 S1 : The Students' Council Breakfast

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
  int p,g,r,o, goal;
  int total = 0, best = 999999999;
  cin >> p >> g >> r >> o >> goal;

  for (int x = 0; x<= goal/p; x++) {
    for (int y = 0; y <= goal/g; y++) {
      for (int z = 0; z <= goal/r; z++) {
        for (int w = 0; w <= goal/o; w++) {
          if (x*p + y*g + z*r + w*o == goal) {
            cout << "# of PINK is "<< x <<" # of GREEN is " << y << " # of RED is " << z << " # of ORANGE is " << w << endl;
            total++;
            if (x+y+z+w < best) best = x+y+z+w;
          }
        }
      }
    }
  }

  cout << "Total combinations is " << total << "." << endl;
  cout << "Minimum number of tickets to print is " << best << ".";
}
