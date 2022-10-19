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
    vector<int> b(n+1);
    int root = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b[i] = x;
        if (x == i) root = x;
    }
 
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
 
    if (p[0] != root) {
        cout << "-1\n";
        return;
    }
 
    vector<int> w(n+1);
    vector<bool> visited(n+1);
    visited[root] = true;
    int weight = 0;
    for (int i = 1; i < n; i++) {
        int node = p[i];
        if (!visited[b[node]]) {
            cout << "-1\n";
            return;
        }
        weight++;
        visited[node] = true;
        w[node] = weight;
    }
 
    for (int i = 0; i < n; i++) {
        cout << w[i+1] - w[b[i+1]] << " ";
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