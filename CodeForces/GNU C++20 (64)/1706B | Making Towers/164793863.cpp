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
    vector<int> colors(n);
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        colors[i] = c;
        pos[c].pb(i);
    }
 
    for (int color = 1; color <= n; color++) {
        int len = 0;
        if (pos.count(color)) {
            int prev = pos[color][0];
            len++;
            for (int i = 1; i < pos[color].size(); i++) {
                if ((pos[color][i] - prev - 1) % 2 == 0) {
                    len++;
                    prev = pos[color][i];
                }
            }
        }
        cout << len << "\n";
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