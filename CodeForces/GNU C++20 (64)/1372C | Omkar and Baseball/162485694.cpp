#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (i+1 == nums[i]) l++;
        else break;
    }
    
    int r = n-1;
    for (int i = n-1; i >= 0; i--) {
        if (i+1 == nums[i]) r--;
        else break;
    }
 
    if (r < l) {
        cout << "0\n";
        return;
    }
    
    int count = 0;
    for (int i = l; i <= r; i++) {
        if (i+1 == nums[i]) {
            count++;
        }
    }
    
    if (count == 0) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
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