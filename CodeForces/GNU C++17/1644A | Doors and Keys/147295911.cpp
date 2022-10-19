#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    string s;
    cin >> s;
    bool keyRed = false, keyBlue = false, keyGreen = false;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 'r') {
            keyRed = true;
        }
        if (s.at(i) == 'g') {
            keyGreen = true;
        }
        if (s.at(i) == 'b') {
            keyBlue = true;
        }
 
        if (s.at(i) == 'R' && keyRed == false) {
            cout << "NO" << "\n";
            return;
        }
        if (s.at(i) == 'G' && keyGreen == false) {
            cout << "NO" << "\n";
            return;
        }
        if (s.at(i) == 'B' && keyBlue == false) {
            cout << "NO" << "\n";
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