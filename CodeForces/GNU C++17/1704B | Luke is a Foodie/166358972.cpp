#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &i: a) cin >> i;
 
    int count = 0;
    int l = a[0]-x, r = a[0]+x;
    for (int i = 1; i < n; i++) {
        int u = a[i]+x;
        int b = a[i]-x;
        if (u < l) {
            count++;
            r = u;
            l = b;
        } else if (b > r) {
            count++;
            r = u;
            l = b;
        } else {
            l = max(l, b);
            r = min(r, u);
        }
    }
    cout << count << "\n";
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