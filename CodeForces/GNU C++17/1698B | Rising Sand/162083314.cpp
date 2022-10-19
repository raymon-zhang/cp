#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i: a) {
        cin >> i;
    }
 
    if (k == 1) {
        int ans = (n-1)/2;
        cout << ans << "\n";
    }
    else {
        int count = 0;
        for (int i = 1; i < n-1; i++) {
            if (a[i] > a[i-1] + a[i+1]) {
                count++;
            }
        }
        cout << count << "\n";
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