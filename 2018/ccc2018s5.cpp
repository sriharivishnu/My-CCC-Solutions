#include <assert.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
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

constexpr int MAX_INT = numeric_limits<int>::max();

constexpr int MAX_N = 100001;

struct Edge {
    enum Type { PORTAL, FLIGHT };
    long a, b, weight;
    Edge::Type type;
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

int uf1[MAX_N], ufR1[MAX_N], uf2[MAX_N], ufR2[MAX_N];
Edge edges[MAX_N + MAX_N];

struct UnionFind {
    int *uf, *ufRank, groups = 0;

    UnionFind(int size, int* uf_, int* ufRank_) : uf{uf_}, ufRank{ufRank_} {
        for (int i = 0; i < size; ++i) {
            uf[i] = i;
            ufRank[i] = 0;
        }
        groups = size;
    }

    int find(int a) {
        if (uf[a] != a) uf[a] = find(uf[a]);
        return uf[a];
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (ufRank[a] > ufRank[b]) {
            uf[b] = a;
        } else if (ufRank[a] < ufRank[b]) {
            uf[a] = b;
        } else {
            uf[a] = b;
            ufRank[b]++;
        }
        --groups;
        return true;
    }
};

// IMPLEMENTATION
long solve(int n, int m, int p, int q, Edge edges[]) {
    UnionFind cityUf(m, uf1, ufR1), planetUf(n, uf2, ufR2);
    long currentCost = 0, bestCost = 0;
    sort(edges, edges + p + q);

    for (int i = 0; i < p + q; ++i) {
        const auto& edge = edges[i];
        if (edge.type == Edge::FLIGHT) {
            currentCost += edge.weight * n;
            if (cityUf.unite(edge.a, edge.b)) {
                bestCost += planetUf.groups * edge.weight;
            }
        } else {
            currentCost += edge.weight * m;
            if (planetUf.unite(edge.a, edge.b)) {
                bestCost += cityUf.groups * edge.weight;
            }
        }
    }

    return currentCost - bestCost;
}

int main() {
    int n, m, p, q;
    scanf("%d %d %d %d", &n, &m, &p, &q);

    for (int i = 0; i < p; ++i) {
        scanf("%ld %ld %ld", &edges[i].a, &edges[i].b, &edges[i].weight);
        edges[i].type = Edge::FLIGHT;
    }

    for (int j = 0; j < q; ++j) {
        scanf("%ld %ld %ld", &edges[j + p].a, &edges[j + p].b,
              &edges[j + p].weight);
        edges[j + p].type = Edge::PORTAL;
    }

    printf("%ld\n", solve(n, m, p, q, edges));
}
