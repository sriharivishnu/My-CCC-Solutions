//Solution by Srihari Vishnu
//CCC 2006 S1 : Maternity
//Simple Implementation

#include <iostream>
#include <string>

using namespace std;
int main() {
  string father, mother;
  string child;
  int n;

  cin >> father >> mother;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> child;
    bool f = false;
    for (int j = 0; j < child.size(); j++) {
      if (isupper(child[j])) {
        if ((father[j*2] != child[j]) && (mother[j*2] != child[j])) {
          f = true;
          break;
        }
      }
      else {
        if ((father[j*2+1] != child[j]) || (mother[j*2+1] != child[j])) {
          f=true;
          break;
        }
      }
    }
    if (f) {
      cout << "Not their baby!" << endl;
    }
    else {
      cout << "Possible baby." << endl;
    }
  }
}
