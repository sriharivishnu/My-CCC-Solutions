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
const int MAX_N = 200000;
int top[MAX_N], bottom[MAX_N];

// IMPLEMENTATION

size_t solve() {
    int n;
    cin >> n;
    size_t ans = 0;

    for (int i = 0; i < n; ++i) cin >> top[i];
    for (int i = 0; i < n; ++i) cin >> bottom[i];

    for (int i = 0; i < n; ++i) {
        if (top[i]) {
            ans += 3 - 2 * (i && top[i - 1]) - (i % 2 == 0 && bottom[i]);
        }
        if (bottom[i]) {
            ans += 3 - 2 * (i && bottom[i - 1]) - (i % 2 == 0 && top[i]);
        }
    }
    return ans;
}

int main() { cout << solve() << endl; }
