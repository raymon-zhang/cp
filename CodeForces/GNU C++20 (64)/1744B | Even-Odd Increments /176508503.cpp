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
    ll n, q;
    cin >> n >> q;
    V<ll> a(n);
    ll eCount = 0, oCount = 0;
    ll sum = 0;
    for (ll &i: a) {
        cin >> i;
        if (i&1) oCount++;
        else eCount++;
        sum += i;
    }
 
    for (ll t = 0; t < q; t++) {
        ll type, x;
        cin >> type >> x;
        if (type) {
            sum += oCount*x;
            cout << sum << "\n";
            if (x&1) {
                eCount += oCount;
                oCount = 0;
            }
        } else {
            sum += eCount*x;
            cout << sum <<"\n";
            if (x&1) {
                oCount += eCount;
                eCount = 0;
            }
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