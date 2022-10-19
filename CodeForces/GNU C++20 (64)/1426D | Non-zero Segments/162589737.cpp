#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
#define int long long
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) {
        cin >> i;
    }
 
    int count = 0;
    unordered_set<int> s;
    s.insert(0);
    int p = 0;
    for (int i = 0; i < n; i++) {
        p += a[i];
        if (s.count(p)) {
            count++;
            s.clear();
            s.insert(0);
            p = a[i];
        }
        s.insert(p);
    }
    cout << count << "\n";
}