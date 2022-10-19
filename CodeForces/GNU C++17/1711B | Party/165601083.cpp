#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
 
#define int ll
 
int a[200005];
int c[200005];
int f[200005];
int s[200005];
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = 0;
    }
    int best = 1e9;
 
    int x,y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        c[x]++;
        c[y]++;
        f[i] = x;
        s[i] = y;
    }
    if (m%2 == 0) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i <= m; i++) {
        int gf = f[i];
        int gs = s[i];
        if (c[gf]%2) {
            if (a[gf] < best) best = a[gf];
        }
        if (c[gs]%2) {
            if (a[gs] < best) best = a[gs];
        }
        if ((c[gf]+c[gs]-1)%2) {
            if (a[gf] + a[gs] < best) best = a[gf]+a[gs];
        }
    }
    
    cout << best << "\n";
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
}