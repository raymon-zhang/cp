 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> nums(n);
        for (int &i: nums) {
            cin >> i;
        }
 
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x) {
                count++;
            }
        }
 
        if (count == n) {
            cout << "0\n";
            continue;
        } else if (count != 0) {
            cout << "1\n" ;
            continue;
        }
 
        int d = 0;
        for (int i = 0; i < n-1; i++) {
            d += x - nums[i];
        }
 
        if (nums[n-1] - d == x) {
            cout << "1\n";
            continue;
        }
        cout << "2\n";
    }
}