#include <assert.h>

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<std::pair<int, int>> vii;

const int MAX_INT = numeric_limits<int>::max();

int powers[14];

// IMPLEMENTATION

bool solve(int m, int x, int y) {
    if (m == 0) {
        return false;
    }

    int block = powers[m] / 5;

    int blockX = x / block, blockY = y / block;
    if ((1 <= blockX && blockX <= 3 && blockY == 0) ||
        (blockX == 2 && blockY == 1)) {
        return true;
    }

    if (blockX == 1 && blockY == 1 || blockX == 2 && blockY == 2 ||
        blockX == 3 && blockY == 1) {
        return solve(m - 1, x - blockX * block, y - blockY * block);
    }
    return false;
}

int main() {
    powers[1] = 5;
    for (int i = 2; i < 14; ++i) {
        powers[i] = powers[i - 1] * 5;
    }

    int t, m, x, y;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> m >> x >> y;
        cout << (solve(m, x, y) ? "crystal" : "empty") << endl;
    }
}
