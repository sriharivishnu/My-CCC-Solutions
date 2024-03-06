// Receives 15 / 20 on DMOJ, would have received 15/15 on CCC grader

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

typedef vector<long> vl;
typedef pair<long, long> pll;
typedef vector<std::pair<long, long>> vll;

typedef unordered_map<int, int> hii;
typedef unordered_map<std::string, int> hsi;

// IMPLEMENTATION

size_t solve() {
    string n, h;
    cin >> n >> h;
    if (n.size() > h.size()) return 0;

    ll counts[26] = {0}, targetCounts[26] = {0}, base1 = 131, base2 = 137,
       base3 = 253;
    ll hash1 = 0, hash2 = 0, hash3 = 0;

    ll power1 = 1, power2 = 1, power3 = 1;
    for (size_t i = 1; i < n.size(); ++i) {
        power1 = power1 * base1;
        power2 = power2 * base2;
        power3 = power3 * base3;
    }

    set<tuple<ll, ll, ll>> hashes;

    for (size_t i = 0; i < n.size(); ++i) {
        targetCounts[n[i] - 'a']++;
        counts[h[i] - 'a']++;
        hash1 = (hash1 * base1) + (h[i] - 'a' + 1);
        hash2 = (hash2 * base2) + (h[i] - 'a' + 1);
        hash3 = (hash3 * base3) + (h[i] - 'a' + 1);
    }

    if (equal(begin(counts), end(counts), begin(targetCounts),
              end(targetCounts))) {
        hashes.emplace(hash1, hash2, hash3);
    }

    for (size_t i = n.size(); i < h.size(); ++i) {
        counts[h[i] - 'a']++;
        counts[h[i - n.size()] - 'a']--;
        hash1 = hash1 - power1 * (h[i - n.size()] - 'a' + 1);
        hash1 = hash1 * base1 + (h[i] - 'a' + 1);

        hash2 = hash2 - power2 * (h[i - n.size()] - 'a' + 1);
        hash2 = hash2 * base2 + (h[i] - 'a' + 1);

        hash3 = hash3 - power3 * (h[i - n.size()] - 'a' + 1);
        hash3 = hash3 * base3 + (h[i] - 'a' + 1);

        if (equal(begin(counts), end(counts), begin(targetCounts),
                  end(targetCounts))) {
            hashes.emplace(hash1, hash2, hash3);
        }
    }
    return hashes.size();
}

int main() { printf("%lu", solve()); }