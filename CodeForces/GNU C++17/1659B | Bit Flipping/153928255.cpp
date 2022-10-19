#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int m = k;
    char target = k%2 ? '0' : '1';
    vector<int> result(n);
 
    for (int i = 0; i < n && m > 0; i++) {
        if (s.at(i) != target) {
            result[i]++;
            m--;
        }
    }
 
    if (m > 0) {
        result[n-1] += m;
    }
 
    for (int i = 0; i < n; i++) {
        if (s.at(i) == '0') {
            cout << ((k-result[i])%2 ? '1' : '0');
        } else {
            cout << ((k-result[i])%2 ? '0' : '1');
        }
    }
    cout << "\n";
    for (int i = 0 ; i < n; i++) {
        cout << result[i] << " ";
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