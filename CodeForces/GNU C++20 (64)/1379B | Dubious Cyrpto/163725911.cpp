#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
void solve() {
    int l, r;
    ll m;
    cin >> l >> r >> m;
    ll lower = m - (r-l);
    ll upper = m + (r-l);
    for (ll i = l; i <= r; i++) {
        if (upper / i * i >= lower) {
            ll target = upper / i * i;
            if (target >= m) {
                cout << i << " " << r - (target - m) << " " << r << "\n";
            } else {
                cout << i << " " << l + (m - target) << " " << l << "\n";
            }
            return;
        }
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