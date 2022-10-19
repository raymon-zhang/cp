#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
 
    string s;
    cin >> s;
 
    vector<bool> chars(26);
 
    int m = 27;
 
    for (int i = 0; i < n; i++) {
        chars[s[i] - 'a'] = true;
        m = min(m, s[i] - 'a');
    }
 
    vector<char> res(k);
    if (k > n) {
        for (int i = 0; i < n; i++) {
            res[i] = s[i];
        }
        for (int i = n; i < k; i++) {
            res[i] = m + 'a';
        }
    }
 
    else {
 
    bool bigger = false;
 
    for (int i = k-1; i >= 0; i--) {
        if (bigger) {
            res[i] = s[i];
            continue;
        }
        if (i < n) {
            for (int j = s[i] - 'a' + 1; j < 26; j++) {
                if (chars[j]) {
                    res[i] = j + 'a';
                    bigger = true;
                    break;
                }
            }
            if (!bigger) {
                res[i] = m + 'a';
            }
        } else {
            res[i] = m + 'a';
        }
    }
    }
 
    string r(res.begin(), res.end());
    cout << r << "\n";
}