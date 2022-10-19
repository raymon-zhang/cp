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
 
#define int ll
#define double long double
 
void solve() {
    int h, c, t;
    cin >> h >> c >> t;
    double m = ((double)h + c)/2;
    if (t >= h) {
        cout << "1\n";
        return;
    }
    if (t <= m) {
        cout << "2\n";
        return;
    }
 
    int l = 0, r = h+1;
    while (l < r) {
        int mid = l+(r-l+1)/2;
        if ((double)(mid * (c+h) + h)/(2*mid + 1) > t) l = mid;
        else r = mid-1;
    }
 
    int lower = l;
 
    double lb = (double)(lower * (c+h) + h)/(2*lower + 1);
    // assert(lb > t);
    if (lb < t) cout << c << " " << h << "\n";
    double ub = (double)((lower+1) * (c+h) + h)/(2*(lower+1) + 1);
    // assert(ub < t);
    if (ub > t) cout << c << " " << h << "\n";
 
 
    if (abs(ub - t) < abs(lb - t)) {
        cout << 2*(lower+1)+1 << "\n";
    } else {
        cout << 2*lower+1 << "\n";
    }
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}