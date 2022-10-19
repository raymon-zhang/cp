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
    char f;
    cin >> n >> f;
    string s;
    cin >> s;
    s += s;
    int best = 0;
    int gap = 0;
    bool active = false;
    for (char c: s) {
        if (active)gap++;
        // cout << c << " " << gap << "\n";
        if (c == f) {
            if (!active) {
                gap = 0;
                active = true;
            }
        }
        else if (c == 'g') {
            best = max(best, gap);
            active = false;
            gap = 0;
        }
    }
    cout << best << "\n";
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