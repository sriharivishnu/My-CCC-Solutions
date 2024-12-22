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
const int MAX_N = 300001;

// IMPLEMENTATION

int a[MAX_N], b[MAX_N], counts[MAX_N];

typedef tuple<char, int, int> swipe;

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int w = 0, c = 0;

    for (int i = 0; i < n; ++i) {
        if (b[i] != b[w]) {
            counts[w] = c;
            b[++w] = b[i];
            c = 0;
        }
        ++c;
    }
    counts[w] = c;
    ++w;

    vector<swipe> swipes, todo;
    int j = 0, done = 0;
    for (int i = 0; i < n && j < w; ++i) {
        if (a[i] == b[j]) {
            if (done < i) {
                swipes.emplace_back('L', done, i);
            }
            int rem = counts[j] - (i - done + 1);
            if (rem > 0) {
                todo.emplace_back('R', i, i + rem);
            }
            done += counts[j];
            j += 1;
        }
    }

    std::reverse(todo.begin(), todo.end());

    if (j >= w) {
        cout << "YES" << endl;
        cout << swipes.size() + todo.size() << endl;

        for (const auto& swipe : swipes) {
            cout << std::get<0>(swipe) << " " << std::get<1>(swipe) << " "
                 << std::get<2>(swipe) << endl;
        }
        for (const auto& swipe : todo) {
            cout << std::get<0>(swipe) << " " << std::get<1>(swipe) << " "
                 << std::get<2>(swipe) << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}

int main() { solve(); }
