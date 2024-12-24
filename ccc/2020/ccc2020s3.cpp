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

    ll counts[26] = {0}, targetCounts[26] = {0}, base1 = 131, base2 = 137;
    ll hash1 = 0, hash2 = 0;

    ll power1 = 1, power2 = 1;
    for (size_t i = 1; i < n.size(); ++i) {
        power1 = power1 * base1;
        power2 = power2 * base2;
    }

    map<tuple<ll, ll>, vector<ll>> hashes;

    for (size_t i = 0; i < n.size(); ++i) {
        targetCounts[n[i] - 'a']++;
        counts[h[i] - 'a']++;
        hash1 = (hash1 * base1) + (h[i] - 'a' + 1);
        hash2 = (hash2 * base2) + (h[i] - 'a' + 1);
    }

    if (equal(begin(counts), end(counts), begin(targetCounts),
              end(targetCounts))) {
        hashes[make_tuple(hash1, hash2)].push_back(0);
    }

    for (size_t i = n.size(); i < h.size(); ++i) {
        counts[h[i] - 'a']++;
        counts[h[i - n.size()] - 'a']--;
        hash1 = hash1 - power1 * (h[i - n.size()] - 'a' + 1);
        hash1 = hash1 * base1 + (h[i] - 'a' + 1);

        hash2 = hash2 - power2 * (h[i - n.size()] - 'a' + 1);
        hash2 = hash2 * base2 + (h[i] - 'a' + 1);

        // counts are equal
        // if hashes are not equal
        // if it is a permutation
        if (equal(begin(counts), end(counts), begin(targetCounts),
                  end(targetCounts))) {
            bool found = false;
            for (const auto& start : hashes[{hash1, hash2}]) {
                if (std::string_view{h.data() + (i - n.size() + 1), n.size()} ==
                    std::string_view{h.data() + start, n.size()}) {
                    found = true;
                }
            }
            if (!found) {
                hashes[{hash1, hash2}].push_back(i - n.size() + 1);
            }
        }
    }

    size_t ans = 0;
    for (const auto& [k, v] : hashes) {
        ans += v.size();
    }
    return ans;
}

int main() { printf("%lu", solve()); }