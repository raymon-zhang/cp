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
 
#define int ll
 
void solve() {
    int n;
    cin >> n;
    V<int> a(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    if (a[0] != a[1] || a[0]%2) {
        cout << "NO\n";
        return;
    }
    int total = 0;
    int cum = 0;
    for (int i = 2; i < 2*n; i+=2) {
        if (a[i] != a[i+1] || a[i]%2) {
            cout << "NO\n";
            return;
        }
        if (!((a[i]-a[i-2]) >= i && (a[i]-a[i-2]) % i == 0)) {
            cout << "NO\n";
            return;
        }
 
        cum += (a[i] - a[i-2]) / i;
        total += cum;
    }
 
    if ((a[0] - 2*total) % (2*n) == 0 && (a[0] - 2*total) / (2*n) > 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}