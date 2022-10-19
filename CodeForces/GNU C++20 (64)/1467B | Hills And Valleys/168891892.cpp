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
 
bool thing(int a, int b, int c) {
    return ((a > b && a > c) || (a < b && a < c));
}
 
void solve() {
    int n;
    cin >> n;
    V<int> a(n);
    V<bool> bad(n);
    for (int &i: a) cin >> i;
    int intimidation = 0;
    for (int i = 1; i < n-1; i++) {
        if (thing(a[i], a[i-1], a[i+1])) {
            intimidation++;
            bad[i] = true;
        }
    }
 
    int ans = intimidation;
    for (int i = 1; i < n-1; i++) {
        int t1 = intimidation;
        if (i > 1 && bad[i-1]) t1--;
        if (bad[i]) t1--;
        if (i < n-2 && !thing(a[i+1], a[i-1], a[i+2]) && bad[i+1]) t1--;
        else if (i < n-2 && thing(a[i+1], a[i-1], a[i+2]) && !bad[i+1]) t1++;
        ans = min(ans, t1);
        int t2 = intimidation;
        if (i < n-2 && bad[i+1]) t2--;
        if (bad[i]) t2--;
        if (i > 1 && !thing(a[i-1], a[i+1], a[i-2]) && bad[i-1]) t2--;
        else if (i > 1 && thing(a[i-1], a[i+1], a[i-2]) && !bad[i-1]) t2++;
        ans = min(ans, t2);
    }
    cout << ans << "\n";
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