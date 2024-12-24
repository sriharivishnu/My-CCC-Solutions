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

constexpr int MAX_N = 1000000 + 1;

int arr[MAX_N];

size_t n, m, k;

// IMPLEMENTATION

void solve() {
    cin >> n >> m >> k;
    if (k < n || (k > n * (n + 1) / 2 - (n - m) * (n - m + 1) / 2)) {
        cout << -1 << endl;
        return;
    }

    arr[0] = 1;
    k -= n;
    for (long i = 1; i < n; ++i) {
        long numSubArraysToAdd = min(k, m - 1);
        if (i - numSubArraysToAdd - 1 < 0) {
            arr[i] = arr[i - 1] + 1;
            k -= i;
        } else {
            arr[i] = arr[i - numSubArraysToAdd - 1];
            k -= numSubArraysToAdd;
        }
    }

    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() { solve(); }
