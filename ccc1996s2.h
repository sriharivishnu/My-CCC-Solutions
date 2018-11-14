#include <iostream>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int arr[51];
void subtract(int i) {
  if (arr[i-1] - arr[i]<0) {
    arr[i-1] = 10 + arr[i-1]-arr[i];
    int j=1;
    while (arr[i-1-j]==0) {
      arr[i-1-j] = 9;
      j++;
    }
    arr[i-1-j] -=1;
  } else {
    arr[i-1] =arr[i-1] - arr[i];
  }
}
int main() {
  string n;
  int length;
  int a0;
  cin >> a0;
  for (int y = 0; y < a0; y ++) {
    cin >> n;
    cout << n << endl;
    length = n.length();
    int valid = 1;
    for (int x = 0; x < n.length(); x++) {
      if (n[x]<'0' || n[x]>'9') {
        valid = 0;
        break;
      }
      arr[x] = n[x] - '0';
    }
    int lead = 0;
    while (valid && (length - lead > 2)) {
      subtract(length-1);
      length -= 1;
      while (lead < length && arr[lead] == 0) {
        lead++;
      }
      for (int i = lead; i < length; i++) {
        cout << arr[i];
      }
      cout << endl;
    }
    if (valid && arr[lead] == arr[length-1] && n.length() != 1) {
      cout << "The number " << n << " is divisible by 11." << endl << endl;
    } else {
      cout << "The number " << n << " is not divisible by 11." << endl << endl;
    }
  }

  return 0;
}
