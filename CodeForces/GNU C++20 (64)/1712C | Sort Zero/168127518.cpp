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
    V<int> a(n);
    for (int &i: a) cin >> i;
 
    int i = 0;
    int cost = 0;
    set<int> encountered;
    V<bool> zeroed(n+1);
    zeroed[0] = true;
    while (i < n-1) {
        if (zeroed[a[i]]) a[i] = 0;
        encountered.insert(a[i]);
        if (zeroed[a[i+1]]) a[i+1] = 0;
        if (a[i] > a[i+1]) {
            for (int x: encountered) {
                if (!zeroed[x]) {
                    zeroed[x] = true;
                    cost++;
                }
            }
            encountered.clear();
        }
        i++;
    }
    cout << cost << "\n";
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