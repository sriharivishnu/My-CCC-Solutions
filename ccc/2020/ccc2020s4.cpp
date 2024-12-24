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

// IMPLEMENTATION
constexpr int MAX_N = 1e6 + 1;

int ap[MAX_N] = {0}, bp[MAX_N] = {0}, cp[MAX_N] = {0};
string s;
size_t ans = 999999999999, na, nb, nc, n;

size_t check(int x[], int y[], size_t i) {
    int nx = x[n], ny = y[n];
    return nx - (x[i] - x[i - nx]) + ny - (y[i - nx] - y[i - nx - ny]) -
           min(x[i - nx] - x[i - nx - ny], y[i] - y[i - nx]);
}

size_t solve() {
    cin >> s;
    n = s.size();
    for (size_t i = 0; i < n; ++i) {
        ap[i + 1] = (s[i] == 'A') + ap[i];
        bp[i + 1] = (s[i] == 'B') + bp[i];
        cp[i + 1] = (s[i] == 'C') + cp[i];
    }
    na = ap[n], nb = bp[n], nc = cp[n];

    for (size_t i = 1; i <= n; ++i) {
        if (na + nb <= i)
            ans = min(ans, min(check(bp, ap, i), check(ap, bp, i)));
        if (na + nc <= i)
            ans = min(ans, min(check(cp, ap, i), check(ap, cp, i)));
        if (nb + nc <= i)
            ans = min(ans, min(check(cp, bp, i), check(bp, cp, i)));
    }

    return ans;
}

int main() { printf("%lu", solve()); }