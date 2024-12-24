#include <assert.h>

#include <algorithm>
#include <cmath>
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
typedef vector<vector<int>> vvi;

const int MAX_N = 2 * 10e5 + 1;
char colors[MAX_N] = {0};
bool visited[MAX_N];
vector<vii> adj;

void dfs(int node, bool parity) {
    for (const auto& [ne, edge] : adj[node]) {
        if (!visited[ne]) {
            visited[ne] = true;
            colors[edge] = parity ? 'R' : 'B';
            dfs(ne, 1 - parity);
        }
    }
}

// IMPLEMENTATION
void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);

    for (int i = 0; i < m; ++i) colors[i] = 'G';
    for (int i = 0; i < n; ++i) visited[i] = false;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, true);
        }
    }
    cout << colors << endl;
}

int main() { solve(); }
