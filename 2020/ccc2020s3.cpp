// This solution receives a score 7/15 (fails on the last subtask)
// Probably too many hash collisions
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <assert.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <limits>
using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<std::pair<int, int> > vii;

typedef vector<long> vl;
typedef pair<long, long> pll;
typedef vector<std::pair<long, long> > vll;

typedef unordered_map<int, int> hii;
typedef unordered_map<std::string, int> hsi;

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(var, a, b) for (int var = a; var < b; var++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--) 
#define FORD(i,a,b) for (int i = a; i >= b; i--) 
#define WL(t) while (t--)
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b))) 
#define pb push_back
#define mp make_pair

#define sfi(x) scanf("%d",&x); 
#define sfi2(x,y) scanf("%d%d",&x,&y); 
#define sfi3(x,y,z) scanf("%d%d%d",&x,&y,&z); 

#define pfi(x) printf("%d\n",x); 
#define pfi2(x,y) printf("%d %d\n",x,y); 
#define pfi3(x,y,z) printf("%d %d %d\n",x,y,z); 

const int MAX_INT = numeric_limits<int>::max();

//Print vector
template<typename T>
void pv(vector<T> v) {
    printf("[");
    FOR(i, 0, v.size()) {
        printf("%d", v[i]);
        if (i != v.size() - 1) printf(", ");
    }
    printf("]\n");
}

//Print vector of pairs
template<typename T>
void pvp(vector<T> v) {
    printf("[");
    FOR(i, 0, v.size()) {
        printf("[%d, %d]", v[i].first, v[i].second);
        if (i != v.size() - 1) printf(", ");
    }
    printf("]\n");
}
//Array
template<typename T>
void pv(T v[], int n) {
    printf("[");
    FOR(i, 0, n) {
        printf("%d", v[i]);
        if (i != n - 1) printf(", ");
    }
    printf("]\n");
}


// IMPLEMENTATION

bool check(const int counts[26], const int freq[26], const string& haystack, int start, int end, unordered_set<string>& hist) {
    int hcounts[26] = {0};
    FOR(i, 0, 26) {
        if (counts[i] != freq[i]) return false;
    }
    string perm = haystack.substr(start, end - start);
    auto it = hist.find(perm);
    if (it != hist.end()) {
        return false;
    } else {
        hist.insert(perm);
    }
    return true;
}
int solve() {
    string n, h;
    cin >> n >> h;
    if (n.size() > h.size()) return 0;
    int counts[26] = {0}, freq[26] = {0};
    int hash = 0, hash_needle = 0;
    unordered_set<string> hist;
    REP(i, n.size()) {
        counts[n[i] - 97]++;
        freq[h[i] - 97]++;
        hash_needle += n[i] - 97;
        hash += h[i] - 97;
    }
    int ans = 0;
    FOR(i, n.size(), h.size()) {
        if (hash == hash_needle) {
            if (check(counts,freq, h, i - n.size(), i, hist)) ans++;
        }
        hash += h[i] - 97;
        hash -= (h[i - n.size()] - 97);
        freq[h[i] - 97]++;
        freq[h[i - n.size()] - 97]--;
    }
    if (check(counts,freq, h, h.size() - n .size(), h.size(), hist)) ans++;    
    return ans;
}

int main() {
    // int t;
    // sfi(t);
    // WL(t) {
    //     solve();
    // }
    printf("%d", solve());
}