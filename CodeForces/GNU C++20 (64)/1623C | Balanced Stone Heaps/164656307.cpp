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
    int n;
    cin >> n;
    assert(n>=3);
    vector<int> h(n);
    for (int &i: h) {
        cin >> i;
    }
    int l = *min_element(all(h));
    int r = *max_element(all(h));
    while (l < r) {
        vector<int> k = h;
        int m = (l+r+1)/2;
        bool good = true;
        for (int i = n-1; i >= 2; i--) {
            if (k[i] < m) {
                good = false;
                break;
            }
            k[i-1] += (min(k[i]-m, h[i])/3);
            k[i-2] += (min(k[i]-m, h[i])/3*2);
        }
        
        if (k[0] < m || k[1] < m) good = false;
        if (good) {
            l = m;
        } else {
            r = m-1;
        }
    }
    cout << l << "\n";
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