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

// IMPLEMENTATION
vector<set<int>> adj{{},
                     {6},
                     {6},
                     {4, 5, 6, 15},
                     {3, 5, 6},
                     {3, 4, 6},
                     {1, 2, 3, 4, 5, 7},
                     {6, 8},
                     {7, 9},
                     {8, 10, 12},
                     {9, 11},
                     {10, 12},
                     {9, 11, 13},
                     {12, 14, 15},
                     {13},
                     {3, 13},
                     {17, 18},
                     {16, 18},
                     {16, 17}};

int bfs(int start, int target) {
    queue<int> que;
    vector<int> dist(51, -1);
    dist[start] = 0;
    que.push(start);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        if (cur == target) {
            return dist[cur];
        }

        for (const auto& ne : adj[cur]) {
            if (dist[ne] == -1) {
                dist[ne] = dist[cur] + 1;
                que.push(ne);
            }
        }
    }
    return -1;
}

int main() {
    char ch;
    int a, b;
    adj.resize(51);

    cin >> ch;
    while (ch != 'q') {
        cin >> a;
        if (ch == 'i' || ch == 'd' || ch == 's') {
            cin >> b;
        }
        switch (ch) {
            case 'i':
                adj[a].emplace(b);
                adj[b].emplace(a);
                break;
            case 'd':
                adj[a].erase(b);
                adj[b].erase(a);
                break;
            case 'n':
                cout << adj[a].size() << endl;
                break;
            case 'f': {
                unordered_set<int> all;
                for (const auto& ne : adj[a]) {
                    all.insert(adj[ne].begin(), adj[ne].end());
                }

                // remove direct and itself
                all.erase(a);
                for (const auto& ne : adj[a]) {
                    all.erase(ne);
                }
                cout << all.size() << std::endl;
                break;
            }
            case 's':
                int res = bfs(a, b);
                if (res == -1) {
                    cout << "Not connected" << endl;
                } else {
                    cout << res << std::endl;
                }
                break;
        }
        cin >> ch;
    }
}
