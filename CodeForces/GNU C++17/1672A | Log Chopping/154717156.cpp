#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x-1;
    }
    cout << ((s % 2) ? "errorgorn" : "maomao90") << "\n";
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}