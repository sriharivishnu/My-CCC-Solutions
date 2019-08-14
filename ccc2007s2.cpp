//Solution by Srihari Vishnu
//CCC 2007 S2 : Boxes
//Implementation Problem

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool fits(int item[3], int box[3]) {
  return (item[0]<=box[0] && item[1]<=box[1] && item[2]<=box[2]);
}

int main() {
  int boxes[1000][3];
  int volumes[1000];
  int temp[3];
  int n, items;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp[0] >> temp[1] >> temp[2];
    volumes[i] = temp[0]*temp[1]*temp[2];
    sort(temp, temp+3);
    boxes[i][0] = temp[0];
    boxes[i][1] = temp[1];
    boxes[i][2] = temp[2];
  }

  cin >> items;
  for (int i = 0; i < items; i++) {
    cin >> temp[0] >> temp[1] >> temp[2];
    sort(temp, temp+3);
    long minimum = pow(2000, 3)+1;
    for (int j = 0; j < n; j++) {
      if ((volumes[j] < minimum) && (fits(temp, boxes[j]))) {
        minimum = volumes[j];
      }
    }
    if (minimum >= pow(2000, 3) +1) {
      cout << "Item does not fit." << endl;;
    } else {
      cout << minimum << endl;
    }
  }
}
