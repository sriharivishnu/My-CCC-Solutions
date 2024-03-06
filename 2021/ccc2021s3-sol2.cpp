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

typedef pair<long, long> pll;

const int MAX_INT = numeric_limits<int>::max();

constexpr int MAX_N = 200000 + 1;

long N;
// IMPLEMENTATION

struct Person {
    long p, w, d;
    long left() const { return p - d; }
    long right() const { return p + d; }
    friend bool operator<(const Person& a, const Person& b) {
        return a.right() > b.right();
    }
};

ll solve() {
    cin >> N;
    vector<Person> items(N);
    for (size_t i = 0; i < N; ++i) {
        cin >> items[i].p >> items[i].w >> items[i].d;
    }

    sort(items.begin(), items.end(),
         [](const Person& a, const Person& b) { return a.left() < b.left(); });

    ll left = 0, right = 0, minPos = items[0].left(), total = 0;
    for (const auto& item : items) {
        total += item.w * (item.p - item.d - minPos);
        right += item.w;
    }

    priority_queue<Person> inCur;
    inCur.push(items[0]);
    ll ans = total;
    right -= items[0].w;

    for (size_t i = 1; i < N; ++i) {
        while (!inCur.empty() && inCur.top().right() < items[i].left()) {
            const Person& person = inCur.top();
            long diff = person.right() - minPos;
            total = total + left * diff - right * diff;
            left += person.w;
            ans = min(ans, total);
            minPos = person.right();
            inCur.pop();
        }
        long diff = items[i].left() - minPos;
        total = total + left * diff - right * diff;
        right -= items[i].w;
        inCur.push(items[i]);
        ans = min(ans, total);
        minPos = items[i].left();
    }
    return ans;
}

int main() { cout << solve(); }