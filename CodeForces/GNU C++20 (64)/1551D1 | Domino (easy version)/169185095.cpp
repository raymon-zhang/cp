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
    int n, m, k;
    cin >> n >> m >> k;
    if (n == 1) {
        cout << (k == m/2 ? "YES\n" : "NO\n");
        return;
    } 
    if (m == 1) {
        cout << (k == 0 ? "YES\n" : "NO\n");
        return;
    }
    
    if (n%2 == 0 && m%2 == 0) {
        cout << (k&1 ? "NO\n" : "YES\n");
    } else if (n%2 == 0) {
        if (k%2 == 0 && k <= (m-1)*n/2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        int k2 = n*m/2 - k; 
        if (k2%2 == 0 && k2 <= (n-1)*m/2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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