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
 
ll binpowmod(ll x, ll n, ll m) {
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}
 
ll fact[MX], inv[MX];
 
void solve() {
    int n, k;
    cin >> n >> k;
    V<int> a(n);
    map<int, int> count;
    for (int &i: a) {
        cin >> i;
        count[i]++;
    }
    sort(all(a));
    reverse(all(a));
    map<int, int> curCount;
    for (int i = 0; i < k; i++) {
        curCount[a[i]]++;
    }
 
    int t = count[a[k-1]];
    int b = curCount[a[k-1]];
 
    cout << fact[t] * inv[b] % MOD * inv[t-b] % MOD << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    fact[0] = 1;
    for (int i = 1; i < MX; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
 
    inv[0] = 1;
    for (int i = 1; i < MX; i++) {
        inv[i] = binpowmod(fact[i], MOD-2, MOD);
    }
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}