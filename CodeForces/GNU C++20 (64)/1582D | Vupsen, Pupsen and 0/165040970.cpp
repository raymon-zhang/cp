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
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i].first = x;
        a[i].second = i;
    }
 
    sort(all(a));
 
    vector<int> b(n, 0);
    for (int i = 0; i < n-1; i+=2) {
        int g = gcd(a[i].first, a[i+1].first);
        b[a[i].second] = -(a[i+1].first/g);
        b[a[i+1].second] = a[i].first/g;
    }
 
    if (n&1) {
        int g = gcd(a[n-1].first, a[n-2].first);
        if (b[a[n-2].second] + a[n-1].first/g == 0) {
            b[a[n-2].second] -= a[n-1].first/g;
            b[a[n-1].second] = (a[n-2].first/g);
        } else {
            b[a[n-2].second] += a[n-1].first/g;
            b[a[n-1].second] = -(a[n-2].first/g);
        }
    }
    for (int i: b) {
        cout << i << " ";
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