#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
const int MOD = 1e9+7;
 
vector<vector<ll>> dp(2e5+1, vector<ll>(10));
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    ll ans = 0;
    while (n) {
        ans += dp[m][n%10];
        ans %= MOD;
        n/=10;
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    for (int i = 0; i < 10; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= 2e5; i++) {
        for (int d = 0; d < 10; d++) {
            if (d == 9) {
                dp[i][d] = dp[i-1][1] + dp[i-1][0];
            } else {
                dp[i][d] = dp[i-1][d+1];
            }
            dp[i][d] %= MOD;
        }
    }
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}