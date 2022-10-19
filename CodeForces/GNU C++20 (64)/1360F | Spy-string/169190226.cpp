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
 
int diff(string s1, string s2) {
    int count = 0;
    for (int i = 0; i < sz(s1); i++) {
        if (s1[i] != s2[i]) count++;
    }
    return count;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    V<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    string f = a[0];
 
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (diff(f, a[i]) > 1) ok = false;
    }
    if (ok) {
        cout << f << "\n";
        return;
    }
 
    for (int i = 0; i < m; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            ok = true;
            string rep = f.substr(0, i) + c + f.substr(i+1);
            for (int j = 1; j < n; j++) {
                if (diff(rep, a[j]) > 1) ok = false;
            }
            if (ok) {
                cout << rep << "\n";
                return;
            }
        }
    }
 
    cout << "-1\n";
}
 
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}