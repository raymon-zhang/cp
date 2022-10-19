#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
 
int toB64(char c) {
    if (c == '-') return 62;
    if (c == '_') return 63;
    if (c <= '9') return c - '0';
    if (c <= 'Z') return c - 'A' + 10;
    return c - 'a' + 36;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    string s;
    cin >> s;
    vector<int> nums;
    for (char c: s) {
        nums.push_back(toB64(c));
    }
 
    long long pos = 1;
    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        for (int p = 0; p < 6; p++) {
            if (!(nums[i]&1<<p)) {
                pos *= 3;
                pos %= MOD;
            }
        }
    }
 
    cout << pos << "\n";
}