#include <assert.h>

#include <algorithm>
#include <cmath>
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

unordered_map<long, long> cache;

// IMPLEMENTATION
long dp(long w) {
    if (cache.count(w)) {
        return cache[w];
    }
    if (w == 1) {
        return 1;
    }
    long ans = 0, last = w;
    for (int val = 2; val <= sqrt(w); ++val) {
        ans += (last - w / val) * dp(val - 1);
        last = w / val;
    }

    for (int k = 2; k <= last; ++k) {
        ans += dp(w / k);
    }
    cache[w] = ans;
    return ans;
}

int main() {
    long n;
    cin >> n;

    cout << dp(n) << endl;
}
