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

char buf[2002][2002] = {0};
// IMPLEMENTATION

void solve(int n, int m, int r, int c) {
    if ((r == n && !(m & 1) && (c & 1)) || (c == m && !(n & 1) && (r & 1))) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) buf[i][j] = 'a';

    r = n - r, c = m - c;

    for (int i = 0; i < r / 2; ++i) buf[i][0]++, buf[n - i - 1][0]++;
    for (int j = 0; j < c / 2; ++j) buf[0][j]++, buf[0][m - j - 1]++;
    if (r & 1) {
        if (r == 1 && n % 2 == 0)
            buf[0][0]++;
        else
            buf[n / 2][0]++;
    }
    if (c & 1) {
        if (c == 1 && m % 2 == 0)
            buf[0][0]++;
        else
            buf[0][m / 2]++;
    }
    for (int i = 0; i < n; ++i) cout << buf[i] << endl;
}

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    solve(n, m, r, c);
}
