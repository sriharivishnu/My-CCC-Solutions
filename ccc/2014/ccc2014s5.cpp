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

constexpr int MAX_INT = numeric_limits<int>::max();

constexpr int MAX_N = 2001;

int x[MAX_N], y[MAX_N];
int dp[MAX_N] = {0}, pdp[MAX_N] = {0}, pdist[MAX_N] = {0};

// IMPLEMENTATION
int dist(const pii& a) {
    return (x[a.first] - x[a.second]) * (x[a.first] - x[a.second]) +
           (y[a.first] - y[a.second]) * (y[a.first] - y[a.second]);
}

// dist(i1, i2) < dist(j1, j2) < dist(k1, k2)
void solve(int n, int* x, int* y) {
    vector<pii> all;
    all.reserve(n * n);
    for (int i = 0; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            all.emplace_back(i, j);
        }
    }

    sort(all.begin(), all.end(),
         [&](const pii& a, const pii& b) { return dist(a) < dist(b); });

    dp[0] = 0;
    for (const auto& [i, j] : all) {
        int d = dist({i, j});
        if (d != pdist[i]) {
            pdp[i] = dp[i];
            pdist[i] = d;
        }

        if (d != pdist[j]) {
            pdp[j] = dp[j];
            pdist[j] = d;
        }

        if (i == 0) {
            dp[i] = max(dp[i], pdp[j]);
        } else {
            dp[i] = max(dp[i], pdp[j] + 1);
            dp[j] = max(dp[j], pdp[i] + 1);
        }
    }
    cout << dp[0] + 1 << endl;
}

int main() {
    int n;
    cin >> n;
    x[0] = y[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    solve(n, x, y);
}