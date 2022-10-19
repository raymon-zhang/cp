#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int a, b;
    cin >> a >> b;
    int digits = 0;
    long long d = 1;
    while (d <= b) {
        digits++;
        d *= 10;
    }
    d/=10;
 
    long long total = 0;
    long long next = 10;
    long long pChange = 0;
 
    while (d) {
        int aDigit = a / d;
        int bDigit = b / d;
        a %= d;
        b %= d;
        long long change = bDigit + next*pChange - aDigit;
        total += change;
        pChange = change;
        d /= 10;
    }
 
    cout << total << "\n";
}
 
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}