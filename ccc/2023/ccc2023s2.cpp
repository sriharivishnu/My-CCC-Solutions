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
const int MAX_N = 5001;

int h[MAX_N];
int ans[MAX_N] = {0};

// IMPLEMENTATION

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        ans[i] = MAX_INT;
    }

    for (int center = 0; center < n; ++center) {
        for (int startI = center, startJ = center; startJ <= center + 1;
             ++startJ) {
            int i = startI, j = startJ, cur = 0;
            while (i >= 0 && j < n) {
                cur += abs(h[i] - h[j]);
                ans[j - i] = min(ans[j - i], cur);
                --i, ++j;
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << endl;
}

int main() { solve(); }
