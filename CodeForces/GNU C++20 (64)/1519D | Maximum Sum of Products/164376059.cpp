#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll &i: a) {
        cin >> i;
    }
    for (ll &i: b) {
        cin >> i;
    }
 
    ll initial = 0;
    for (int i = 0; i < n; i++) {
        initial += a[i] * b[i];
    }
    ll ans = initial;
 
    for (int m = 0; m < n; m++) {
        ll score = initial;
        int l = m-1, r = m+1;
        while (l >= 0 && r < n) {
            score += (a[r] - a[l]) * (b[l] - b[r]);
            ans = max(ans, score);
            l--;r++;
        }
 
        score = initial;
        l = m; r = m+1;
        while (l >= 0 && r < n) {
            score += (a[r] - a[l]) * (b[l] - b[r]);
            ans = max(ans, score);
            l--;r++;
        }
    }
    cout << ans << "\n";
}