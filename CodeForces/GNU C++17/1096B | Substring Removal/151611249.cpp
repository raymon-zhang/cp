#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 998244353;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    string s;
    cin >> n >> s;
 
    long long l = 1;
    for (int i = 0; i < n && s[i] == s[0]; i++) {
        l++;
        l %= MOD;
    }
 
    long long r = 1;
    for (int i = n-1; i >= 0 && s[i] == s[n-1]; i--) {
        r++;
        r %= MOD;
    }
 
    if (s[0] == s[n-1]) {
        cout << (l*r)%MOD << "\n";
    } else {
        cout << (l + r - 1)%MOD << "\n";
    }
}