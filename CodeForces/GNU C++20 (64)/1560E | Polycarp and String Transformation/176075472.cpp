#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
template<class T> using V = vector<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
 
template<class T> bool smin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool smax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
const int MOD = 1e9+7; // 998244353
const int MX = 2e5+5;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
 
void solve() {
    string s;
    cin >> s;
 
    map<char, int> f;
    for (char c: s)f[c]++;
    
    map<char, bool> seen;
    vector<char> order;
    for (int i = sz(s)-1; i >= 0; i--) {
        if (!seen[s.at(i)]) {
            seen[s.at(i)] = true;
            order.pb(s.at(i));
        }
    }
 
    reverse(all(order));
 
    // int total = sz(order);
 
    map<char, int> initialF;
 
    for (int i = 0; i < sz(order); i++) {
        if (f[order[i]] % (i+1)) {
            cout << "-1\n";
            return;
        }
        initialF[order[i]] = f[order[i]]/(i+1);
    }
 
    map<char, int> initial;
    string start = "";
    for (char c: s) {
        initial[c]++;
        start += c;
        if (initial == initialF) break;
    }
 
    if (initial != initialF) {
        cout << "-1\n";
        return;
    }
 
    string res = start;
    string sstart = start;
    for (char c: order) {
        string next = "";
        for (char ch: sstart) {
            if (ch != c) next += ch;
        }
        res += next;
        sstart = next;
    }
 
    // cout << res << "\n";
 
    if (res == s) {
        cout << start << " ";
        for (char c: order) cout << c;
        cout << "\n";
    } else {
        cout << "-1\n";
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