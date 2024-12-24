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

typedef pair<long, long> pll;

const int MAX_INT = numeric_limits<int>::max();

constexpr int MAX_N = 200000 + 1;

long N;
// IMPLEMENTATION

long p[MAX_N], w[MAX_N], d[MAX_N];

ll solve() {
    cin >> N;
    long lo = 0, hi = 0;
    for (int i = 0; i < N; ++i) {
        cin >> p[i] >> w[i] >> d[i];
        if (p[i] > hi) hi = p[i];
    }

    while (lo < hi) {
        long mid = (lo + hi) / 2;

        long diff = 0;
        for (int i = 0; i < N; ++i) {
            if (p[i] + d[i] <= mid) {
                diff += w[i];
            } else if (p[i] - d[i] >= mid + 1) {
                diff -= w[i];
            }
        }

        if (diff > 0) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    ll ans = 0;
    for (long i = 0; i < N; ++i) {
        if (p[i] + d[i] <= lo) {
            ans += w[i] * (lo - p[i] - d[i]) * 1LL;
        } else if (p[i] - d[i] >= lo) {
            ans += w[i] * (p[i] - d[i] - lo) * 1LL;
        }
    }
    return ans;
}

int main() { cout << solve(); }
