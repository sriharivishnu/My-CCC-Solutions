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

constexpr int MAX_INT = numeric_limits<int>::max();

constexpr int MAX_N = 401;

int balls[MAX_N];

// dp(i, j) stores the rice ball that can be made from using all of i to j
// 0 if we cannot create rice ball
// max of all dp(i, j) is the answer
int dp[MAX_N][MAX_N] = {0};

// IMPLEMENTATION
int solve(int n, int* arr) {
    // base case
    int best = 0;
    for (int i = 0; i < n; ++i) {
        dp[i][i] = balls[i];
        best = std::max(best, dp[i][i]);
    }

    for (int sz = 2; sz <= n; ++sz) {
        for (int i = 0; i < n - sz + 1; ++i) {
            int j = i + sz - 1, k = i, l = j;
            while (k < l) {
                int left = dp[i][k];
                int right = dp[l][j];

                if (left < right) {
                    ++k;
                } else if (left > right) {
                    --l;
                } else {
                    if (left) {
                        // consecutive
                        if (k + 1 == l) {
                            dp[i][j] = left + right;
                        }
                        // rice ball in between
                        else if (dp[k + 1][l - 1]) {
                            dp[i][j] = left + right + dp[k + 1][l - 1];
                        }
                    }
                    ++k;
                    --l;
                }
            }
            best = std::max(best, dp[i][j]);
        }
    }

    return best;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> balls[i];
    }

    std::cout << solve(n, balls) << std::endl;
}
