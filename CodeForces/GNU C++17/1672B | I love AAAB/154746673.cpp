#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    string s;
    cin >> s;
    vector<int> aLeft(s.size());
    vector<int> bLeft(s.size());
    int bC = 0;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s.at(i) == 'B') {
            bC++;
        }
        bLeft[i] = bC;
    }
    int aC = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 'A') {
            aC++;
        } else {
            if (aC == 0) {
                cout << "NO\n";
                return;
            }
            aC--;
        }
        if (bLeft[i] == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES" << "\n";
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}