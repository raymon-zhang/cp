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
 
    int k;
    cin >> k;
    int n = (1<<k) - 1;
    V<char> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    reverse(all(s));
 
    V<int> dp(n+1);
    for (int i = n; i > 0; i--) {
        if (i*2 > n) {
            dp[i] = (s[i-1] == '?' ? 2 : 1);
        } else {
            if (s[i-1] == '0') {
                dp[i] = dp[i*2+1];
            } else if (s[i-1] == '1') {
                dp[i] = dp[i*2];
            } else {
                dp[i] = dp[i*2] + dp[i*2+1];
            }
        }
    }
 
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int p;
        char c;
        cin >> p >> c;
        p = n-p+1;
        s[p-1] = c;
        while (p>0) {
            // cout << p << " ";
            if (p*2 > n) {
                dp[p] = (s[p-1] == '?' ? 2 : 1);
            } else {
                if (s[p-1] == '0') {
                    dp[p] = dp[p*2+1];
                } else if (s[p-1] == '1') {
                    dp[p] = dp[p*2];
                } else {
                    dp[p] = dp[p*2] + dp[p*2+1];
                }
            }
            p = p>>1;
        }
 
        // cout << "\n" << s[1] << "\n";
        cout << dp[1] << "\n";
    }
}