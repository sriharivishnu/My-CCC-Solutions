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

// IMPLEMENTATION
void solve() {
    int n;
    cin >> n;

    int ans = 0;
    while (n > 1) {
        bool found = false;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                int dec = n / i;
                n -= dec;
                ans += (n / dec);
                found = true;
                break;
            }
        }

        if (!found) {
            n -= 1;
            ans += n;
        }
    }
    cout << ans << endl;
}

int main() { solve(); }
