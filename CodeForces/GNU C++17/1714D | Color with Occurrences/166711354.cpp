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
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<string> s(n);
    map<string, int> si;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        si[s[i]] = i;
    }
 
    vector<pair<string, int>> cover(t.size());
    for (string x: s) {
        for (int i = 0; i < (int)t.size()-(int)x.size()+1; i++) {
            bool good = true;
            for (int j = 0; j < (int)x.size(); j++) {
                if (x[j] != t[i+j]) good = false;
            }
 
            if (good) {
                for (int j = 0; j < (int)x.size(); j++) {
                    if ((int)x.size() + i > (int)cover[i+j].second) {
                        cover[i+j] = {x, (int)x.size()+i};
                    }
                }
            }
        }
    }
 
    int cost = 0;
    vector<bool> colored(t.size());
    vector<pii> operations;
    for (int i = 0; i < (int)t.size(); i++) {
        if (colored[i]) continue;
        if (cover[i].first.empty()) {
            cout << -1 << "\n";
            return;
        }
        for (int j = cover[i].second-1; j > cover[i].second-(int)cover[i].first.size(); j--) {
            colored[j] = true;
        }
        cost++;
        operations.pb({si[cover[i].first]+1, cover[i].second-(int)cover[i].first.size()+1});
    }
    cout << cost << "\n";
    for (pii i: operations) {
        cout << i.first << " " << i.second << "\n";
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