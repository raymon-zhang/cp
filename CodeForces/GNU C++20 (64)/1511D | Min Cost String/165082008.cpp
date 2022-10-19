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
 
    int n, k;
    cin >> n >> k;
    vector<vector<int>> freq(k, vector<int>(k));
 
    vector<int> cycle;
    vector<int> cur(k);
    stack<int> s;
    s.push(0);
    while (!s.empty()) {
        int u = s.top();
        if (cur[u] < k) {
            s.push(cur[u]++);
        } else {
            cycle.pb(u);
            s.pop();
        }
    }
 
    cout << 'a';
    for (int i = 0; i < n-1; i++) {
        cout << (char)('a' + cycle[i%(cycle.size()-1)]);
    }
    cout << "\n";
}