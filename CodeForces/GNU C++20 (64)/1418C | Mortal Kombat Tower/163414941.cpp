#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
const int M = 9;
 
void solve() {
    int n;
    cin >> n;
    vector<int> bosses(n);
    for (int &i: bosses) {
        cin >> i;
    }
 
    vector<vector<int>> dp(n, vector<int>(2));
    assert(n >= 1);
    dp[0][1] = M;
    dp[0][0] = bosses[0] ? 1 : 0;
    if (n > 1) {
        dp[1][0] = dp[0][0] + bosses[1];
        dp[1][1] = dp[0][0];
        // cout << dp[0][0] << " " << bosses[1] << "\n";
        // cout << (dp[0][0] + bosses[1]) << " " << dp[1][0] << "\n";
    }
    for (int i = 2; i < n; i++) {
        int friendCost = bosses[i] ? 1 : 0;
        int pFriendCost = bosses[i-1] ? 1 : 0;
        dp[i][0] = min(dp[i-2][1] + friendCost + pFriendCost, dp[i-1][1] + friendCost);
        dp[i][1] = min(dp[i-2][0], dp[i-1][0]);
    }
    cout << min(dp[n-1][0], dp[n-1][1]) << "\n";
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