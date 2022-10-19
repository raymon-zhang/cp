#include <bits/stdc++.h>
using namespace std;
 
const long long MAX = -(2e9);
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<vector<long long>> dp(n+1, vector<long long>(n+1, MAX));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    dp[0][0] = 0;
 
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= i; j++) {
            if (dp[i-1][j-1] + x >= 0) {
                dp[i][j] = max(dp[i-1][j-1]+x, dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    //
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    //
    int ans = n;
    while (dp[n][ans] == MAX) {
        ans--;
    }
    cout << ans << "\n";
}