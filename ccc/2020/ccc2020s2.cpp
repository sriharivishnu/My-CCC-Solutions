#include <iostream>
#include <queue> 
#include <math.h>
#include <string> 
using namespace std;

bool visited[1002][1002] = {false};
int grid[1002][1002] = {0};
bool inque[1002][1002] = {false};

vector<int> store_factors[1000001];

vector<int> getFactors(int n) {
    if (!store_factors[n].empty()) return store_factors[n];
    vector<int> f;
    for (int i = 1; i < sqrt(n)+1; i++) {
        if (n % i == 0) {
            f.push_back(i);
        }
    }
    store_factors[n] = f;
    return f;
}

int main() {
    int m, n;
    cin >> m >> n;

    pair<int, int> start = make_pair(1,1);
    inque[1][1] = true;
    visited[1][1] = true;
    queue<pair<int, int> > que;
    
    for (int i = 1; i < m+1; i++) {
        for (int j = 1; j < n+1; j++) {
            int a; 
            scanf("%d", &a);
            grid[i][j] = a;
        }
    }

    que.push(start);
    string ans = "no";

    //Main Loop
    while (!que.empty()) {
        pair<int, int> c = que.front();
        que.pop();

        inque[c.first][c.second] = false;
        visited[c.first][c.second] = true;

        
        int curr = grid[c.first][c.second];
        vector <int> factors = getFactors(curr);

        if (c.first == m && c.second == n) {
            ans = "yes";
            break;
        }
        //For each factor
        for (int i = 0; i < factors.size(); i++) {
            int a = factors[i];
            
            if ((a <= m) && (curr/a <= n) && (!inque[a][curr/a]) && (!visited[a][curr/a])) {
                que.push(make_pair(a, curr/a));
                visited[a][curr/a] = true;
                inque[a][curr/a] = true;
            }
            if ((curr/a <= m) && (a <= n) && (!inque[curr/a][a]) && (!visited[curr/a][a])) {
                que.push(make_pair(curr/a, a));
                visited[curr/a][a] = true;
                inque[curr/a][a] = true;
            }
        }

    }

    cout << ans << endl;

}