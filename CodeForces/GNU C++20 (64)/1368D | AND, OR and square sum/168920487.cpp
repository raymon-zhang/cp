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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    V<int> count(20);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < 20; j++) {
            if (x & (1<<j)) count[j]++;
        }
    }
 
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        for (int j = 0; j < 20; j++) {
            if (count[j] > i) num += (1<<j);
        }
        ans += num*num;
    }
    cout << ans << "\n";
}