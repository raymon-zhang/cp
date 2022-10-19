#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &i: a) {
        cin >> i;
    }
 
    bool sorted = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != i+1) {
            sorted = false;
        }
    }
 
    int need = n;
    while (a[need-1] == need) {
        need--;
    }
 
    double res = 1;
    for (int i = 0; i < m; i++) {
        int r;
        double p;
        cin >> r >> p;
        if (r >= need) {
            res *= 1-p;
        }
    }
    if (sorted) {
        cout << "1\n";
        return;
    }
    cout << setprecision(12) << 1-res << "\n";
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