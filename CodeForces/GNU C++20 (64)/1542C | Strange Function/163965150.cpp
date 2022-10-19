#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
const ll MAX = 1e16;
const int MOD = 1e9+7;
 
void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "2\n";
        return;
    } else if (n == 2) {
        cout << "5\n";
        return;
    }
    ll f = 1;
    int fn = 2;
    vector<ll> periods;
    while (f < MAX) {
        periods.pb(f);
        f = lcm(f, fn);
        fn++;
    }
    periods.pb(lcm(f,fn));
 
    int i = 0;
    ll res = 0;
    fn = 2;
    while (periods[i] <= n) {
        ll prev = n/periods[i];
        ll next = n/periods[i+1];
        res += (prev-next) * fn;
        res %= MOD;
        i++;
        fn++;
    }
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