#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
 
    unordered_set<int> counts;
 
    for (auto kv: mp) {
        counts.insert(kv.second);
    }
 
    int ans = 2e5;
    for (int count: counts) {
        int total = 0;
        for (auto kv: mp) {
            if (kv.second < count) {
                total += kv.second;
            } else {
                total += (kv.second - count);
            }
        }
        ans = min(ans, total);
    }
 
    cout << ans << "\n";
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