#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    int m, k;
    cin >> n >> m >> k;
    int x, s;
    cin >> x >> s;
 
    vector<int> a(m+1);
    a[0] = x;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
 
    vector<int> b(m+1);
    b[0] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
 
    vector<int> c(k+1);
    c[0] = 0;
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }
 
    vector<int> d(k+1);
    d[0] = 0;
    for (int i = 1; i <= k; i++) {
        cin >> d[i];
    }
 
    long long best = 1LL * x * n;
    for (int i = 0; i <= m; i++) {
        if (b[i] > s) continue;
        int left = s - b[i];
        int l = 0, r = k;
        while (l < r) {
            int m = (l+r+1)/2;
            if (d[m] <= left) {
                l = m;
            } else {
                r = m-1;
            }
        }
        best = min(best, 1LL * (n - c[l]) * a[i]);
    }
 
    cout << best << "\n";
}