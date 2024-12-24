//Solution by Srihari Vishnu

#include <iostream>
#include <string>
using namespace std;
int main() {
  string name;
  int value;
  int coldest;
  string coldest_city;
  cin >> coldest_city >> coldest;
  while (true) {
    cin >> name >> value;
    if (value < coldest) {
      coldest = value;
      coldest_city = name;
    }
    if (name == "Waterloo") {
      break;
    }
  }
  cout << coldest_city;
}
