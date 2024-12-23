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

char buf[2001];
// IMPLEMENTATION

void solve(int n, int m, int r, int c) {
    if (r == 0 && c == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << (((i + j) % 3 == 0) ? 'a'
                                            : (((i + j) % 3 == 1) ? 'b' : 'c'));
            }
            cout << endl;
        }
    } else if (r == n) {
        if (((m % 2 == 1) || c % 2 == 0)) {
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < m; ++j) cout << 'a';
                cout << endl;
            }
            for (int j = 0; j < m / 2; ++j) {
                char ch = c >= 2 ? 'a' : 'b';
                if (c >= 2) c -= 2;
                buf[j] = ch;
                buf[m - 1 - j] = ch;
            }
            if (m % 2 == 1) {
                buf[m / 2] = c == 1 ? 'a' : 'b';
            }
            for (int j = 0; j < m; ++j) cout << buf[j];
            cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    } else if (c == m) {
        if (((n % 2 == 1) || r % 2 == 0)) {
            for (int j = 0; j < n / 2; ++j) {
                char ch = r >= 2 ? 'a' : 'b';
                if (r >= 2) r -= 2;
                buf[j] = ch;
                buf[n - 1 - j] = ch;
            }
            if (n % 2 == 1) {
                buf[n / 2] = r == 1 ? 'a' : 'b';
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m - 1; ++j) cout << 'a';
                cout << buf[i] << endl;
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    } else if (r == 0) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; ++j) cout << 'a';
            cout << 'c' << endl;
        }
        for (int j = 0; j < c - 1; ++j) cout << 'a';
        for (int j = c - 1; j < m - 1; ++j) cout << 'b';
        cout << 'c' << endl;
    } else if (c == 0) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; ++j) cout << 'a';
            cout << (r > 1 ? 'a' : 'b');
            if (r > 1) r--;
            cout << endl;
        }
        for (int j = 0; j < m; ++j) cout << 'c';
        cout << endl;
    } else {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < m; ++j) cout << 'a';
            cout << endl;
        }
        for (int i = 0; i < n - r; ++i) {
            for (int j = 0; j < c; ++j) cout << 'a';
            for (int j = 0; j < m - c; ++j) cout << 'b';
            cout << endl;
        }
    }
}

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    solve(n, m, r, c);
}
