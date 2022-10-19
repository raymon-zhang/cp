#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    string s;
    cin >> s;
    vector<int> d(0);
    vector<int> f(10);
    for (char c: s) {
        d.push_back((c-'0'));
        f[(c-'0')]++;
    }
    int n = d.size();
    int ans = n;
    for (int i = 0; i <= 9; i++) {
        ans = min(ans, n-f[i]);
    }
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            int count = 0;
            bool isI = true;
            for (int k = 0; k < n; k++) {
                if (d[k] == (isI ? i : j)) {
                    count++;
                    isI = !isI;
                }
            }
            if (count & 1) {
                count--;
            }
            ans = min(ans, n-count);
        }
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