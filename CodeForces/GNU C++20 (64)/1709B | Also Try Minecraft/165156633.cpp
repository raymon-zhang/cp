#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &i: a) {
        cin >> i;
    }
 
    vector<ll> p;
    p.pb(0);
    p.pb(0);
    for (int i = 1; i < n; i++) {
        p.pb(p[i] + (a[i] < a[i-1] ? a[i-1]-a[i] : 0));
    }
 
    vector<ll> s(n+1);
    s[n] = 0;
    s[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        s[i] = s[i+1] + (a[i] < a[i+1] ? a[i+1] - a[i] : 0);
    }
 
 
    for (int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        if (x < y) {
            cout << p[y] - p[x] << "\n";
        } else {
            cout << s[y-1] - s[x-1] << "\n";
        }
    }
}