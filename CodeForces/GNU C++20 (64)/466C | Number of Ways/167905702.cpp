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
    V<int> a(n);
    ll sum = 0;
    for (int &i: a) {
        cin >> i;
        sum += i;
    }
    if (sum%3) {
        cout << "0\n";
        return 0;
    }
 
    sum /= 3;
 
    V<int> sc(n+1);
    ll suf = 0;
    sc[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        suf += a[i];
        sc[i] = sc[i+1];
        if (suf == sum) sc[i]++;
    }
 
    ll count = 0;
 
    ll p = a[0];
    for (int i = 1; i < n-1; i++) {
        if (p == sum) count += sc[i+1];
        p += a[i];
    }
 
    cout << count << "\n";
}