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
    int n;
    cin >> n;
    V<int> k(n), h(n);
    for (int &i: k) cin >> i;
    for (int &i: h) cin >> i;
 
    V<pll> segments;
    V<ll> ends;
    for (int i = 0; i < n; i++) {
        ll s = k[i] - h[i] + 1, e = k[i];
        // cout << s << " " << e << "hi\n";
        auto p = lower_bound(all(ends), s);
        // cout << p-begin(ends) << " " << e << "hi\n";
        if (p == end(ends)) {
            segments.pb({s, e});
            ends.pb(e);
        } else {
            int pi = p - begin(ends);
            // cout << pi << " " << e << "hi\n";
            V<pll> newSegments(segments.begin(), segments.begin()+pi);
            V<ll> newEnds(ends.begin(), ends.begin()+pi);
            newSegments.pb({min((*(segments.begin() + pi)).first, s), e});
            newEnds.pb(e);
            segments = newSegments;
            ends = newEnds;
        }
    }
 
    ll sum = 0;
    for (pii x: segments) {
        sum += (x.second - x.first + 2ll) * (x.second - x.first + 1ll) / 2ll;
        // cout << x.first << " " << x.second << "\n";
    }
    cout << sum << "\n";
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