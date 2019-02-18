// CCC 2017 S3 : Nailed It!
//Solution by Srihari Vishnu

#include <iostream>
using namespace std;
int arr[2001];
int sums[4002];
int a,heights;
int length;
int main() {
  int n;
  cin >> n;
  for (int i =0; i<n; i++) {
    cin >> a;
    arr[a]+=1;
  }
  for (int i = 1; i<2001; i++) {
    if (arr[i] >0) {
      for (int j = i; j<2001; j++) {
        if (i ==j) {
          sums[i+j] += int(arr[j]/2);
        } else {
          sums[i+j] += min(arr[i],arr[j]);
        }
      }
    }
  }
  for (int i = 0; i<4001;i++) {
    if (sums[i]>length) {
      length =sums[i];
      heights = 1;
    }
    else if (sums[i] == length) {
      heights +=1;
    }
  }
  if (length == 0) {
    length =1;
  }
  cout << length << " " << heights;

}
