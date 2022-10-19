#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int l = -1, r = -2;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (i && (nums[i] == nums[i-1])) {
            if (l == -1) {
                l = i;
            }
            r = i-1;
        }
    }
    if (r < l) {
        cout << "0\n";
    } else {
        cout << max(r-l, 1) << "\n";
    }
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}