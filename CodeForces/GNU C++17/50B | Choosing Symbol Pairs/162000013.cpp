#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    map<char, long long> m;
    string s;
    cin >> s;
    for (char c: s) {
        m[c]++;
    }
    long long total = 0;
 
    for (auto p : m) {
        total += p.second * p.second;
    }
    cout << total << "\n";
}