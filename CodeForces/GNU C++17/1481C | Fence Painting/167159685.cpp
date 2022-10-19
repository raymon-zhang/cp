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
    V<int> a(n), b(n);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;
 
    set<int> colors;
    map<int, V<int>> needed;
    map<int, int> count;
    V<int> latest(n+1, -1);
    for (int i = 0; i < n; i++) {
        colors.insert(b[i]);
        if (b[i] != a[i]) {
            needed[b[i]].pb(i);
            count[b[i]]++;
        }
        latest[b[i]] = i;
    }
 
    map<int, int> paint;
    V<int> c(m);
    V<int> res(m);
    for (int &i: c) {
        cin >> i;
        paint[i]++;
    }
 
    bool ok = true;
    for (pii x: count) {
        if (paint[x.first] < x.second) ok = false;
    }
 
    cout << (ok && colors.count(c[m-1]) ? "YES\n": "NO\n");
    if (ok && colors.count(c[m-1])) {
        for (int i = m-1; i >= 0; i--) {
            if (sz(needed[c[i]]) > 0) {
                res[i] = needed[c[i]].back();
                needed[c[i]].pop_back();
            } else if (latest[c[i]] != -1) {
                res[i] = latest[c[i]];
            } else {
                res[i] = res[m-1];
            }
        }
        for (int i: res) {
            cout << i+1 << " ";
        }
        cout << "\n";
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