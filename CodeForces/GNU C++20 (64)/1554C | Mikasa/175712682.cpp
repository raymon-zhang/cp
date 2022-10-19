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
 
void solve() {
    ll n, m;
    cin >> n >> m;
 
    ll res = 0;
    int pos = 30;
    while (pos >= 0) {
        ll mask = 1<<pos;
        // cout << mask << " " << (n&mask) << "\n";
        if (!(m & mask) && (n & mask)) {
            // cout << "hi\n";
            cout << res << "\n";
            return;
        }
        if ((m & mask) && !(n & mask)) res |= mask;
        pos--;
    }
 
    for (int i = 0; i <= 30; i++) {
        if (!(n & (1<<i)) && !(m & (1<<i))) {
            res |= 1<<i;
            for (int j = i-1; j >= 0; j--) res &= ~(1<<j);
            break;
        }
    }
 
    cout << res << "\n";
    // cout << "hi\n";
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