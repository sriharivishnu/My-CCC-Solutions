#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC target("avx,avx2,fma")

#include <cstdio>

int m, n, k;
bool rows[1 << 23], cols[1 << 23];
bool* arr[] = {rows, cols};
char c;
int x, ans = 0;
// IMPLEMENTATION

int solve() {
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < m; ++i) rows[i] = false;
    for (int i = 0; i < n; ++i) cols[i] = false;

    for (int i = 0; i < k; ++i) {
        scanf(" %c %d", &c, &x);
        arr[c == 'C'][x - 1] ^= 1;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += rows[i] ^ cols[j];
        }
    }
    return ans;
}

int main() { printf("%d", solve()); }
