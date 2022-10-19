#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e5+1;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    int m = 0;
    vector<long long> freqs(MAX);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freqs[x]++;
        m = max(m, x);
    }
 
    vector<long long> dp(m+1);
 
    for (long long i = 1; i <= m; i++) {
        if (i == 1) {
            dp[i] = i * freqs[i];
        }
        else {
            dp[i] = max(dp[i-1], dp[i-2] + i * freqs[i]);
        }
    }
 
    cout << dp[m] << "\n";
}