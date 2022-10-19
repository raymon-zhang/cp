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
    int n, k;
    cin >> n >> k;
    V<int> a(n);
    for (int &i: a) cin >> i;
 
    V<int> f(2*k+1);
    V<int> fm(2*k+1);
    V<int> fx(2*k+1);
    V<int> fb(2*k+1);
    for (int i = 0; i < n/2; i++) {
        f[a[i] + a[n-1-i]]++;
        fm[min(a[i], a[n-1-i])]++;
        fx[max(a[i], a[n-1-i])]++;
        if (a[i] == a[n-1-i]) fb[a[i]]++;
    }
 
    V<int> g(2*k+1);
    V<int> l(2*k+1);
    for (int i = 2*k-1; i >= 0; i--) {
        g[i] = g[i+1];
        g[i] += fm[i+1];
    }
 
    for (int i = 2; i <= 2*k; i++) {
        l[i] = l[i-1];
        l[i] += fx[i-1];
    }
    //
    // for (int i = 0; i < 2*k+1; i++) {
    //     cout << l[i] << " ";
    // }
    // cout << "\n";
    //
    int ans = 1e9;
    for (int x = 2; x <= 2*k; x++) {
        ans = min(ans, (n/2-f[x]) + g[x-1] + (x > k ? l[x-k] : 0));
        // cout << g[x] << "fm\n";
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