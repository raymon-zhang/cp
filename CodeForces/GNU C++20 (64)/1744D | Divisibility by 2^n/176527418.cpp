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
    int twos = 0;
    for (int &i: a) {
        cin >> i;
        int c = 0;
        int x = i;
        while (!(x&1)) {
            c++;
            x /= 2;
        }
        twos += c;
    }
 
    V<int> avail;
    for (int i = 1; i <= n; i++) {
        int c = 0, x = i;
        while (!(x&1)) {
            c++;
            x /= 2;
        }
        avail.pb(c);
    }
    sort(all(avail));
    reverse(all(avail));
 
    int count = 0;
    for (int i = 0; i < sz(avail) && twos < n; i++) {
        // cout << avail[i] << " ";
        count++;
        twos += avail[i];
    }
    // cout << "\n";
    if (twos >= n) {
        cout << count << "\n";
    }
    else {
        cout << "-1\n";
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