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
    ll n;
    cin >> n;
    V<ll> b(n);
 
    ll sum = 0;
    for (ll &i: b) {
        cin >> i;
        sum += i;
    }
 
    ll total = n * (n+1) / 2;
 
    if (n == 1) {
        cout << "YES\n";
        cout << b[0] << "\n";
        return;
    } else if (sum % total) {
        cout << "NO\n";
        return;
    }
 
    sum /= total;
 
    V<ll> ans(n);
 
    for (int i = 1; i < n; i++) {
        ll d = sum - (b[i] - b[i-1]);
        if (!(d % n) && d/n > 0) {
            ans[i] = d/n;
        } else {
            cout << "NO\n";
            return;
        }
    }
 
    ll d = sum - (b[0] - b[n-1]);
    if (!(d % n) && d/n > 0) {
        ans[0] = d/n;
    } else {
        cout << "NO\n";
        return;
    }
 
    cout << "YES\n";
    for (ll i: ans) cout << i << " ";
    cout << "\n";
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