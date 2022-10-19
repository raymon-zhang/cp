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
 
ll choose(ll n) {
    return max(0ll, n * (n-1) * (n-2) / 6);
}
 
void solve() {
    ll n;
    cin >> n;
    V<pii> problems;
    map<ll, ll> a;
    map<ll, ll> b;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        a[x]++;
        b[y]++;
        problems.pb({x, y});
    }
 
    ll bad = 0;
    for (int i = 0; i < n; i++) {
        bad += (a[problems[i].first] - 1) * (b[problems[i].second] - 1);
    }
 
    cout << choose(n) - bad << "\n";
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