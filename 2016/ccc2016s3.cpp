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

// IMPLEMENTATION

vector<unordered_set<int>> adj;
unordered_set<int> pho;

int diameter = 0;

int dfs(int cur, int last) {
    int best = 0, best2 = 0;
    for (const auto& ne : adj[cur]) {
        if (ne != last) {
            int res = dfs(ne, cur) + 1;
            if (res >= best) {
                best2 = best;
                best = res;
            } else if (res >= best2) {
                best2 = res;
            }
        }
    }
    diameter = std::max(diameter, best + best2);
    return best;
}

int solve(int n, int m) {
    adj.resize(n);
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a;
        pho.insert(a);
    }

    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].emplace(b);
        adj[b].emplace(a);
    }

    queue<int> que;
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() == 1 && !pho.count(i)) {
            que.push(i);
        }
    }

    int erased = 0;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (const auto& ne : adj[cur]) {
            adj[ne].erase(cur);
            ++erased;
            if (adj[ne].size() == 1 && !pho.count(ne)) {
                que.push(ne);
            }
        }
    }

    // find diameter of tree
    dfs(*pho.begin(), -1);
    return 2 * (n - 1 - erased) - diameter;
}

int main() {
    int n, m;
    cin >> n >> m;
    std::cout << solve(n, m) << std::endl;
}
