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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &i: a) {
        cin >> i;
    }
    reverse(all(a));
    vector<bool> res;
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= x) {
            res.pb(1);
        }
        else if (x < q) {
            res.pb(1);
            x++;
        } else {
            res.pb(0);
        }
    }
    reverse(all(res));
    for (int i = 0; i < n; i++) {
        cout << res[i];
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