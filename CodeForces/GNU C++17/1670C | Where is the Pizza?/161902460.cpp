#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
 
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        ab[x].first = i;
        a[i] = x;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        ab[x].second = i;
        b[i] = x;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
 
    long long total = 1;
    vector<bool> seen(n);
    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        int cur = i;
        int pos = 2;
        int compSize = 0;
 
        while (!seen[cur]) {
            compSize++;
            if (c[cur] != 0) {
                pos = 1;
            }
            seen[cur] = true;
            cur = ab[a[cur]].second;
        }
        if (compSize == 1) {
            pos = 1;
        }
        total *= pos;
        total %= MOD;
    }
    cout << total << "\n";
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