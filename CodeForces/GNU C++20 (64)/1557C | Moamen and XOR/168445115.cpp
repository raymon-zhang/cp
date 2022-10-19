 
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
 
#define int ll
 
ll fact[MX+1], inv[MX+1];
 
ll binpowmod(ll x, ll n, ll m) {
    x = (x+m)%m;
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x + m) % m;
        x = (x * x + m) % m;
        n >>= 1;
    }
    return res;
}
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    ll ne = 0;
    for (int i = 0; i < n; i += 2) ne += ((fact[n] * inv[i] + MOD) % MOD * inv[n-i] + MOD) % MOD;
    ne = (ne+MOD)%MOD;
 
    V<V<ll>> dp(k+1, V<ll>(2));
 
    dp[0][0] = 1; dp[0][1] = 1;
    for (int i = 1; i <= k; i++) {
        dp[i][1] = (dp[i-1][1] * binpowmod(2, n, MOD) + MOD) % MOD;
        if (n & 1) {
            dp[i][0] = (dp[i-1][0] * (ne + 1) + MOD) % MOD;
        } else {
            dp[i][0] = (dp[i-1][1] + (dp[i-1][0] * ne + MOD)%MOD + MOD) % MOD;
        }
    }
 
    cout << dp[k][0] << "\n";
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    fact[0] = 1;
    for (int i = 1; i <= MX; i++) {
        fact[i] = (fact[i-1] * i + MOD) % MOD;
    }
 
    inv[0] = 1;
    for (int i = 1; i <= MX; i++) {
        inv[i] = binpowmod(fact[i], MOD-2, MOD);
    }
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}