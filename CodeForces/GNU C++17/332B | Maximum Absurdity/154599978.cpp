#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = nums[i-1] + p[i-1];
    }
 
    vector<pair<int, int>> bestR(n);
    int s = 0, m = 0, l = 0;
    for (int i = 0; i < n; i++) {
        s += nums[n-1-i];
        if (i >= k-1) {
            if (s >= m) {
                l = n-1-i;
                m = s;
            }
            bestR[n-1-i] = {m, l};
            s -= nums[n-1-i+k-1];
        }
    }
 
    int best = 0, a = 0, b = 0;
    for (int i = 0; i <= n-2*k; i++) {
        if (p[i+k]-p[i] + bestR[i+k].first > best) {
            a = i;
            b = bestR[i+k].second;
            best = p[i+k]-p[i] + bestR[i+k].first;
        }
    }
    cout << a+1 << " " << b+1 << "\n";
}