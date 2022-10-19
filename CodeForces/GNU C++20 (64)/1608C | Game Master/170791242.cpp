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
    V<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    map<int, int> ab, ba;
    for (int i = 0; i < n; i++) {
        ab[a[i]] = b[i];
        ba[b[i]] = a[i];
    }
    V<int> oa = a;
    V<int> ob = b;
    map<int, int> ap, bp;
    sort(all(a));
    sort(all(b));
    for (int i = 0; i < n; i++) {
        ap[a[i]] = i;
        bp[b[i]] = i;
    }
 
    int bc = 0;
    int mxbp = 0;
    int ac = 0;
    int mxap = 0;
    int starta = 0;
    while (true) {
        // cout << ac << "ac\n";
        for (int i = ac; i <= mxap; i++) {
            smax(mxbp, bp[ab[a[i]]]);
        }
        ac = mxap;
        for (int i = bc; i <= mxbp; i++) {
            smax(mxap, ap[ba[b[i]]]);
        }
        bc = mxbp;
 
        if (mxap == n-1) {
            break;
        } else if (mxap <= ac) {
            ac++;
            mxap = ac;
            starta = ac;
        }
    }
 
    bc = 0;
    mxbp = 0;
    ac = 0;
    mxap = 0;
    int startb = 0;
    while (true) {
        for (int i = bc; i <= mxbp; i++) {
            smax(mxap, ap[ba[b[i]]]);
        }
        bc = mxbp;
        for (int i = ac; i <= mxap; i++) {
            smax(mxbp, bp[ab[a[i]]]);
        }
        ac = mxap;
 
 
        if (mxbp == n-1) {
            break;
        } else if (mxbp <= bc) {
            bc++;
            mxbp = bc;
            startb = bc;
        }
    }
    // cout << starta << " " << startb << "\n";
 
    for (int i = 0; i < n; i++) {
        // cout << b[i] << " " << bp[b[i]] << "\n";
        if (ap[oa[i]] >= starta || bp[ob[i]] >= startb) {
            cout << "1";
        } else cout << "0";
    }
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