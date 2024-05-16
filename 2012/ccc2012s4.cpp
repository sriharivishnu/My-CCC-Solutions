// Just brute force BFS search game tree

#include <assert.h>

#include <algorithm>
#include <array>
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

constexpr int MAX_N = 8;

int coins[MAX_N];

struct State {
    std::array<string, MAX_N> pos;

    inline bool operator==(const State& other) const {
        bool equal = true;
        for (char i = 0; i < MAX_N; ++i) {
            equal = equal && other.pos[i] == pos[i];
        }
        return equal;
    }
};

template <>
struct std::hash<State> {
    size_t operator()(const State& s) const noexcept {
        size_t ans = 0;
        for (char i = 0; i < MAX_N; ++i) {
            ans ^= (hash<std::string>{}(s.pos[i])) + 0x9e3779b9 + (ans << 6) +
                   (ans >> 2);
        }
        return ans;
    }
};

// IMPLEMENTATION

int solve(int n, int* c) {
    unordered_set<State> visited;
    queue<State> que;
    State initial, target;
    for (int i = 0; i < n; ++i) {
        initial.pos[i].push_back(static_cast<char>(c[i]));
        target.pos[i].push_back(i + 1);
    }

    que.emplace(initial);
    visited.emplace(initial);

    int dist = 0;
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            auto& state = que.front();
            if (state == target) {
                return dist;
            }

            for (int i = 0; i < n; ++i) {
                if (state.pos[i].empty()) continue;
                if (i && (state.pos[i - 1].empty() ||
                          state.pos[i - 1].back() > state.pos[i].back())) {
                    state.pos[i - 1].push_back(state.pos[i].back());
                    state.pos[i].pop_back();

                    if (!visited.count(state)) {
                        que.emplace(state);
                        visited.emplace(state);
                    }
                    state.pos[i].push_back(state.pos[i - 1].back());
                    state.pos[i - 1].pop_back();
                }

                if (i < n - 1 &&
                    (state.pos[i + 1].empty() ||
                     state.pos[i + 1].back() > state.pos[i].back())) {
                    state.pos[i + 1].push_back(state.pos[i].back());
                    state.pos[i].pop_back();

                    if (!visited.count(state)) {
                        que.emplace(state);
                        visited.emplace(state);
                    }
                    state.pos[i].push_back(state.pos[i + 1].back());
                    state.pos[i + 1].pop_back();
                }
            }
            que.pop();
        }
        ++dist;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    while (n != 0) {
        for (int i = 0; i < n; ++i) cin >> coins[i];

        int res = solve(n, coins);
        if (res == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << res << endl;
        }

        cin >> n;
    }
}
