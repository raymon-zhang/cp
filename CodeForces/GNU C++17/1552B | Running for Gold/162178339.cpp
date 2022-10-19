#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> r(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> r[i][j];
        }
    }
 
    int w = 0;
    for (int i = 1; i < n; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++) {
            if (r[i][j] < r[w][j]) {
                count++;
            }
        }
        if (count >= 3) {
            w = i;
        }
    }
 
    for (int i = 0; i < n; i++) {
        if (i == w) continue;
        int count = 0;
        for (int j = 0; j < 5; j++) {
            if (r[i][j] < r[w][j]) {
                count++;
            }
        }
        if (count >= 3) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << w+1 << "\n";
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