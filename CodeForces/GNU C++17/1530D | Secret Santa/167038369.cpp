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
    int n;
    cin >> n;
    V<int> a(n+1);
    V<int> deg(n+1);
    V<int> zeros;
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        deg[a[i]]++;
    }
 
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) zeros.pb(i);
    }
 
    V<int> taken(n+1);
    V<int> res;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!taken[a[i]]) {
            res.pb(a[i]);
            taken[a[i]] = i;
            count++;
        } else {
            res.pb(zeros.back());
            zeros.pop_back();
        }
 
        if (res[i-1] == i) swap(res[i-1], res[taken[a[i]]-1]);
    }
    cout << count << "\n";
    for (int i: res) cout << i << " ";
    cout << "\n";
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