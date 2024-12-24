//Solution by Srihari Vishnu
//Dynamic Programming
//C++ Solution to CCC 2007 J5 : Keep on Truckin'

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
  vector<int> motels;
  int ways[7001];
  int mindist, maxdist, n;
  int x;
  motels.push_back(0);
  motels.push_back(990);
  motels.push_back(1010);
  motels.push_back(1970);
  motels.push_back(2030);
  motels.push_back(2940);
  motels.push_back(3060);
  motels.push_back(3930);
  motels.push_back(4060);
  motels.push_back(4970);
  motels.push_back(5030);
  motels.push_back(5990);
  motels.push_back(6010);
  motels.push_back(7000);

  fill(ways, ways+7001, 0);
  cin >> mindist >> maxdist >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    motels.push_back(x);
  }
  n += 14;
  sort(motels.begin(), motels.end());
  ways[0] = 1;
  for (int i = 0; i<motels.size(); i++) {
    for (int j = i; j < n; j++) {
      if (motels[j] >= motels[i]+ mindist && motels[j] <= motels[i]+maxdist) {
        ways[j] += ways[i];
      }
    }
  }
  cout << ways[n-1] << endl;

}
