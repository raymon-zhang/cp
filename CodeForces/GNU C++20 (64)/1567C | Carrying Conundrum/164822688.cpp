#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
int numCombos(int x) {
    return x < 10 ? x+1 : (9-x+9+1);
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> digits;
    int size = 0;
    while (n) {
        digits.pb(n%10);
        n/=10;
        size++;
    }
    reverse(all(digits));
    vector<vector<vector<ll>>> dp(size, vector<vector<ll>>(2, vector<ll>(2)));
    dp[size-1][0][0] = numCombos(digits[size-1]);
    dp[size-1][1][0] = numCombos(10+digits[size-1]);
    for (int i = size-2; i >= 0; i--) {
        dp[i][0][0] = dp[i+1][0][0] * numCombos(digits[i]) + dp[i+1][0][1] * numCombos(digits[i]-1);
        dp[i][1][0] = dp[i+1][0][0] * numCombos(10+digits[i]) + dp[i+1][0][1] * numCombos(10+digits[i]-1);
        dp[i][0][1] = dp[i+1][1][0] * numCombos(digits[i]) + dp[i+1][1][1] * numCombos(digits[i]-1);
        dp[i][1][1] = dp[i+1][1][0] * numCombos(10+digits[i]) + dp[i+1][1][1] * numCombos(10+digits[i]-1);
    }
    cout << dp[0][0][0]-2 << "\n";
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