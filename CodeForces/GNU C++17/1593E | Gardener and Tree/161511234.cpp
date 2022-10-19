#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n,k;
    cin >> n >> k;
 
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    vector<bool> rem(n);
 
    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
 
    queue<int> curQ;
    for (int i = 0; i < n; i++) {
        if (deg[i] <= 1) {
            curQ.push(i);
        }
    }
    queue<int> nextQ;
    int layer = 0;
    while (n > 0 && layer < k) {
        while (!curQ.empty()) {
            int node = curQ.front();
            curQ.pop();
            rem[node] = true;
            n--;
            for (int g: adj[node]) {
                if (!rem[g]) {
                    deg[g]--;
                    if (deg[g] == 1) {
                        nextQ.push(g);
                    }
                }
            }
        }
        curQ = nextQ;
        nextQ = queue<int>();
        layer++;
    }
 
    cout << n << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}