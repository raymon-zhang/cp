#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &x : nums) {
        cin >> x;
    }
 
    vector<vector<int>> numAs(n, vector<int> (n));
    vector<vector<int>> numDs(n, vector<int> (n));
 
    for (int c = 0; c < n; c++) {
        int pc = nums[c];
        int lessThan = 0;
        for (int b = 0; b < c; b++) {
            numAs[c][b] = lessThan;
            if (nums[b] < pc) {
                lessThan++;
            }
        }
    }
 
    for (int b = n-1; b >= 0; b--) {
        int pb = nums[b];
        int greaterThan = 0;
        for (int c = n-1; c > b; c--) {
            numDs[b][c] = greaterThan;
            if (nums[c] < pb) {
                greaterThan++;
            }
        }
    }
 
    long long total = 0;
    for (int b = 0; b < n; b++) {
        for (int c = b + 1; c < n; c++) {
            total += numAs[c][b] * numDs[b][c];
        }
    }
    cout << total << "\n";
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