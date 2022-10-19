#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
const int MOD = 1e9+7;
 
ll binpow(ll x, ll n, ll m) {
    assert(n >= 0);
    x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1)  // if n is odd
        res = res * x % m;
        x = x * x % m;
        n /= 2;  // divide by two
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        ans %= MOD;
    }
 
    cout << ((ans - binpow(2, n-1, MOD)) + MOD) % MOD << "\n";
}