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
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
 
    V<ll> af, bf;
    for (ll i = 1; i*i <= a; i++) {
        if (i*i > a) break;
        if (a%i == 0) {
            af.pb(i);
            af.pb(a/i);
        }
    }
    for (ll i = 1; i*i <= b; i++) {
        if (i*i > b) break;
        if (b%i == 0) {
            bf.pb(i);
            bf.pb(b/i);
        }
    }
 
    for (ll fa: af) {
        for (ll fb: bf) {
            ll f1 = fa*fb;
            ll f2 = a*b/f1;
            ll ab = a/f1;
            ab *= f1;
            if (ab <= a) ab += f1;
            ll bb = b/f2;
            bb *= f2;
            if (bb <= b) bb += f2;
            if (ab <= c && bb <= d) {
                cout << ab << " " << bb << "\n";
                return;
            }
        }
    }
    cout << "-1 -1\n";
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