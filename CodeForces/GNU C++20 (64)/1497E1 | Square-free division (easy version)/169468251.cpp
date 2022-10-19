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
const int MX = 2e7+5;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
 
int max_div[MX + 1];
 
int res(int x) {
    int ans = 1;
    while (x != 1) {
        int prime = max_div[x];
        int count = 0;
        while (x % prime == 0) {
            count++;
            x /= prime;
        }
        if (count & 1) ans *= prime;
    }
    return ans;
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    V<int> a(n);
    for (int &i: a) cin >> i;
 
    map<int, int> f;
    int count = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int r = res(a[i]);
        if (f.count(r)) {
            f = map<int, int>();
            ans++;
            count++;
        }
        f[r]++;
        count++;
    }
    if (count) ans++;
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    for (int i = 2; i <= MX; i++) {
        if (max_div[i] == 0) {
            for (int j = i; j <= MX; j+= i) max_div[j] = i;
        }
    }
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}