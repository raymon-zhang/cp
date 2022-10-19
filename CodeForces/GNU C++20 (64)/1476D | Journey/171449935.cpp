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
    string s;
    cin >> s;
    
    V<int> dpl0(n+1), dpr0(n+1), dpl1(n+1), dpr1(n+1);
    for (int i = 1; i <= n; i++) {
        dpl0[i] = s[i-1] == 'L' ? dpl1[i-1]+1 : 0;
        dpl1[i] = s[i-1] == 'R' ? dpl0[i-1]+1 : 0;
    }
    
    for (int i = n-1; i >= 0; i--) {
        dpr0[i] = s[i] == 'R' ? dpr1[i+1]+1 : 0;
        dpr1[i] = s[i] == 'L' ? dpr0[i+1]+1 : 0;
    }
    
    for (int i = 0; i <= n; i++) {
        cout << dpl0[i] + dpr0[i] + 1 << " ";
    }
    cout << "\n";
}
 
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}