#include <bits/stdc++.h>
using namespace std;
 
const int M = 1e9+1;
 
void solve() {
    int n;
    cin >> n;
    vector<int> left{M, M, M}, right{0, 0, M}, one{M, 0, M};
    for (int i = 0; i < n; i++) {
        vector<int> item(3);
        cin >> item[0] >> item[1] >> item[2];
        if (item[0] < left[0]) {
            left = item;
        } else if (item[0] == left[0]) {
            if (item[2] < left[2]) {
                left = item;
            }
        }
        if (item[1] > right[1]) {
            right = item;
        } else if (item[1] == right[1]) {
            if (item[2] < right[2]) {
                right = item;
            }
        }
 
        if (item[1] - item[0] > one[1] - one[0]) {
            one = item;
        } else if (item[1] - item[0] == one[1] - one[0]) {
            if (item[2] < one[2]) {
                one = item;
            }
        }
 
        int ans = left[2] + right[2];
        if (one[1] - one[0] == right[1] - left[0]) {
            ans = min(ans, one[2]);
        }
        cout << ans << "\n";
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