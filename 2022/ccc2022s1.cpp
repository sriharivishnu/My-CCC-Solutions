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

// IMPLEMENTATION

size_t solve() {
    int n;
    cin >> n;

    if (n % 5 == 0) return (n / 5) / 4 + 1;
    while (n > 5 && (n % 4 > 0)) n -= 5;
    if (n % 4 == 0) return (n / 4) / 5 + 1;
    return 0;
}

int main() { cout << solve() << endl; }
