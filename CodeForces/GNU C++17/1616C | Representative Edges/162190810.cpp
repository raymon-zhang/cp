#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<double> a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int count = n-1;
 
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double d = (a[j]-a[i])/(j-i);
            double start = a[i] - i * d;
            int c = 0;
            for (int k = 0; k < n; k++) {
                if (abs(start + k * d - a[k]) > 1e-9) {
                    c++;
                }
            }
            count = min(count, c);
        }
    }
 
    cout << count << "\n";
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