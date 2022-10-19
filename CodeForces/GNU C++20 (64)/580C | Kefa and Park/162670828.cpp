#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
const int MAX = 1e5+1;
int n, m;
vector<vector<int>> g(MAX);
vector<bool> a(MAX);
int res = 0;
 
void dfs(int node, int p, int cats) {
    if (a[node]) cats++;
    else cats = 0;
    if (cats > m) {
        return;
    }
    int count = 0;
    for (int v: g[node]) {
        if (v != p) {
            dfs(v, node, cats);
            count++;
        }
    }
    if (!count) {
        res++;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x) a[i+1] = 1;
        else a[i+1] = 0;
    }
    for (int i = 0; i < n-1; i++) {
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
 
    dfs(1, 0, 0);
    cout << res << "\n";
}