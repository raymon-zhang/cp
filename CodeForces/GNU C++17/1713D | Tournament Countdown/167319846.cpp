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
    n = 1<<n;
    V<pii> g;
    for (int i = 1; i <= n; i+=2) {
        g.pb({i, i+1});
    }
 
    int blockSize = 2;
    while (sz(g) > 1) {
        V<pii> ng;
        for (int i = 0; i < n/blockSize; i+=2) {
            cout << "? " << g[i].first << " " << g[i+1].first << endl;
            int ans;
            cin >> ans;
            if (ans == 1) ng.pb({g[i].first, g[i+1].second});
            else if (ans == 2) ng.pb({g[i+1].first, g[i].second});
            else ng.pb({g[i].second, g[i+1].second});
        }
        g = ng;
        blockSize *= 2;
    }
 
    cout << "? " << g[0].first << " " << g[0].second << endl;
    int ans;
    cin >> ans;
    if (ans == 1) {
        cout << "! " << g[0].first << endl;
    } else {
        cout << "! " << g[0].second << endl;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    // cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}