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
        i--;
    }
    vector<char> s(m, 'B');
 
    for (int i = 0; i < n; i++) {
        int l = min(a[i], m-1-a[i]);
        if (s[l] == 'B') {
            s[l] = 'A';
        } else {
            s[m-1-l] = 'A';
        }
    }
    for (int i = 0; i < m; i++) {
        cout << s[i];
    }
    cout << "\n";
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