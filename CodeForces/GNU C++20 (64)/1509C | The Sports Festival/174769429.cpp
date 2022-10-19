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
    int n;
    cin >> n;
    V<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
 
    sort(all(s));
 
    V<V<ll>> dp(n+1, V<ll>(n+1));
 
    for (int l = 2; l <= n; l++) {
        for (int start = 0; start+l-1 < n; start++) {
            dp[l][start] = min(dp[l-1][start], dp[l-1][start+1]) + s[start+l-1] - s[start];
        }
    }
 
    cout << dp[n][0] << "\n";
}