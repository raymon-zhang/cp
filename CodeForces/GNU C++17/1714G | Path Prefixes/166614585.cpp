#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
const int MAXN = 2e5+1;
int n;
int r[MAXN];
 
void dfs(vector<vector<pair<int, pii>>> &c, int node, int p, vector<ll> &path, ll costA) {
    if (node > 0) {
        r[node] = (int) (lower_bound(all(path), costA+1) - path.begin()) - 1;
    }
    // cout << " hi " << costA << " " << costB << "\n";
    // cout << "\n";
    for (auto &i: c[node]) {
        if (i.first == p) continue;
        path.pb(path.back() + i.second.second);
        dfs(c, i.first, node, path, costA+i.second.first);
        path.pop_back();
    }
}
 
void solve() {
    cin >> n;
    vector<vector<pair<int, pii>>> c(n+1);
    for (int i = 0; i < n-1; i++) {
        int p, a, b;
        cin >> p >> a >> b;
        p--;
        c[p].pb({i+1, {a,b}});
    }
 
    vector<ll> path;
    path.pb(0);
    dfs(c, 0, -1, path, 0);
 
    for (int i = 1; i < n; i++) {
        cout << r[i] << " ";
    }
    cout << "\n";
}
 
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}