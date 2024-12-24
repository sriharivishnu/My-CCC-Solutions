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

constexpr int MAX_N = 10000 + 1;

size_t N;
int h[MAX_N + 1], w[MAX_N];

// IMPLEMENTATION

float solve() {
    cin >> N;

    for (size_t i = 0; i < N + 1; ++i) cin >> h[i];
    for (size_t i = 0; i < N; ++i) cin >> w[i];

    double ans = 0;

    for (size_t i = 0; i < N; ++i) {
        ans += (h[i] + h[i + 1]) * w[i];
    }
    return ans / 2.0;
}

int main() { cout << fixed << solve(); }
