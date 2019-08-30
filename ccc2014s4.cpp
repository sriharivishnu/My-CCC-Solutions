#include <iostream>
#include <set>
#include <vector>
using namespace std;
long n, xl, yl, xr, yr,w;
long t;
set<long> xranges, yranges;
vector<long> xindexed, yindexed;
long rects[1002][5];
long tints[2002][2002] = {0};

int binary_search(long i, vector<long> arr) {
  int lo = 0; 
  int hi = arr.size()-1;
  while (lo <= hi) {
    int mid = (lo+hi)/2;
    if (arr[mid] == i) {
      return mid;
    }
    else if (arr[mid] > i) {hi = mid-1;}
    else if (arr[mid] < i) {lo = mid+1;}
  }
  return -1;
}
int main() {
  scanf("%ld%ld", &n, &t);
  for (int i = 0 ; i < n; i++) {
    scanf("%ld%ld%ld%ld%ld", &xl, &yl, &xr, &yr, &w);
    long temp[5] = {xl,yl,xr, yr,w};
    for (int j = 0; j < 5; j++) {rects[i][j] = temp[j];}
    xranges.insert(xl);
    xranges.insert(xr);
    yranges.insert(yl);
    yranges.insert(yr);
  }
  xindexed.assign(xranges.begin(), xranges.end());
  yindexed.assign(yranges.begin(), yranges.end());
  
  long long ans = 0;
  for (long* a : rects) {
    for (int i = binary_search(a[0], xindexed); xindexed[i] < a[2] && i < xindexed.size()-1; i++) {
      for (int j = binary_search(a[1], yindexed); yindexed[j] < a[3] && j < yindexed.size()-1; j++) {
        if ((tints[i][j] < t) && (tints[i][j] + a[4] >= t)) {
          ans += (xindexed[i+1]- xindexed[i])*(yindexed[j+1]-yindexed[j]);
        }
        tints[i][j] += a[4];
      }
    }
    
  }
  cout << ans;
}
