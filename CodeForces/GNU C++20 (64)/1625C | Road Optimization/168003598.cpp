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
 
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(nullptr);
 
    int n, l, k;
    cin >> n >> l >> k;
    V<int> d(n), a(n);
    for (int &i: d) cin >> i;
    for (int &i: a) cin >> i;
    d.pb(l);
 
    V<V<int>> dp(n+1, V<int>(k+1));
    for (int i = 0; i <= k; i++) dp[0][i] = 0;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j] + a[i-1] * (d[i] - d[i-1]);
 
            for (int x = i-2; x >= i-1-j && x >= 0; x--) {
                smin(dp[i][j], dp[x][j-(i-x-1)] + a[x] * (d[i] - d[x]));
            }
        }
    }
 
    cout << dp[n][k] << "\n";
}