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
    map<int, int> f;
    for (int &i: a) {
        cin >> i;
        f[i]++;
    }
    sort(all(a));
 
    priority_queue<int> q;
    ll cost = 0;
    bool done = false;
    for (int i = 0; i <= n; i++) {
        if (done) {
            cout << "-1" << " ";
            continue;
        }
        if (i > 0 && !f[i-1]) {
            if (!q.empty()) {
                int t = q.top(); q.pop();
                cost += i-t-1;
            } else {
                done = true;
                cout << "-1" << " ";
                continue;
            }
        }
        cout << cost + f[i] << " ";
        if (i > 0) for (int j = 0; j < f[i-1]-1; j++) q.push(i-1);
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