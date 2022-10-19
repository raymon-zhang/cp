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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int l = 0, r = n;
    while (l < r) {
        int m = (l+r+1)/2;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (count <= b[i] && m-1-count <= a[i]) {
                count++;
            }
        }
        if (count < m) {
            r = m-1;
        } else {
            l = m;
        }
    }
    cout << l << "\n";
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