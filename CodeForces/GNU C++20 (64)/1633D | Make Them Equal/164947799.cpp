#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    vector<int> cost(1001, 1001);
    cost[1] = 0;
    for (int i = 1; i < 1001; i++) {
        for (int x = 1; x <= i; x++) {
            if ((i+i/x) < 1001) cost[i + i/x] = min(cost[i + i/x], cost[i] + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[i] = cost[x];
    }
 
    vector<int> c(n);
    for (int &i: c) {
        cin >> i;
    }
 
    vector<int> dp(k+1);
    for (int i = 0; i < n; i++) {
        for (int x = k; x >= b[i]; x--) {
            dp[x] = max(dp[x], dp[x-b[i]] + c[i]);
        }
    }
    cout << dp[k] << "\n";
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