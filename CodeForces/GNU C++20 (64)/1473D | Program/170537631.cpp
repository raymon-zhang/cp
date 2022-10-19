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
 
void solve() {
    int n, m;
    cin >> n >> m;
    int x = 0;
    V<int> a(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') x++;
        else x--;
        a[i] = x;
    }
 
    set<int> seen;
    seen.insert(0);
    V<int> up(n+1);
    for (int i = 1; i <= n; i++) {
        up[i] = up[i-1];
        if (!seen.count(a[i-1])) up[i]++;
        seen.insert(a[i-1]);
    }
 
    V<int> smn(n), smx(n);
    smn[n-1] = a[n-1];
    smx[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        smx[i] = max(smx[i+1], a[i]);
        smn[i] = min(smn[i+1], a[i]);
    }
 
    V<int> pmn(n), pmx(n);
    pmn[0] = min(a[0], 0);
    pmx[0] = max(a[0], 0);
    for (int i = 1; i < n; i++) {
        pmn[i] = min(pmn[i-1], a[i]);
        pmx[i] = max(pmx[i-1], a[i]);
    }
 
 
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;r--;
        int u = 0, b = 0;
        if (r < n-1) {
            if (l == 0) {
                u = max(smx[r+1] - a[r], 0);
                b = max(-smn[r+1] + a[r], 0);
            } else {
                u = max(smx[r+1] - a[r] + a[l-1] - pmx[l-1], 0);
                b = max(pmn[l-1] - smn[r+1] + a[r] - a[l-1], 0);
            }
        }
        cout << 1 + (l >= 0 ? up[l] : 0) + u + b << "\n";
    }
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