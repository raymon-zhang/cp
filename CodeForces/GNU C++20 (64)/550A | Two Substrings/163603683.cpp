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
 
    string s;
    cin >> s;
    int ab = 0;
    vector<int> ai;
    int ba = 0;
    vector<int> bi;
    int n = s.size();
    for (int i = 0; i < n-1; i++) {
        if (s.at(i) == 'A' && s.at(i+1) == 'B') {
            ab++;
            ai.pb(i);
        } else if (s.at(i) == 'B' && s.at(i+1) == 'A') {
            ba++;
            bi.pb(i);
        }
    }
 
    if (ab == 0 || ba == 0) {
        cout << "NO\n";
    }
    else if (ab > 2 || ba > 2) {
        cout << "YES\n";
    }
    else if (ab == 1 && ba == 1) {
        if (bi[0] == ai[0]+1 || bi[0] == ai[0]-1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    else if (ab == 1) {
        sort(all(bi));
        if (bi[0] == ai[0]-1 && bi[1] == ai[0]+1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    else if (ba == 1) {
        sort(all(ai));
        if (ai[0] == bi[0]-1 && ai[1] == bi[0]+1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    } else {
        cout << "YES\n";
    }
}