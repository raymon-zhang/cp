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
    int s;
    cin >> s;
    vector<int> digits;
    int cur = 9;
    while (s > 0) {
        digits.pb(min(s, cur));
        s -= min(s, cur);
        cur--;
    }
    sort(all(digits));
    for (int i: digits) cout << i;
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