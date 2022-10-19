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
    // set<ll> layer;
    vector<int> gaps;
    vector<int> infected;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        a--;
        infected.pb(a);
    }
 
    sort(all(infected));
    for (int i = 1; i < m; i++) {
        if (infected[i]-infected[i-1]-1 > 0) gaps.pb(infected[i]-infected[i-1]-1);
    }
    if (infected[0]+n-infected[m-1]-1 > 0) gaps.pb(infected[0]+n-infected[m-1]-1);
 
    sort(all(gaps));
    reverse(all(gaps));
 
    int count = 0;
    int ans = m;
    for (int i: gaps) {
        int j = max(0, i-2*count);
        // cout << j << "\n";
        if (j == 0) ans += i;
        else if (j == 1) {
            count++;
            ans += i-1;
        } else if (j == 2) {
            count++;
            ans += i-1;
        } else {
            count+=2;
            ans += (i-j)+1;
        }
    }
 
    cout << ans << "\n";
}
 
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}