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
const ll BIG = 1e18;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
 
void solve() {
    ll n, k, z;
    cin >> n >> k >> z;
    V<ll> a(n);
    for (ll &i: a) {
        cin >> i;
    }
 
    ll biggest = 0;
    ll biggestOne = 0;
    ll sum = 0;
    for (ll i = 0; i < k-2*z; i++) {
        if (i) smax(biggest, a[i]+a[i-1]);
        smax(biggestOne, a[i]);
        sum += a[i];
    }
    ll best = 0;
    for (ll i = k-2*z; i <= k; i++) {
        if (i >= 0) {
            sum += a[i];
            if (i>0) smax(biggest, a[i]+a[i-1]);
            smax(biggestOne, a[i]);
            if (i > 0) {
                if ((k-i)%2 == 0) smax(best, sum + biggest*((k-i)/2));
                else smax(best, sum + biggest*((k-i)/2) + a[i-1]);
            }
 
            // cout << (k-i)/2 << "\n";
        }
    }
 
    // if (best > 100000) cout << n << " " << k << " " << z << "\n";
 
    cout << best << "\n";
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