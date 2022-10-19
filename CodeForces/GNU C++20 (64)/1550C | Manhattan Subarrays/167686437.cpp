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
 
bool good(pii a, pii b, pii c) {
    if ((b.first >= a.first && b.first <= c.first) || (b.first >= c.first && b.first <= a.first)) return false;
    return true;
}
 
void solve() {
    int n;
    cin >> n;
    V<int> a(n);
    for (int &i: a) cin >> i;
    int ans = 2*n-1;
    for (int i = 0; i < n-2; i++) {
        if (good({a[i], i+1}, {a[i+1], i+2}, {a[i+2], i+3})) ans++;
    }
    for (int i = 0; i < n-3; i++) {
        bool ok = true;
        ok &= good({a[i], i+1}, {a[i+1], i+2}, {a[i+2], i+3});
        ok &= good({a[i], i+1}, {a[i+1], i+2}, {a[i+3], i+4});
        ok &= good({a[i], i+1}, {a[i+2], i+3}, {a[i+3], i+4});
        ok &= good({a[i+1], i+2}, {a[i+2], i+3}, {a[i+3], i+4});
        if (ok) {
            ans++;
            // cout << a[i] << " " << a[i+2] << " " << a[i+3] << "\n";
        }
    }
    cout << ans << "\n";
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