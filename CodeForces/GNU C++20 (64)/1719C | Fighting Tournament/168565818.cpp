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
    int n, q;
    cin >> n >> q;
    V<int> a(n+1);
    V<pii> segments(n+1);
 
    cin >> a[0];
    int posBig = (a[0] == n) ? 1 : 0;
    int winner = a[0];
    segments[a[0]].first = 1;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i] == n) posBig = i;
        if (a[i] > winner) {
            segments[a[i]].first = i;
            segments[winner].second = i;
            winner = a[i];
        } else {
            segments[a[i]].first = i;
            segments[a[i]].second = i;
        }
    }
 
    posBig++;
 
    for (int j = 0; j < q; j++) {
        int i, k;
        cin >> i >> k;
 
        i = a[i-1];
 
        if (i == n) {
            cout << max(0, k-posBig + 1 + (posBig != 1)) << "\n";
        } else {
            cout << max(0, min(k+1, segments[i].second) - (segments[i].first)) << "\n";
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