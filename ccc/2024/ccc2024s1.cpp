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
const int MAX_N = 1000001;
int hats[MAX_N];

// IMPLEMENTATION

size_t solve() {
    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> hats[i];
    }

    for (int i = 0; i * 2 < n; ++i) {
        if (hats[i] == hats[(i + n / 2) % n]) ++ans;
    }
    return ans * 2;
}

int main() { cout << solve() << endl; }
