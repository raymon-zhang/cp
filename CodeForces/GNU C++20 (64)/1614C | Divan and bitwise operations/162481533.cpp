#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
 
using ll = long long;
 
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
 
void solve() {
    int n,m;
    cin >> n >> m;
    ll x = 0;
    for (int i = 0; i < m; i++) {
        int l,r,c;
        cin >> l >> r >> c;
        x |= c;
    }
    
    ll ans = binpow(2, n-1, MOD);
    ll res = (ans * x)%MOD;
 
    cout << res << "\n";
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