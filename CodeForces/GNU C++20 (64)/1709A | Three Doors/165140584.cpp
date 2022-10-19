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
    int x;
    cin >> x;
    vector<int> keys(4);
    vector<bool> visited(4);
    cin >> keys[1] >> keys[2] >> keys[3];
    visited[x] = true;
    x = keys[x];
    visited[x] = true;
    x = keys[x];
    visited[x] = true;
    x = keys[x];
    visited[x] = true;
    int good = true;
    for (int i = 1; i <= 3; i++) {
        if (!visited[i]) {
            good = false;
        }
    }
    cout << (good ? "YES\n": "NO\n");
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