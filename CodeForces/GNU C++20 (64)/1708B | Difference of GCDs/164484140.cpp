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
 
    int T;
    cin >> T;
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> res;
        bool good = true;
        for (int i = 1; i <= n; i++) {
            if (r/i*i >= l) {
                res.pb(r/i*i);
            } else {
                good = false;
            }
        }
        if (good) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << res[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
}