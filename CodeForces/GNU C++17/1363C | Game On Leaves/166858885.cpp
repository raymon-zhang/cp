#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
template<class T> using V = vector<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
 
template<class T> bool smin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool smax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
const int MOD = 1e9+7; // 998244353
const int MX = 2e5+5;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
 
int dfs(V<V<int>> &adj, V<int> &size, int node, int p) {
    int s = 1;
    for (int i: adj[node]) {
        if (i != p) {
            s += dfs(adj, size, i, node);
        }
    }
    size[node] = s;
    return s;
}
 
void solve() {
    int n, x;
    cin >> n >> x;
    V<V<int>> adj(n+1);
    V<int> size(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    dfs(adj, size, x, -1);
 
    int ones = 0;
    int deg = 0;
    for (int i: adj[x]) {
        if (size[i]&1) ones++;
        deg++;
    }
    if (deg <= 1) {
        cout << "Ayush\n";
        return;
    }
    // cout << ones << "\n";
    cout << ((ones&1) ? "Ayush" : "Ashish") << "\n";
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