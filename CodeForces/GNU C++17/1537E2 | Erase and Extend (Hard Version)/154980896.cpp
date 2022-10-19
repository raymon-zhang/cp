#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n,k;
    string s;
    cin >> n >> k >> s;
 
    int i = 0;
    int l = 0;
    for (i = 1; i < n; i++) {
        if (s.at(i) > s.at(l)) {
            break;
        }
        if (s.at(i) == s.at(l)) {
            l++;
        } else {
            l = 0;
        }
    }
    i -= l;
    for (int j = 0; j < k; j++) {
        cout << s.at(j%i);
    }
    cout << "\n";
}