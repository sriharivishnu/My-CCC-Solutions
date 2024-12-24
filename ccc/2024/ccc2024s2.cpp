#include <assert.h>

#include <algorithm>
#include <cstring>
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

char counts[26];

// IMPLEMENTATION

char solve(int n) {
    memset(counts, 0, sizeof(counts));
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) ++counts[s[i] - 'a'];

    bool ans = true;
    for (int i = 1; i < n; ++i) {
        if ((counts[s[i] - 'a'] == 1) == (counts[s[i - 1] - 'a'] == 1))
            return 'F';
    }

    return 'T';
}

int main() {
    int t, n;
    cin >> t >> n;
    for (int i = 0; i < t; ++i) cout << solve(n) << endl;
}
