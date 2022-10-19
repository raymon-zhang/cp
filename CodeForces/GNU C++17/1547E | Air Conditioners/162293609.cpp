#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 2e9;
 
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(k);
    vector<int> t(n, MAX);
 
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
 
    for (int i = 0; i < k; i++) {
        cin >> t[--a[i]];
    }
 
    vector<int> fromLeft(n);
    vector<int> fromRight(n);
 
    int cur = MAX;
    for (int i = 0; i < n; i++) {
        cur = min(cur, t[i]);
        fromLeft[i] = cur;
        cur++;
    }
 
    cur = MAX;
    for (int i = n-1; i >= 0; i--) {
        cur = min(cur, t[i]);
        fromRight[i] = cur;
        cur++;
    }
 
    for (int i = 0; i < n; i++) {
        cout << min(fromLeft[i], fromRight[i]) << " ";
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