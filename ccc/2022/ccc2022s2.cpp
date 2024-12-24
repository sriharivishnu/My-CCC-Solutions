// Didn't read that each name can only appear in one group lol
// Code could've been cleaner but oh well, works either way

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
constexpr int MAX_N = 100001;

int x, y, g;

// IMPLEMENTATION

size_t solve() {
    size_t ans = 0;

    map<string, set<string>> dependencies;
    map<string, set<string>> anti;

    cin >> x;

    string a, b;
    for (int i = 0; i < x; ++i) {
        cin >> a >> b;
        if (a > b) std::swap(a, b);
        dependencies[a].insert(b);
    }

    cin >> y;
    for (int i = 0; i < y; ++i) {
        cin >> a >> b;
        if (a > b) std::swap(a, b);
        anti[a].insert(b);
    }

    cin >> g;
    string arr[3];
    for (int i = 0; i < g; ++i) {
        cin >> arr[0] >> arr[1] >> arr[2];
        if (arr[0] > arr[1]) swap(arr[0], arr[1]);
        if (arr[0] > arr[2]) swap(arr[0], arr[2]);
        if (arr[1] > arr[2]) swap(arr[1], arr[2]);

        ans += anti[arr[0]].count(arr[1]);
        ans += anti[arr[1]].count(arr[2]);
        ans += anti[arr[0]].count(arr[2]);

        for (const auto& dep : dependencies[arr[0]])
            ans += dep != arr[1] && dep != arr[2];
        for (const auto& dep : dependencies[arr[1]]) ans += dep != arr[2];
        ans += dependencies[arr[2]].size();
    }
    return ans;
}

int main() { cout << solve() << endl; }
