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

typedef pair<long, long> pll;

const int MAX_INT = numeric_limits<int>::max();

constexpr int MAX_N = 200000 + 1;

long N, W, D;

long stations[MAX_N], walkwayDist[MAX_N], subwayDist[MAX_N];

// IMPLEMENTATION

void solve() {
    cin >> N >> W >> D;
    unordered_map<int, vector<int>> adj;
    for (int i = 0, a, b; i < W; ++i) {
        cin >> a >> b;

        // store reverse to allow for BFS later
        adj[b - 1].emplace_back(a - 1);
    }

    for (int i = 0; i < N; ++i) {
        cin >> stations[i];
        subwayDist[--stations[i]] = i;
        walkwayDist[i] = 1e12;
    }

    walkwayDist[N - 1] = 0;
    // precompute walkway distances
    queue<int> que;
    que.push(N - 1);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (const auto& ne : adj[cur]) {
            if (walkwayDist[ne] == 1e12) {
                walkwayDist[ne] = walkwayDist[cur] + 1;
                que.push(ne);
            }
        }
    }

    multiset<long> vals;
    for (int i = 0; i < N; ++i) {
        vals.insert(subwayDist[i] + walkwayDist[i]);
    }
    vector<long> ans;
    for (int i = 0, x, y; i < D; ++i) {
        cin >> x >> y;
        --x, --y;
        vals.extract(subwayDist[stations[x]] + walkwayDist[stations[x]]);
        vals.extract(subwayDist[stations[y]] + walkwayDist[stations[y]]);
        swap(subwayDist[stations[x]], subwayDist[stations[y]]);
        swap(stations[x], stations[y]);
        vals.insert(subwayDist[stations[x]] + walkwayDist[stations[x]]);
        vals.insert(subwayDist[stations[y]] + walkwayDist[stations[y]]);
        ans.emplace_back(*vals.begin());
    }

    for (auto i : ans) cout << i << endl;
}

int main() { solve(); }