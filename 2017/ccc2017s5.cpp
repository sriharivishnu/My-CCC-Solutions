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

const int MAX_N = 150001, MAX_M = 150001, MAX_Q = 150001;

const int BLOCKS = 400;

int stationToL[MAX_N];
int block_sums[BLOCKS];
int offsets[MAX_M];
int station_idx_in_l[MAX_N];
int block_ends[BLOCKS][MAX_M];

// IMPLEMENTATION
void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    int block_size = sqrt(n);

    for (int i = 0; i < sqrt(n) + 1; ++i) block_sums[i] = 0;
    for (int i = 0; i < m; ++i) offsets[i] = 0;

    vector<vector<int>> line_blocks(m);

    for (int i = 0; i < n; ++i) {
        int line;
        cin >> line;
        line--;
        stationToL[i] = line;
        int block_num = i / block_size;
        if (line_blocks[line].empty() ||
            line_blocks[line].back() != block_num) {
            line_blocks[line].push_back(block_num);
        }
        block_ends[block_num][line] = i;
    }

    vector<vector<int>> passengers(m);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        station_idx_in_l[i] = passengers[stationToL[i]].size();
        passengers[stationToL[i]].push_back(a);
        block_sums[i / block_size] += a;
    }

    while (q--) {
        int a, l, r, x;
        cin >> a;
        if (a == 1) {
            cin >> l >> r;
            --l, --r;
            int ans = 0;
            for (int i = l; i < min(r + 1, l + (block_size - (l % block_size)));
                 ++i) {
                int line = stationToL[i];
                ans += passengers[line][(station_idx_in_l[i] - offsets[line] +
                                         passengers[line].size()) %
                                        passengers[line].size()];
            }
            for (int b = l / block_size + 1; b <= r / block_size - 1; ++b) {
                ans += block_sums[b];
            }
            if (r / block_size != l / block_size) {
                for (int i = r / block_size * block_size; i <= r; ++i) {
                    int line = stationToL[i];
                    ans +=
                        passengers[line][(station_idx_in_l[i] - offsets[line] +
                                          passengers[line].size()) %
                                         passengers[line].size()];
                }
            }
            cout << ans << endl;
        } else {
            cin >> x;
            --x;
            for (int bi = 0; bi < line_blocks[x].size(); ++bi) {
                int b = line_blocks[x][bi],
                    next_b = line_blocks[x][(bi + 1) % line_blocks[x].size()];
                int transferred_to_next =
                    passengers[x][(passengers[x].size() - offsets[x] +
                                   station_idx_in_l[block_ends[b][x]]) %
                                  passengers[x].size()];
                block_sums[b] -= transferred_to_next;
                block_sums[next_b] += transferred_to_next;
            }
            offsets[x] = (offsets[x] + 1) % passengers[x].size();
        }
    }
}

int main() { solve(); }
