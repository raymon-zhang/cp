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
 
// bool f[MX];
// V<int> g[MX];
// int c[MX];
int n, k;
bool good = false;
 
 
 
int closest(int x, int p, V<int> &f, V<V<int>> &g, V<int> &c) {
    if (f[x]) {
        c[x] = 0;
        return c[x];
    }
    c[x] = 1e9;
    for (int v: g[x]) {
        if (v == p) continue;
        c[x] = min(c[x], closest(v, x, f, g, c)+1);
    }
    return c[x];
}
 
void dfs(int x, int p, int d, V<int> &f, V<V<int>> &g, V<int> &c) {
    if (d >= c[x]) return;
    int count = 0;
    for (int v: g[x]) {
        if (v == p) continue;
        dfs(v, x, d+1, f, g, c);
        count++;
    }
    if (count == 0) {
        good = true;
    }
}
 
void solve() {
    cin >> n >> k;
    
    // if (n >= 10) {
    //     cout << "hi\n";
    //     return;
    // }
 
    // memset(f, 0, sizeof(f));
    // memset(g, 0, sizeof(g));
    // memset(c, 0, sizeof(c));
    V<int> f(n+1);
    V<V<int>> g(n+1);
    V<int> c(n+1);
    good = false;
 
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        f[x] = true;
    }
 
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
 
    closest(1, -1, f, g, c);
 
    dfs(1, -1, 0, f, g, c);
    cout << (good ? "YES\n" : "NO\n");
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