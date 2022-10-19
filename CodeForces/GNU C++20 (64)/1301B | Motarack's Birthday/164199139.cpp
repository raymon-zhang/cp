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
    vector<int> a(n);
    for (int &i: a) {
        cin >> i;
    }
    int mn = 1e9, mx = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            if ((i && a[i-1] == -1) || (i < n-1 && a[i+1] == -1)) {
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
                count++;
            }
        }
    }
    int res = 0;
    if (count) {
        res = (mn + mx)/2;
    }
    int maxD = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = res;
        }
        if (i) {
            maxD = max(maxD, abs(a[i] - a[i-1]));
        }
    }
    cout << maxD << " " << res << "\n";
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