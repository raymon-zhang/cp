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
    bool m5 = false, m0 = false;
    for (int &i: a) {
        cin >> i;
        if ((i+10) % 10 == 0) m0 = true;
        if ((i+10) % 10 == 5) m5 = true;
    }
    if (m0 || m5) {
        for (int &i: a) {
            if ((i+10) % 10 != 0 && (i+10) % 10 != 5) {
                cout << "NO\n";
                return;
            }
            while ((i+10) %10) i += (i+10)%10;
            if (i != a[0]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    } else {
        for (int &i: a) {
            while ((i+10) % 10 != 2) i += (i+10)%10;
            if (((i - a[0])/10)&1) {
                cout << "NO\n";
                return;
            }
        }
 
        cout << "YES\n";
        return;
    }
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