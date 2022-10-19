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
 
bool f[MX];
V<int> g[MX];
int c[MX];
int n, k;
bool good = false;
 
int closest(int x, int p) {
    if (f[x]) {
        c[x] = 0;
        return c[x];
    }
    c[x] = 1e9;
    for (int v: g[x]) {
        if (v == p) continue;
        c[x] = min(c[x], closest(v, x)+1);
    }
    return c[x];
}
 
void dfs(int x, int p, int d) {
    if (d >= c[x]) return;
    int count = 0;
    for (int v: g[x]) {
        if (v == p) continue;
        dfs(v, x, d+1);
        count++;
    }
    if (count == 0) {
        good = true;
    }
}
 
void solve() {
    cin >> n >> k;
 
    fill(f, f+n+1, 0);
    fill(g, g+n+1, V<int>());
    fill(c, c+n+1, 0);
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
 
    closest(1, -1);
 
    dfs(1, -1, 0);
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