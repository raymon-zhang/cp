#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<int> a;
vector<vector<pair<int, int>>> g;
 
int res = 0;
 
void del(int node, int p) {
    res++;
    for (auto edge: g[node]) {
        if (edge.first != p) {
            del(edge.first, node);
        }
    }
}
 
void dfs(int node, int p, long long minV, long long sumToP) {
    minV = min(minV, sumToP);
    if (sumToP - minV > a[node]) {
        del(node, p);
        return;
    }
    for (auto edge: g[node]) {
        if (edge.first != p) {
            dfs(edge.first, node, minV, sumToP + edge.second);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    cin >> n;
 
    g.resize(n);
 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
 
    for (int i = 0; i < n-1; i++) {
        int p, c;
        cin >> p >> c;
        p--;
        g[i+1].push_back({p, c});
        g[p].push_back({i+1, c});
    }
 
    dfs(0, -1, 0, 0);
    cout << res << "\n";
}